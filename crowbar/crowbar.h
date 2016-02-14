#ifndef _CRB_CROWBAR_H
#define _CRB_CROWBAR_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>

#define LINE_BUF_SIZE 500

enum class BinaryOperator
{
    ADD, SUB, MUL, DIV,
    MOD,
    LEFT_SHIFT, RIGHT_SHIFT,
    EQ, NE,
    LT, LE,
    GT, GE,
    ASSIGN, OR, AND,
    BITWISE_AND, BITWISE_OR, BITWISE_XOR,
    COMMA,
    NONE
};

enum class UnaryOperator
{
    NOT, NEGATIVE
};

class Node {
public:
    virtual ~Node() {}
};

class Expression : public Node{};
class Statement : public Node {};

class Block;

class TranslationUnit {
public:
    void push(Node* definition_or_statement) {
        this->_definitions_or_statements.push_back(definition_or_statement);
    }
private:
    std::vector<Node*> _definitions_or_statements;
};

class Function : public Node {
public:
    ~Function() {}
    Function(std::string name, std::vector<std::string> parameter_list, Block* block)
        : _name(name), _parameter_list(parameter_list), _block(block) {}
    Function(std::string name, Block* block)
        : _name(name), _block(block) {}

private:
    std::string _name;
    std::vector<std::string> _parameter_list;
    Block* _block;
};


class AssignExpression : public Expression {
public:
    AssignExpression(std::string identifier, Expression* expression)
        : _identifier(identifier), _expression(expression) {}

private:
    std::string _identifier;
    Expression* _expression;
};

class BinaryExpression : public Expression {
public:
    BinaryExpression(BinaryOperator op, Expression* left, Expression* right)
        :_op(op), _left(left), _right(right) {}
private:
    BinaryOperator _op;
    Expression* _left;
    Expression* _right;
};

class UnaryExpression : public Expression {
public:
    UnaryExpression(UnaryOperator op, Expression* expr)
        :_op(op), _expr(expr) {}

private:
    UnaryOperator _op;
    Expression* _expr;
};

class PrimaryExpression : public Expression {
};

class FunctionCall : public PrimaryExpression {
public:
    FunctionCall(std::string name, std::vector<Expression*> arguments) 
        : _name(name), _arguments(arguments) {}
    FunctionCall(std::string name) : _name(name) {}
private:
    std::string _name;
    std::vector<Expression*> _arguments;
};

enum class PrimitiveType {
    INT_LITERAL,
    DOUBLE_LITERAL,
    STRING_LITERAL,
    TRUE_T,
    FALSE_T,
    NULL_T
};

class Primitive : public PrimaryExpression {
public:
    Primitive(PrimitiveType type, std::string literal)
        : _type(type), _literal(literal) {}
    Primitive(PrimitiveType type)
        : _type(type) {}
private:
    PrimitiveType _type;
    std::string _literal;
};

class IdentifierExpression : public PrimaryExpression {
public:
    IdentifierExpression(std::string identifier)
        : _identifier(identifier) {}
private:
    std::string _identifier;
};

typedef std::vector<Expression*> ArgumentList;
typedef std::vector<Statement*> StatementList;
typedef std::vector<std::string> IdentifierList;
typedef std::vector<std::string> ParameterList;

class ExpressionStatement : public Statement {
public:
    ExpressionStatement(Expression* expression)
        : _expression(expression) {}
private:
    Expression* _expression;
};

class GlobalStatement : public Statement {
public:
    GlobalStatement(std::vector<std::string> identifiers)
        : _identifier_list(identifiers) {}
private:
    std::vector<std::string> _identifier_list;
};


class Block : public Statement {
public:
    Block() {}
    Block(StatementList list) : _list(list) {}
private:
    StatementList _list;
};

class ElsIf : public Statement {
public:
    ElsIf(Expression* expression, Block* block)
        : _expression(expression), _block(block) {}
private:
    Expression* _expression;
    Block* _block;
};

class ElsIfList : public Statement {
public:
    ElsIfList(ElsIf* els_if, ElsIfList* elsif_list) : _els_if(els_if), _elsif_list(elsif_list) {}
private:
    ElsIf* _els_if;
    ElsIfList* _elsif_list;
};

class IfElseIfStatement : public Statement {
public:
    IfElseIfStatement(Expression *expression, Block* block, ElsIfList* els_if_list)
        : _expression(expression), _block(block), _els_if_list(els_if_list) {}
    IfElseIfStatement(Expression *expression, Block* block, ElsIfList* els_if_list, Block* else_block)
        : _expression(expression), _block(block), _els_if_list(els_if_list), _else_block(else_block) {}
private:
    Expression* _expression;
    Block* _block;
    ElsIfList* _els_if_list;
    Block* _else_block;
};

class IfStatement : public Statement {
public:
    IfStatement(Expression* expression, Block* block)
        : _expression(expression), _block(block) {}
    IfStatement(Expression* expression, Block* block, Block *else_block)
        : _expression(expression), _block(block), _else_block(else_block) {}
private:
    Expression* _expression;
    Block* _block;
    Block* _else_block;
};

class WhileStatement : public Statement {
public:
    WhileStatement(Expression* expression, Block* block)
        : _expression(expression), _block(block) {}
private:
    Expression* _expression;
    Block* _block;
};

class ForStatement : public Statement {
public:
    ForStatement(Expression *init_expression, Expression *cond_expression,
        Expression *action_expression, Block* block)
        : _init_expression(init_expression), _cond_expression(cond_expression),
          _action_expression(action_expression), _block(block) {}
private:
    Expression *_init_expression, *_cond_expression, *_action_expression;
    Block* _block;
};

class ReturnStatement : public Statement {
public:
    ReturnStatement(Expression *expression)
        : _expression(expression) {}
private:
    Expression *_expression;
};

class BreakStatement : public Statement {
};

class ContinueStatement : public Statement {
};

/* string.cpp */
class StringLiteral {
public:
    static const char* getStringLiteral();
    static void addToString(char ch);
    static void createStringLiteral();
    static const char* closeStringLiteral();
private:
    static std::stringstream ss;
};

/* lexer.cpp */
class LexerUtil {
public:
    static void increaseLineNumber();
    static int getLinerNumber();
private:
    static int lineNumber;
};

#endif