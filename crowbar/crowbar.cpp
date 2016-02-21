#include "crowbar.h"
#include "vistor.h"

void TranslationUnit::accept(Visitor& visitor) {
    visitor.visit(this);
}

void Function::accept(Visitor& visitor) {
    visitor.visit(this);
}

void AssignExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}

void BinaryExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}

void UnaryExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}

void FunctionCall::accept(Visitor& visitor) {
    visitor.visit(this);
}

void Primitive::accept(Visitor& visitor) {
    visitor.visit(this);
}

void IdentifierExpression::accept(Visitor& visitor) {
    visitor.visit(this);
}
void ExpressionStatement::accept(Visitor& visitor) {
    visitor.visit(this);
}

void GlobalStatement::accept(Visitor& visitor) {
    visitor.visit(this);
}

void Block::accept(Visitor& visitor) {
    visitor.visit(this);
}

void ElsIf::accept(Visitor& visitor) {
    visitor.visit(this);
}

void ElsIfList::accept(Visitor& visitor) {
    visitor.visit(this);
}

void IfElseIfStatement::accept(Visitor& visitor) {
    visitor.visit(this);
}

void IfStatement::accept(Visitor& visitor) {
    visitor.visit(this);
}

void WhileStatement::accept(Visitor& visitor) {
    visitor.visit(this);
}

void ForStatement::accept(Visitor& visitor) {
    visitor.visit(this);
}

void ReturnStatement::accept(Visitor& visitor) {
    visitor.visit(this);
}

void BreakStatement::accept(Visitor& visitor) {
    visitor.visit(this);
}

void ContinueStatement::accept(Visitor& visitor) {
    visitor.visit(this);
}