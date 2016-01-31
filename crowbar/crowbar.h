#include <iostream>
#include <vector>

class Node {
public:
    virtual ~Node() {}
};

class Expression : public Node{
};

class Statement : public Node {
};

class BinaryExpression : public Expression {
};

class CompareExpression : public Expression {
};

class LogicExpression : public Expression {
};

class Function
