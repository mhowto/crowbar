%{
#include <stdio.h>
#include <string.h>
#include "CRB.h"
#include "crowbar.h"
#include "parser.tab.h"
#include "error.h"

int yywrap(void)
{
	return 1;
}

%}

%start COMMENT STRING_LITERAL_STATE

%%
<INITIAL>"function"     return FUNCTION;
<INITIAL>"if"           return IF;
<INITIAL>"else"         return ELSE;
<INITIAL>"elsif"        return ELSIF;
<INITIAL>"while"        return WHILE;
<INITIAL>"for"          return FOR;
<INITIAL>"return"       return RETURN_T;
<INITIAL>"break"        return BREAK;
<INITIAL>"continue"     return CONTINUE;
<INITIAL>"null"         return NULL_T;
<INITIAL>"true"         return TRUE_T;
<INITIAL>"false"        return FALSE_T;
<INITIAL>"global"       return GLOBAL_T;
<INITIAL>"("            return LP;
<INITIAL>")"            return RP;
<INITIAL>"{"            return LC;
<INITIAL>"}"            return RC;
<INITIAL>";"            return SEMICOLON;
<INITIAL>","            return COMMA;
<INITIAL>"&&"           return LOGICAL_AND;
<INITIAL>"||"           return LOGICAL_OR;
<INITIAL>"="            return ASSIGN;
<INITIAL>"=="           return EQ;
<INITIAL>"!="           return NE;
<INITIAL>">"            return GT;
<INITIAL>">="           return GE;
<INITIAL>"<"            return LT;
<INITIAL>"<="           return LE;
<INITIAL>"+"            return ADD;
<INITIAL>"-"            return SUB;
<INITIAL>"*"            return MUL;
<INITIAL>"/"            return DIV;
<INITIAL>"%"            return MOD;

<INITIAL>[A-Za-z_][A-Za-z_0-9]* {
	yylval.identifier = dupYYText(yytext);
	return IDENTIFIER;
}

<INITIAL>([1-9][0-9]*)|"0" {
	Expression *expression = new Primitive(PrimitiveType::INT_LITERAL, dupYYText(yytext));
	yylval.expression = expression;
	return INT_LITERAL;
}

<INITIAL>[0-9]+\.[0-9]+ {
	Expression *expression = new Primitive(PrimitiveType::DOUBLE_LITERAL, dupYYText(yytext));
	yylval.expression = expression;
	return DOUBLE_LITERAL;
}

<INITIAL>\" {
	StringLiteral::createStringLiteral();
	BEGIN STRING_LITERAL_STATE;
}

<INITIAL>[ \t] ;
<INITIAL>\n {
	LexerUtil::increaseLineNumber();
}
<INITIAL># {
	BEGIN COMMENT;
}
<INITIAL>. {
	char buf[LINE_BUF_SIZE];

	if (isprint(yytext[0])) {
		buf[0] = yytext[0];
		buf[1] = '\0';
	} else {
		sprintf(buf, "0x%02x", (unsigned char) yytext[0]);
	}

	generateCompileError(CompileError::CHARACTER_INVALID_ERR,
					  MessageArgumentType::STRING_MESSAGE_ARGUMENT, "bad_char", buf,
					  MessageArgumentType::MESSAGE_ARGUMENT_END);
}

<COMMENT>\n     {
    LexerUtil::increaseLineNumber();
    BEGIN INITIAL;
}
<COMMENT>.      ;
<STRING_LITERAL_STATE>\"        {
    Expression *expression = new Primitive(PrimitiveType::STRING_LITERAL, StringLiteral::closeStringLiteral());
    yylval.expression = expression;
    BEGIN INITIAL;
    return STRING_LITERAL;
}
<STRING_LITERAL_STATE>\n        {
    //crb_add_string_literal('\n');
    //increment_line_number();
	StringLiteral::addToString('\n');
	LexerUtil::increaseLineNumber();
}
<STRING_LITERAL_STATE>\\\"      StringLiteral::addToString('"');
<STRING_LITERAL_STATE>\\n       StringLiteral::addToString('\n');
<STRING_LITERAL_STATE>\\t       StringLiteral::addToString('\t');
<STRING_LITERAL_STATE>\\\\      StringLiteral::addToString('\\');
<STRING_LITERAL_STATE>.         StringLiteral::addToString(yytext[0]);
%%