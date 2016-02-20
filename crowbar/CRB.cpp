#include "CRB.h"

//Interpreter* interpreter = nullptr;
void parseFile(FILE* fp) {
    extern int yyparse(void);
    extern FILE *yyin;

    yyin = fp;
    if (yyparse()) {
        fprintf(stderr, "Error ! Error ! Error !\n");
        exit(1);
    }
}

/*
std::unique_ptr<char[]> dupYYText(char* YYText) {
    auto dst = std::make_unique<char[]>(std::strlen(YYText) + 1);
    std::strcpy(dst.get(), YYText);
    return dst;
}
*/

char* dupYYText(char* YYText) {
    char* dst = new char[std::strlen(YYText) + 1];
    std::strcpy(dst, YYText);
    return dst;
}