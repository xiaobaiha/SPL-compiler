%{  
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>  
#include "token.h"
#include "y.tab.h"
#include "error.h"

int cur_line_num = 1;
int yycolumn = 1;
int charPos=1;

int yylex(void);
int yyerror(char *s);
void init_scanner();
void lex_error(char* msg, int line);
void NewLine();
void adjust(void);

int install_str(); 

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
[\n]    { adjust(); EM_newline(); cur_line_num++;}
{whitespace} {/* do nothing*/}
"{"[^{}]*"}" 	{ adjust();/* ignore comments */}

{lp}    { adjust();return LP;}
{rp}    { adjust();return RP;}
{lb}    { adjust();return LB;}
{rb}    { adjust();return RB;}
{dot}   { adjust();return DOT;}
{comma} { adjust();return COMMA;}
{colon} { adjust();return COLON;}
{mul}   { adjust();return MUL;}
{div}   { adjust();return DIV;}
{unequal}   { adjust();return UNEQUAL;}
{read}        { adjust();return READ;}
{not}   { adjust();return NOT;}
{plus}  { adjust();return PLUS;}
{minus} { adjust();return MINUS;}
{ge}    { adjust();return GE;}
{gt}    { adjust();return GT;}
{le}    { adjust();return LE;}
{lt}    { adjust();return LT;}
{equal} { adjust();return EQUAL;}
{assign}    { adjust();return ASSIGN;}
{mod}   { adjust();return MOD;}
{dotdot}    { adjust();return DOTDOT;}
{semi}  { adjust();return SEMI;}
{and}   { adjust();return AND;}
{array} { adjust();return ARRAY;}
{begin} { adjust();return BEGIN_TOKEN;}
{case}  { adjust();return CASE;}
{const} { adjust();return CONST;}
{do}    { adjust();return DO;}
{downto}    { adjust();return DOWNTO;}
{else}  { adjust();return ELSE;}
{end}   { adjust();return END;}
{for}   { adjust();return FOR;}
{function}  { adjust();return FUNCTION;}
{goto}  { adjust();return GOTO;}
{if}    { adjust();return IF;}
{of}    { adjust();return OF;}
{or}    { adjust();return OR;}
{procedure} { adjust();return PROCEDURE;}
{program}   { adjust();return PROGRAM;}
{record}    { adjust();return RECORD;}
{repeat}    { adjust();return REPEAT;}
{then}  { adjust();return THEN;}
{to}    { adjust();return TO;}
{type}  { adjust();return TYPE;}
{until} { adjust();return UNTIL;}
{var}   { adjust();return VAR;}
{while} { adjust();return WHILE;}

{sys_con}   { adjust();return SYS_CON;}
{sys_funct} { adjust();return SYS_FUNCT;}   
{sys_proc}  { adjust();return SYS_PROC;}
{sys_type}  { adjust();return SYS_TYPE;}

{name}  { adjust();return NAME;}
{string}	{ adjust();return install_str();}
{integer}   { adjust();return INTEGER;}
{real}  { adjust();return REAL;}

.   { adjust();EM_error(EM_tokPos, "Illegal Token!");}

%%

int yywrap(void){charPos=1;return 1;} 

int install_str() {
	/* string max length = 15 */
	
	int len = 0;
	char c;
	while ((c = input()) != '\'') {
		/*if (len < 15) yylval->stringval[len] = c;*/
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

void adjust(void)
{
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