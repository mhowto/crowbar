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
    CRBValue* result; // ��һ��eval�õ���ֵ

    bool isGlobalEnv; // ���ڱ���Ƿ���ȫ��
    // ��ջ��ʽ�ľֲ�������
    std::vector<VariableEnv> localVariableEnvs;
    //std::map<std::string, CRBValue*> localVariableEnv;

    // ȫ�ֱ������ȫ�ֺ�����
    VariableEnv globalVariableEnv;
    FunctionEnv globalFunctionEnv;

    // ���ڼ�¼�����е�ȫ�ֱ�����, ҲΪ��ջ��ʽ
    std::vector<std::set<std::string> > globalVariableDefinitions;

    CRBValue* getVariable(std::string variableName);
    Function* getFunction(std::string functionName);

    // ִ��statementʱʹ��
    StatementResult* statementResult;

    void addOrSetLocalVariable(std::string variableName, CRBValue* value);
    void addOrSetGlobalVariable(std::string variableName, CRBValue* value);

    void addOrSetLocalFunction(std::string functionName, Function* function);
    void addOrSetGlobalFunction(std::string functionName, Function* function);

    void deleteLocalVariable(std::string variableName);
    void deleteGlobalVariable(std::string variableName);

    void deleteLocalFunction(std::string functionName);
    void deleteGlobalFunction(std::string functionName);

    // ��������
    bool visitBoolExpr(Expression* expr);  // eval һ��bool���ʽ
    // StatementResult* visitBlock(Block* block); // evalһ��block
};

#endif