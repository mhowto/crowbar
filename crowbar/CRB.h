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

enum class ValueType {
    StringValue = 1,
    IntValue,
    DoubleValue,
    NativePointer
};

class CRBValue {
public:
    ValueType _type;
    CRBValue(ValueType type): _type(type) {}
    virtual ~CRBValue() = 0;
};

class CRBStringValue : public CRBValue {
public:
    std::string _value;
    CRBStringValue(std::string value): CRBValue(ValueType::StringValue), _value(value) {}
};

class CRBIntValue : public CRBValue {
public:
    int _value;
    CRBIntValue(int value): CRBValue(ValueType::IntValue), _value(value) {}
};

class CRBDoubleValue : public CRBValue {
public:
    double _value;
    CRBDoubleValue(double value): CRBValue(ValueType::DoubleValue), _value(value) {}
};

class CRBNativePointer :public CRBValue {
public:
    void *_pointer;
    std::string _pointerType;
    CRBNativePointer(std::string pointerType, void* pointer): 
        CRBValue(ValueType::NativePointer), _pointerType(pointerType), _pointer(pointer) {}
};


#endif