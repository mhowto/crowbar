#include "crowbar.h"

std::stringstream StringLiteral::ss;

const char* StringLiteral::getStringLiteral()
{
    return ss.str().c_str();
}

void StringLiteral::addToString(char ch)
{
    ss << ch;
}

void StringLiteral::createStringLiteral()
{
    ss.str(std::string());
    ss.clear();
}

const char* StringLiteral::closeStringLiteral()
{
    const char* str = ss.str().c_str();
    ss.str(std::string());
    ss.clear();
    return str;
}