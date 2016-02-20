#include "interpreter.h"

Interpreter* Interpreter::createInterpreter(Node* node) {
    Interpreter* _interpreter = new Interpreter(node);
    return _interpreter;
}
