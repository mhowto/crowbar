#include <iostream>
#include "CRB.h"

Interpreter* interpreter = nullptr; // 全局变量定义
int main(int argc, char **argv)
{
    std::FILE* fp = std::fopen("test.crb", "r");
    if (!fp) {
        std::cout << "File opening failed";
        return EXIT_FAILURE;
    }
    parseFile(fp);
    if (interpreter) {
        interpreter->interpret();
    }
    std::cout << "main cpp";
    std::cin.get();
}