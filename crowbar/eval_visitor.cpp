#include "eval_visitor.h"

bool EvalVisitor::visitBoolExpr(Expression* expr) {
    expr->accept(*this);
    if (this->result->type != ValueType::BoolValue) {
        std::cout << "error: the eval result of cond expression in while-statement is not of type bool" << std::endl;
        exit(1);
    }
    return static_cast<CRBBoolValue*>(this->result)->value;
}

CRBValue* EvalVisitor::getVariable(std::string variableName) {
    if (!localVariableEnvs.empty()) {
        VariableEnv localEnv = localVariableEnvs.back();
        if (localEnv.find(variableName) != localEnv.end()) {
            return localEnv[variableName];
        }
    }
    if (!globalVariableDefinitions.empty()) {
        std::set<std::string> globalNames = globalVariableDefinitions.back();
        if (globalNames.find(variableName) != globalNames.end()) {
            return globalVariableEnv[variableName];
        }
    }
    return nullptr;
}

Function* EvalVisitor::getFunction(std::string functionName) {
    if (globalFunctionEnv.find(functionName) != globalFunctionEnv.end()) {
        return globalFunctionEnv[functionName];
    }
    return nullptr;
}

void EvalVisitor::visit(FunctionCall* functionCall) {
    std::string functionName = functionCall->getName();
    std::vector<Expression*> arguments = functionCall->getArguments();

    Function* function = getFunction(functionName);
    if (!function) {
        std::cout << "error: cannot find function definition:" << functionName << std::endl;
        exit(1);
    }

    std::vector<std::string> parameterList = function->getParamerterList();

    if (parameterList.size() != arguments.size()) {
        std::cout << "error: mismatch arguments size for function " << functionName << std::endl;
        exit(1);
    }

    VariableEnv variableEnv;
    for (std::vector<Expression*>::size_type i = 0; i < arguments.size(); i++) {
        Expression* expr = arguments[i];
        expr->accept(*this);
        variableEnv[parameterList[i]] = this->getResult();
    }

    localVariableEnvs.push_back(variableEnv);

    // evaluate function
    bool originGlobalEnv = isGlobalEnv;
    isGlobalEnv = false;
    function->accept(*this);
    isGlobalEnv = originGlobalEnv;

    localVariableEnvs.pop_back();
}

void EvalVisitor::visit(Function* function) {
    function->getBlock()->accept(*this);
}

void EvalVisitor::visit(Block* block) {
    StatementList statementList = block->getList();
    for (StatementList::iterator iter = statementList.begin(); iter != statementList.end(); iter++) {
        (*iter)->accept(*this);
        if (this->statementResult->type != StatementResultType::NormalStatementResult) {
            return;
        }
    }

    if (this->statementResult) {
        this->statementResult->~StatementResult();
    }
    this->statementResult = new StatementResult(StatementResultType::NormalStatementResult);
}

void EvalVisitor::visit(ContinueStatement* continueStatement) {
    this->statementResult->~StatementResult();
    this->statementResult = new StatementResult(StatementResultType::ContinueStatementResult);
}

void EvalVisitor::visit(BreakStatement* breakStatement) {
    this->statementResult->~StatementResult();
    this->statementResult = new StatementResult(StatementResultType::BreakStatementResult);
}

void EvalVisitor::visit(ReturnStatement* returnStatement) {
    returnStatement->expression->accept(*this);
    this->statementResult->~StatementResult();
    this->statementResult = new StatementResult(StatementResultType::ReturnStatementResult, this->result);
    this->result = nullptr; // delegate the expression's result to the statement
}

void EvalVisitor::visit(ForStatement* forStatement) {
    Expression *initExpr = forStatement->initExpression;
    Expression *condExpr = forStatement->condExpression;
    Expression *actionExpr = forStatement->actionExpression;
    Block *block = forStatement->block;

    StatementResult* result;
    CRBValue* condResult;
    bool condValue;
    initExpr->accept(*this);
    do {
        block->accept(*this);
        result = this->statementResult;
        switch (result->type) {
        case StatementResultType::BreakStatementResult:
            this->statementResult = new StatementResult(StatementResultType::NormalStatementResult);
            result->~StatementResult();
            return;
        case StatementResultType::ReturnStatementResult:
            this->statementResult = new StatementResult(StatementResultType::ReturnStatementResult, this->result);
            result->~StatementResult();
            return;
        default:
            break;
        }

        actionExpr->accept(*this);

        condExpr->accept(*this);
        condResult = this->result;
        if (condResult->type != ValueType::BoolValue) {
            std::cout << "error: the eval result of cond expression in for-statement is not of type bool" << std::endl;
            exit(1);
        }
        condValue = static_cast<CRBBoolValue*>(condResult)->value;
    } while (condValue);

    this->statementResult = new StatementResult(StatementResultType::NormalStatementResult);
}

void EvalVisitor::visit(WhileStatement* whileStatement) {
    Expression* expr = whileStatement->expression;
    Block* block = whileStatement->block;

    expr->accept(*this);
    if (this->result->type != ValueType::BoolValue) {
        std::cout << "error: the eval result of cond expression in while-statement is not of type bool" << std::endl;
        exit(1);
    }
    bool condValue = static_cast<CRBBoolValue*>(this->result)->value;
    StatementResult* result;
    while (condValue) {
        block->accept(*this);
        result = this->statementResult;
        switch (result->type) {
        case StatementResultType::BreakStatementResult:
            this->statementResult = new StatementResult(StatementResultType::NormalStatementResult);
            result->~StatementResult();
            return;
        case StatementResultType::ReturnStatementResult:
            this->statementResult = new StatementResult(StatementResultType::ReturnStatementResult, this->result);
            result->~StatementResult();
            return;
        default:
            break;
        }
        expr->accept(*this);
        if (this->result->type != ValueType::BoolValue) {
            std::cout << "error: the eval result of cond expression in while-statement is not of type bool" << std::endl;
            exit(1);
        }
        condValue = static_cast<CRBBoolValue*>(this->result)->value;
    }

    this->statementResult = new StatementResult(StatementResultType::NormalStatementResult);
}

void EvalVisitor::visit(IfElseIfStatement *ifElseIfStatement) {
    std::vector<Expression*> expressions = ifElseIfStatement->getExpressions();
    std::vector<Block*> blocks = ifElseIfStatement->getBlocks();

    auto evalBlockResult = [this]() {
        StatementResult* result = this->statementResult;
        switch (result->type) {
        case StatementResultType::BreakStatementResult:
            this->statementResult = new StatementResult(StatementResultType::NormalStatementResult);
            result->~StatementResult();
            return true;
        case StatementResultType::ReturnStatementResult:
            this->statementResult = new StatementResult(StatementResultType::ReturnStatementResult, this->result);
            result->~StatementResult();
            return true;
        case StatementResultType::ContinueStatementResult:
            this->statementResult = new StatementResult(StatementResultType::ContinueStatementResult, this->result);
            result->~StatementResult();
            return true;
        default:
            return false;  // return normal result
        }
        return false;
    };

    auto exprNum = expressions.size();
    auto blockNum = blocks.size();

    if (exprNum != blockNum || exprNum + 1 != blockNum) {
        std::cout << "mismatch of expression and block pair in if-else statement" << std::endl;
        exit(1);
    }

    for (std::size_t i = 0; i < exprNum; i++) {
        Expression* expr = expressions[i];
        Block* block = blocks[i];

        if (visitBoolExpr(expr)) {
            block->accept(*this);
            /*
            if (this->statementResult->type == StatementResultType::ReturnStatementResult) {
            }
            return;
            */
        }
    }

    if (exprNum + 1 == blockNum) {
        Block* block = blocks[blockNum - 1];
        block->accept(*this);
    }
}

void EvalVisitor::visit(IfStatement* ifStatement) {
    Expression* expr = ifStatement->expression;
    Block* block = ifStatement->block;
    Block* elseBlock = ifStatement->elseBlock;

    if (visitBoolExpr(expr)) {
        block->accept(*this);
    }
    else if (elseBlock){
        elseBlock->accept(*this);
    }
}

void EvalVisitor::visit(TranslationUnit* transUnit) {
    std::vector<Node*> units = transUnit->getUnits();
    for (auto iter = units.begin(); iter != units.end(); ++iter) {
        isGlobalEnv = true;
        (*iter)->accept(*this);
        if (this->statementResult) {
            // �����statement
            switch (this->statementResult->type) {
            case StatementResultType::BreakStatementResult:
                std::cout << "illegal break statement in translation unit" << std::endl;
                std::exit(1);
                break;
            case StatementResultType::ContinueStatementResult:
                std::cout << "illegal continue statement in translation unit" << std::endl;
                std::exit(1);
                break;
            case StatementResultType::ReturnStatementResult:
                return;
            default:
                // Normal Result
                break;
            }
        }

        delete this->statementResult;
    }
}

void EvalVisitor::visit(AssignExpression* assignExpr) {
    std::string iden = assignExpr->getIdentifier();
    Expression* expr = assignExpr->getExpression();

    expr->accept(*this);
    if (!this->result) {
        std::cout << "assign expression eval failed" << std::endl;
        exit(1);
    }

    CRBValue* value = getVariable(iden);

    if (isGlobalEnv) {
        globalVariableEnv[iden] = this->result;
    }
    else {
        std::map<std::string, CRBValue*>& localEnv = localVariableEnvs.back();
        localEnv[iden] = this->result;
    }

    result = nullptr;

    /*
    switch (this->result->type) {
    case ValueType::BoolValue:
        break;
    case ValueType::DoubleValue:
        break;
    case ValueType::IntValue:
        break;
    case ValueType::NativePointer:
        break;
    case ValueType::StringValue:
        break;
    default:
        return;
    }
    */
}

void EvalVisitor::visit(BinaryExpression* binaryExpr) {
    BinaryOperator op = binaryExpr->getOp();
    Expression* leftExpr = binaryExpr->getLeft();
    Expression* rightExpr = binaryExpr->getRight();


    leftExpr->accept(*this);
    CRBValue* leftVal = this->result;
    rightExpr->accept(*this);
    CRBValue* rightVal = this->result;

    ValueType leftType = leftVal->type;
    ValueType rightType = rightVal->type;

    // ��̬����Ҫת����һ�µ�����
    // ��ʽ��������ת��ԭ��
    // ���Σ�����javascript����
    // 1. �;��� ת���� �߾��� �� int->double true->1 false->0
    // 2. int, double, bool -> string 
    switch (op) {
    case BinaryOperator::ADD: 
    {
        if (leftType == ValueType::StringValue || rightType == ValueType::StringValue) {
            delete this->result;
            this->result = new CRBStringValue(leftVal->toString() + rightVal->toString());
        }
        else {
            delete this->result;
            this->result = new CRBDoubleValue(leftVal->toDouble() + rightVal->toDouble());
        }
        break;
    }
    case BinaryOperator::SUB:
        delete this->result;
        this->result = new CRBDoubleValue(leftVal->toDouble() + rightVal->toDouble());
        break;
    case BinaryOperator::MUL:
        delete this->result;
        this->result = new CRBDoubleValue(leftVal->toDouble() + rightVal->toDouble());
        break;
    case BinaryOperator::DIV:
    {
        delete this->result;
        double lval = leftVal->toDouble();
        double rval = rightVal->toDouble();
        if (almost_equal(rval, 0.0, 2)) {
            this->result = new CRBDoubleValue(std::nan("0"));
        }
        else {
            this->result = new CRBDoubleValue(lval / rval);
        }
        break;
    }
    case BinaryOperator::MOD:
    {
        delete this->result;
        int lval = leftVal->toInt();
        int rval = rightVal->toInt();
        if (rval = 0) {
            this->result = new CRBDoubleValue(std::nan("0"));
        }
        else {
            this->result = new CRBDoubleValue(lval % rval);
        }
        break;
    }
    case BinaryOperator::AND:
        delete this->result;
        this->result = new CRBBoolValue(leftVal->toBool() && rightVal->toBool());
        break;
    case BinaryOperator::OR:
        delete this->result;
        this->result = new CRBBoolValue(leftVal->toBool() || rightVal->toBool());
        break;
    case BinaryOperator::LT:
    {
        delete this->result;

        double lval = leftVal->toDouble();
        double rval = rightVal->toDouble();
        if (std::isnan(lval) || std::isnan(rval)) {
            this->result = new CRBBoolValue(false);
        }
        else {
            this->result = new CRBBoolValue(lval < rval);
        }
        break;
    }
    case BinaryOperator::LE:
    {
        delete this->result;

        double lval = leftVal->toDouble();
        double rval = rightVal->toDouble();
        if (std::isnan(lval) || std::isnan(rval)) {
            this->result = new CRBBoolValue(false);
        }
        else {
            this->result = new CRBBoolValue(lval <= rval);
        }
        break;
    }
    case BinaryOperator::GT:
    {
        delete this->result;

        double lval = leftVal->toDouble();
        double rval = rightVal->toDouble();
        if (std::isnan(lval) || std::isnan(rval)) {
            this->result = new CRBBoolValue(false);
        }
        else {
            this->result = new CRBBoolValue(lval > rval);
        }
        break;
    }
    case BinaryOperator::GE:
    {
        delete this->result;

        double lval = leftVal->toDouble();
        double rval = rightVal->toDouble();
        if (std::isnan(lval) || std::isnan(rval)) {
            this->result = new CRBBoolValue(false);
        }
        else {
            this->result = new CRBBoolValue(lval >= rval);
        }
        break;
    }
    case BinaryOperator::EQ:
    {
        delete this->result;

        if (leftType != rightType) {
            this->result = new CRBBoolValue(false);
        }
        else {
            switch (leftType) {
            case ValueType::BoolValue:
                this->result = new CRBBoolValue(leftVal->toBool() == rightVal->toBool());
                break;
            case ValueType::DoubleValue:
                this->result = new CRBBoolValue(almost_equal(leftVal->toDouble(), rightVal->toDouble(), 2));
                break;
            case ValueType::NativePointer:
                this->result = new CRBBoolValue(leftVal->toInt() == rightVal->toInt());
                break;
            case ValueType::StringValue:
                this->result = new CRBBoolValue(leftVal->toString() == rightVal->toString());
                break;
            }
        }
        break;
    }
    case BinaryOperator::NE:
    {
        delete this->result;

        if (leftType != rightType) {
            this->result = new CRBBoolValue(true);
        }
        else {
            switch (leftType) {
            case ValueType::BoolValue:
                this->result = new CRBBoolValue(leftVal->toBool() != rightVal->toBool());
                break;
            case ValueType::DoubleValue:
                this->result = new CRBBoolValue(!almost_equal(leftVal->toDouble(), rightVal->toDouble(), 2));
                break;
            case ValueType::NativePointer:
                this->result = new CRBBoolValue(leftVal->toInt() != rightVal->toInt());
                break;
            case ValueType::StringValue:
                this->result = new CRBBoolValue(leftVal->toString() != rightVal->toString());
                break;
            }
        }
        break;
    }
    default:
        break;
    }
}

void EvalVisitor::visit(UnaryExpression*) {
}

void EvalVisitor::visit(FunctionCall*) {
}

void EvalVisitor::visit(Primitive* primitive) {
    PrimitiveType type = primitive->getType();
    std::string literal = primitive->getLiteral();
    switch (type) {
    case PrimitiveType::INT_LITERAL:
        this->result = new CRBDoubleValue(literal);
        break;
    case PrimitiveType::DOUBLE_LITERAL:
        this->result = new CRBDoubleValue(literal);
        break;
    case PrimitiveType::STRING_LITERAL:
        this->result = new CRBStringValue(literal);
        break;
    case PrimitiveType::FALSE_T:
        this->result = new CRBBoolValue(false);
        break;
    case PrimitiveType::TRUE_T:
        this->result = new CRBBoolValue(true);
        break;
    case PrimitiveType::NULL_T:
        this->result = new CRBNativePointer(nullptr);
        break;
    default:
        break;
    }
}

void EvalVisitor::visit(IdentifierExpression*) {
}

void EvalVisitor::visit(ExpressionStatement*) {

}

void EvalVisitor::visit(GlobalStatement*) {
}