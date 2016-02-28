#include "eval_visitor.h"

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
    function->accept(*this);

    localVariableEnvs.pop_back();
}

void EvalVisitor::visit(Function* function) {
    function->getBlock()->accept(*this);
}

void EvalVisitor::visit(Block* block) {
    StatementList statementList = block->getList();
    for (StatementList::iterator iter = statementList.begin();
    iter != statementList.end();
        iter++) {
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

}

void EvalVisitor::visit(ElsIf *elsIf) {

}

void EvalVisitor::visit(ElsIfList *elsIfList) {

}

void EvalVisitor::visit(IfStatement* ifStatement) {

}
