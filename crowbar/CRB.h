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
    NativePointer,
    BoolValue
};

enum class StatementResultType {
    NormalStatementResult = 1,
    ReturnStatementResult,
    BreakStatementResult,
    ContinueStatementResult,
};

class CRBValue {
public:
    ValueType type;
    CRBValue(ValueType _type): type(_type) {}
    virtual ~CRBValue() = 0;
};

class StatementResult {
public:
    StatementResultType type;
    CRBValue* returnValue;

    StatementResult(StatementResultType _type) : type(_type) {}
    StatementResult(StatementResultType _type, CRBValue* value) : type(_type), returnValue(value) {}

    ~StatementResult() {
        delete returnValue;
    }
};

class CRBStringValue : public CRBValue {
public:
    std::string value;
    CRBStringValue(std::string _value): CRBValue(ValueType::StringValue), value(_value) {}
};

class CRBIntValue : public CRBValue {
public:
    int value;
    CRBIntValue(int _value): CRBValue(ValueType::IntValue), value(_value) {}
};

class CRBDoubleValue : public CRBValue {
public:
    double value;
    CRBDoubleValue(double _value): CRBValue(ValueType::DoubleValue), value(_value) {}
};

class CRBNativePointer :public CRBValue {
public:
    void *pointer;
    std::string pointerType;
    CRBNativePointer(std::string _pointerType, void* _pointer): 
        CRBValue(ValueType::NativePointer), pointerType(_pointerType), pointer(_pointer) {}
};

class CRBBoolValue : public CRBValue {
public:
    bool value;

    CRBBoolValue(bool _value) : CRBValue(ValueType::BoolValue), value(_value) {}
};


#endif