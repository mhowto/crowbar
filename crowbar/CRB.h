#ifndef _CRB_H
#define _CRB_H

#include <cstdio>
#include "interpreter.h"
#include "crowbar.h"
#include <memory>

extern Interpreter* interpreter;
void parseFile(FILE*);

//std::unique_ptr<char[]> dupYYText(char* YYText);
char* dupYYText(char* YYText);

typedef struct CRB_Interpreter_tag CRB_Interpreter;
CRB_Interpreter *CRB_create_interpreter(void);
void CRB_compile(CRB_Interpreter *interpreter, FILE *fp);
void CRB_interpret(CRB_Interpreter *interpreter);
void CRB_dispose_interpreter(CRB_Interpreter *interpreter);

#endif