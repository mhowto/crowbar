#ifndef _CRB_EVAL_VISITOR_H
#define _CRB_EVAL_VISITOR_H

#include "vistor.h"
#include "CRB.h"
#include <map>

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
private:
    CRBValue* lastValue; // ��һ��eval�õ���ֵ

    // �ֲ�������;ֲ�������
    std::map<std::string, CRBValue*> localVariableEnv;
    std::map<std::string, Function*> localFunctionEnv;

    // ȫ�ֱ������ȫ�ֺ�����
    std::map<std::string, CRBValue*> globalVariableEnv;
    std::map<std::string, Function*> globalFunctionEnv;

    // �������еĲ���
    std::map<std::string, CRBValue*> arguments;

    CRBValue* getVariable(std::string variableName);
    Function* getFunction(std::string functionName);

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