#include "crowbar.h"

int LexerUtil::lineNumber = 0;

void LexerUtil::increaseLineNumber()
{
    lineNumber++;
}

int LexerUtil::getLinerNumber()
{
    return lineNumber;
}