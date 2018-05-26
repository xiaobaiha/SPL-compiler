%{  
#include <stdio.h>  
#include "token.h"

int cur_line_num = 1;

int yylex(void);
int yyerror(char *s);
void init_scanner();
void lex_error(char* msg, int line);
%}
delim   [" "\t]
whitespace  {delim}+
digit 	[0-9]
integer {digit}+
float_num   {digit}+\.{digit}+

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
mod "mod"
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
in  "in"
of  "of"
or  "or"
packed  "packed"
procedure   "procedure"
program "program"
record  "record"
repeat  "repeat"
set "set"
then    "then"
to  "to"
type    "type"
until   "until"
var "var"
while   "while"
with    "with"

sys_con     "true"|"maxint"|"false"
sys_funct   "abs"|"chr"|"odd"|"ord"|"pred"|"sqr"|"sqrt"|"succ"
sys_proc    "write"|"writeln"
sys_type    "boolean"|"char"|"integer"|"real"

name    [a-zA-Z][_a-zA-Z0-9]*
%%
[\n]    { cur_line_num++;}
{whitespace} {/* do nothing*/}
"{"[^{}]*"}" 	{/* ignore comments */}

{lp}    {return LP;}
{rp}    {return RP;}
{lb}    {return LB;}
{rb}    {return RB;}
{dot}   {return DOT;}
{comma} {return COMMA;}
{colon} {return COLON;}
{mul}   {return MUL;}
{div}   {return DIV;}
{unequal}   {return UNEQUAL;}
{not}   {return NOT;}
{plus}  {return PLUS;}
{minus} {return MINUS;}
{ge}    {return GE;}
{gt}    {return GT;}
{le}    {return LE;}
{lt}    {return LT;}
{equal} {return EQUAL;}
{assign}    {return ASSIGN;}
{mod}   {return MOD;}
{dotdot}    {return DOTDOT;}
{semi}  {return SEMI;}
{and}   {return AND;}
{array} {return ARRAY;}
{begin} {return BEGIN_TOKEN;}
{case}  {return CASE;}
{const} {return CONST;}
{do}    {return DO;}
{downto}    {return DOWNTO;}
{else}  {return ELSE;}
{end}   {return END;}
{for}   {return FOR;}
{function}  {return FUNCTION;}
{goto}  {return GOTO;}
{if}    {return IF;}
{in}    {return IN;}
{mod}   {return MOD;}
{of}    {return OF;}
{or}    {return OR;}
{packed}    {return PACKED;}
{procedure} {return PROCEDURE;}
{program}   {return PROGRAM;}
{record}    {return RECORD;}
{repeat}    {return REPEAT;}
{set}   {return SET;}
{then}  {return THEN;}
{to}    {return TO;}
{type}  {return TYPE;}
{until} {return UNTIL;}
{var}   {return VAR;}
{while} {return WHILE;}
{with}  {return WITH;}

{sys_con}   {return SYS_CON;}
{sys_funct} {return SYS_FUNCT;}   
{sys_proc}  {return SYS_PROC;}
{sys_type}  {return SYS_TYPE;}

{name}  {return NAME;}
{integer}   {return INTEGER;}
{float_num} {return FLOAT_NUM;}

%%

int yywrap(void){return 1;} 

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