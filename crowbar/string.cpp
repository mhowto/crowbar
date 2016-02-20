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

char* StringLiteral::closeStringLiteral()
{
    std::string temp(ss.str());
    ss.str(std::string());
    ss.clear();
    char* str = new char[temp.length() + 1];
    std::strcpy(str, temp.c_str());
    return str;
}