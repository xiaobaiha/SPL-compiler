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

extern FILE *yyin;
int yylex(void);
void yyerror(char *s);

#line 76 "y.tab.c" /* yacc.c:339  */

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
    NAME = 258,
    LP = 259,
    RP = 260,
    LB = 261,
    RB = 262,
    DOT = 263,
    COMMA = 264,
    COLON = 265,
    MUL = 266,
    DIV = 267,
    UNEQUAL = 268,
    NOT = 269,
    PLUS = 270,
    MINUS = 271,
    GE = 272,
    GT = 273,
    LE = 274,
    LT = 275,
    EQUAL = 276,
    ASSIGN = 277,
    MOD = 278,
    DOTDOT = 279,
    SEMI = 280,
    AND = 281,
    ARRAY = 282,
    BEGIN_TOKEN = 283,
    CASE = 284,
    CONST = 285,
    DO = 286,
    DOWNTO = 287,
    ELSE = 288,
    END = 289,
    FOR = 290,
    FUNCTION = 291,
    GOTO = 292,
    IF = 293,
    OF = 294,
    OR = 295,
    PROCEDURE = 296,
    PROGRAM = 297,
    RECORD = 298,
    REPEAT = 299,
    THEN = 300,
    TO = 301,
    TYPE = 302,
    UNTIL = 303,
    VAR = 304,
    WHILE = 305,
    SYS_CON = 306,
    SYS_FUNCT = 307,
    SYS_PROC = 308,
    SYS_TYPE = 309,
    READ = 310,
    INTEGER = 311,
    CHAR = 312,
    REAL = 313,
    STRING = 314
  };
#endif
/* Tokens.  */
#define NAME 258
#define LP 259
#define RP 260
#define LB 261
#define RB 262
#define DOT 263
#define COMMA 264
#define COLON 265
#define MUL 266
#define DIV 267
#define UNEQUAL 268
#define NOT 269
#define PLUS 270
#define MINUS 271
#define GE 272
#define GT 273
#define LE 274
#define LT 275
#define EQUAL 276
#define ASSIGN 277
#define MOD 278
#define DOTDOT 279
#define SEMI 280
#define AND 281
#define ARRAY 282
#define BEGIN_TOKEN 283
#define CASE 284
#define CONST 285
#define DO 286
#define DOWNTO 287
#define ELSE 288
#define END 289
#define FOR 290
#define FUNCTION 291
#define GOTO 292
#define IF 293
#define OF 294
#define OR 295
#define PROCEDURE 296
#define PROGRAM 297
#define RECORD 298
#define REPEAT 299
#define THEN 300
#define TO 301
#define TYPE 302
#define UNTIL 303
#define VAR 304
#define WHILE 305
#define SYS_CON 306
#define SYS_FUNCT 307
#define SYS_PROC 308
#define SYS_TYPE 309
#define READ 310
#define INTEGER 311
#define CHAR 312
#define REAL 313
#define STRING 314

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 245 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   335

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  258

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

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
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    27,    27,    31,    34,    37,    41,    44,    47,    49,
      52,    55,    58,    60,    62,    64,    66,    69,    71,    73,
      75,    78,    82,    84,    86,    89,    91,    93,    94,    96,
      97,    98,   101,   105,   108,   110,   114,   118,   120,   123,
     125,   129,   131,   134,   136,   137,   139,   140,   141,   142,
     146,   150,   154,   158,   162,   165,   167,   170,   174,   178,
     180,   182,   186,   191,   194,   196,   199,   203,   206,   209,
     211,   214,   217,   220,   223,   226,   229,   232,   235,   239,
     241,   244,   246,   249,   252,   253,   255,   258,   261,   264,
     266,   269,   272,   275,   279,   282,   286,   289,   292,   296,
     299,   302,   305,   308,   311,   314,   318,   321,   324,   327,
     331,   334,   337,   340,   343,   347,   350,   353,   355,   358,
     361,   364,   367,   370,   372,   376,   379
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "LP", "RP", "LB", "RB", "DOT",
  "COMMA", "COLON", "MUL", "DIV", "UNEQUAL", "NOT", "PLUS", "MINUS", "GE",
  "GT", "LE", "LT", "EQUAL", "ASSIGN", "MOD", "DOTDOT", "SEMI", "AND",
  "ARRAY", "BEGIN_TOKEN", "CASE", "CONST", "DO", "DOWNTO", "ELSE", "END",
  "FOR", "FUNCTION", "GOTO", "IF", "OF", "OR", "PROCEDURE", "PROGRAM",
  "RECORD", "REPEAT", "THEN", "TO", "TYPE", "UNTIL", "VAR", "WHILE",
  "SYS_CON", "SYS_FUNCT", "SYS_PROC", "SYS_TYPE", "READ", "INTEGER",
  "CHAR", "REAL", "STRING", "$accept", "program_stmt", "program_head",
  "routine", "sub_routine", "routine_head", "label_part", "const_part",
  "const_expr_list", "const_value", "type_part", "type_decl_list",
  "type_definition", "type_decl", "simple_type_decl", "array_type_decl",
  "record_type_decl", "field_decl_list", "field_decl", "name_list",
  "var_part", "var_decl_list", "var_decl", "routine_part",
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF -180

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-180)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,    65,    93,  -180,    80,  -180,    98,    86,    91,  -180,
    -180,  -180,  -180,  -180,   123,    84,   157,   111,   144,   151,
     106,    24,    78,  -180,   155,   103,    78,  -180,    78,   162,
     163,   164,  -180,   153,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,   190,   159,   167,   151,  -180,   194,    22,
      78,    78,   195,    78,    35,    78,    78,    78,  -180,   198,
    -180,  -180,  -180,  -180,  -180,   252,    10,    99,  -180,   177,
    -180,   132,   187,   263,    78,    78,   224,  -180,   180,   190,
      61,  -180,  -180,    13,   194,  -180,   203,   205,  -180,  -180,
      22,   186,    22,   189,   313,    69,   288,   196,   313,    78,
      78,   214,   152,  -180,  -180,    78,    78,    78,    78,    78,
      78,    78,   125,    78,    78,    78,    78,    78,    78,    78,
      78,   201,    78,   201,    70,   313,   215,  -180,  -180,   207,
     197,   194,   190,   213,   194,  -180,   199,   208,  -180,  -180,
    -180,   223,    61,  -180,   230,   230,  -180,  -180,  -180,  -180,
    -180,    78,   206,    78,    71,   304,  -180,  -180,   118,    10,
      10,    10,    10,    10,    10,   234,   240,   105,  -180,    99,
      99,    99,  -180,  -180,  -180,  -180,    -1,   222,   313,  -180,
    -180,    78,  -180,  -180,   255,   137,   236,    44,    18,  -180,
      25,   190,  -180,  -180,   238,     4,   254,  -180,   241,    86,
     242,   313,    78,   313,  -180,  -180,  -180,   201,   201,  -180,
    -180,  -180,  -180,    78,   201,   313,  -180,  -180,    -2,   268,
    -180,  -180,    61,  -180,  -180,   194,   269,    19,  -180,   283,
      44,  -180,  -180,  -180,   313,   277,   278,   279,  -180,   190,
    -180,   265,   287,   269,  -180,     4,    44,  -180,  -180,  -180,
     201,  -180,    61,  -180,  -180,  -180,  -180,  -180
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     7,     0,     1,     0,     0,     9,     3,
       2,    64,     4,    61,     0,    18,     0,     0,     8,     0,
      40,    79,     0,    62,     0,     0,     0,    64,     0,    81,
       0,     0,    69,     0,    66,    67,    68,    70,    71,    72,
      73,    74,    75,     0,     0,     0,    17,    20,     0,    44,
       0,     0,     0,     0,   115,     0,     0,     0,    16,   117,
      12,    14,    13,    15,   119,     0,   105,   109,   114,     0,
      96,     0,     0,     0,     0,     0,     0,    63,     0,     0,
       0,    19,    38,     0,    39,    42,     0,     0,     6,    45,
      46,     0,    47,     0,   126,     0,     0,     0,    76,     0,
       0,     0,     0,   121,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,     0,    65,    11,     0,
      26,     0,     0,     0,     0,    25,     0,     0,    22,    23,
      24,     0,     0,    41,    55,    55,    48,     7,    49,     7,
      80,     0,     0,     0,     0,     0,   124,   120,     0,   104,
      99,   100,   101,   102,   103,     0,     0,     0,    93,   106,
     107,   108,   110,   111,   112,   113,     0,    84,    86,    87,
      82,     0,    83,    10,     0,     0,     0,     0,     0,    35,
       0,     0,    21,    37,     0,     0,     0,    53,     0,     0,
       0,   125,     0,    78,   116,   123,   118,     0,     0,    91,
      92,    90,    89,     0,     0,    97,    31,    27,     0,     0,
      33,    34,     0,    28,    43,     0,    60,     0,    57,     0,
       0,    50,     5,    52,    77,     0,     0,     0,    85,     0,
      29,     0,     0,    59,    54,     0,     0,    51,    95,    94,
       0,    30,     0,    36,    56,    58,    88,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -180,  -180,  -180,  -180,   165,   310,  -180,  -180,  -180,   -43,
    -180,  -180,   270,  -139,  -179,  -180,  -180,  -180,   127,  -129,
    -180,  -180,   235,  -180,    51,  -180,  -180,  -180,  -180,   173,
    -180,    75,  -180,   128,    -6,   301,  -117,   253,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,   168,  -180,  -180,
     -13,   179,   -29,   -46,   -72
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,   198,   199,     8,    15,    18,    64,
      20,    46,    47,   137,   138,   139,   140,   188,   189,    83,
      49,    84,    85,    88,    89,    90,    91,    92,    93,   196,
     227,   228,   229,    12,    32,    16,    33,    34,    35,    36,
      37,    38,    39,    40,   213,    41,   167,   168,    42,   124,
      94,    66,    67,    68,    95
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      78,    13,   185,   194,   177,   190,   179,    82,   219,    65,
     103,   104,   106,    71,   239,    73,   107,   108,   109,   110,
     111,    82,   141,   142,   244,   113,   114,   154,    50,   126,
      51,   211,    52,   158,   141,   222,   129,   136,    96,    99,
      98,   100,   102,   101,   245,   212,    53,   130,   131,    58,
     115,   247,   220,   225,    60,    61,    62,    63,    86,   190,
     132,   125,     1,    87,   130,   131,   226,   255,     4,   166,
     172,   173,   174,   175,   150,   180,   204,   132,   151,   181,
     151,    54,    55,   242,   169,   170,   171,   155,   133,   186,
     235,   236,    56,     5,    57,    58,   243,   238,   135,   136,
      60,    61,    62,    63,   134,     9,    10,   176,   165,   178,
     116,   117,    58,   257,    11,   135,   226,    60,    61,    62,
      63,    14,   118,   206,   166,   119,    17,   151,   165,    58,
      59,    19,    43,   256,    60,    61,    62,    63,   201,   209,
     203,   146,   217,   148,   136,   106,   141,    44,   223,   107,
     108,   109,   110,   111,    45,    48,    58,   157,    69,    70,
      21,    60,    61,    62,    63,   106,    74,    75,   215,   107,
     108,   109,   110,   111,    76,   240,    58,   121,    77,   136,
      79,    60,    61,    62,    63,    11,    22,   136,    80,   234,
      21,    23,    24,    13,    25,    26,   251,    82,    97,   120,
     237,    27,   105,   136,    21,   128,   144,    28,   145,   136,
      29,   147,    30,    31,   149,    11,    22,   156,   153,   187,
     182,   184,    24,   191,    25,    26,   193,    21,   202,    11,
      22,    27,   183,   192,   195,   122,    24,    28,    25,    26,
      29,    58,    30,    31,   207,    27,    60,    61,    62,    63,
     208,    28,    11,    22,    29,   214,    30,    31,   216,    24,
     218,    25,    26,   224,   230,   106,   231,   233,    27,   107,
     108,   109,   110,   111,    28,   241,   106,    29,   141,    30,
     107,   108,   109,   110,   111,   159,   160,   161,   162,   163,
     164,   112,   106,   246,   123,   152,   107,   108,   109,   110,
     111,   106,   248,   249,   252,   107,   108,   109,   110,   111,
     250,   205,   253,     7,   200,   221,    81,   106,   197,   143,
     254,   107,   108,   109,   110,   111,   106,   232,    72,   127,
     107,   108,   109,   110,   111,   210
};

static const yytype_uint8 yycheck[] =
{
      43,     7,   131,   142,   121,   134,   123,     3,   187,    22,
      56,    57,    13,    26,    16,    28,    17,    18,    19,    20,
      21,     3,     9,    10,     5,    15,    16,    99,     4,    75,
       6,    32,     8,   105,     9,    10,    79,    80,    51,     4,
      53,     6,    55,     8,    25,    46,    22,     3,     4,    51,
      40,   230,    34,    49,    56,    57,    58,    59,    36,   188,
      16,    74,    42,    41,     3,     4,   195,   246,     3,   112,
     116,   117,   118,   119,     5,     5,     5,    16,     9,     9,
       9,     3,     4,   222,   113,   114,   115,   100,    27,   132,
     207,   208,    14,     0,    16,    51,   225,   214,    54,   142,
      56,    57,    58,    59,    43,    25,     8,   120,     3,   122,
      11,    12,    51,   252,    28,    54,   245,    56,    57,    58,
      59,    30,    23,     5,   167,    26,     3,     9,     3,    51,
      52,    47,    21,   250,    56,    57,    58,    59,   151,    34,
     153,    90,     5,    92,   187,    13,     9,     3,   191,    17,
      18,    19,    20,    21,     3,    49,    51,     5,     3,    56,
       3,    56,    57,    58,    59,    13,     4,     4,   181,    17,
      18,    19,    20,    21,    10,   218,    51,    45,    25,   222,
      21,    56,    57,    58,    59,    28,    29,   230,    21,   202,
       3,    34,    35,   199,    37,    38,   239,     3,     3,    22,
     213,    44,     4,   246,     3,    25,     3,    50,     3,   252,
      53,    25,    55,    56,    25,    28,    29,     3,    22,     6,
       5,    24,    35,    24,    37,    38,     3,     3,    22,    28,
      29,    44,    25,    25,     4,    48,    35,    50,    37,    38,
      53,    51,    55,    56,    10,    44,    56,    57,    58,    59,
      10,    50,    28,    29,    53,    33,    55,    56,     3,    35,
      24,    37,    38,    25,    10,    13,    25,    25,    44,    17,
      18,    19,    20,    21,    50,     7,    13,    53,     9,    55,
      17,    18,    19,    20,    21,   106,   107,   108,   109,   110,
     111,    39,    13,    10,    31,     7,    17,    18,    19,    20,
      21,    13,    25,    25,    39,    17,    18,    19,    20,    21,
      31,     7,    25,     3,   149,   188,    46,    13,   145,    84,
     245,    17,    18,    19,    20,    21,    13,   199,    27,    76,
      17,    18,    19,    20,    21,   167
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    61,    62,     3,     0,    63,    65,    66,    25,
       8,    28,    93,    94,    30,    67,    95,     3,    68,    47,
      70,     3,    29,    34,    35,    37,    38,    44,    50,    53,
      55,    56,    94,    96,    97,    98,    99,   100,   101,   102,
     103,   105,   108,    21,     3,     3,    71,    72,    49,    80,
       4,     6,     8,    22,     3,     4,    14,    16,    51,    52,
      56,    57,    58,    59,    69,   110,   111,   112,   113,     3,
      56,   110,    95,   110,     4,     4,    10,    25,    69,    21,
      21,    72,     3,    79,    81,    82,    36,    41,    83,    84,
      85,    86,    87,    88,   110,   114,   110,     3,   110,     4,
       6,     8,   110,   113,   113,     4,    13,    17,    18,    19,
      20,    21,    39,    15,    16,    40,    11,    12,    23,    26,
      22,    45,    48,    31,   109,   110,   113,    97,    25,    69,
       3,     4,    16,    27,    43,    54,    69,    73,    74,    75,
      76,     9,    10,    82,     3,     3,    84,    25,    84,    25,
       5,     9,     7,    22,   114,   110,     3,     5,   114,   111,
     111,   111,   111,   111,   111,     3,    69,   106,   107,   112,
     112,   112,   113,   113,   113,   113,   110,    96,   110,    96,
       5,     9,     5,    25,    24,    79,    69,     6,    77,    78,
      79,    24,    25,     3,    73,     4,    89,    89,    64,    65,
      64,   110,    22,   110,     5,     7,     5,    10,    10,    34,
     107,    32,    46,   104,    33,   110,     3,     5,    24,    74,
      34,    78,    10,    69,    25,    49,    79,    90,    91,    92,
      10,    25,    93,    25,   110,    96,    96,   110,    96,    16,
      69,     7,    73,    79,     5,    25,    10,    74,    25,    25,
      31,    69,    39,    25,    91,    74,    96,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    63,    64,    65,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    69,    70,    70,    71,
      71,    72,    73,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    75,    76,    77,    77,    78,    79,    79,    80,
      80,    81,    81,    82,    83,    83,    84,    84,    84,    84,
      85,    86,    87,    88,    89,    89,    90,    90,    91,    92,
      92,    93,    94,    95,    95,    96,    96,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    98,    98,    98,    99,
      99,    99,    99,    99,   100,   100,   101,   102,   103,   104,
     104,   105,   106,   106,   107,   107,   108,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   111,   111,   111,   111,
     112,   112,   112,   112,   112,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   114,   114
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 27 "spl.y" /* yacc.c:1646  */
    {
    printf("program_stmt\n");
}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 31 "spl.y" /* yacc.c:1646  */
    {
}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 34 "spl.y" /* yacc.c:1646  */
    {
}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 37 "spl.y" /* yacc.c:1646  */
    {
}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 41 "spl.y" /* yacc.c:1646  */
    {
}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 44 "spl.y" /* yacc.c:1646  */
    {
}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 47 "spl.y" /* yacc.c:1646  */
    {
    }
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 49 "spl.y" /* yacc.c:1646  */
    {
    }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 52 "spl.y" /* yacc.c:1646  */
    {
            
        }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 55 "spl.y" /* yacc.c:1646  */
    {
        }
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 58 "spl.y" /* yacc.c:1646  */
    {
            }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 60 "spl.y" /* yacc.c:1646  */
    {
            }
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 62 "spl.y" /* yacc.c:1646  */
    {
            }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 64 "spl.y" /* yacc.c:1646  */
    {
            }
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 66 "spl.y" /* yacc.c:1646  */
    {
            }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 69 "spl.y" /* yacc.c:1646  */
    {
            }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 71 "spl.y" /* yacc.c:1646  */
    {
            }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 73 "spl.y" /* yacc.c:1646  */
    {
                }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 75 "spl.y" /* yacc.c:1646  */
    {
                }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 78 "spl.y" /* yacc.c:1646  */
    {
                }
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 82 "spl.y" /* yacc.c:1646  */
    {
    }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 84 "spl.y" /* yacc.c:1646  */
    { 
    }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 86 "spl.y" /* yacc.c:1646  */
    { 
    }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 89 "spl.y" /* yacc.c:1646  */
    { 
    }
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 91 "spl.y" /* yacc.c:1646  */
    {
    }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 94 "spl.y" /* yacc.c:1646  */
    {  
    }
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 101 "spl.y" /* yacc.c:1646  */
    {
    }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 105 "spl.y" /* yacc.c:1646  */
    {    }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 108 "spl.y" /* yacc.c:1646  */
    {
    }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 110 "spl.y" /* yacc.c:1646  */
    {
    }
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 114 "spl.y" /* yacc.c:1646  */
    {
    }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 118 "spl.y" /* yacc.c:1646  */
    {
    }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 120 "spl.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
    }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 123 "spl.y" /* yacc.c:1646  */
    {
    }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 125 "spl.y" /* yacc.c:1646  */
    {
    }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 129 "spl.y" /* yacc.c:1646  */
    {
    }
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 131 "spl.y" /* yacc.c:1646  */
    {;
    }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 134 "spl.y" /* yacc.c:1646  */
    {
    }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 146 "spl.y" /* yacc.c:1646  */
    {

    }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 150 "spl.y" /* yacc.c:1646  */
    {

    }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 154 "spl.y" /* yacc.c:1646  */
    {

    }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 158 "spl.y" /* yacc.c:1646  */
    {

    }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 162 "spl.y" /* yacc.c:1646  */
    {

    }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 167 "spl.y" /* yacc.c:1646  */
    {

    }
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 170 "spl.y" /* yacc.c:1646  */
    {
;
    }
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 174 "spl.y" /* yacc.c:1646  */
    {
        
    }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 178 "spl.y" /* yacc.c:1646  */
    { 
    }
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 180 "spl.y" /* yacc.c:1646  */
    {
    }
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 182 "spl.y" /* yacc.c:1646  */
    {

            }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 186 "spl.y" /* yacc.c:1646  */
    {

                }
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 191 "spl.y" /* yacc.c:1646  */
    {

    }
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 196 "spl.y" /* yacc.c:1646  */
    {

    }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 199 "spl.y" /* yacc.c:1646  */
    {

    }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 203 "spl.y" /* yacc.c:1646  */
    {

    }
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 206 "spl.y" /* yacc.c:1646  */
    {

    }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 209 "spl.y" /* yacc.c:1646  */
    {
    }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 211 "spl.y" /* yacc.c:1646  */
    {

    }
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 214 "spl.y" /* yacc.c:1646  */
    {

    }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 217 "spl.y" /* yacc.c:1646  */
    {

    }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 220 "spl.y" /* yacc.c:1646  */
    {

    }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 223 "spl.y" /* yacc.c:1646  */
    {

    }
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 226 "spl.y" /* yacc.c:1646  */
    {

    }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 229 "spl.y" /* yacc.c:1646  */
    {

            }
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 232 "spl.y" /* yacc.c:1646  */
    {
 
            }
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 235 "spl.y" /* yacc.c:1646  */
    {

           }
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 239 "spl.y" /* yacc.c:1646  */
    {
            }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 241 "spl.y" /* yacc.c:1646  */
    {

            }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 244 "spl.y" /* yacc.c:1646  */
    { 
            }
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 246 "spl.y" /* yacc.c:1646  */
    {

            }
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 249 "spl.y" /* yacc.c:1646  */
    {
            }
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 255 "spl.y" /* yacc.c:1646  */
    {

            }
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 258 "spl.y" /* yacc.c:1646  */
    {

            }
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 261 "spl.y" /* yacc.c:1646  */
    {
      
            }
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 264 "spl.y" /* yacc.c:1646  */
    {
            }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 266 "spl.y" /* yacc.c:1646  */
    {
              }
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 269 "spl.y" /* yacc.c:1646  */
    {

            }
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 272 "spl.y" /* yacc.c:1646  */
    {

                }
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 275 "spl.y" /* yacc.c:1646  */
    {

                }
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 279 "spl.y" /* yacc.c:1646  */
    {

            }
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 282 "spl.y" /* yacc.c:1646  */
    {

              }
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 289 "spl.y" /* yacc.c:1646  */
    {

                }
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 292 "spl.y" /* yacc.c:1646  */
    {

                }
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 296 "spl.y" /* yacc.c:1646  */
    {

            }
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 299 "spl.y" /* yacc.c:1646  */
    {

            }
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 302 "spl.y" /* yacc.c:1646  */
    {

            }
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 305 "spl.y" /* yacc.c:1646  */
    {

            }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 308 "spl.y" /* yacc.c:1646  */
    {

            }
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 311 "spl.y" /* yacc.c:1646  */
    {

            }
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 314 "spl.y" /* yacc.c:1646  */
    {

            }
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 318 "spl.y" /* yacc.c:1646  */
    {

    }
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 321 "spl.y" /* yacc.c:1646  */
    {

    }
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 324 "spl.y" /* yacc.c:1646  */
    {

    }
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 327 "spl.y" /* yacc.c:1646  */
    {

    }
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 331 "spl.y" /* yacc.c:1646  */
    {

    }
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 334 "spl.y" /* yacc.c:1646  */
    {

    }
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 337 "spl.y" /* yacc.c:1646  */
    {
 
    }
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 340 "spl.y" /* yacc.c:1646  */
    {

    }
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 343 "spl.y" /* yacc.c:1646  */
    {

    }
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 347 "spl.y" /* yacc.c:1646  */
    {

    }
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 350 "spl.y" /* yacc.c:1646  */
    {

    }
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 353 "spl.y" /* yacc.c:1646  */
    { 
    }
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 355 "spl.y" /* yacc.c:1646  */
    {

    }
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 358 "spl.y" /* yacc.c:1646  */
    {

    }
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 361 "spl.y" /* yacc.c:1646  */
    {

    }
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 364 "spl.y" /* yacc.c:1646  */
    {

    }
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 367 "spl.y" /* yacc.c:1646  */
    {

    }
#line 2323 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 370 "spl.y" /* yacc.c:1646  */
    {
    }
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 372 "spl.y" /* yacc.c:1646  */
    {

    }
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 376 "spl.y" /* yacc.c:1646  */
    {

            }
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 379 "spl.y" /* yacc.c:1646  */
    {

            }
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2358 "y.tab.c" /* yacc.c:1646  */
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 383 "spl.y" /* yacc.c:1906  */

extern int cur_line_num;
void yyerror(char *s)
{
	fprintf(stderr, " line %d: %s\n", cur_line_num, s);
	exit(-1);
}

int main(int argc, char *argv[])
{
    ++argv, --argc;    /* skip argv[0] */
    if (argc > 0) {
        yyin = fopen(argv[0], "r");
    } else {
        yyin = stdin;
    }
    printf("\n\nStart parsing...:\n\n");
    yyparse();
    return 0;
};
