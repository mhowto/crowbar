#ifndef _CRB_EVAL_VISITOR_H
#define _CRB_EVAL_VISITOR_H

#include "vistor.h"
#include "CRB.h"
#include <map>
#include <set>

typedef std::map<std::string, CRBValue*> VariableEnv;
typedef std::map<std::string, Function*> FunctionEnv;
typedef CRBValue* (*NativeFunctionProc) (int, std::vector<CRBValue*>);

class EvalVisitor : public Visitor {
public:

    /*
    typedef void (*Callback0)(void* ret);
    typedef void (*Callback1)(void* p1, void* ret);
    typedef void (*Callback2)(void* p1, void* p2, void* ret);
    typedef void (*Callback3)(void* p1, void* p2, void* p3, void* ret);
    */

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

    EvalVisitor();
private:
    CRBValue* result; // 上一次eval得到的值

    bool isGlobalEnv; // 用于标记是否是全局
    // 堆栈形式的局部变量表
    std::vector<VariableEnv> localVariableEnvs;
    //std::map<std::string, CRBValue*> localVariableEnv;

    // 全局变量表和全局函数表
    VariableEnv globalVariableEnv;
    FunctionEnv globalFunctionEnv;

    /*********** 预定义函数 ********/
    /* 实现太复杂
    bool callPreDefinedFunction(std::string name, std::vector<std::string> params);
    std::vector<std::string> preDefinedFunctionNames;

    std::map<std::string, Callback0> funcMap0;
    std::map<std::string, Callback1> funcMap1;
    std::map<std::string, Callback2> funcMap2;
    std::map<std::string, Callback3> funcMap3;
    */
    /*********** 预定义函数 ********/

    std::set<std::string> globalVariableDefinitions;

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

    // 辅助函数
    bool visitBoolExpr(Expression* expr);  // eval 一个bool表达式
    // StatementResult* visitBlock(Block* block); // eval一个block

    void init();
    void addNativeFunction(std::string name, NativeFunctionProc proc);
};

#endif