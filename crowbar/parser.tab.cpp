/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"

#include "crowbar.h"
#include "interpreter.h"
#include "CRB.h"

extern int yylex();
void yyerror(const char *s) { printf("ERROR: %s\n", s); }

/* Line 371 of yacc.c  */
#line 77 "parser.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_LITERAL = 258,
     DOUBLE_LITERAL = 259,
     STRING_LITERAL = 260,
     IDENTIFIER = 261,
     FUNCTION = 262,
     IF = 263,
     ELSE = 264,
     ELSIF = 265,
     WHILE = 266,
     FOR = 267,
     RETURN_T = 268,
     BREAK = 269,
     CONTINUE = 270,
     NULL_T = 271,
     LP = 272,
     RP = 273,
     LC = 274,
     RC = 275,
     SEMICOLON = 276,
     COMMA = 277,
     ASSIGN = 278,
     LOGICAL_AND = 279,
     LOGICAL_OR = 280,
     EQ = 281,
     NE = 282,
     GT = 283,
     GE = 284,
     LT = 285,
     LE = 286,
     ADD = 287,
     SUB = 288,
     MUL = 289,
     DIV = 290,
     MOD = 291,
     TRUE_T = 292,
     FALSE_T = 293,
     GLOBAL_T = 294
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 10 "parser.y"

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


/* Line 387 of yacc.c  */
#line 176 "parser.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 204 "parser.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  53
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   230

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    19,    25,    27,
      31,    33,    37,    39,    42,    44,    48,    50,    54,    56,
      60,    62,    66,    70,    72,    76,    80,    84,    88,    90,
      94,    98,   100,   104,   108,   112,   114,   117,   122,   126,
     130,   132,   134,   136,   138,   140,   142,   144,   147,   149,
     151,   153,   155,   157,   159,   161,   165,   167,   171,   177,
     185,   192,   201,   203,   206,   212,   218,   228,   229,   231,
     235,   238,   241,   245
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    41,    42,    -1,    43,    -1,
      56,    -1,     7,     6,    17,    44,    18,    68,    -1,     7,
       6,    17,    18,    68,    -1,     6,    -1,    44,    22,     6,
      -1,    47,    -1,    45,    22,    47,    -1,    56,    -1,    46,
      56,    -1,    48,    -1,     6,    23,    47,    -1,    49,    -1,
      48,    25,    49,    -1,    50,    -1,    49,    24,    50,    -1,
      51,    -1,    50,    26,    51,    -1,    50,    27,    51,    -1,
      52,    -1,    51,    28,    52,    -1,    51,    29,    52,    -1,
      51,    30,    52,    -1,    51,    31,    52,    -1,    53,    -1,
      52,    32,    53,    -1,    52,    33,    53,    -1,    54,    -1,
      53,    34,    54,    -1,    53,    35,    54,    -1,    53,    36,
      54,    -1,    55,    -1,    33,    54,    -1,     6,    17,    45,
      18,    -1,     6,    17,    18,    -1,    17,    47,    18,    -1,
       6,    -1,     3,    -1,     4,    -1,     5,    -1,    37,    -1,
      38,    -1,    16,    -1,    47,    21,    -1,    57,    -1,    59,
      -1,    62,    -1,    63,    -1,    65,    -1,    66,    -1,    67,
      -1,    39,    58,    21,    -1,     6,    -1,    58,    22,     6,
      -1,     8,    17,    47,    18,    68,    -1,     8,    17,    47,
      18,    68,     9,    68,    -1,     8,    17,    47,    18,    68,
      60,    -1,     8,    17,    47,    18,    68,    60,     9,    68,
      -1,    61,    -1,    60,    61,    -1,    10,    17,    47,    18,
      68,    -1,    11,    17,    47,    18,    68,    -1,    12,    17,
      64,    21,    64,    21,    64,    18,    68,    -1,    -1,    47,
      -1,    13,    64,    21,    -1,    14,    21,    -1,    15,    21,
      -1,    19,    46,    20,    -1,    19,    20,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    60,    69,    70,    80,    84,    91,    96,
     104,   109,   117,   122,   130,   131,   138,   139,   146,   147,
     154,   155,   159,   166,   167,   171,   175,   179,   186,   187,
     191,   198,   199,   203,   207,   214,   215,   222,   230,   234,
     238,   242,   243,   244,   245,   249,   253,   260,   264,   265,
     266,   267,   268,   269,   270,   274,   280,   285,   293,   297,
     301,   305,   312,   316,   323,   330,   337,   345,   348,   352,
     359,   366,   373,   377
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_LITERAL", "DOUBLE_LITERAL",
  "STRING_LITERAL", "IDENTIFIER", "FUNCTION", "IF", "ELSE", "ELSIF",
  "WHILE", "FOR", "RETURN_T", "BREAK", "CONTINUE", "NULL_T", "LP", "RP",
  "LC", "RC", "SEMICOLON", "COMMA", "ASSIGN", "LOGICAL_AND", "LOGICAL_OR",
  "EQ", "NE", "GT", "GE", "LT", "LE", "ADD", "SUB", "MUL", "DIV", "MOD",
  "TRUE_T", "FALSE_T", "GLOBAL_T", "$accept", "translation_unit",
  "definition_or_statement", "function_definition", "parameter_list",
  "argument_list", "statement_list", "expression", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "primary_expression", "statement", "global_statement", "identifier_list",
  "if_statement", "elsif_list", "elsif", "while_statement",
  "for_statement", "expression_opt", "return_statement", "break_statement",
  "continue_statement", "block", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    43,    43,    44,    44,
      45,    45,    46,    46,    47,    47,    48,    48,    49,    49,
      50,    50,    50,    51,    51,    51,    51,    51,    52,    52,
      52,    53,    53,    53,    53,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    58,    58,    59,    59,
      59,    59,    60,    60,    61,    62,    63,    64,    64,    65,
      66,    67,    68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     6,     5,     1,     3,
       1,     3,     1,     2,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     4,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     5,     7,
       6,     8,     1,     2,     5,     5,     9,     0,     1,     3,
       2,     2,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    41,    42,    43,    40,     0,     0,     0,     0,    67,
       0,     0,    46,     0,     0,    44,    45,     0,     0,     2,
       4,     0,    14,    16,    18,    20,    23,    28,    31,    35,
       5,    48,    49,    50,    51,    52,    53,    54,     0,     0,
       0,     0,     0,    67,    68,     0,    70,    71,     0,    40,
      36,    56,     0,     1,     3,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,    10,    15,     0,     0,     0,     0,    69,    39,    55,
       0,    17,    19,    21,    22,    24,    25,    26,    27,    29,
      30,    32,    33,    34,    37,     0,     8,     0,     0,     0,
       0,    67,    57,    11,     0,     7,     0,     0,    58,    65,
       0,    73,     0,    12,     6,     9,     0,     0,    60,    62,
      67,    72,    13,    59,     0,     0,    63,     0,     0,    61,
       0,     0,    66,    64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    18,    19,    20,    98,    70,   112,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    52,    32,
     118,   119,    33,    34,    45,    35,    36,    37,   105
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -100
static const yytype_int16 yypact[] =
{
      57,  -100,  -100,  -100,     8,    20,    60,    68,    72,   174,
      16,    30,  -100,   174,   192,  -100,  -100,    85,     3,  -100,
    -100,    80,    77,    69,    31,    15,    34,    14,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,   168,   174,
      86,   174,   174,   174,  -100,    83,  -100,  -100,    87,    89,
    -100,  -100,    54,  -100,  -100,  -100,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,  -100,
       5,  -100,  -100,     6,    90,    91,    92,  -100,  -100,  -100,
     101,    69,    31,    15,    15,    34,    34,    34,    34,    14,
      14,  -100,  -100,  -100,  -100,   174,  -100,    93,    17,    93,
      93,   174,  -100,  -100,   113,  -100,    93,   104,    74,  -100,
      99,  -100,   150,  -100,  -100,  -100,    93,    97,    78,  -100,
     174,  -100,  -100,  -100,   174,    93,  -100,   105,   114,  -100,
      93,    93,  -100,  -100
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -100,  -100,   116,  -100,  -100,  -100,  -100,    -9,  -100,    66,
      79,    39,    19,    35,   -12,  -100,   -99,  -100,  -100,  -100,
    -100,    13,  -100,  -100,   -42,  -100,  -100,  -100,   -78
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      44,    76,    50,    53,    48,   113,     1,     2,     3,     4,
       5,     6,    96,   122,     7,     8,     9,    10,    11,    12,
      13,   108,   109,    94,    97,    38,    40,    95,   114,    71,
      72,    39,    74,    75,    44,   106,    14,    46,   123,   107,
      15,    16,    17,    60,    61,    62,    63,   129,    66,    67,
      68,    47,   132,   133,    91,    92,    93,    58,    59,   110,
       1,     2,     3,     4,     5,     6,    64,    65,     7,     8,
       9,    10,    11,    12,    13,    79,    80,    41,   127,    85,
      86,    87,    88,   116,   117,    42,   103,   125,   117,    43,
      14,    51,    44,    57,    15,    16,    17,    83,    84,    89,
      90,    55,    56,    73,    77,    78,    38,   102,    99,   100,
     115,    44,   104,   101,   124,   128,     1,     2,     3,     4,
     120,     6,    81,   130,     7,     8,     9,    10,    11,    12,
      13,   126,   131,   111,    54,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,     0,
      15,    16,    17,     1,     2,     3,     4,     0,     6,     0,
       0,     7,     8,     9,    10,    11,    12,    13,     0,     0,
     121,     1,     2,     3,     4,     0,     0,     1,     2,     3,
       4,     0,     0,    14,    12,    13,    69,    15,    16,    17,
      12,    13,     0,     0,     0,     1,     2,     3,    49,     0,
       0,    14,     0,     0,     0,    15,    16,    14,    12,    13,
       0,    15,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,     0,     0,     0,    15,
      16
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-100)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       9,    43,    14,     0,    13,   104,     3,     4,     5,     6,
       7,     8,     6,   112,    11,    12,    13,    14,    15,    16,
      17,    99,   100,    18,    18,    17,     6,    22,   106,    38,
      39,    23,    41,    42,    43,    18,    33,    21,   116,    22,
      37,    38,    39,    28,    29,    30,    31,   125,    34,    35,
      36,    21,   130,   131,    66,    67,    68,    26,    27,   101,
       3,     4,     5,     6,     7,     8,    32,    33,    11,    12,
      13,    14,    15,    16,    17,    21,    22,    17,   120,    60,
      61,    62,    63,     9,    10,    17,    95,     9,    10,    17,
      33,     6,   101,    24,    37,    38,    39,    58,    59,    64,
      65,    21,    25,    17,    21,    18,    17,     6,    18,    18,
       6,   120,    19,    21,    17,   124,     3,     4,     5,     6,
      21,     8,    56,    18,    11,    12,    13,    14,    15,    16,
      17,   118,    18,    20,    18,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      37,    38,    39,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      20,     3,     4,     5,     6,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,    33,    16,    17,    18,    37,    38,    39,
      16,    17,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
      -1,    33,    -1,    -1,    -1,    37,    38,    33,    16,    17,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    37,
      38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    11,    12,    13,
      14,    15,    16,    17,    33,    37,    38,    39,    41,    42,
      43,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    59,    62,    63,    65,    66,    67,    17,    23,
       6,    17,    17,    17,    47,    64,    21,    21,    47,     6,
      54,     6,    58,     0,    42,    21,    25,    24,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    18,
      45,    47,    47,    17,    47,    47,    64,    21,    18,    21,
      22,    49,    50,    51,    51,    52,    52,    52,    52,    53,
      53,    54,    54,    54,    18,    22,     6,    18,    44,    18,
      18,    21,     6,    47,    19,    68,    18,    22,    68,    68,
      64,    20,    46,    56,    68,     6,     9,    10,    60,    61,
      21,    20,    56,    68,    17,     9,    61,    64,    47,    68,
      18,    18,    68,    68
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 55 "parser.y"
    {
		(yyval.translation_unit) = new TranslationUnit();
		(yyval.translation_unit)->push((yyvsp[(1) - (1)].node));
		interpreter = Interpreter::createInterpreter((yyval.translation_unit));
	}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 61 "parser.y"
    {
		(yyval.translation_unit) = (yyvsp[(1) - (2)].translation_unit);
		(yyval.translation_unit)->push((yyvsp[(2) - (2)].node));
		interpreter = Interpreter::createInterpreter((yyval.translation_unit));
	}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 81 "parser.y"
    {
		(yyval.function) = new Function((yyvsp[(2) - (6)].identifier), *(yyvsp[(4) - (6)].parameter_list), (yyvsp[(6) - (6)].block));
	}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 85 "parser.y"
    {
		(yyval.function) = new Function((yyvsp[(2) - (5)].identifier), (yyvsp[(5) - (5)].block));
	}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 92 "parser.y"
    {
		(yyval.parameter_list) = new ParameterList();
		(yyval.parameter_list)->push_back((yyvsp[(1) - (1)].identifier));
	}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 97 "parser.y"
    {
		(yyvsp[(1) - (3)].parameter_list)->push_back((yyvsp[(3) - (3)].identifier));
		(yyval.parameter_list) = (yyvsp[(1) - (3)].parameter_list);
	}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 105 "parser.y"
    {
		(yyval.argument_list) = new ArgumentList();
		(yyval.argument_list)->push_back((yyvsp[(1) - (1)].expression));
	}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 110 "parser.y"
    {
		(yyvsp[(1) - (3)].argument_list)->push_back((yyvsp[(3) - (3)].expression));
		(yyval.argument_list) = (yyvsp[(1) - (3)].argument_list);
	}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 118 "parser.y"
    {
		(yyval.statement_list) = new StatementList();
		(yyval.statement_list)->push_back((yyvsp[(1) - (1)].statement));
	}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 123 "parser.y"
    {
		(yyvsp[(1) - (2)].statement_list)->push_back((yyvsp[(2) - (2)].statement));
		(yyval.statement_list) = (yyvsp[(1) - (2)].statement_list);
	}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 132 "parser.y"
    {
		(yyval.expression) = new AssignExpression((yyvsp[(1) - (3)].identifier), (yyvsp[(3) - (3)].expression));
	}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 140 "parser.y"
    {
		(yyval.expression) = new BinaryExpression(BinaryOperator::OR, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 148 "parser.y"
    {
		(yyval.expression) = new BinaryExpression(BinaryOperator::AND, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 156 "parser.y"
    {
		(yyval.expression) = new BinaryExpression(BinaryOperator::EQ, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 160 "parser.y"
    {
		(yyval.expression) = new BinaryExpression(BinaryOperator::NE, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 168 "parser.y"
    {
		(yyval.expression) = new BinaryExpression(BinaryOperator::GT, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 172 "parser.y"
    {
		(yyval.expression) = new BinaryExpression(BinaryOperator::GE, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 176 "parser.y"
    {
		(yyval.expression) = new BinaryExpression(BinaryOperator::LT, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 180 "parser.y"
    {
		(yyval.expression) = new BinaryExpression(BinaryOperator::LE, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 188 "parser.y"
    {
		(yyval.expression) = new BinaryExpression(BinaryOperator::ADD, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 192 "parser.y"
    {
		(yyval.expression) = new BinaryExpression(BinaryOperator::SUB, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 200 "parser.y"
    {
		(yyval.expression) = new BinaryExpression(BinaryOperator::MUL, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 204 "parser.y"
    {
		(yyval.expression) = new BinaryExpression(BinaryOperator::DIV, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 208 "parser.y"
    {
		(yyval.expression) = new BinaryExpression(BinaryOperator::MOD, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 216 "parser.y"
    {
		(yyval.expression) = new UnaryExpression(UnaryOperator::NEGATIVE, (yyvsp[(2) - (2)].expression));
	}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 223 "parser.y"
    {
	   //std::cout << $1 << std::endl;
	   //std::cout << $3 << std::endl;
	   printf((yyvsp[(1) - (4)].identifier));
	   //printf($3);
		(yyval.expression) = new FunctionCall((yyvsp[(1) - (4)].identifier), *(yyvsp[(3) - (4)].argument_list));
	}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 231 "parser.y"
    {
		(yyval.expression) = new FunctionCall((yyvsp[(1) - (3)].identifier));
	}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 235 "parser.y"
    {
		(yyval.expression) = (yyvsp[(2) - (3)].expression);
	}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 239 "parser.y"
    {
		(yyval.expression) = new IdentifierExpression((yyvsp[(1) - (1)].identifier));
	}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 246 "parser.y"
    {
		(yyval.expression) = new Primitive(PrimitiveType::TRUE_T);
	}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 250 "parser.y"
    {
		(yyval.expression) = new Primitive(PrimitiveType::FALSE_T);
	}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 254 "parser.y"
    {
		(yyval.expression) = new Primitive(PrimitiveType::NULL_T);
	}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 261 "parser.y"
    {
		(yyval.statement) = new ExpressionStatement((yyvsp[(1) - (2)].expression));
	}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 275 "parser.y"
    {
		(yyval.statement) = new GlobalStatement(*(yyvsp[(2) - (3)].identifier_list));
	}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 281 "parser.y"
    {
		(yyval.identifier_list) = new IdentifierList();
		(yyval.identifier_list)->push_back((yyvsp[(1) - (1)].identifier));
	}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 286 "parser.y"
    {
		(yyvsp[(1) - (3)].identifier_list)->push_back((yyvsp[(3) - (3)].identifier));
		(yyval.identifier_list) = (yyvsp[(1) - (3)].identifier_list);
	}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 294 "parser.y"
    {
		(yyval.statement) = new IfStatement((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].block));
	}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 298 "parser.y"
    {
		(yyval.statement) = new IfStatement((yyvsp[(3) - (7)].expression), (yyvsp[(5) - (7)].block), (yyvsp[(7) - (7)].block));
	}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 302 "parser.y"
    {
		(yyval.statement) = new IfElseIfStatement((yyvsp[(3) - (6)].expression), (yyvsp[(5) - (6)].block), (yyvsp[(6) - (6)].elsif_list));
	}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 306 "parser.y"
    {
		(yyval.statement) = new IfElseIfStatement((yyvsp[(3) - (8)].expression), (yyvsp[(5) - (8)].block), (yyvsp[(6) - (8)].elsif_list), (yyvsp[(8) - (8)].block));
	}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 313 "parser.y"
    {
		(yyval.elsif_list) = new ElsIfList((yyvsp[(1) - (1)].elsif), 0);
	}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 317 "parser.y"
    {
		(yyval.elsif_list) = new ElsIfList((yyvsp[(2) - (2)].elsif), (yyvsp[(1) - (2)].elsif_list));
	}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 324 "parser.y"
    {
		(yyval.elsif) = new ElsIf((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].block));
	}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 331 "parser.y"
    {
		(yyval.statement) = new WhileStatement((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].block));
	}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 338 "parser.y"
    {
		(yyval.statement) = new ForStatement((yyvsp[(3) - (9)].expression), (yyvsp[(5) - (9)].expression), (yyvsp[(7) - (9)].expression), (yyvsp[(9) - (9)].block));
	}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 345 "parser.y"
    {
		(yyval.expression) = nullptr;
	}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 353 "parser.y"
    {
		(yyval.statement) = new ReturnStatement((yyvsp[(2) - (3)].expression));
	}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 360 "parser.y"
    {
		(yyval.statement) = new BreakStatement();
	}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 367 "parser.y"
    {
		(yyval.statement) = new ContinueStatement();
	}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 374 "parser.y"
    {
		(yyval.block) = new Block(*(yyvsp[(2) - (3)].statement_list));
	}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 378 "parser.y"
    {
		(yyval.block) = new Block();
	}
    break;


/* Line 1792 of yacc.c  */
#line 1963 "parser.tab.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 382 "parser.y"
