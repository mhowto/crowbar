#ifndef _CRB_INTERPRETER_H
#define _CRB_INTERPRETER_H

#include <cstdio>
#include "crowbar.h"

class Interpreter {
public:
    Interpreter(Node* node): _node(node) {}

    void interpret();
    static Interpreter* createInterpreter(Node* node);
private:
    int currentLineNumber;
    std::vector<Statement*> statementList;
    std::vector<Function*> functionList;

    Node* _node; // AST root
};

#endif