#ifndef _CRB_VISITOR_H
#define _CRB_VISITOR_H

#include "crowbar.h"

class Visitor {
public:
    virtual void visit(TranslationUnit*) = 0;
    virtual void visit(Function*) = 0;
    virtual void visit(AssignExpression*) = 0;
    virtual void visit(BinaryExpression*) = 0;
    virtual void visit(UnaryExpression*) = 0;
    virtual void visit(FunctionCall*) = 0;
    virtual void visit(Primitive*) = 0;
    virtual void visit(IdentifierExpression*) = 0;
    virtual void visit(ExpressionStatement*) = 0;
    virtual void visit(GlobalStatement*) = 0;
    virtual void visit(Block*) = 0;
    virtual void visit(ElsIf*) = 0;
    virtual void visit(ElsIfList*) = 0;
    virtual void visit(IfElseIfStatement*) = 0;
    virtual void visit(IfStatement*) = 0;
    virtual void visit(WhileStatement*) = 0;
    virtual void visit(ForStatement*) = 0;
    virtual void visit(ReturnStatement*) = 0;
    virtual void visit(BreakStatement*) = 0;
    virtual void visit(ContinueStatement*) = 0;
};

#endif