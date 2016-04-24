#ifndef _CRB_INTERPRETER_H
#define _CRB_INTERPRETER_H

#include <cstdio>
#include "crowbar.h"

class EvalVisitor;

class Interpreter {
public:
    Interpreter(Node* node);

    void interpret();
    static Interpreter* createInterpreter(Node* node);

    //Node* getNode();
private:
    int currentLineNumber;
    std::vector<Statement*> statementList;
    std::vector<Function*> functionList;

    Node* _node; // AST root
    EvalVisitor* evalVisitor;
};

#endif