/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "spl.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "symbol.h"
#include "absyn.h"
#include "types.h"
#include "error.h"
extern FILE *yyin;
int yylex(void);
void yyerror(char *s);

A_pro root = NULL;

#line 81 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LP = 258,
    RP = 259,
    LB = 260,
    RB = 261,
    DOT = 262,
    COMMA = 263,
    COLON = 264,
    MUL = 265,
    DIV = 266,
    UNEQUAL = 267,
    NOT = 268,
    PLUS = 269,
    MINUS = 270,
    GE = 271,
    GT = 272,
    LE = 273,
    LT = 274,
    EQUAL = 275,
    ASSIGN = 276,
    MOD = 277,
    DOTDOT = 278,
    SEMI = 279,
    AND = 280,
    ARRAY = 281,
    BEGIN_TOKEN = 282,
    CASE = 283,
    CONST = 284,
    DO = 285,
    DOWNTO = 286,
    ELSE = 287,
    END = 288,
    FOR = 289,
    FUNCTION = 290,
    GOTO = 291,
    IF = 292,
    OF = 293,
    OR = 294,
    PROCEDURE = 295,
    PROGRAM = 296,
    RECORD = 297,
    REPEAT = 298,
    THEN = 299,
    TO = 300,
    TYPE = 301,
    UNTIL = 302,
    VAR = 303,
    WHILE = 304,
    READ = 305,
    SYS_TYPE = 306,
    INTEGER = 307,
    REAL = 308,
    CHAR = 309,
    STRING = 310,
    NAME = 311,
    SYS_CON = 312,
    SYS_FUNCT = 313,
    SYS_PROC = 314,
    IFX = 315
  };
#endif
/* Tokens.  */
#define LP 258
#define RP 259
#define LB 260
#define RB 261
#define DOT 262
#define COMMA 263
#define COLON 264
#define MUL 265
#define DIV 266
#define UNEQUAL 267
#define NOT 268
#define PLUS 269
#define MINUS 270
#define GE 271
#define GT 272
#define LE 273
#define LT 274
#define EQUAL 275
#define ASSIGN 276
#define MOD 277
#define DOTDOT 278
#define SEMI 279
#define AND 280
#define ARRAY 281
#define BEGIN_TOKEN 282
#define CASE 283
#define CONST 284
#define DO 285
#define DOWNTO 286
#define ELSE 287
#define END 288
#define FOR 289
#define FUNCTION 290
#define GOTO 291
#define IF 292
#define OF 293
#define OR 294
#define PROCEDURE 295
#define PROGRAM 296
#define RECORD 297
#define REPEAT 298
#define THEN 299
#define TO 300
#define TYPE 301
#define UNTIL 302
#define VAR 303
#define WHILE 304
#define READ 305
#define SYS_TYPE 306
#define INTEGER 307
#define REAL 308
#define CHAR 309
#define STRING 310
#define NAME 311
#define SYS_CON 312
#define SYS_FUNCT 313
#define SYS_PROC 314
#define IFX 315

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "spl.y" /* yacc.c:355  */

    
	Ty_kind ty_kind;
	
	A_pro a_pro;
	table_t s_symbol;
	A_routine a_routine;
	A_routine_head a_routine_head;
	A_stmtList a_stmtList;
	A_decList a_decList;
	A_dec a_dec;
	A_const a_const;
	A_type a_type;
	A_simple_type a_simple_type;
	A_array a_array;
	A_fieldList a_fieldList;
	A_nameList a_nameList;
	A_range a_range;
	A_field a_field;
	A_varDecList a_varDecList;
	A_routine_part_head a_routine_part_head;
	A_paraList a_paraList;
	A_paraField a_paraField;
	A_stmt a_stmt;
	A_exp a_exp;
	A_caseList a_caseList;
	A_case a_case;
	A_expList a_expList;
    int ival;
    double fval;
    char cval;
    char* sval;

    enum SYS_CON_ENUM{SYS_CON_FALSE, SYS_CON_TRUE} sys_con;
    enum SYS_FUNCT_ENUM{SYS_FUNCT_ABS, SYS_FUNCT_CHR, SYS_FUNCT_ODD, 
		SYS_FUNCT_ORD, SYS_FUNCT_PRED, SYS_FUNCT_SQR, SYS_FUNCT_SQRT, SYS_FUNCT_SUCC} sys_funct;
    enum SYS_PROC_ENUM{SYS_PROC_WRITE, SYS_PROC_WRITELN} sys_proc;

#line 280 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 311 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   336

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  258

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   112,   112,   116,   120,   124,   129,   133,   137,   140,
     144,   147,   151,   154,   157,   160,   163,   170,   173,   176,
     179,   183,   188,   191,   194,   198,   201,   204,   207,   210,
     214,   219,   224,   229,   232,   235,   240,   245,   248,   251,
     254,   259,   262,   266,   270,   271,   273,   274,   275,   276,
     279,   283,   287,   291,   295,   298,   302,   305,   309,   313,
     316,   320,   324,   330,   334,   336,   339,   343,   346,   349,
     352,   355,   358,   361,   364,   367,   370,   373,   376,   380,
     383,   386,   392,   398,   402,   405,   409,   412,   415,   418,
     421,   425,   428,   431,   435,   438,   442,   447,   450,   454,
     457,   460,   463,   466,   469,   472,   476,   479,   482,   485,
     489,   492,   495,   498,   501,   505,   508,   511,   523,   535,
     539,   542,   545,   548,   551,   555,   558
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LP", "RP", "LB", "RB", "DOT", "COMMA",
  "COLON", "MUL", "DIV", "UNEQUAL", "NOT", "PLUS", "MINUS", "GE", "GT",
  "LE", "LT", "EQUAL", "ASSIGN", "MOD", "DOTDOT", "SEMI", "AND", "ARRAY",
  "BEGIN_TOKEN", "CASE", "CONST", "DO", "DOWNTO", "ELSE", "END", "FOR",
  "FUNCTION", "GOTO", "IF", "OF", "OR", "PROCEDURE", "PROGRAM", "RECORD",
  "REPEAT", "THEN", "TO", "TYPE", "UNTIL", "VAR", "WHILE", "READ",
  "SYS_TYPE", "INTEGER", "REAL", "CHAR", "STRING", "NAME", "SYS_CON",
  "SYS_FUNCT", "SYS_PROC", "IFX", "$accept", "program_stmt",
  "program_head", "routine", "sub_routine", "routine_head", "label_part",
  "const_part", "const_expr_list", "const_value", "type_part",
  "type_decl_list", "type_definition", "type_decl", "simple_type_decl",
  "array_type_decl", "record_type_decl", "field_decl_list", "field_decl",
  "name_list", "var_part", "var_decl_list", "var_decl", "routine_part",
  "routine_decl_list", "function_decl", "function_head", "procedure_decl",
  "procedure_head", "parameters", "para_decl_list", "para_type_list",
  "var_para_list", "routine_body", "compound_stmt", "stmt_list", "stmt",
  "non_label_stmt", "assign_stmt", "proc_stmt", "if_stmt", "repeat_stmt",
  "while_stmt", "for_stmt", "direction", "case_stmt", "case_expr_list",
  "case_expr", "goto_stmt", "expression_list", "expression", "expr",
  "term", "factor", "args_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
};
# endif

#define YYPACT_NINF -174

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-174)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -23,     9,    75,  -174,    63,  -174,    89,    83,    88,  -174,
    -174,  -174,  -174,  -174,    66,    98,   136,   125,    91,    93,
     102,    71,  -174,   103,   109,    71,  -174,    71,   168,   166,
      56,   174,  -174,   165,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,  -174,   244,   171,   179,    93,  -174,   144,    27,
      71,    71,    71,  -174,  -174,  -174,  -174,    99,  -174,   198,
    -174,    73,    12,   261,  -174,   181,  -174,    22,   170,   232,
      71,   204,    71,    71,   149,    71,    71,  -174,   184,   244,
      79,  -174,  -174,    24,   144,  -174,   154,   155,  -174,  -174,
      27,   188,    27,   192,   164,  -174,  -174,    71,    71,   162,
      71,    71,    71,    71,    71,    71,    71,    85,    71,    71,
      71,    71,    71,    71,    71,    71,   187,    71,   187,   221,
    -174,   297,    11,   273,   206,   297,    50,   297,  -174,   209,
     144,   244,   223,   144,  -174,   211,   219,   231,  -174,  -174,
    -174,   200,    79,  -174,   254,   254,  -174,  -174,  -174,  -174,
    -174,    72,   288,  -174,   104,    12,    12,    12,    12,    12,
      12,   226,   249,   212,  -174,   261,   261,   261,  -174,  -174,
    -174,  -174,     4,   227,   297,  -174,  -174,  -174,    71,   240,
      71,  -174,    71,  -174,   105,   250,   100,    -4,  -174,    35,
     224,   244,  -174,  -174,   257,   -31,   275,  -174,   263,    83,
     271,  -174,  -174,  -174,   187,   187,  -174,  -174,  -174,  -174,
      71,   187,   297,    71,   297,   297,  -174,    -7,   276,  -174,
    -174,    79,  -174,  -174,  -174,   144,   294,     7,  -174,   301,
     100,  -174,  -174,  -174,   279,   287,   258,  -174,   297,   244,
    -174,   274,   300,   294,  -174,   -31,   100,  -174,  -174,  -174,
     187,  -174,    79,  -174,  -174,  -174,  -174,  -174
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     7,     0,     1,     0,     0,     9,     3,
       2,    64,     4,    61,     0,    18,     0,     0,     8,     0,
      40,     0,    62,     0,     0,     0,    64,     0,     0,     0,
      79,    81,    69,     0,    66,    67,    68,    70,    71,    72,
      73,    74,    75,     0,     0,     0,    17,    20,     0,    44,
       0,     0,     0,    12,    13,    14,    15,   115,    16,   117,
     119,     0,   105,   109,   114,     0,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,     0,     0,
       0,    19,    38,     0,    39,    42,     0,     0,     6,    45,
      46,     0,    47,     0,     0,   121,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,   126,     0,     0,     0,    76,     0,    98,    11,     0,
       0,     0,     0,     0,    25,    26,     0,     0,    22,    23,
      24,     0,     0,    41,    55,    55,    48,     7,    49,     7,
     120,     0,     0,   124,     0,   104,    99,   100,   101,   102,
     103,     0,     0,     0,    93,   106,   107,   108,   110,   111,
     112,   113,     0,    84,    86,    87,    83,    80,     0,     0,
       0,    82,     0,    10,     0,     0,     0,     0,    35,     0,
       0,     0,    21,    37,     0,     0,     0,    53,     0,     0,
       0,   116,   123,   118,     0,     0,    91,    92,    90,    89,
       0,     0,   125,     0,    78,    97,    27,     0,     0,    33,
      34,     0,    31,    28,    43,     0,    60,     0,    57,     0,
       0,    50,     5,    52,     0,     0,     0,    85,    77,     0,
      29,     0,     0,    59,    54,     0,     0,    51,    95,    94,
       0,    30,     0,    36,    56,    58,    88,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -174,  -174,  -174,  -174,   176,   323,  -174,  -174,  -174,   -43,
    -174,  -174,   281,  -138,  -173,  -174,  -174,  -174,   141,  -127,
    -174,  -174,   245,  -174,   -11,  -174,  -174,  -174,  -174,   185,
    -174,    86,  -174,   133,    -5,   307,  -104,   264,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,   173,  -174,  -174,
     -20,   217,    57,   -42,    19
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,   198,   199,     8,    15,    18,    60,
      20,    46,    47,   137,   138,   139,   140,   187,   188,    83,
      49,    84,    85,    88,    89,    90,    91,    92,    93,   196,
     227,   228,   229,    12,    32,    16,    33,    34,    35,    36,
      37,    38,    39,    40,   210,    41,   163,   164,    42,   126,
     121,    62,    63,    64,   122
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      78,    61,    13,   184,   194,    67,   189,    69,   239,    95,
      96,   244,   173,   218,   175,   177,   101,   225,     1,   178,
     102,   103,   104,   105,   106,    82,   108,   109,   119,   219,
      94,   245,   141,   142,   101,   208,   129,   136,   102,   103,
     104,   105,   106,   141,   221,    53,    54,    55,    56,   209,
      58,   110,    82,   123,   181,   125,   127,   247,   182,    72,
     189,    73,    86,    74,   162,     4,   116,    87,   226,   168,
     169,   170,   171,   255,    50,     5,   201,    75,   152,   146,
     178,   148,   130,   242,    51,   101,    52,     9,   185,   102,
     103,   104,   105,   106,   131,   172,    10,   174,   243,   136,
     234,   235,    97,   130,    98,   132,    99,   237,   203,   216,
      11,   107,   178,   141,   257,   131,   151,    14,   226,   154,
     162,   133,    17,    53,    54,    55,    56,    57,    58,    59,
     134,    53,    54,    55,    56,   135,    58,    53,    54,    55,
      56,   161,    58,   136,    19,    43,   256,    44,   223,    45,
      48,   134,    53,    54,    55,    56,   135,    58,   212,    65,
     214,    66,   215,    11,    21,   165,   166,   167,   150,    22,
      23,    70,    24,    25,   240,    71,   101,    76,   136,    26,
     102,   103,   104,   105,   106,    27,    28,   136,    29,    77,
     236,    79,    30,   238,    13,    31,   251,    11,    21,    80,
      82,   100,   115,   136,    23,   124,    24,    25,   128,   136,
     144,   145,   147,    26,    11,    21,   149,   117,   153,    27,
      28,    23,    29,    24,    25,   176,    30,   180,   186,    31,
      26,    11,    21,   183,   190,   204,    27,    28,    23,    29,
      24,    25,   191,    30,   101,   206,    31,    26,   102,   103,
     104,   105,   106,    27,    28,   192,   193,   195,   205,   211,
      30,   213,   118,    31,    53,    54,    55,    56,   161,    58,
     101,   111,   112,   217,   102,   103,   104,   105,   106,   179,
     222,   224,   241,   113,   230,   101,   114,   231,   250,   102,
     103,   104,   105,   106,   202,   233,    53,    54,    55,    56,
     101,    58,   141,   248,   102,   103,   104,   105,   106,   101,
     246,   249,   252,   102,   103,   104,   105,   106,   155,   156,
     157,   158,   159,   160,   253,   200,     7,    81,   220,   143,
     197,   254,   232,    68,     0,   120,   207
};

static const yytype_int16 yycheck[] =
{
      43,    21,     7,   130,   142,    25,   133,    27,    15,    51,
      52,     4,   116,   186,   118,     4,    12,    48,    41,     8,
      16,    17,    18,    19,    20,    56,    14,    15,    70,    33,
      50,    24,     8,     9,    12,    31,    79,    80,    16,    17,
      18,    19,    20,     8,     9,    52,    53,    54,    55,    45,
      57,    39,    56,    73,     4,    75,    76,   230,     8,     3,
     187,     5,    35,     7,   107,    56,    44,    40,   195,   111,
     112,   113,   114,   246,     3,     0,     4,    21,    98,    90,
       8,    92,     3,   221,    13,    12,    15,    24,   131,    16,
      17,    18,    19,    20,    15,   115,     7,   117,   225,   142,
     204,   205,     3,     3,     5,    26,     7,   211,     4,     4,
      27,    38,     8,     8,   252,    15,    97,    29,   245,   100,
     163,    42,    56,    52,    53,    54,    55,    56,    57,    58,
      51,    52,    53,    54,    55,    56,    57,    52,    53,    54,
      55,    56,    57,   186,    46,    20,   250,    56,   191,    56,
      48,    51,    52,    53,    54,    55,    56,    57,   178,    56,
     180,    52,   182,    27,    28,   108,   109,   110,     4,    33,
      34,     3,    36,    37,   217,     9,    12,     3,   221,    43,
      16,    17,    18,    19,    20,    49,    50,   230,    52,    24,
     210,    20,    56,   213,   199,    59,   239,    27,    28,    20,
      56,     3,    21,   246,    34,    56,    36,    37,    24,   252,
      56,    56,    24,    43,    27,    28,    24,    47,    56,    49,
      50,    34,    52,    36,    37,     4,    56,    21,     5,    59,
      43,    27,    28,    24,    23,     9,    49,    50,    34,    52,
      36,    37,    23,    56,    12,    33,    59,    43,    16,    17,
      18,    19,    20,    49,    50,    24,    56,     3,     9,    32,
      56,    21,    30,    59,    52,    53,    54,    55,    56,    57,
      12,    10,    11,    23,    16,    17,    18,    19,    20,     6,
      56,    24,     6,    22,     9,    12,    25,    24,    30,    16,
      17,    18,    19,    20,     6,    24,    52,    53,    54,    55,
      12,    57,     8,    24,    16,    17,    18,    19,    20,    12,
       9,    24,    38,    16,    17,    18,    19,    20,   101,   102,
     103,   104,   105,   106,    24,   149,     3,    46,   187,    84,
     145,   245,   199,    26,    -1,    71,   163
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    62,    63,    56,     0,    64,    66,    67,    24,
       7,    27,    94,    95,    29,    68,    96,    56,    69,    46,
      71,    28,    33,    34,    36,    37,    43,    49,    50,    52,
      56,    59,    95,    97,    98,    99,   100,   101,   102,   103,
     104,   106,   109,    20,    56,    56,    72,    73,    48,    81,
       3,    13,    15,    52,    53,    54,    55,    56,    57,    58,
      70,   111,   112,   113,   114,    56,    52,   111,    96,   111,
       3,     9,     3,     5,     7,    21,     3,    24,    70,    20,
      20,    73,    56,    80,    82,    83,    35,    40,    84,    85,
      86,    87,    88,    89,   111,   114,   114,     3,     5,     7,
       3,    12,    16,    17,    18,    19,    20,    38,    14,    15,
      39,    10,    11,    22,    25,    21,    44,    47,    30,   114,
      98,   111,   115,   111,    56,   111,   110,   111,    24,    70,
       3,    15,    26,    42,    51,    56,    70,    74,    75,    76,
      77,     8,     9,    83,    56,    56,    85,    24,    85,    24,
       4,   115,   111,    56,   115,   112,   112,   112,   112,   112,
     112,    56,    70,   107,   108,   113,   113,   113,   114,   114,
     114,   114,   111,    97,   111,    97,     4,     4,     8,     6,
      21,     4,     8,    24,    80,    70,     5,    78,    79,    80,
      23,    23,    24,    56,    74,     3,    90,    90,    65,    66,
      65,     4,     6,     4,     9,     9,    33,   108,    31,    45,
     105,    32,   111,    21,   111,   111,     4,    23,    75,    33,
      79,     9,    56,    70,    24,    48,    80,    91,    92,    93,
       9,    24,    94,    24,    97,    97,   111,    97,   111,    15,
      70,     6,    74,    80,     4,    24,     9,    75,    24,    24,
      30,    70,    38,    24,    92,    75,    97,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    64,    65,    66,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    73,    74,    74,    74,    75,    75,    75,    75,    75,
      75,    75,    76,    77,    78,    78,    79,    80,    80,    81,
      81,    82,    82,    83,    84,    84,    85,    85,    85,    85,
      86,    87,    88,    89,    90,    90,    91,    91,    92,    93,
      93,    94,    95,    96,    96,    97,    97,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    99,    99,    99,   100,
     100,   100,   100,   100,   101,   101,   102,   103,   104,   105,
     105,   106,   107,   107,   108,   108,   109,   110,   110,   111,
     111,   111,   111,   111,   111,   111,   112,   112,   112,   112,
     113,   113,   113,   113,   113,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     2,     5,     0,     2,     0,
       5,     4,     1,     1,     1,     1,     1,     2,     0,     2,
       1,     4,     1,     1,     1,     1,     1,     3,     3,     4,
       5,     3,     6,     3,     2,     1,     4,     3,     1,     2,
       0,     2,     1,     4,     0,     1,     1,     1,     2,     2,
       4,     5,     4,     3,     3,     0,     3,     1,     3,     2,
       1,     1,     3,     3,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     6,     5,     1,
       4,     1,     4,     4,     4,     6,     4,     4,     8,     1,
       1,     5,     2,     1,     4,     4,     2,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     1,     4,     1,     4,     1,
       3,     2,     2,     4,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex ();
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
  *++yylsp = yylloc;
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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 112 "spl.y" /* yacc.c:1646  */
    {
	root = A_Fuction_Program((yyvsp[-2].s_symbol), (yyvsp[-1].a_routine));
}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 116 "spl.y" /* yacc.c:1646  */
    {
	(yyval.s_symbol) = makeSymbol((yyvsp[-1].sval), NULL);
}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 120 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_routine) = A_Fuction_Routine((yyvsp[-1].a_routine_head), (yyvsp[0].a_stmtList));
}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 124 "spl.y" /* yacc.c:1646  */
    {
    (yyval.a_routine) = A_Fuction_Routine((yyvsp[-1].a_routine_head), (yyvsp[0].a_stmtList));
}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 129 "spl.y" /* yacc.c:1646  */
    {
    (yyval.a_routine_head) = A_Routine_head((yyvsp[-3].a_decList), (yyvsp[-2].a_decList), (yyvsp[-1].a_decList), (yyvsp[0].a_decList));
}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 133 "spl.y" /* yacc.c:1646  */
    {

}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 137 "spl.y" /* yacc.c:1646  */
    {
    (yyval.a_decList) = (yyvsp[0].a_decList);
    }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 140 "spl.y" /* yacc.c:1646  */
    {
    (yyval.a_decList) = NULL;
    }
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 144 "spl.y" /* yacc.c:1646  */
    {
		    (yyval.a_decList) = A_Fuction_ExprList(A_Fuction_ConstDec(makeSymbol((yyvsp[-3].sval), NULL),(yyvsp[-1].a_const)),(yyvsp[-4].a_decList));            
        }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 147 "spl.y" /* yacc.c:1646  */
    {
		    (yyval.a_decList) = A_Fuction_ExprList(A_Fuction_ConstDec(makeSymbol((yyvsp[-3].sval), NULL),(yyvsp[-1].a_const)),NULL);
        }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 151 "spl.y" /* yacc.c:1646  */
    {
            (yyval.a_const) = A_Fuction_Integer((yyvsp[0].ival));
            }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 154 "spl.y" /* yacc.c:1646  */
    {
            (yyval.a_const) = A_Fuction_Real((yyvsp[0].fval));
            }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 157 "spl.y" /* yacc.c:1646  */
    {
            (yyval.a_const) = A_Fuction_Char((yyvsp[0].cval));
            }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 160 "spl.y" /* yacc.c:1646  */
    {
            (yyval.a_const) = A_Fuction_String((yyvsp[0].sval));
            }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 163 "spl.y" /* yacc.c:1646  */
    {
                switch((yyvsp[0].sys_con)){
			        case SYS_CON_FALSE: (yyval.a_const) = A_Fuction_Bool(0); break;
			        case SYS_CON_TRUE: (yyval.a_const) = A_Fuction_Bool(1); break;
		        }
            }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 170 "spl.y" /* yacc.c:1646  */
    {
            (yyval.a_decList) = (yyvsp[0].a_decList);
            }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 173 "spl.y" /* yacc.c:1646  */
    {
            (yyval.a_decList) = NULL;
            }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 176 "spl.y" /* yacc.c:1646  */
    {
				(yyval.a_decList) = A_Fuction_ExprList((yyvsp[0].a_dec), (yyvsp[-1].a_decList));
                }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 179 "spl.y" /* yacc.c:1646  */
    {
				(yyval.a_decList) = A_Fuction_ExprList((yyvsp[0].a_dec), NULL);
                }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 183 "spl.y" /* yacc.c:1646  */
    {
				(yyval.a_dec) = A_Fuction_TypeDec(makeSymbol((yyvsp[-3].sval), NULL),(yyvsp[-1].a_type));
                }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 188 "spl.y" /* yacc.c:1646  */
    {
    (yyval.a_type) = A_Fuction_SimpleType((yyvsp[0].a_simple_type));
    }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 191 "spl.y" /* yacc.c:1646  */
    {
    (yyval.a_type) = A_Fuction_ArrayType((yyvsp[0].a_array)); 
    }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 194 "spl.y" /* yacc.c:1646  */
    { 
    (yyval.a_type) = A_Fuction_RecordType((yyvsp[0].a_fieldList));
    }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 198 "spl.y" /* yacc.c:1646  */
    {
    (yyval.a_simple_type) = A_Fuction_SimpleSysType((yyvsp[0].ty_kind)); 
    }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 201 "spl.y" /* yacc.c:1646  */
    {
    (yyval.a_simple_type) = A_Fuction_SimpleNameType(makeSymbol((yyvsp[0].sval), NULL));
    }
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 204 "spl.y" /* yacc.c:1646  */
    {
    (yyval.a_simple_type) = A_Fuction_SimpleNameListType((yyvsp[-1].a_nameList));
    }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 207 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_simple_type) = A_Fuction_SimpleRangeType(A_Fuction_ConstRange((yyvsp[-2].a_const),(yyvsp[0].a_const)));  
    }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 210 "spl.y" /* yacc.c:1646  */
    {
    (yyvsp[-2].a_const)->value.integer *= -1;
    (yyval.a_simple_type) = A_Fuction_SimpleRangeType(A_Fuction_ConstRange((yyvsp[-2].a_const),(yyvsp[0].a_const))); 
    }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 214 "spl.y" /* yacc.c:1646  */
    {
	(yyvsp[-3].a_const)->value.integer *= -1;
	(yyvsp[0].a_const)->value.integer *= -1;
	(yyval.a_simple_type) = A_Fuction_SimpleRangeType(A_Fuction_ConstRange((yyvsp[-3].a_const),(yyvsp[0].a_const))); 
	}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 219 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_simple_type) = A_Fuction_SimpleRangeType(A_Fuction_NameRange(makeSymbol((yyvsp[-2].sval), NULL),makeSymbol((yyvsp[0].sval), NULL))); 
	}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 224 "spl.y" /* yacc.c:1646  */
    {
	    (yyval.a_array) = A_Fuction_Array((yyvsp[-3].a_simple_type)->value.range,(yyvsp[0].a_type));
    }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 229 "spl.y" /* yacc.c:1646  */
    { (yyval.a_fieldList) = (yyvsp[-1].a_fieldList);   }
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 232 "spl.y" /* yacc.c:1646  */
    {
    (yyval.a_fieldList) = A_Fuction_FieldList((yyvsp[0].a_field),(yyvsp[-1].a_fieldList));
    }
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 235 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_fieldList) = A_Fuction_FieldList((yyvsp[0].a_field), NULL);
    }
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 240 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_field) = A_Fuction_Field((yyvsp[-3].a_nameList), (yyvsp[-1].a_type));
    }
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 245 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_nameList) = A_Fuction_NameList(A_Fuction_Name(makeSymbol((yyvsp[0].sval), NULL)), (yyvsp[-2].a_nameList));
    }
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 248 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_nameList) = A_Fuction_NameList(A_Fuction_Name(makeSymbol((yyvsp[0].sval), NULL)), NULL);        
    }
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 251 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_decList) = (yyvsp[0].a_decList);
    }
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 254 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_decList) = NULL;
    }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 259 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_decList) = A_Fuction_ExprList(A_Fuction_VarDec((yyvsp[0].a_varDecList)),(yyvsp[-1].a_decList));
    }
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 262 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_decList) = A_Fuction_ExprList(A_Fuction_VarDec((yyvsp[0].a_varDecList)),NULL);
    }
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 266 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_varDecList) = A_Fuction_VarDecList((yyvsp[-3].a_nameList),(yyvsp[-1].a_type));
    }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 270 "spl.y" /* yacc.c:1646  */
    {(yyval.a_decList) = NULL;}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 271 "spl.y" /* yacc.c:1646  */
    {(yyval.a_decList) = (yyvsp[0].a_decList);}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 273 "spl.y" /* yacc.c:1646  */
    {(yyval.a_decList) = A_Fuction_ExprList((yyvsp[0].a_dec), NULL);}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 274 "spl.y" /* yacc.c:1646  */
    {(yyval.a_decList) = A_Fuction_ExprList((yyvsp[0].a_dec), NULL);}
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 275 "spl.y" /* yacc.c:1646  */
    {(yyval.a_decList) = A_Fuction_ExprList((yyvsp[-1].a_dec), (yyvsp[0].a_decList));}
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 276 "spl.y" /* yacc.c:1646  */
    {(yyval.a_decList) = A_Fuction_ExprList((yyvsp[-1].a_dec), (yyvsp[0].a_decList));}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 279 "spl.y" /* yacc.c:1646  */
    {
	    (yyval.a_dec) = A_Fuction_RoutinePartDec(A_Fuction_RoutinePart((yyvsp[-3].a_routine_part_head), (yyvsp[-1].a_routine)))    ;
    }
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 283 "spl.y" /* yacc.c:1646  */
    {
	    (yyval.a_routine_part_head) = A_Fuction_FuncHead(makeSymbol((yyvsp[-3].sval), NULL), (yyvsp[-2].a_paraList), (yyvsp[0].a_simple_type));
    }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 287 "spl.y" /* yacc.c:1646  */
    {
	    (yyval.a_dec) = A_Fuction_RoutinePartDec(A_Fuction_RoutinePart((yyvsp[-3].a_routine_part_head), (yyvsp[-1].a_routine)));
    }
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 291 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_routine_part_head) = A_Fuction_ProcHead(makeSymbol((yyvsp[-1].sval), NULL), (yyvsp[0].a_paraList));
    }
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 295 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_paraList) = (yyvsp[-1].a_paraList);
    }
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 298 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_paraList) = NULL;
	}
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 302 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_paraList) = A_Fuction_ParaList((yyvsp[0].a_paraField), (yyvsp[-2].a_paraList));
    }
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 305 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_paraList) = A_Fuction_ParaList((yyvsp[0].a_paraField), NULL);
    }
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 309 "spl.y" /* yacc.c:1646  */
    {
    (yyval.a_paraField) = A_Fuction_VarParaField((yyvsp[-2].a_nameList), (yyvsp[0].a_simple_type));
    }
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 313 "spl.y" /* yacc.c:1646  */
    { 
	(yyval.a_nameList) = (yyvsp[0].a_nameList);
    }
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 316 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_nameList) = (yyvsp[0].a_nameList);
    }
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 320 "spl.y" /* yacc.c:1646  */
    {
			    (yyval.a_stmtList) = (yyvsp[0].a_stmt)->value.compoundStmt->substmtList;
            }
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 324 "spl.y" /* yacc.c:1646  */
    {
                    printf("compound_stmt\n");
				    (yyval.a_stmt) = A_Fuction_CompoundStatement((yyvsp[-1].a_stmtList));
                }
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 330 "spl.y" /* yacc.c:1646  */
    {
        printf("stmt_list\n");
	    (yyval.a_stmtList) = A_Fuction_StatementList((yyvsp[-1].a_stmt), (yyvsp[-2].a_stmtList));
    }
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 334 "spl.y" /* yacc.c:1646  */
    {(yyval.a_stmtList) = NULL;}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 336 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_stmt) = A_Fuction_LabelStatement((yyvsp[-2].ival), (yyvsp[0].a_stmt));
    }
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 339 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_stmt) = (yyvsp[0].a_stmt);
    }
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 343 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_stmt) = (yyvsp[0].a_stmt);
    }
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 346 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_stmt) = (yyvsp[0].a_stmt);
    }
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 349 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_stmt) = (yyvsp[0].a_stmt);
    }
#line 2218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 352 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_stmt) = (yyvsp[0].a_stmt);
    }
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 355 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_stmt) = (yyvsp[0].a_stmt);
    }
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 358 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_stmt) = (yyvsp[0].a_stmt);
    }
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 361 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_stmt) = (yyvsp[0].a_stmt);
    }
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 364 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_stmt) = (yyvsp[0].a_stmt);
    }
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 367 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_stmt) = (yyvsp[0].a_stmt);
    }
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 370 "spl.y" /* yacc.c:1646  */
    {
			    (yyval.a_stmt) = A_Fuction_AssignStatement(A_Fuction_Var(makeSymbol((yyvsp[-2].sval), NULL)), (yyvsp[0].a_exp));
            }
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 373 "spl.y" /* yacc.c:1646  */
    {
 			    (yyval.a_stmt) = A_Fuction_AssignStatement(A_Fuction_ArrayElement(makeSymbol((yyvsp[-5].sval), NULL), (yyvsp[-3].a_exp)), (yyvsp[0].a_exp));
            }
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 376 "spl.y" /* yacc.c:1646  */
    {
		        (yyval.a_stmt) = A_Fuction_AssignStatement(A_Fuction_RecordField(makeSymbol((yyvsp[-4].sval), NULL), makeSymbol((yyvsp[-2].sval), NULL)), (yyvsp[0].a_exp));	
           }
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 380 "spl.y" /* yacc.c:1646  */
    {
			    (yyval.a_stmt) = A_Fuction_ProcStatement(A_Fuction_Proc(makeSymbol((yyvsp[0].sval), NULL), NULL));
            }
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 383 "spl.y" /* yacc.c:1646  */
    {
			    (yyval.a_stmt) = A_Fuction_ProcStatement(A_Fuction_Proc(makeSymbol((yyvsp[-3].sval), NULL), (yyvsp[-1].a_expList)));
            }
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 386 "spl.y" /* yacc.c:1646  */
    { 
                    switch((yyvsp[0].sys_proc)){
                        case SYS_PROC_WRITE: (yyval.a_stmt) = A_Fuction_ProcStatement(A_Fuction_Proc(makeSymbol("write", NULL), NULL)); break;
                        case SYS_PROC_WRITELN: (yyval.a_stmt) = A_Fuction_ProcStatement(A_Fuction_Proc(makeSymbol("writeln", NULL), NULL)); break;
                    }
                }
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 392 "spl.y" /* yacc.c:1646  */
    {
                    switch((yyvsp[-3].sys_proc)){
                        case SYS_PROC_WRITE: (yyval.a_stmt) = A_Fuction_ProcStatement(A_Fuction_Proc(makeSymbol("write", NULL), (yyvsp[-1].a_expList))); break;
                        case SYS_PROC_WRITELN: (yyval.a_stmt) = A_Fuction_ProcStatement(A_Fuction_Proc(makeSymbol("read", NULL), (yyvsp[-1].a_expList))); break;
                    }
                }
#line 2328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 398 "spl.y" /* yacc.c:1646  */
    {
                    (yyval.a_stmt) = A_Fuction_ProcStatement(A_Fuction_Proc(makeSymbol("read", NULL), A_Fuction_ExpList((yyvsp[-1].a_exp), NULL)));
                }
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 402 "spl.y" /* yacc.c:1646  */
    {
		(yyval.a_stmt) = A_Fuction_IfStatement((yyvsp[-2].a_exp), (yyvsp[0].a_stmt), NULL);
        }
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 405 "spl.y" /* yacc.c:1646  */
    {
		(yyval.a_stmt) = A_Fuction_IfStatement((yyvsp[-4].a_exp), (yyvsp[-2].a_stmt), (yyvsp[0].a_stmt));		
		}
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 409 "spl.y" /* yacc.c:1646  */
    {
			(yyval.a_stmt) = A_Fuction_RepeatStatement((yyvsp[0].a_exp), (yyvsp[-2].a_stmtList));
            }
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 412 "spl.y" /* yacc.c:1646  */
    {
			(yyval.a_stmt) = A_Fuction_WhileStatement((yyvsp[-2].a_exp), (yyvsp[0].a_stmt));
            }
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 415 "spl.y" /* yacc.c:1646  */
    {
      		(yyval.a_stmt) = A_Fuction_ForStatement(A_Fuction_Var(makeSymbol((yyvsp[-6].sval), NULL)), (yyvsp[-4].a_exp), (yyvsp[-3].ival), (yyvsp[-2].a_exp), (yyvsp[0].a_stmt));
            }
#line 2376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 418 "spl.y" /* yacc.c:1646  */
    {
			(yyval.ival) = 1;
            }
#line 2384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 421 "spl.y" /* yacc.c:1646  */
    {
			  (yyval.ival) = -1;
              }
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 425 "spl.y" /* yacc.c:1646  */
    {
			(yyval.a_stmt) = A_Fuction_CaseStatement((yyvsp[-3].a_exp), (yyvsp[-1].a_caseList));
            }
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 428 "spl.y" /* yacc.c:1646  */
    {
				(yyval.a_caseList) = A_Fuction_CaseList((yyvsp[0].a_case), (yyvsp[-1].a_caseList));
                }
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 431 "spl.y" /* yacc.c:1646  */
    {
				(yyval.a_caseList) = A_Fuction_CaseList((yyvsp[0].a_case), NULL);
                }
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 435 "spl.y" /* yacc.c:1646  */
    {
			(yyval.a_case) = A_Fuction_Case((yyvsp[-3].a_const), NULL, (yyvsp[-1].a_stmt));
            }
#line 2424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 438 "spl.y" /* yacc.c:1646  */
    {
			  (yyval.a_case) = A_Fuction_Case(NULL, makeSymbol((yyvsp[-3].sval), NULL), (yyvsp[-1].a_stmt));
              }
#line 2432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 442 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_stmt) = A_Fuction_GotoStatement((yyvsp[0].ival));
}
#line 2440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 447 "spl.y" /* yacc.c:1646  */
    {
				(yyval.a_expList) = A_Fuction_ExpList((yyvsp[0].a_exp), (yyvsp[-2].a_expList));
                }
#line 2448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 450 "spl.y" /* yacc.c:1646  */
    {
				(yyval.a_expList) = A_Fuction_ExpList((yyvsp[0].a_exp), NULL);
                }
#line 2456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 454 "spl.y" /* yacc.c:1646  */
    {
			(yyval.a_exp) = A_Fuction_OpExp(A_geOp, (yyvsp[-2].a_exp), (yyvsp[0].a_exp));
            }
#line 2464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 457 "spl.y" /* yacc.c:1646  */
    {
			(yyval.a_exp) = A_Fuction_OpExp(A_gtOp, (yyvsp[-2].a_exp), (yyvsp[0].a_exp));
            }
#line 2472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 460 "spl.y" /* yacc.c:1646  */
    {
			(yyval.a_exp) = A_Fuction_OpExp(A_leOp, (yyvsp[-2].a_exp), (yyvsp[0].a_exp));
            }
#line 2480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 463 "spl.y" /* yacc.c:1646  */
    {
			(yyval.a_exp) = A_Fuction_OpExp(A_ltOp, (yyvsp[-2].a_exp), (yyvsp[0].a_exp));
            }
#line 2488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 466 "spl.y" /* yacc.c:1646  */
    {
			(yyval.a_exp) = A_Fuction_OpExp(A_eqOp, (yyvsp[-2].a_exp), (yyvsp[0].a_exp));
            }
#line 2496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 469 "spl.y" /* yacc.c:1646  */
    {
			(yyval.a_exp) = A_Fuction_OpExp(A_neqOp, (yyvsp[-2].a_exp), (yyvsp[0].a_exp));
            }
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 472 "spl.y" /* yacc.c:1646  */
    {
			(yyval.a_exp) = (yyvsp[0].a_exp);
            }
#line 2512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 476 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_exp) = A_Fuction_OpExp(A_plusOp, (yyvsp[-2].a_exp), (yyvsp[0].a_exp));
    }
#line 2520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 479 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_exp) = A_Fuction_OpExp(A_minusOp, (yyvsp[-2].a_exp), (yyvsp[0].a_exp));
    }
#line 2528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 482 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_exp) = A_Fuction_OpExp(A_orOp, (yyvsp[-2].a_exp), (yyvsp[0].a_exp));
    }
#line 2536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 485 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_exp) = (yyvsp[0].a_exp);
    }
#line 2544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 489 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_exp) = A_Fuction_OpExp(A_mulOp, (yyvsp[-2].a_exp), (yyvsp[0].a_exp));
    }
#line 2552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 492 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_exp) = A_Fuction_OpExp(A_divOp, (yyvsp[-2].a_exp), (yyvsp[0].a_exp));
    }
#line 2560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 495 "spl.y" /* yacc.c:1646  */
    {
 	(yyval.a_exp) = A_Fuction_OpExp(A_modOp, (yyvsp[-2].a_exp), (yyvsp[0].a_exp));
    }
#line 2568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 498 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_exp) = A_Fuction_OpExp(A_andOp, (yyvsp[-2].a_exp), (yyvsp[0].a_exp));
    }
#line 2576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 501 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_exp) = (yyvsp[0].a_exp);
    }
#line 2584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 505 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_exp) = A_Fuction_NameExp(makeSymbol((yyvsp[0].sval), NULL));
    }
#line 2592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 508 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_exp) = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol((yyvsp[-3].sval), NULL), (yyvsp[-1].a_expList)));
    }
#line 2600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 511 "spl.y" /* yacc.c:1646  */
    {
	    switch((yyvsp[0].sys_funct)){
			case SYS_FUNCT_ABS: (yyval.a_exp) = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("abs", NULL),NULL)); break;
			case SYS_FUNCT_CHR: (yyval.a_exp) = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("char", NULL),NULL)); break;
			case SYS_FUNCT_ODD: (yyval.a_exp) = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("odd", NULL),NULL)); break;
			case SYS_FUNCT_ORD: (yyval.a_exp) = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("ord", NULL),NULL)); break;
			case SYS_FUNCT_PRED: (yyval.a_exp) = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("pred", NULL),NULL)); break;
			case SYS_FUNCT_SQR: (yyval.a_exp) = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("sqr", NULL),NULL)); break;
			case SYS_FUNCT_SQRT: (yyval.a_exp) = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("sqrt", NULL),NULL)); break;
			case SYS_FUNCT_SUCC: (yyval.a_exp) = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("succ", NULL),NULL)); break;
		}
    }
#line 2617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 523 "spl.y" /* yacc.c:1646  */
    {
        switch((yyvsp[-3].sys_funct)){
			case SYS_FUNCT_ABS: (yyval.a_exp) = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("abs", NULL),(yyvsp[-1].a_expList))); break;
			case SYS_FUNCT_CHR: (yyval.a_exp) = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("char", NULL),(yyvsp[-1].a_expList))); break;
			case SYS_FUNCT_ODD: (yyval.a_exp) = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("odd", NULL),(yyvsp[-1].a_expList))); break;
			case SYS_FUNCT_ORD: (yyval.a_exp) = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("ord", NULL),(yyvsp[-1].a_expList))); break;
			case SYS_FUNCT_PRED: (yyval.a_exp) = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("pred", NULL),(yyvsp[-1].a_expList))); break;
			case SYS_FUNCT_SQR: (yyval.a_exp) = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("sqr", NULL),(yyvsp[-1].a_expList))); break;
			case SYS_FUNCT_SQRT: (yyval.a_exp) = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("sqrt", NULL),(yyvsp[-1].a_expList))); break;
			case SYS_FUNCT_SUCC: (yyval.a_exp) = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("succ", NULL),(yyvsp[-1].a_expList))); break;
		}
    }
#line 2634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 535 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_exp) = A_Fuction_ConstExp((yyvsp[0].a_const));

    }
#line 2643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 539 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_exp) = (yyvsp[-1].a_exp);
    }
#line 2651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 542 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_exp) = A_Fuction_OpExp(A_notOp, NULL, (yyvsp[0].a_exp));
    }
#line 2659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 545 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_exp) = A_Fuction_OpExp(A_negOp, NULL, (yyvsp[0].a_exp));
    }
#line 2667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 548 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_exp) = A_Fuction_VarExp(A_Fuction_ArrayElement(makeSymbol((yyvsp[-3].sval), NULL), (yyvsp[-1].a_exp)));
    }
#line 2675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 551 "spl.y" /* yacc.c:1646  */
    {
	(yyval.a_exp) = A_Fuction_VarExp(A_Fuction_RecordField(makeSymbol((yyvsp[-2].sval), NULL), makeSymbol((yyvsp[0].sval), NULL)));
    }
#line 2683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 555 "spl.y" /* yacc.c:1646  */
    {
			(yyval.a_expList) = A_Fuction_ExpList((yyvsp[0].a_exp), (yyvsp[-2].a_expList));
            }
#line 2691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 558 "spl.y" /* yacc.c:1646  */
    {
			(yyval.a_expList) = A_Fuction_ExpList((yyvsp[0].a_exp), NULL);
            }
#line 2699 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2703 "y.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
  return yyresult;
}
#line 564 "spl.y" /* yacc.c:1906  */

extern int cur_line_num;
void yyerror(char *s)
{
	fprintf(stderr, " line %d: %s\n", cur_line_num, s);
	exit(-1);
}

/*
int main(int argc, char *argv[])
{
    ++argv, --argc;  
    if (argc > 0) {
        yyin = fopen(argv[0], "r");
    } else {
        yyin = stdin;
    }
    printf("\n\nStart parsing...:\n\n");
    yyparse();
    return 0;
};
*/
