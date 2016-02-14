#include "error.h"
#include <iostream>

void generateCompileError(CompileError id, ...)
{
    std::cout << "Compile Error";
}

void generateRuntimeError(int line_number, RuntimeError id, ...)
{
    std::cout << "Runtime Error";
}