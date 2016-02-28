#include "eval_visitor.h"

CRBValue* EvalVisitor::getVariable(std::string variableName) {
    if (!localVariableEnvs.empty()) {
        VariableEnv localEnv = localVariableEnvs[localVariableEnvs.size() - 1];
        if (localEnv.find(variableName) != localEnv.end()) {
            return localEnv[variableName];
        }
    }
    if (!globalVariableDefinitions.empty()) {
        std::set<std::string> globalNames = globalVariableDefinitions[globalVariableDefinitions.size() - 1];
        if (globalNames.find(variableName) != globalNames.end()) {
            return globalVariableEnv[variableName];
        }
    }
    return nullptr;
}

Function* EvalVisitor::getFunction(std::string functionName) {
    if (localFunctionEnv.find(functionName) != localFunctionEnv.end()) {
        return localFunctionEnv[functionName];
    }
    if (globalFunctionEnv.find(functionName) != globalFunctionEnv.end()) {
        return globalFunctionEnv[functionName];
    }
    return nullptr;
}

void EvalVisitor::visit(FunctionCall* functionCall) {
    std::string functionName = functionCall->getName();
    std::vector<Expression*> arguments = functionCall->getArguments();

    if (globalFunctionEnv.find(functionName) == globalFunctionEnv.end()) {
        std::cout << "error: cannot find function definition:" << functionName << std::endl;
    }
    Function* function = globalFunctionEnv[functionName];
    std::vector<std::string> parameterList = function->getParamerterList();

    if (parameterList.size() != arguments.size()) {
        std::cout << "error: mismatch arguments size for function " << functionName << std::endl;
    }

    VariableEnv variableEnv;
    for (std::vector<Expression*>::size_type i = 0; i < arguments.size(); i++) {
        Expression* expr = arguments[i];
        expr->accept(*this);
        variableEnv[parameterList[i]] = this->getResult();
    }

    localVariableEnvs.push_back(variableEnv);

    // evalue function



    localVariableEnvs.pop_back();
}
