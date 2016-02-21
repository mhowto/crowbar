#include "eval_visitor.h"

CRBValue* EvalVisitor::getVariable(std::string variableName) {
    if (localVariableEnv.find(variableName) != localVariableEnv.end()) {
        return localVariableEnv[variableName];
    }
    if (globalVariableEnv.find(variableName) != globalVariableEnv.end()) {
        return globalVariableEnv[variableName];
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

}
