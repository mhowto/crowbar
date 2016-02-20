#include <iostream>
#include "CRB.h"

Interpreter* interpreter = nullptr;
int main(int argc, char **argv)
{
    std::FILE* fp = std::fopen("test.crb", "r");
    if (!fp) {
        std::cout << "File opening failed";
        return EXIT_FAILURE;
    }
    parseFile(fp);
    std::cout << "main cpp";
    std::cin.get();
}