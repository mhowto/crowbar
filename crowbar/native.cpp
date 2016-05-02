#include "CRB.h"

CRBValue* native_print(int argSize, std::vector<CRBValue*> args) {
    if (argSize != 1) {
        std::cout << "print requires 1 argument but " << argSize << "found" << std::endl;
        std::exit(1);
    }
    std::cout << args[0]->toString() << std::endl;
}