#ifndef _CRB_EVAL_VISITOR_H
#define _CRB_EVAL_VISITOR_H

#include "vistor.h"
#include "CRB.h"
#include <map>
#include <set>

typedef std::map<std::string, CRBValue*> VariableEnv;
typedef std::map<std::string, Function*> FunctionEnv;

class EvalVisitor : public Visitor {
public:
    virtual void visit(TranslationUnit*) override;
    virtual void visit(Function*) override;
    virtual void visit(AssignExpression*) override;
    virtual void visit(BinaryExpression*) override;
    virtual void visit(UnaryExpression*) override;
    virtual void visit(FunctionCall*) override;
    virtual void visit(Primitive*) override;
    virtual void visit(IdentifierExpression*) override;
    virtual void visit(ExpressionStatement*) override;
    virtual void visit(GlobalStatement*) override;
    virtual void visit(Block*) override;
    virtual void visit(ElsIf*) override;
    virtual void visit(ElsIfList*) override;
    virtual void visit(IfElseIfStatement*) override;
    virtual void visit(IfStatement*) override;
    virtual void visit(WhileStatement*) override;
    virtual void visit(ForStatement*) override;
    virtual void visit(ReturnStatement*) override;
    virtual void visit(BreakStatement*) override;
    virtual void visit(ContinueStatement*) override;

    CRBValue* getResult() {
        return result;
    }

private:
    CRBValue* result; // 上一次eval得到的值

    // 堆栈形式的局部变量表
    std::vector<VariableEnv> localVariableEnvs;
    //std::map<std::string, CRBValue*> localVariableEnv;

    // 全局变量表和全局函数表
    VariableEnv globalVariableEnv;
    FunctionEnv globalFunctionEnv;

    // 用于记录函数中的全局变量表, 也为堆栈形式
    std::vector<std::set<std::string> > globalVariableDefinitions;

    CRBValue* getVariable(std::string variableName);
    Function* getFunction(std::string functionName);

    // 执行statement时使用
    StatementResult* statementResult;

    void addOrSetLocalVariable(std::string variableName, CRBValue* value);
    void addOrSetGlobalVariable(std::string variableName, CRBValue* value);

    void addOrSetLocalFunction(std::string functionName, Function* function);
    void addOrSetGlobalFunction(std::string functionName, Function* function);

    void deleteLocalVariable(std::string variableName);
    void deleteGlobalVariable(std::string variableName);

    void deleteLocalFunction(std::string functionName);
    void deleteGlobalFunction(std::string functionName);
};

#endif