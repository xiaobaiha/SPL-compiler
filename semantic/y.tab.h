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
