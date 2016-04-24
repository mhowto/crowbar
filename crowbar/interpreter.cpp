#include "interpreter.h"
#include "eval_visitor.h"
#include <algorithm>

Interpreter::Interpreter(Node* node) {
    this->_node = node;
    evalVisitor = new EvalVisitor();
}


Interpreter* Interpreter::createInterpreter(Node* node) {
    Interpreter* _interpreter = new Interpreter(node);
    return _interpreter;
}

void Interpreter::interpret() {
    TranslationUnit* translationUnit = dynamic_cast<TranslationUnit*>(this->_node);
    if (!translationUnit) {
        return;
    }

    std::vector<Node*> units = translationUnit->getUnits();
    std::for_each(
        units.begin(), 
        units.end(), 
        [this](Node* node) {
            node->accept(*(this->evalVisitor));
            CRBValue* value = this->evalVisitor->getResult();
            if (value) {
                std::cout << value->toString();
            }
        }
    );
}
