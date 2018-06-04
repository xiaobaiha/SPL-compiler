%{
#include <stdio.h>
#include <stdlib.h>
#include "absyn.h"

extern FILE *yyin;
int yylex(void);
void yyerror(char *s);
%}

enum SYS_CON0{SYS_CON_FALSE, SYS_CON_TRUE, SYS_CON_MAXINT} conval;
enum SYS_FUNCT0{SYS_FUNCT_ABS, SYS_FUNCT_CHR, SYS_FUNCT_ODD, 
        SYS_FUNCT_ORD, SYS_FUNCT_PRED, SYS_FUNCT_SQR, SYS_FUNCT_SQRT, SYS_FUNCT_SUCC} functval;
enum SYS_PROC0{SYS_PROC_WRITE, SYS_PROC_WRITELN} procval;
SysType typeval;
int ival;
double fval;
char cval;
char* sval;

%token<sval> NAME

%token LP RP LB RB DOT COMMA COLON
%token MUL DIV UNEQUAL NOT PLUS MINUS
%token GE GT LE LT EQUAL ASSIGN MOD DOTDOT
%token SEMI AND
%token ARRAY BEGIN_TOKEN CASE CONST DO DOWNTO ELSE END
%token FOR FUNCTION GOTO IF
%token OF OR PROCEDURE 
%token PROGRAM RECORD REPEAT THEN 
%token TO TYPE UNTIL VAR WHILE
%token READ

%token<conval> SYS_CON 
%token<functval> SYS_FUNCT 
%token<procval>SYS_PROC 
%token<typeval>SYS_TYPE 

%token<ival> INTEGER 
%token<cval> CHAR 
%token<fval> REAL 
%token<sval> STRING

%%
program 
    : program_head routine DOT    {$$ = A_Fuction_Program($1, $2);}
program_stmt: program_head  routine  DOT 
{
    $$ = A_Fuction_Program($1, $2);
}
program_head: PROGRAM  NAME  SEMI 
{
    $$ = $2;
}
;
routine: routine_head  routine_body 
{
    $$ = A_Fuction_Routine($1, $2);
}
;
sub_routine: routine_head  routine_body 
{
    $$ = A_Fuction_Routine($1, $2);
}
;

routine_head: label_part  const_part  type_part  var_part  routine_part 
{
    $$ = A_Fuction_RoutineHead($2, $3, $4, $5);
}
;
label_part: {}
;
const_part: CONST const_expr_list 
{
    $$ = $2;
}
    | 
    {
        $$ = NULL;
    }
;
const_expr_list: const_expr_list  const_dec 
{
    $$ = A_Fuction_DecList($2, $1);      
}
        |  const_dec 
        {
            $$ = A_Fuction_DecList($1, NULL);
        }
;    /* ?  */
const_dec
    : NAME EQUAL const_value SEMI     {$$ = A_Fuction_ConstDec(S_Symbol($1), $3);}

const_value: INTEGER 
{
    $$ = A_Fuction_Integer(@1, $1);
}
    |  REAL 
    {
        $$ = A_Fuction_Real(@1, $1);
    }
    |  CHAR 
    {
        $$ = A_Fuction_Char(@1, $1);
    }
    |  STRING 
    {
        $$ = A_Fuction_String(@1, $1);
    }
    |  SYS_CON 
    {
        switch($1)
        {
            case SYS_CON_FALSE: $$ = A_Fuction_Bool(@1, 0); break;
            case SYS_CON_TRUE: $$ = A_Fuction_Bool(@1, 1); break;
            case SYS_CON_MAXINT: $$ = A_Fuction_Integer(@1, 32767);break;
        };
    }
type_part: TYPE type_decl_list 
{
    $$ = $2;
}
    | { $$ = NULL; }
;

type_decl_list: type_decl_list  type_definition 
{
    $$ = A_Fuction_DecList($2, $1);
}
    | type_definition 
    {
        $$ = A_Fuction_DecList($1, NULL);
    }
;
type_definition: NAME  EQUAL  type_decl  SEMI 
{
    $$ = A_Fuction_TypeDec(S_Symbol($1), $3);
}
;
type_decl:
    simple_type_decl 
    {
        $$ = A_Fuction_SimpleType($1);
    }
    |  array_type_decl 
    { 
        $$ = A_Fuction_ArrayType($1);
    }
    |  record_type_decl 
    { 
        $$ = A_Fuction_RecordType($1);
    };
simple_type_decl: 
    SYS_TYPE 
    {
        $$ = A_Fuction_SimpleSysType($1); 
    }
    |  NAME 
    {
        $$ = A_Fuction_SimpleNameType(S_Symbol($1));
    }
    |  LP  name_list  RP 
    {
        $$ = A_Fuction_SimpleNameListType($2);
    }
    |  const_value  DOTDOT  const_value 
    {
        $$ = A_Fuction_ConstRange($1, $3);  
    }
    |  MINUS  const_value  DOTDOT  const_value 
    {
        $2->u.integer *= -1;
        $$ = A_Fuction_ConstRange($2, $4);
    }
    |  MINUS  const_value  DOTDOT  MINUS  const_value {
        $2->u.integer *= -1;
        $5->u.integer *= -1;
        $$ = A_Fuction_ConstRange($2, $5);
    }
    |  NAME  DOTDOT  NAME 
    {
        $$ = A_Fuction_NameRange(S_Symbol($1), S_Symbol($3));
    }
;
array_type_decl:
    ARRAY  LB  simple_type_decl  RB  OF  type_decl 
    {
        $$ = A_Array($3, $6);
    }
;
record_type_decl:
    RECORD  field_decl_list  END {  $$ = $2;  }
;
field_decl_list:
    field_decl_list  field_decl 
    {
        $$ = A_Fuction_FieldList($2, $1);
    }
    | field_decl 
    {
        $$ = A_Fuction_FieldList($1, NULL);
    }
;
field_decl:
    name_list  COLON  type_decl  SEMI
    {
        A_Fuction_Field($1, $3);
    }
;
name_list:
    name_list  COMMA  NAME 
    {
        $$ = A_Fuction_NameList(A_Fuction_Name(@3, $3), $1);
    }
    | NAME 
    {
        $$ = A_Fuction_NameList(A_Fuction_Name(@1, $1), NULL);
    };
var_part: VAR  var_decl_list 
{
    $$ = $2;
}
    | { $$ = NULL; }
;
var_decl_list :
    var_decl_list  var_decl 
    {
        $$ = A_Fuction_DecList(A_Fuction_VarDec(@2, $2), $1);
    }
    | var_decl 
    {
        $$ = A_Fuction_DecList(A_Fuction_VarDec(@1, $1), NULL);
    };
var_decl:
    name_list  COLON  type_decl  SEMI 
    {
        $$ = A_Fuction_VarDecList($1, $3);
    };
routine_part
    : routine_part function_decl                    {$$ = A_Fuction_DecList($2, $1);}
    | routine_part procedure_decl                   {$$ = A_Fuction_DecList($2, $1);}
    | function_decl                                 {$$ = A_Fuction_DecList($1, NULL);}
    | procedure_decl                                {$$ = A_Fuction_DecList($1, NULL);}
    |                                               {$$ = NULL;}

function_decl :
    function_head  SEMI  sub_routine  SEMI 
    {
        $$ = A_Fuction_RoutinePartDec(A_Fuction_RoutinePart($1, $3));
    };
function_head :
    FUNCTION  NAME  parameters  COLON  simple_type_decl 
    {
        $$ = A_Fuction_FuncHead(S_Symbol($2), $3, $5);
    };
procedure_decl :
    procedure_head  SEMI  sub_routine  SEMI 
    {
        $$ = A_Fuction_RoutinePartDec(A_Fuction_RoutinePart($1, $3));
    };
procedure_head :
    PROCEDURE NAME parameters 
    {
        $$ = A_Fuction_ProcHead(S_Symbol($2), $3);
    };
parameters:
    LP  para_decl_list  RP 
    {
        $$ = $2;
    }
    | { $$ = NULL; };
para_decl_list:
    para_decl_list  SEMI  para_type_list 
    {
        $$ = A_Fuction_ParaList($3, $1);
    }
    | para_type_list 
    {
        $$ = A_Fuction_ParaList($1, NULL);
    };
para_type_list:
    var_para_list COLON  simple_type_decl 
    {
        $$ = A_Fuction_VarParaField($1, $3);        
    };
var_para_list:
    VAR name_list 
    {
        $$ = $2;
    };
    | name_list 
    {
        $$ = $1;
    };
routine_body: compound_stmt 
{
    $$ = $1->u.compoundStmt.substmtList;
}
;
compound_stmt: BEGIN_TOKEN  stmt_list  END 
{
    $$ = A_Fuction_CompoundStatement($2);
}
;
stmt_list:
    stmt_list  stmt  SEMI 
    {
        $$ = A_Fuction_StatementList($2, $1);
    }
    | { $$ = NULL; }
;
stmt:
    INTEGER  COLON non_label_stmt 
    {
        $$ = A_Fuction_LabelStatement($1, $3);
    }
    |  non_label_stmt
    {
        $$ = $1;
    };
non_label_stmt
    : assign_stmt                               {$$ = $1;}
    | proc_stmt                                 {$$ = $1;}
    | compound_stmt                             {$$ = $1;}
    | if_stmt                                   {$$ = $1;}
    | repeat_stmt                               {$$ = $1;}
    | while_stmt                                {$$ = $1;}
    | for_stmt                                  {$$ = $1;}
    | case_stmt                                 {$$ = $1;}
    | goto_stmt                                 {$$ = $1;}

assign_stmt: NAME  ASSIGN  expression 
{
    $$ = A_Fuction_AssignStatement(A_Fuction_Var(@1, $1), $3);
}
    | NAME LB expression RB ASSIGN expression 
    {
        $$ = A_Fuction_AssignStatement(A_Fuction_ArrayElement(@1, $1, $3), $6);
    }
    | NAME  DOT  NAME  ASSIGN  expression 
    {
        $$ = A_Fuction_AssignStatement(A_Fuction_RecordField(@1, $1, $3), $5);
    }
;
proc_stmt:     NAME 
{
    $$ = A_Fuction_ProcStatement(A_Fuction_Proc($1, NULL));
}
    |  NAME  LP  args_list  RP 
    {
        $$ = A_Fuction_ProcStatement(A_Fuction_Proc($1, $3));
    }
    |  SYS_PROC 
    { 
        switch($1)
        {
        case SYS_PROC_WRITE: $$ = A_Fuction_ProcStatement(A_Fuction_Proc(S_Symbol("write"), NULL)); break;
        case SYS_PROC_WRITELN: $$ = A_Fuction_ProcStatement(A_Fuction_Proc(S_Symbol("writeln"), NULL)); break;
        }
    }
    |  SYS_PROC  LP  expression_list  RP 
    {
        {   switch($1)
            {
            case SYS_PROC_WRITE: $$ = A_Fuction_ProcStatement(A_Fuction_Proc(S_Symbol("write"), $3)); break;
            case SYS_PROC_WRITELN: $$ = A_Fuction_ProcStatement(A_Fuction_Proc(S_Symbol("writeln"), $3)); break;
            }
        }
    }
    |  READ  LP  factor  RP 
    {
        $$ = A_Fuction_ProcStatement(A_Fuction_Proc(S_Symbol("read"), A_Fuction_ExpList($3, NULL)));
    }
;
/* ? */
if_stmt
    : IF expression THEN stmt else_clause       {$$ = A_Fuction_IfStatement($2, $4, $5);}
else_clause
    : ELSE stmt                                   {$$ = $2;}
    |                                             {$$ = NULL;}
;
repeat_stmt: REPEAT  stmt_list  UNTIL  expression 
{
    $$ = A_Fuction_RepeatStatement($4, $2);
};
while_stmt: WHILE  expression  DO stmt 
{
    $$ = A_Fuction_WhileStatement($2, $4);
};
for_stmt:     FOR  NAME  ASSIGN  expression  direction  expression  DO stmt 
{
    $$ = A_Fuction_ForStatement(A_Fuction_Var(@2, $2), $4, $5, $6, $8);
};
direction:  TO 
{   $$ = 1;   }
    | DOWNTO 
    { $$ = -1; }
;
case_stmt:     CASE expression OF case_expr_list  END 
{
    $$ = A_Fuction_CaseStatement($2, $4);
};
case_expr_list: case_expr_list  case_expr 
{   
    $$ = A_Fuction_CaseList($2, $1);
}
    | case_expr 
    { 
        $$ = A_Fuction_CaseList($1, NULL);
    }
;
case_expr:     const_value  COLON  stmt  SEMI 
{ 
    $$ = A_Fuction_Case($1, NULL, $3);
}
    |  NAME  COLON  stmt  SEMI 
    { 
        $$ = A_Fuction_Case(NULL, $1, $3);
    }
;
goto_stmt: GOTO  INTEGER { $$ = A_Fuction_GotoStatement($2); }
;

expression_list: expression_list  COMMA  expression 
{
    $$ = A_Fuction_ExpList($3, $1);
}
    | expression 
    {
        $$ = A_Fuction_ExpList($1, NULL);
    }
;
expression: expression  GE  expr 
{
    $$ = A_Fuction_OpExp(A_geOp, $1, $3);
}
    |  expression  GT  expr { $$ = A_Fuction_OpExp(A_gtOp, $1, $3); }
    |  expression  LE  expr { $$ = A_Fuction_OpExp(A_leOp, $1, $3); }
    |  expression  LT  expr { $$ = A_Fuction_OpExp(A_ltOp, $1, $3); }
    |  expression  EQUAL  expr { $$ = A_Fuction_OpExp(A_eqOp, $1, $3); }
    |  expression  UNEQUAL  expr { $$ = A_Fuction_OpExp(A_neqOp, $1, $3); }
    |  expr { $$ = $1; }
;
expr: expr  PLUS  term 
{
    $$ = A_Fuction_OpExp(A_plusOp, $1, $3);
}
    |  expr  MINUS  term 
    {
        $$ = A_Fuction_OpExp(A_minusOp, $1, $3);    
    }
    |  expr  OR  term 
    {
        $$ = A_Fuction_OpExp(A_orOp, $1, $3);
    }
    |  term 
    {
        $$ = $1;
    }
;
term: term  MUL  factor 
{
    $$ = A_Fuction_OpExp(A_mulOp, $1, $3);
}
    |  term  DIV  factor
    {
        $$ = A_Fuction_OpExp(A_divOp, $1, $3);
    }
    |  term  MOD  factor 
    {
        $$ = A_Fuction_OpExp(A_modOp, $1, $3);
    }
    |  term  AND  factor 
    {
        $$ = A_Fuction_OpExp(A_andOp, $1, $3);
    }
    |  factor 
    {
        $$ = $1;
    }
;
factor: NAME 
{
    $$ = A_Fuction_NameExp(S_Symbol($1));
}
    |  NAME  LP  args_list  RP 
    {
        $$ = A_Fuction_FuncExp(A_Fuction_Proc(S_Symbol($1), $3));
    }
    |  SYS_FUNCT 
    { 
        switch($1)
        {
            case SYS_FUNCT_ABS: $$ = A_Fuction_FuncExp(A_Fuction_Proc(S_Symbol("abs"), NULL)); break;
            case SYS_FUNCT_CHR: $$ = A_Fuction_FuncExp(A_Fuction_Proc(S_Symbol("chr"), NULL)); break;
            case SYS_FUNCT_ODD: $$ = A_Fuction_FuncExp(A_Fuction_Proc(S_Symbol("odd"), NULL)); break;
            case SYS_FUNCT_ORD: $$ = A_Fuction_FuncExp(A_Fuction_Proc(S_Symbol("ord"), NULL)); break;
            case SYS_FUNCT_PRED: $$ = A_Fuction_FuncExp(A_Fuction_Proc(S_Symbol("pred"), NULL)); break;
            case SYS_FUNCT_SQR: $$ = A_Fuction_FuncExp(A_Fuction_Proc(S_Symbol("sqr"), NULL)); break;
            case SYS_FUNCT_SQRT: $$ = A_Fuction_FuncExp(A_Fuction_Proc(S_Symbol("sqrt"), NULL)); break;
            case SYS_FUNCT_SUCC: $$ = A_Fuction_FuncExp(A_Fuction_Proc(S_Symbol("succ"), NULL)); break;
        }
    }
    |  SYS_FUNCT  LP  args_list  RP 
    {
        switch($1)
        {
            case SYS_FUNCT_ABS: $$ = A_Fuction_FuncExp(A_Fuction_Proc(S_Symbol("abs"), $3)); break;
            case SYS_FUNCT_CHR: $$ = A_Fuction_FuncExp(A_Fuction_Proc(S_Symbol("chr"), $3)); break;
            case SYS_FUNCT_ODD: $$ = A_Fuction_FuncExp(A_Fuction_Proc(S_Symbol("odd"), $3)); break;
            case SYS_FUNCT_ORD: $$ = A_Fuction_FuncExp(A_Fuction_Proc(S_Symbol("ord"), $3)); break;
            case SYS_FUNCT_PRED: $$ = A_Fuction_FuncExp(A_Fuction_Proc(S_Symbol("pred"), $3)); break;
            case SYS_FUNCT_SQR: $$ = A_Fuction_FuncExp(A_Fuction_Proc(S_Symbol("sqr"), $3)); break;
            case SYS_FUNCT_SQRT: $$ = A_Fuction_FuncExp(A_Fuction_Proc(S_Symbol("sqrt"), $3)); break;
            case SYS_FUNCT_SUCC: $$ = A_Fuction_FuncExp(A_Fuction_Proc(S_Symbol("succ"), $3)); break;
        }
    }
/* ? */
    |  const_value { $$ = A_Fuction_ConstExp($1); }
    |  LP  expression  RP { $$ = $2; }
    |  NOT  factor { $$ = A_Fuction_OpExp(A_notOp, NULL, $2); }
    |  MINUS  factor { $$ = A_Fuction_OpExp(A_negOp, NULL, $2); }
    |  NAME  LB  expression  RB { $$ = A_Fuction_VarExp(A_Fuction_ArrayElement($1, $3)); }
    |  NAME  DOT  NAME { $$ = A_Fuction_VarExp(A_Fuction_RecordField($1, $3)); }
;
args_list:     args_list  COMMA  expression 
            {
                $$ = A_Fuction_ExpList($3, $1);
            }
            |  expression 
            {
                $$ = A_Fuction_ExpList($1, NULL);
            }
;
/* ? */
%%
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
