%{  
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>  
#include "token.h"
#include "absyn.h"
#include "y.tab.h"
#include "error.h"
#include "util.h"


int cur_line_num = 1;
int yycolumn = 1;
int charPos=1;

int yylex(void);
int yyerror(char *s);
void init_scanner();
void lex_error(char* msg, int line);
void NewLine();
void adjust(char* text);

int construct_str();
int construct_name();
int construct_int();
int construct_real();

#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng; \

%}
%option yylineno

delim   [" "\t]
whitespace  {delim}+
digit 	[0-9]
integer {digit}+
real    {digit}+(\.{digit}+)?(([E|e])[+\-]?{digit}+)?
string		[\']

lp  "("
rp  ")"
lb  "["
rb  "]"
dot "."
comma   ","
colon   ":"
mul "*"
div "/"
unequal "<>"
not "not"
plus    "+"
minus   "-"
ge  ">="
gt  ">"
le  "<="
lt  "<"
equal   "="
assign  ":="
mod "%"
dotdot  ".."
semi    ";"

and "and"
array   "array"
begin   "begin"
case    "case"
const   "const"
do  "do"
downto  "downto"
else    "else"
end "end"
for "for"
function    "function"
goto    "goto"
if  "if"
of  "of"
or  "or"
procedure   "procedure"
program "program"
record  "record"
repeat  "repeat"
then    "then"
to  "to"
type    "type"
until   "until"
var "var"
while   "while"
read    "read"

sys_con     "true"|"maxint"|"false"
sys_funct   "abs"|"chr"|"odd"|"ord"|"pred"|"sqr"|"sqrt"|"succ"
sys_proc    "write"|"writeln"
sys_type    "boolean"|"char"|"integer"|"real"

name    [a-zA-Z][_a-zA-Z0-9]*
%%
[\n]    { adjust(yytext); lex_newline(); cur_line_num++;}
{whitespace} {/* do nothing*/}
"{"[^{}]*"}" 	{ adjust(yytext);/* ignore comments */}

{lp}    { adjust(yytext);return LP;}
{rp}    { adjust(yytext);return RP;}
{lb}    { adjust(yytext);return LB;}
{rb}    { adjust(yytext);return RB;}
{dot}   { adjust(yytext);return DOT;}
{comma} { adjust(yytext);return COMMA;}
{colon} { adjust(yytext);return COLON;}
{mul}   { adjust(yytext);return MUL;}
{div}   { adjust(yytext);return DIV;}
{unequal}   { adjust(yytext);return UNEQUAL;}
{read}        { adjust(yytext);return READ;}
{not}   { adjust(yytext);return NOT;}
{plus}  { adjust(yytext);return PLUS;}
{minus} { adjust(yytext);return MINUS;}
{ge}    { adjust(yytext);return GE;}
{gt}    { adjust(yytext);return GT;}
{le}    { adjust(yytext);return LE;}
{lt}    { adjust(yytext);return LT;}
{equal} { adjust(yytext);return EQUAL;}
{assign}    { adjust(yytext);return ASSIGN;}
{mod}   { adjust(yytext);return MOD;}
{dotdot}    { adjust(yytext);return DOTDOT;}
{semi}  { adjust(yytext);return SEMI;}
{and}   { adjust(yytext);return AND;}
{array} { adjust(yytext);return ARRAY;}
{begin} { adjust(yytext);return BEGIN_TOKEN;}
{case}  { adjust(yytext);return CASE;}
{const} { adjust(yytext);return CONST;}
{do}    { adjust(yytext);return DO;}
{downto}    { adjust(yytext);return DOWNTO;}
{else}  { adjust(yytext);return ELSE;}
{end}   { adjust(yytext);return END;}
{for}   { adjust(yytext);return FOR;}
{function}  { adjust(yytext);return FUNCTION;}
{goto}  { adjust(yytext);return GOTO;}
{if}    { adjust(yytext);return IF;}
{of}    { adjust(yytext);return OF;}
{or}    { adjust(yytext);return OR;}
{procedure} { adjust(yytext);return PROCEDURE;}
{program}   { adjust(yytext);return PROGRAM;}
{record}    { adjust(yytext);return RECORD;}
{repeat}    { adjust(yytext);return REPEAT;}
{then}  { adjust(yytext);return THEN;}
{to}    { adjust(yytext);return TO;}
{type}  { adjust(yytext);return TYPE;}
{until} { adjust(yytext);return UNTIL;}
{var}   { adjust(yytext);return VAR;}
{while} { adjust(yytext);return WHILE;}

{sys_con}   { adjust(yytext);return SYS_CON;}
{sys_funct} { adjust(yytext);return SYS_FUNCT;}   
{sys_proc}  { adjust(yytext);return SYS_PROC;}
{sys_type}  { adjust(yytext);return SYS_TYPE;}

{name}  { adjust(yytext);return construct_name();}
{string}	{ adjust(yytext);return construct_str();}
{integer}   { adjust(yytext);return construct_int();}
{real}  { adjust(yytext);return construct_real();}

.   { adjust(yytext);lexError(cur_line_num, EM_tokPos, "Illegal Token!");
	}

%%

int yywrap(void){charPos=1;return 1;} 

int construct_int()
{
	int num;
	sscanf(yytext, "%d", &num);
	yylval.ival = num;
	return INTEGER;
}

int construct_real()
{
	float num;
	sscanf(yytext, "%f", &num);
	yylval.fval = num;
	return REAL;
}

int construct_name()
{
	
	yylval.sval = checked_malloc(yyleng+1);
	strcpy(yylval.sval, yytext);
	return NAME;
	/*
	int len = yyleng;
	if (len > MAXNAMELEN) {
		len = MAXNAMELEN;
	}

	for (int i = 0; i < len; i++) {
		yylval.sval[i] = yytext[i];
	}

	yylval.sval[len] = '\0';

	return NAME;
	*/
}

int construct_str(){
	
	int len = 0;
	char c;
	while ((c = input()) != '\'') {
		/*if (len < 15) yylval.sval[len] = c;*/
		len++;
	}
	if (len > 15) len = 15;
	
	if (len == 1) {
		return CHAR;
	}
	else {
		return STRING;
	}
	
}

void NewLine(){
	cur_line_num++;
	yycolumn = 0;
}

void adjust(char* text)
{
	//yylloc.first_line = cur_line_num;
	//yylloc.first_column = startColNum;
	//yylloc.last_line = rowNum;
	//yylloc.last_column = endColNum;
	if(DEBUG){
		printf("Token '%s' at %d:%d-%d\n", text,
						yylloc.first_line,
                        yylloc.first_column,
                        yylloc.last_column);
	}
    EM_tokPos=charPos;
    charPos+=yyleng;
}

/*
void init_scanner() {
    printf("%-20s%s\n", "TOKEN-TYPE", "TOKEN-VALUE");
    printf("-------------------------------------------------\n");
}

void lex_error(char* msg, int line) {
    printf("\nError at line %-3d: %s\n\n", line, msg);
}

int main(int argc, char* argv[]) {
    int token;
    init_scanner();
    while (token = yylex()) {
        print_token(token);
        puts(yytext);
    }
    return 0;
}
*/