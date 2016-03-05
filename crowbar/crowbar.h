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

class Visitor;

class Node {
public:
    virtual ~Node() {}
    virtual void accept(Visitor&) = 0;
};

class Expression : public Node{};
class Statement : public Node {};

class Block;

class TranslationUnit :public Node{
public:
    void push(Node* definition_or_statement) {
        this->_definitions_or_statements.push_back(definition_or_statement);
    }

    virtual void accept(Visitor& visitor) override;

    std::vector<Node*> getUnits() {
        return _definitions_or_statements;
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

    std::string getName() {
        return _name;
    }

    std::vector<std::string> getParamerterList() {
        return _parameter_list;
    }

    Block* getBlock() {
        return _block;
    }

    virtual void accept(Visitor& visitor) override;
private:
    std::string _name;
    std::vector<std::string> _parameter_list;
    Block* _block;
};


class AssignExpression : public Expression {
public:
    AssignExpression(std::string identifier, Expression* expression)
        : _identifier(identifier), _expression(expression) {}

    virtual void accept(Visitor& visitor) override;

    std::string getIdentifier() {
        return  _identifier;
    }

    Expression* getExpression() {
        return _expression;
    }

private:
    std::string _identifier;
    Expression* _expression;
};

class BinaryExpression : public Expression {
public:
    BinaryExpression(BinaryOperator op, Expression* left, Expression* right)
        :_op(op), _left(left), _right(right) {}
    virtual void accept(Visitor& visitor) override;
private:
    BinaryOperator _op;
    Expression* _left;
    Expression* _right;
};

class UnaryExpression : public Expression {
public:
    UnaryExpression(UnaryOperator op, Expression* expr)
        :_op(op), _expr(expr) {}

    virtual void accept(Visitor& visitor) override;
private:
    UnaryOperator _op;
    Expression* _expr;
};

class PrimaryExpression : public Expression {
};

class FunctionCall : public PrimaryExpression {
public:
    FunctionCall(std::string name, std::vector<Expression*> arguments) 
        : _name(name), _arguments(arguments) {
        std::cout << "name:" << name << std::endl;
    }
    FunctionCall(char* name, std::vector<Expression*> arguments) 
        : _name(name), _arguments(arguments) {
        delete name;
    }
    FunctionCall(std::string name) : _name(name) {}
    virtual void accept(Visitor& visitor) override;

    std::string getName() {
        return _name;
    }

    std::vector<Expression*> getArguments() {
        return _arguments;
    }
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
    Primitive(PrimitiveType type, char* literal)
        : _type(type), _literal(literal) {
        delete literal;
    }
    Primitive(PrimitiveType type)
        : _type(type) {}
    virtual void accept(Visitor& visitor) override;
private:
    PrimitiveType _type;
    std::string _literal;
};

class IdentifierExpression : public PrimaryExpression {
public:
    IdentifierExpression(std::string identifier)
        : _identifier(identifier) {}
    virtual void accept(Visitor& visitor) override;
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
    virtual void accept(Visitor& visitor) override;
private:
    Expression* _expression;
};

class GlobalStatement : public Statement {
public:
    GlobalStatement(std::vector<std::string> identifiers)
        : _identifier_list(identifiers) {}
    virtual void accept(Visitor& visitor) override;
private:
    std::vector<std::string> _identifier_list;
};


class Block : public Statement {
public:
    Block() {}
    Block(StatementList list) : _list(list) {}
    virtual void accept(Visitor& visitor) override;

    StatementList getList() {
        return _list;
    }
        
private:
    StatementList _list;
};

class ElsIf : public Statement {
public:
    ElsIf(Expression* expression, Block* block)
        : _expression(expression), _block(block) {}
    virtual void accept(Visitor& visitor) override;

    Expression* _expression;
    Block* _block;
};

class ElsIfList : public Statement {
public:
    ElsIfList(ElsIf* els_if, ElsIfList* elsif_list) : _els_if(els_if), _elsif_list(elsif_list) {}
    virtual void accept(Visitor& visitor) override;

    ElsIf* _els_if;
    ElsIfList* _elsif_list;
};

class IfElseIfStatement : public Statement {
public:
    IfElseIfStatement(Expression *expression, Block* block, ElsIfList* els_if_list) {
        _expressions.push_back(expression);
        _blocks.push_back(block);

        while (els_if_list) {
            if (els_if_list->_els_if) {
                _expressions.push_back(els_if_list->_els_if->_expression);
                _blocks.push_back(els_if_list->_els_if->_block);
            }

            els_if_list = els_if_list->_elsif_list;
        }
    }

    IfElseIfStatement(Expression *expression, Block* block, ElsIfList* els_if_list, Block* else_block) {
        _expressions.push_back(expression);
        _blocks.push_back(block);

        while (els_if_list) {
            if (els_if_list->_els_if) {
                _expressions.push_back(els_if_list->_els_if->_expression);
                _blocks.push_back(els_if_list->_els_if->_block);
            }

            els_if_list = els_if_list->_elsif_list;
        }

        if (else_block) {
            _blocks.push_back(else_block);
        }
    }

    virtual void accept(Visitor& visitor) override;

    std::vector<Expression*> getExpressions() {
        return _expressions;
    }

    std::vector<Block*> getBlocks() {
        return _blocks;
    }

private:
    std::vector<Expression*> _expressions;
    //Expression* _expression;
    std::vector<Block*> _blocks;
    //Block* _block;
    //ElsIfList* _els_if_list;
    //Block* _else_block;
};

class IfStatement : public Statement {
public:
    IfStatement(Expression* _expression, Block* _block)
        : expression(_expression), block(_block) {}
    IfStatement(Expression* _expression, Block* _block, Block *else_block)
        : expression(_expression), block(_block), elseBlock(else_block) {}
    Expression* expression;
    Block* block;
    Block* elseBlock;

    virtual void accept(Visitor& visitor) override;
    /*
private:
    Expression* _expression;
    Block* _block;
    Block* _else_block;
    */
};

class WhileStatement : public Statement {
public:
    WhileStatement(Expression* _expression, Block* _block)
        : expression(_expression), block(_block) {}
    virtual void accept(Visitor& visitor) override;

    Expression* expression;
    Block* block;
    /*
private:
    Expression* _expression;
    Block* _block;
    */
};

class ForStatement : public Statement {
public:
    ForStatement(Expression *init_expression, Expression *cond_expression,
        Expression *action_expression, Block* _block)
        : initExpression(init_expression), condExpression(cond_expression),
          actionExpression(action_expression), block(_block) {}

    Expression *initExpression, *condExpression, *actionExpression;
    Block* block;

    virtual void accept(Visitor& visitor) override;

    /*
    Expression* getInitExpression() {
        return _init_expression;
    }

    Expression* getCondExpression() {
        return _cond_expression;
    }

    Expression* getActionExpression() {
        return _action_expression;
    }

    Expression* getBlock() {

    }

private:
    Expression *_init_expression, *_cond_expression, *_action_expression;
    Block* _block;
    */
};

class ReturnStatement : public Statement {
public:
    ReturnStatement(Expression *_expression)
        : expression(_expression) {}

    Expression* expression;
    virtual void accept(Visitor& visitor) override;
    /*
private:
    Expression *_expression;
    */
};

class BreakStatement : public Statement {
    virtual void accept(Visitor& visitor) override;
};

class ContinueStatement : public Statement {
    virtual void accept(Visitor& visitor) override;
};

/* string.cpp */
class StringLiteral {
public:
    static const char* getStringLiteral();
    static void addToString(char ch);
    static void createStringLiteral();
    static char* closeStringLiteral();
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