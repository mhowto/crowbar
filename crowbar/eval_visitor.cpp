#include "eval_visitor.h"

EvalVisitor::EvalVisitor() {
    init();
}

void EvalVisitor::init() {
    addNativeFunction("print", native_print);
}

typedef CRBValue* (*NativeFunctionProc) (int, std::vector<CRBValue*>);
void EvalVisitor::addNativeFunction(std::string name, NativeFunctionProc proc) {
    Function* func = new Function(name, proc);
    globalFunctionEnv[name] = func;
}

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
    if (globalVariableDefinitions.find(variableName) != globalVariableDefinitions.end()) {
        return globalVariableEnv[variableName];
    }
    return nullptr;
}

Function* EvalVisitor::getFunction(std::string functionName) {
    if (globalFunctionEnv.find(functionName) != globalFunctionEnv.end()) {
        return globalFunctionEnv[functionName];
    }
    return nullptr;
}

typedef CRBValue* (Function::*ProcType) (int, std::vector<CRBValue*>);

void EvalVisitor::visit(FunctionCall* functionCall) {
    std::string functionName = functionCall->getName();
    std::vector<Expression*> arguments = functionCall->getArguments();

    Function* function = getFunction(functionName);
    if (function) {
        std::vector<std::string> parameterList = function->getParamerterList();

        if (function->isNative()) {
            std::vector<CRBValue *> argList;
            for (std::vector<Expression*>::size_type i = 0; i < arguments.size(); i++) {
                Expression* expr = arguments[i];
                expr->accept(*this);
                argList.push_back(this->getResult());
            }
          
            function->_proc(argList.size(), argList);
            /*
            ProcType proc = function->getProc();
            NativeFunctionProc proc = function->getProc();
            if (proc) {
                proc(argList.size(), argList);
            }
            */
        }
        else {
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
            std::vector<std::string> globalVals = function->global_vals;
            isGlobalEnv = true;
            for (std::string valName : globalVals) {
                variableEnv[valName] = globalVariableEnv[valName];
            }

            localVariableEnvs.push_back(variableEnv);
            bool originGlobalEnv = isGlobalEnv;
            isGlobalEnv = false;

            function->getBlock()->accept(*this);
            variableEnv = localVariableEnvs.back();
            for (std::string valName : globalVals) {
                globalVariableEnv[valName] = variableEnv[valName]->copyOnce();
            }

            isGlobalEnv = originGlobalEnv;
            localVariableEnvs.pop_back();
        }
    }
}

void EvalVisitor::visit(Function* function) {
    Block* block = function->getBlock();
    StatementList statements = block->getList();
    for (auto iter = std::begin(statements); iter != std::end(statements);) {
        if ((*iter)->is_global_statement) {
            GlobalStatement* globalStatement = static_cast<GlobalStatement*>(*iter);
            std::vector<std::string> identifiers = globalStatement->getIdentifiers();
            function->global_vals = identifiers;
            iter = statements.erase(iter);
        }
        else {
            iter++;
        }
    }
    // 向runtime注册一个函数 
    globalFunctionEnv[function->getName()] = function;
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
    if (returnStatement->expression) {
        returnStatement->expression->accept(*this);
        this->statementResult->~StatementResult();
        this->statementResult = new StatementResult(StatementResultType::ReturnStatementResult, this->result);
    }
    else {
        this->statementResult->~StatementResult();
        this->result = new CRBStringValue("undefined"); 
        this->statementResult = new StatementResult(StatementResultType::ReturnStatementResult, nullptr);
    }
}

void EvalVisitor::visit(ForStatement* forStatement) {
    Expression *initExpr = forStatement->initExpression;
    Expression *condExpr = forStatement->condExpression;
    Expression *actionExpr = forStatement->actionExpression;
    Block *block = forStatement->block;

    StatementResult* result;
    CRBValue* condResult;
    bool condValue = true;;
    if (initExpr) {
        initExpr->accept(*this);
    }
    do {
        if (block) {
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
        }

        if (actionExpr) {
            actionExpr->accept(*this);
        }

        if (condExpr) {
            condExpr->accept(*this);
            condResult = this->result;
            if (condResult->type != ValueType::BoolValue) {
                std::cout << "error: the eval result of cond expression in for-statement is not of type bool" << std::endl;
                exit(1);
            }
            condValue = static_cast<CRBBoolValue*>(condResult)->value;
        }
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

    if (exprNum != blockNum && exprNum + 1 != blockNum) {
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

void EvalVisitor::visit(ElsIf* elsIf) {}

void EvalVisitor::visit(ElsIfList* elsIfList) {}

void EvalVisitor::visit(TranslationUnit* transUnit) {
    std::vector<Node*> units = transUnit->getUnits();
    // 先得到所有的function def
    for (auto iter = std::begin(units); iter != std::end(units);) {
        if ((*iter)->isFunction()) {
            (*iter)->accept(*this);
            iter = units.erase(iter);
        }
        else {
            ++iter;
        }
    }
    for (auto iter = units.begin(); iter != units.end(); ++iter) {
        isGlobalEnv = true;
        (*iter)->accept(*this);
        if (this->statementResult) {
            // 如果是statement
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

    //CRBValue* value = getVariable(iden);
    if (isGlobalEnv) {
        globalVariableDefinitions.insert(iden);
        globalVariableEnv[iden] = this->result->copyOnce();
    }
    else {
        std::map<std::string, CRBValue*>& localEnv = localVariableEnvs.back();
        localEnv[iden] = this->result->copyOnce();
    }
    //this->result = nullptr;
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

    // 动态语言要转换成一致的类型
    // 隐式类型类型转换原则：
    // 无奈，做成javascript那种
    // 1. 低精度 转换到 高精度 即 int->double true->1 false->0
    // 2. int, double, bool -> string 
    switch (op) {
    case BinaryOperator::ADD: 
    {
        if (leftType == ValueType::StringValue || rightType == ValueType::StringValue) {
            //delete this->result;
            this->result = new CRBStringValue(leftVal->toString() + rightVal->toString());
        }
        else {
            //delete this->result;
            this->result = new CRBDoubleValue(leftVal->toDouble() + rightVal->toDouble());
        }
        break;
    }
    case BinaryOperator::SUB:
        //delete this->result;
        this->result = new CRBDoubleValue(leftVal->toDouble() - rightVal->toDouble());
        break;
    case BinaryOperator::MUL:
        //delete this->result;
        this->result = new CRBDoubleValue(leftVal->toDouble() * rightVal->toDouble());
        break;
    case BinaryOperator::DIV:
    {
        //delete this->result;
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
        //delete this->result;
        int lval = leftVal->toInt();
        int rval = rightVal->toInt();
        if (rval == 0) {
            this->result = new CRBDoubleValue(std::nan("0"));
        }
        else {
            this->result = new CRBDoubleValue(lval % rval);
        }
        break;
    }
    case BinaryOperator::AND:
        //delete this->result;
        this->result = new CRBBoolValue(leftVal->toBool() && rightVal->toBool());
        break;
    case BinaryOperator::OR:
        //delete this->result;
        this->result = new CRBBoolValue(leftVal->toBool() || rightVal->toBool());
        break;
    case BinaryOperator::LT:
    {
        //delete this->result;
        if (leftType == ValueType::StringValue || rightType == ValueType::StringValue) {
            std::string lval = leftVal->toString();
            std::string rval = rightVal->toString();
            this->result = new CRBBoolValue(lval < rval);
        }
        else {
            double lval = leftVal->toDouble();
            double rval = rightVal->toDouble();
            if (std::isnan(lval) || std::isnan(rval)) {
                this->result = new CRBBoolValue(false);
            }
            else {
                this->result = new CRBBoolValue(lval < rval);
            }
        }
        break;
    }
    case BinaryOperator::LE:
    {
        //delete this->result;
        if (leftType == ValueType::StringValue || rightType == ValueType::StringValue) {
            std::string lval = leftVal->toString();
            std::string rval = rightVal->toString();
            this->result = new CRBBoolValue(lval <= rval);
        }
        else {
            double lval = leftVal->toDouble();
            double rval = rightVal->toDouble();
            if (std::isnan(lval) || std::isnan(rval)) {
                this->result = new CRBBoolValue(false);
            }
            else {
                this->result = new CRBBoolValue(lval <= rval);
            }
        }
        break;
    }
    case BinaryOperator::GT:
    {
        //delete this->result;
        if (leftType == ValueType::StringValue || rightType == ValueType::StringValue) {
            std::string lval = leftVal->toString();
            std::string rval = rightVal->toString();
            this->result = new CRBBoolValue(lval > rval);
        }
        else {
            double lval = leftVal->toDouble();
            double rval = rightVal->toDouble();
            if (std::isnan(lval) || std::isnan(rval)) {
                this->result = new CRBBoolValue(false);
            }
            else {
                this->result = new CRBBoolValue(lval > rval);
            }
        }
        break;
    }
    case BinaryOperator::GE:
    {
        //delete this->result;
        if (leftType == ValueType::StringValue || rightType == ValueType::StringValue) {
            std::string lval = leftVal->toString();
            std::string rval = rightVal->toString();
            this->result = new CRBBoolValue(lval >= rval);
        }
        else {
            double lval = leftVal->toDouble();
            double rval = rightVal->toDouble();
            if (std::isnan(lval) || std::isnan(rval)) {
                this->result = new CRBBoolValue(false);
            }
            else {
                this->result = new CRBBoolValue(lval >= rval);
            }
        }
        break;
    }
    case BinaryOperator::EQ:
    {
        //delete this->result;

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
        //delete this->result;

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
    delete leftVal;
    delete rightVal;
}

void EvalVisitor::visit(UnaryExpression* unaryExpr) {
    Expression* expr = unaryExpr->getExpr();
    UnaryOperator op = unaryExpr->getOp();

    expr->accept(*this);
    CRBValue* val = this->result;

    switch (op) {
    case UnaryOperator::NEGATIVE:
        //delete this->result;
        this->result = new CRBDoubleValue(-val->toDouble());
        break;
    case UnaryOperator::NOT:
        //delete this->result;
        this->result = new CRBBoolValue(!val->toBool());
        break;
    }
    delete val;
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
        this->result = new CRBNativePointer("char", nullptr);
        break;
    default:
        break;
    }
}

void EvalVisitor::visit(IdentifierExpression* idenExpr) {
    std::string identifier = idenExpr->getIdentifier();

    CRBValue* val = getVariable(identifier);
    if (val) {
        this->result = val->copyOnce();
    }
    else {
        this->result = new CRBStringValue("undefined");
    }
}

void EvalVisitor::visit(ExpressionStatement* statement) {
    Expression* expr = statement->getExpression();
    expr->accept(*this);
    this->statementResult = new StatementResult(StatementResultType::NormalStatementResult);
}

void EvalVisitor::visit(GlobalStatement* globalStatement) {
/*
    std::vector<std::string> identifiers = globalStatement->getIdentifiers();
    std::set<std::string> env = globalVariableDefinitions.back();
    for (int i = 0; i < identifiers.size(); i++) {
        std::string iden = identifiers[i];
        if (env.find(iden) == env.end()) {
            env.insert(iden);
        }
    }
    this->statementResult = new StatementResult(StatementResultType::NormalStatementResult);
*/
}