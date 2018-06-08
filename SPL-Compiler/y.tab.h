/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 16 "spl.y" /* yacc.c:1909  */

    
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

#line 213 "y.tab.h" /* yacc.c:1909  */
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
