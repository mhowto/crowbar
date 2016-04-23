%{
#include "crowbar.h"
#include "interpreter.h"
#include "CRB.h"

extern int yylex();
void yyerror(const char *s) { printf("ERROR: %s\n", s); }
%}

%union {
	TranslationUnit* translation_unit;
	Node* node;
	char* identifier;
	ParameterList* parameter_list;
	ArgumentList* argument_list;
	Expression* expression;
	Statement *statement;
	StatementList* statement_list;
	Block* block;
	ElsIf* elsif;
	ElsIfList* elsif_list;
	IdentifierList* identifier_list;
	Function* function;
}
%token <expression> INT_LITERAL
%token <expression> DOUBLE_LITERAL
%token <expression> STRING_LITERAL
%token <identifier> IDENTIFIER
%token FUNCTION IF ELSE ELSIF WHILE FOR RETURN_T BREAK CONTINUE NULL_T
	LP RP LC RC SEMICOLON COMMA ASSIGN LOGICAL_AND LOGICAL_OR
	EQ NE GT GE LT LE ADD SUB MUL DIV MOD TRUE_T FALSE_T GLOBAL_T

%type <parameter_list> parameter_list
%type <argument_list> argument_list
%type <expression> expression expression_opt
	logical_and_expression logical_or_expression
    equality_expression relational_expression
    additive_expression multiplicative_expression
    unary_expression primary_expression
%type <statement> statement global_statement
    if_statement while_statement for_statement
    return_statement break_statement continue_statement
%type <statement_list> statement_list
%type <block> block
%type <elsif> elsif
%type <elsif_list> elsif_list
%type <identifier_list> identifier_list
%type <translation_unit> translation_unit;
%type <node> definition_or_statement;
%type <function> function_definition;

%%
translation_unit
	: definition_or_statement
	{
		$$ = new TranslationUnit();
		$$->push($1);
		interpreter = Interpreter::createInterpreter($$);
	}
	| translation_unit definition_or_statement
	{
		$$ = $1;
		$$->push($2);
		interpreter = Interpreter::createInterpreter($$);
	}
	;

definition_or_statement
	: function_definition
	| statement
	//{
	//	CRB_Interpreter *inter = crb_get_current_interpreter();

//        inter->statement_list
 //           = crb_chain_statement_list(inter->statement_list, $1);
//	}
	;

function_definition
	: FUNCTION IDENTIFIER LP parameter_list RP block
	{
		$$ = new Function($2, *$4, $6);
	}
	| FUNCTION IDENTIFIER LP RP block
	{
		$$ = new Function($2, $5);
	}
	;

parameter_list
	: IDENTIFIER
	{
		$$ = new ParameterList();
		$$->push_back($1);
	}
	| parameter_list COMMA IDENTIFIER
	{
		$1->push_back($3);
		$$ = $1;
	}
	;

argument_list
	: expression
	{
		$$ = new ArgumentList();
		$$->push_back($1);
	}
	| argument_list COMMA expression
	{
		$1->push_back($3);
		$$ = $1;
	}
	;

statement_list
	: statement
	{
		$$ = new StatementList();
		$$->push_back($1);
	}
	| statement_list statement
	{
		$1->push_back($2);
		$$ = $1;
	}
	;

expression
	: logical_or_expression
	| IDENTIFIER ASSIGN expression
	{
		$$ = new AssignExpression($1, $3);
	}
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression LOGICAL_OR logical_and_expression
	{
		$$ = new BinaryExpression(BinaryOperator::OR, $1, $3);
	}
	;

logical_and_expression
	: equality_expression
	| logical_and_expression LOGICAL_AND equality_expression
	{
		$$ = new BinaryExpression(BinaryOperator::AND, $1, $3);
	}
	;

equality_expression
	: relational_expression
	| equality_expression EQ relational_expression
	{
		$$ = new BinaryExpression(BinaryOperator::EQ, $1, $3);
	}
	| equality_expression NE relational_expression
	{
		$$ = new BinaryExpression(BinaryOperator::NE, $1, $3);
	}
	;

relational_expression
	: additive_expression
	| relational_expression GT additive_expression
	{
		$$ = new BinaryExpression(BinaryOperator::GT, $1, $3);
	}
	| relational_expression GE additive_expression
	{
		$$ = new BinaryExpression(BinaryOperator::GE, $1, $3);
	}
	| relational_expression LT additive_expression
	{
		$$ = new BinaryExpression(BinaryOperator::LT, $1, $3);
	}
	| relational_expression LE additive_expression
	{
		$$ = new BinaryExpression(BinaryOperator::LE, $1, $3);
	}
	;

additive_expression
	: multiplicative_expression
	| additive_expression ADD multiplicative_expression
	{
		$$ = new BinaryExpression(BinaryOperator::ADD, $1, $3);
	}
	| additive_expression SUB multiplicative_expression
	{
		$$ = new BinaryExpression(BinaryOperator::SUB, $1, $3);
	}
	;

multiplicative_expression
	: unary_expression
	| multiplicative_expression MUL unary_expression
	{
		$$ = new BinaryExpression(BinaryOperator::MUL, $1, $3);
	}
	| multiplicative_expression DIV unary_expression
	{
		$$ = new BinaryExpression(BinaryOperator::DIV, $1, $3);
	}
	| multiplicative_expression MOD unary_expression
	{
		$$ = new BinaryExpression(BinaryOperator::MOD, $1, $3);
	}
	;

unary_expression
	: primary_expression
	| SUB unary_expression
	{
		$$ = new UnaryExpression(UnaryOperator::NEGATIVE, $2);
	}
	;

primary_expression
	: IDENTIFIER LP argument_list RP
	{
	   //std::cout << $1 << std::endl;
	   //std::cout << $3 << std::endl;
	   printf($1);
	   //printf($3);
		$$ = new FunctionCall($1, *$3);
	}
	| IDENTIFIER LP RP
	{
		$$ = new FunctionCall($1);
	}
	| LP expression RP
	{
		$$ = $2;
	}
	| IDENTIFIER
	{
		$$ = new IdentifierExpression($1);
	}
	| INT_LITERAL
	| DOUBLE_LITERAL
	| STRING_LITERAL
	| TRUE_T
	{
		$$ = new Primitive(PrimitiveType::TRUE_T);
	}
	| FALSE_T
	{
		$$ = new Primitive(PrimitiveType::FALSE_T);
	}
	| NULL_T
	{
		$$ = new Primitive(PrimitiveType::NULL_T);
	}
	;

statement
	: expression SEMICOLON
	{
		$$ = new ExpressionStatement($1);
	}
	| global_statement
	| if_statement
	| while_statement
	| for_statement
	| return_statement
	| break_statement
	| continue_statement
	;

global_statement
	: GLOBAL_T identifier_list SEMICOLON
	{
		$$ = new GlobalStatement(*$2);
	};

identifier_list
	: IDENTIFIER
	{
		$$ = new IdentifierList();
		$$->push_back($1);
	}
	| identifier_list COMMA IDENTIFIER
	{
		$1->push_back($3);
		$$ = $1;
	}
	;

if_statement
	: IF LP expression RP block
	{
		$$ = new IfStatement($3, $5);
	}
	| IF LP expression RP block ELSE block
	{
		$$ = new IfStatement($3, $5, $7);
	}
	| IF LP expression RP block elsif_list
	{
		$$ = new IfElseIfStatement($3, $5, $6);
	}
	| IF LP expression RP block elsif_list ELSE block
	{
		$$ = new IfElseIfStatement($3, $5, $6, $8);
	}
	;

elsif_list
	: elsif
	{
		$$ = new ElsIfList($1, 0);
	}
	| elsif_list elsif
	{
		$$ = new ElsIfList($2, $1);
	}
	;

elsif
	: ELSIF LP expression RP block
	{
		$$ = new ElsIf($3, $5);
	}
	;

while_statement
	: WHILE LP expression RP block
	{
		$$ = new WhileStatement($3, $5);
	}
	;

for_statement
	: FOR LP expression_opt SEMICOLON expression_opt SEMICOLON expression_opt RP block
	{
		$$ = new ForStatement($3, $5, $7, $9);
	}
	;

expression_opt
	: /*emptry*/
	{
		$$ = nullptr;
	};
	| expression
	;

return_statement
	: RETURN_T expression_opt SEMICOLON
	{
		$$ = new ReturnStatement($2);
	}
	;

break_statement
	: BREAK SEMICOLON
	{
		$$ = new BreakStatement();
	}
	;

continue_statement
	: CONTINUE SEMICOLON
	{
		$$ = new ContinueStatement();
	}
	;

block
	: LC statement_list RC
	{
		$$ = new Block(*$2);
	}
	| LC RC
	{
		$$ = new Block();
	}
	;
%%