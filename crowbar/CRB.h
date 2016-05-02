#ifndef _CRB_H
#define _CRB_H

#include <cstdio>
#include "interpreter.h"
#include "crowbar.h"
#include <memory>
#include <string>

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
    virtual ~CRBValue() {};

    virtual bool toBool() = 0;
    virtual double toDouble() = 0;
    virtual std::string toString() = 0;
    virtual int toInt() = 0;
    virtual CRBValue* copyOnce() = 0;
};

class StatementResult {
public:
    StatementResultType type;
    CRBValue* returnValue;

    StatementResult(StatementResultType _type) : type(_type), returnValue(nullptr) {}
    StatementResult(StatementResultType _type, CRBValue* value) : type(_type), returnValue(value) {}

    ~StatementResult() {
        //delete returnValue;
    }
};

class CRBStringValue : public CRBValue {
public:
    std::string value;
    CRBStringValue(std::string _value): CRBValue(ValueType::StringValue), value(_value) {}
    ~CRBStringValue() {}

    bool toBool() override {
        return !value.empty();
    }

    double toDouble() override {
        return std::nan("0");
    }

    std::string toString() override {
        return value;
    }

    int toInt() override {
        return std::nan("0");
    }

    CRBValue* copyOnce() override {
        return new CRBStringValue(value);
    }
};

class CRBIntValue : public CRBValue {
public:
    int value;
    CRBIntValue(int _value): CRBValue(ValueType::IntValue), value(_value) {}
    CRBIntValue(std::string literal): CRBValue(ValueType::IntValue), value(std::stod(literal)) {}
    ~CRBIntValue() {}

    bool toBool() override {
        return value != 0;
    }

    double toDouble() override {
        return 0.0;
    }

    std::string toString() override {
        return std::to_string(value);
    }

    int toInt() override {
        return value;
    }

    CRBValue* copyOnce() override {
        return new CRBIntValue(value);
    }
};

template<class T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
almost_equal(T x, T y, int ulp)
{
    // the machine epsilon has to be scaled to the magnitude of the values used
    // and multiplied by the desired precision in ULPs (units in the last place)
    return std::abs(x - y) < std::numeric_limits<T>::epsilon() * std::abs(x + y) * ulp
        // unless the result is subnormal
        || std::abs(x - y) < std::numeric_limits<T>::min();
}

class CRBDoubleValue : public CRBValue {
public:
    double value;
    CRBDoubleValue(double _value): CRBValue(ValueType::DoubleValue), value(_value) {}
    CRBDoubleValue(std::string literal): CRBValue(ValueType::DoubleValue), value(std::stod(literal)) {}

    ~CRBDoubleValue() override {}

    bool toBool() override {
        return almost_equal(value, 0.0, 2);
    }

    double toDouble() override {
        return value;
    }

    std::string toString() override {
        return std::to_string(value);
    }

    int toInt() override {
        return (int) value;
    }

    CRBValue* copyOnce() override {
        return new CRBDoubleValue(value);
    }
};

class CRBNativePointer :public CRBValue {
public:
    void *pointer;
    std::string pointerType;
    CRBNativePointer(std::string _pointerType, void* _pointer): 
        CRBValue(ValueType::NativePointer), pointerType(_pointerType), pointer(_pointer) {}
    ~CRBNativePointer() {}

    bool toBool() override {
        return !pointer;
    }
 
    double toDouble() override {
        return std::nan("0");
    }

    std::string toString() override {
        return std::to_string((char*) pointer - (char*) 0);
    }

    int toInt() override {
        return (char*)pointer - (char*)0;
    }

    CRBValue* copyOnce() override {
        return new CRBNativePointer(pointerType, pointer);
    }
};

class CRBBoolValue : public CRBValue {
public:
    bool value;

    CRBBoolValue(bool _value) : CRBValue(ValueType::BoolValue), value(_value) {}
    ~CRBBoolValue() {}

    bool toBool() override {
        return value;
    }

    double toDouble() override {
        return (value ? 1.0 : 0.0);
    }

    std::string toString() override {
        return (value ? "true" : "false");
    }

    int toInt() override {
        return (value ? 1 : 0);
    }

    CRBValue* copyOnce() override {
        return new CRBBoolValue(value);
    }
};

/* native.cpp */
CRBValue* native_print(int argSize, std::vector<CRBValue*> args);
CRBValue* native_fopen(int argSize, std::vector<CRBValue*> args);
CRBValue* native_fputs(int argSize, std::vector<CRBValue*> args);

#endif