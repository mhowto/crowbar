
%%
definition_or_statement
	: function_definition
	| statement
	{
	}
	;

function_definition
	: FUNCTION IDENTIFIER LP parameter_list RP block
	{
	}
	| FUNCTION IDENTIFIER LP RP block
	{
	}
	;

paramerter_list
	: IDENTIFIER
	{
	}
	| parameter_list COMMA IDENTIFIER
	{
	}
	;

argument_list
	: expression
	{
	}
	| argument_list COMMA expression
	{
	}
	;

statement_list
	: statement
	{
	}
	| statement_list statement
	{
	}
	;

expression
	: logical_or_expression
	| IDENTIFIER ASSIGN expression
	{
	}
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression LOGICAL_OR logical_and_expression
	{
	}
	;

logical_and_expression
	: equality_expression
	| logical_and_expression LOGICAL_AND equality_expression
	{
	}
	;

equality_expression
	: relational_expression
	| equality_expression EQ relational_expression
	{
	}
	| equality_expression NE releational_expression
	{
	}
	;

relational_expression
	: additive_expression
	| relational_expression GT additive_expression
	{
	}
	| relational_expression GE additive_expression
	{
	}
	| relational_expression LT additive_expression
	{
	}
	| relational_expression LE additive_expression
	{
	}
	;

additive_expression
	: multiplicative_expression
	| additive_expression ADD multiplicative_expression
	{
	}
	| additive_expression SUB multiplicative_expression
	{
	}
	;

multiplicative_expression
	: unary_expression
	| multiplicative_expression MUL unary_expression
	{
	}
	| multiplicative_expression DIV unary_expression
	{
	}
	| multiplicative_expression MOD unary_expression
	{
	}
	;

unary_expression
	: primary_expression
	| SUB unary_expression
	{
	}
	;

primary_expression
	: IDENTIFIER LP argument_list RP
	{
	}
	| IDENTIFIER LP RP
	{
	}
	| LP expression RP
	{
	}
	| IDENTIFIER
	{
	}
	| INT_LITERAL
	| DOUBLE_LITERAL
	| STRING_LITERAL
	| TRUE_T
	{
	}
	| FALSE_T
	{
	}
	| NULL_T
	{
	}
	;

statement
	: expression SEMICOLON
	{
	}
	| global_statement
	| if_statement
	| while_statement
	| for_statement
	| retur_statement
	| break_statement
	| continue_statement
	;

global_statement
	: GLOBAL_T identifier_list SEMICOLON
	{
	};

identifier_list
	: IDENTIFIER
	{
	}
	| identifier_list COMMA IDENTIFIER
	{
	}
	;

if_statement
	:





%%