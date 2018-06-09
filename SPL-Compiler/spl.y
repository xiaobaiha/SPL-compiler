%{
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
%}

%union {
    
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
}

%locations



%token LP RP LB RB DOT COMMA COLON
%token MUL DIV UNEQUAL NOT PLUS MINUS
%token GE GT LE LT EQUAL ASSIGN MOD DOTDOT
%token SEMI AND
%token ARRAY BEGIN_TOKEN CASE CONST DO DOWNTO ELSE END
%token FOR FUNCTION GOTO IF
%token OF OR PROCEDURE 
%token PROGRAM RECORD REPEAT THEN 
%token TO TYPE UNTIL VAR WHILE READ

%token<ty_kind> SYS_TYPE
%token<ival> INTEGER
%token<fval> REAL
%token<cval> CHAR 
%token<sval> STRING
%token<sval> NAME

%token<sys_con> SYS_CON
%token<sys_funct> SYS_FUNCT
%token<sys_proc> SYS_PROC

%type<s_symbol> program_head 
%type<a_pro> program_stmt 
%type<a_routine> routine sub_routine
%type<a_routine_head> routine_head
%type<a_stmtList> stmt_list routine_body
%type<a_decList> const_part type_part var_part routine_part const_expr_list type_decl_list var_decl_list routine_decl_list
%type<a_dec> type_definition
%type<a_const> const_value
%type<a_type> type_decl
%type<a_simple_type> simple_type_decl
%type<a_array> array_type_decl
%type<a_fieldList> record_type_decl field_decl_list
%type<a_nameList> name_list var_para_list
%type<a_field> field_decl
%type<a_varDecList> var_decl
%type<a_dec> function_decl procedure_decl
%type<a_routine_part_head> function_head procedure_head
%type<a_paraList> parameters para_decl_list
%type<a_paraField> para_type_list
%type<a_stmt> stmt non_label_stmt assign_stmt proc_stmt compound_stmt if_stmt repeat_stmt while_stmt for_stmt case_stmt goto_stmt
%type<a_exp> expression expr term factor
%type<ival> direction 
%type<a_caseList> case_expr_list
%type<a_case> case_expr
%type<a_expList> expression_list args_list

%nonassoc IFX
%nonassoc ELSE

%start program_stmt

%%
program_stmt: program_head  routine  DOT {
	root = A_Fuction_Program($1, $2);
}
;
program_head: PROGRAM  NAME  SEMI {
	$$ = makeSymbol($2, NULL);
}
;
routine: routine_head  routine_body {
	$$ = A_Fuction_Routine($1, $2);
}
;
sub_routine: routine_head  routine_body {
    $$ = A_Fuction_Routine($1, $2);
}
;

routine_head: label_part  const_part  type_part  var_part  routine_part {
    $$ = A_Routine_head($2, $3, $4, $5);
}
;
label_part: {

}
;
const_part: CONST const_expr_list {
    $$ = $2;
    }
    | {
    $$ = NULL;
    }
;
const_expr_list: const_expr_list  NAME  EQUAL  const_value  SEMI {
		    $$ = A_Fuction_ExprList(A_Fuction_ConstDec(makeSymbol($2, NULL),$4),$1);            
        }
        |  NAME  EQUAL  const_value  SEMI {
		    $$ = A_Fuction_ExprList(A_Fuction_ConstDec(makeSymbol($1, NULL),$3),NULL);
        }
;
const_value: INTEGER {
            $$ = A_Fuction_Integer($1);
            }
            |  REAL {
            $$ = A_Fuction_Real($1);
            }
            |  CHAR {
            $$ = A_Fuction_Char($1);
            }
            |  STRING {
            $$ = A_Fuction_String($1);
            }
            |  SYS_CON {
                switch($1){
			        case SYS_CON_FALSE: $$ = A_Fuction_Bool(0); break;
			        case SYS_CON_TRUE: $$ = A_Fuction_Bool(1); break;
		        }
            };

type_part: TYPE type_decl_list {
            $$ = $2;
            }
            | {
            $$ = NULL;
            };
type_decl_list: type_decl_list  type_definition {
				$$ = A_Fuction_ExprList($2, $1);
                }
                | type_definition {
				$$ = A_Fuction_ExprList($1, NULL);
                }
;
type_definition: NAME  EQUAL  type_decl  SEMI {
				$$ = A_Fuction_TypeDec(makeSymbol($1, NULL),$3);
                }
;   
type_decl:
    simple_type_decl {
    $$ = A_Fuction_SimpleType($1);
    }
    |  array_type_decl {
    $$ = A_Fuction_ArrayType($1); 
    }
    |  record_type_decl { 
    $$ = A_Fuction_RecordType($1);
    };
simple_type_decl: 
    SYS_TYPE {
    $$ = A_Fuction_SimpleSysType($1); 
    }
    |  NAME {
    $$ = A_Fuction_SimpleNameType(makeSymbol($1, NULL));
    }
    |  LP  name_list  RP{
    $$ = A_Fuction_SimpleNameListType($2);
    }
    |  const_value  DOTDOT  const_value {
	$$ = A_Fuction_SimpleRangeType(A_Fuction_ConstRange($1,$3));  
    }
    |  MINUS  const_value  DOTDOT  const_value{
    $2->value.integer *= -1;
    $$ = A_Fuction_SimpleRangeType(A_Fuction_ConstRange($2,$4)); 
    }
    |  MINUS  const_value  DOTDOT  MINUS  const_value{
	$2->value.integer *= -1;
	$5->value.integer *= -1;
	$$ = A_Fuction_SimpleRangeType(A_Fuction_ConstRange($2,$5)); 
	}
    |  NAME  DOTDOT  NAME{
	$$ = A_Fuction_SimpleRangeType(A_Fuction_NameRange(makeSymbol($1, NULL),makeSymbol($3, NULL))); 
	}
;
array_type_decl:
    ARRAY  LB  simple_type_decl  RB  OF  type_decl {
	    $$ = A_Fuction_Array($3->value.range,$6);
    }
;
record_type_decl:
    RECORD  field_decl_list  END { $$ = $2;   }
;
field_decl_list:
    field_decl_list  field_decl {
    $$ = A_Fuction_FieldList($2,$1);
    }
    | field_decl {
	$$ = A_Fuction_FieldList($1, NULL);
    }
;
field_decl:
    name_list  COLON  type_decl  SEMI {
	$$ = A_Fuction_Field($1, $3);
    }
;
name_list:
    name_list  COMMA  NAME {
	$$ = A_Fuction_NameList(A_Fuction_Name(makeSymbol($3, NULL)), $1);
    }
    | NAME {
	$$ = A_Fuction_NameList(A_Fuction_Name(makeSymbol($1, NULL)), NULL);        
    };
var_part: VAR  var_decl_list {
	$$ = $2;
    }
    | {
	$$ = NULL;
    }
;
var_decl_list :
    var_decl_list  var_decl {
	$$ = A_Fuction_ExprList(A_Fuction_VarDec($2),$1);
    }
    | var_decl {
	$$ = A_Fuction_ExprList(A_Fuction_VarDec($1),NULL);
    };
var_decl:
    name_list  COLON  type_decl  SEMI {
	$$ = A_Fuction_VarDecList($1,$3);
    };
routine_part:
	/*empty*/			{$$ = NULL;}
    | routine_decl_list {$$ = $1;}
routine_decl_list: 
      function_decl {$$ = A_Fuction_ExprList($1, NULL);}
    | procedure_decl {$$ = A_Fuction_ExprList($1, NULL);}
    | function_decl routine_decl_list {$$ = A_Fuction_ExprList($1, $2);}
    | procedure_decl routine_decl_list {$$ = A_Fuction_ExprList($1, $2);}
;  
function_decl :
    function_head  SEMI  sub_routine  SEMI {
	    $$ = A_Fuction_RoutinePartDec(A_Fuction_RoutinePart($1, $3))    ;
    };
function_head :
    FUNCTION  NAME  parameters  COLON  simple_type_decl {
	    $$ = A_Fuction_FuncHead(makeSymbol($2, NULL), $3, $5);
    };
procedure_decl :
    procedure_head  SEMI  sub_routine  SEMI {
	    $$ = A_Fuction_RoutinePartDec(A_Fuction_RoutinePart($1, $3));
    };
procedure_head :
    PROCEDURE NAME parameters {
	$$ = A_Fuction_ProcHead(makeSymbol($2, NULL), $3);
    };
parameters:
    LP  para_decl_list  RP {
	$$ = $2;
    }
    | {
	$$ = NULL;
	};
para_decl_list:
    para_decl_list  SEMI  para_type_list {
	$$ = A_Fuction_ParaList($3, $1);
    }
    | para_type_list {
	$$ = A_Fuction_ParaList($1, NULL);
    };
para_type_list:
    var_para_list COLON  simple_type_decl {
    $$ = A_Fuction_VarParaField($1, $3);
    };
var_para_list:
    VAR name_list { 
	$$ = $2;
    };
    | name_list {
	$$ = $1;
    }; 

routine_body: compound_stmt {
			    $$ = $1->value.compoundStmt->substmtList;
            }
;
compound_stmt: BEGIN_TOKEN  stmt_list  END {
                    
				    $$ = A_Fuction_CompoundStatement($2);
                }
;
stmt_list:
    stmt_list  stmt  SEMI {
	    $$ = A_Fuction_StatementList($2, $1);
    }
    |{$$ = NULL;};
stmt:
    INTEGER  COLON non_label_stmt {
	$$ = A_Fuction_LabelStatement($1, $3);
    }
    |  non_label_stmt {
	$$ = $1;
    };
non_label_stmt:
    assign_stmt {
	$$ = $1;
    }
    | proc_stmt {
	$$ = $1;
    }
    | compound_stmt {
	$$ = $1;
    }
    | if_stmt {
	$$ = $1;
    }
    | repeat_stmt {
	$$ = $1;
    }
    | while_stmt {
	$$ = $1;
    }
    | for_stmt {
	$$ = $1;
    }
    | case_stmt {
	$$ = $1;
    }
    | goto_stmt {
	$$ = $1;
    };
assign_stmt: NAME  ASSIGN  expression {
			    $$ = A_Fuction_AssignStatement(A_Fuction_Var(makeSymbol($1, NULL)), $3);
            }
           | NAME LB expression RB ASSIGN expression {
 			    $$ = A_Fuction_AssignStatement(A_Fuction_ArrayElement(makeSymbol($1, NULL), $3), $6);
            }
           | NAME  DOT  NAME  ASSIGN  expression {
		        $$ = A_Fuction_AssignStatement(A_Fuction_RecordField(makeSymbol($1, NULL), makeSymbol($3, NULL)), $5);	
           }
;
proc_stmt:  NAME {
			    $$ = A_Fuction_ProcStatement(A_Fuction_Proc(makeSymbol($1, NULL), NULL));
            }
              |  NAME  LP  args_list  RP {
			    $$ = A_Fuction_ProcStatement(A_Fuction_Proc(makeSymbol($1, NULL), $3));
            }
              | SYS_PROC { 
                    switch($1){
                        case SYS_PROC_WRITE: $$ = A_Fuction_ProcStatement(A_Fuction_Proc(makeSymbol("write", NULL), NULL)); break;
                        case SYS_PROC_WRITELN: $$ = A_Fuction_ProcStatement(A_Fuction_Proc(makeSymbol("writeln", NULL), NULL)); break;
                    }
                }
              | SYS_PROC  LP  expression_list  RP {
                    switch($1){
                        case SYS_PROC_WRITE: $$ = A_Fuction_ProcStatement(A_Fuction_Proc(makeSymbol("write", NULL), $3)); break;
                        case SYS_PROC_WRITELN: $$ = A_Fuction_ProcStatement(A_Fuction_Proc(makeSymbol("read", NULL), $3)); break;
                    }
                }
              | READ  LP  factor  RP {
                    $$ = A_Fuction_ProcStatement(A_Fuction_Proc(makeSymbol("read", NULL), A_Fuction_ExpList($3, NULL)));
                }
;
if_stmt: IF  expression  THEN  stmt %prec IFX{
		$$ = A_Fuction_IfStatement($2, $4, NULL);
        } 
        | IF  expression THEN  stmt ELSE stmt{
		$$ = A_Fuction_IfStatement($2, $4, $6);		
		}            
;
repeat_stmt: REPEAT  stmt_list  UNTIL  expression {
			$$ = A_Fuction_RepeatStatement($4, $2);
            };
while_stmt: WHILE  expression  DO stmt {
			$$ = A_Fuction_WhileStatement($2, $4);
            };
for_stmt:     FOR  NAME  ASSIGN  expression  direction  expression  DO stmt {
      		$$ = A_Fuction_ForStatement(A_Fuction_Var(makeSymbol($2, NULL)), $4, $5, $6, $8);
            };
direction:     TO {
			$$ = 1;
            }
              | DOWNTO {
			  $$ = -1;
              }
;
case_stmt:     CASE expression OF case_expr_list  END {
			$$ = A_Fuction_CaseStatement($2, $4);
            };
case_expr_list: case_expr_list  case_expr {
				$$ = A_Fuction_CaseList($2, $1);
                }
                | case_expr {
				$$ = A_Fuction_CaseList($1, NULL);
                }
;
case_expr:     const_value  COLON  stmt  SEMI {
			$$ = A_Fuction_Case($1, NULL, $3);
            }
              |  NAME  COLON  stmt  SEMI {
			  $$ = A_Fuction_Case(NULL, makeSymbol($1, NULL), $3);
              }
;
goto_stmt: GOTO  INTEGER {
	$$ = A_Fuction_GotoStatement($2);
}
;

expression_list: expression_list  COMMA  expression {
				$$ = A_Fuction_ExpList($3, $1);
                }
                | expression {
				$$ = A_Fuction_ExpList($1, NULL);
                }
;
expression: expression  GE  expr {
			$$ = A_Fuction_OpExp(A_geOp, $1, $3);
            }
            |  expression  GT  expr {
			$$ = A_Fuction_OpExp(A_gtOp, $1, $3);
            }
            |  expression  LE  expr {
			$$ = A_Fuction_OpExp(A_leOp, $1, $3);
            }
            |  expression  LT  expr {
			$$ = A_Fuction_OpExp(A_ltOp, $1, $3);
            }
            |  expression  EQUAL  expr {
			$$ = A_Fuction_OpExp(A_eqOp, $1, $3);
            }
            |  expression  UNEQUAL  expr {
			$$ = A_Fuction_OpExp(A_neqOp, $1, $3);
            }
            |  expr {
			$$ = $1;
            }
;
expr: expr  PLUS  term {
	$$ = A_Fuction_OpExp(A_plusOp, $1, $3);
    }
    |  expr  MINUS  term {
	$$ = A_Fuction_OpExp(A_minusOp, $1, $3);
    }
    |  expr  OR  term {
	$$ = A_Fuction_OpExp(A_orOp, $1, $3);
    }
    |  term {
	$$ = $1;
    }
;
term: term  MUL  factor {
	$$ = A_Fuction_OpExp(A_mulOp, $1, $3);
    }
    |  term  DIV  factor {
	$$ = A_Fuction_OpExp(A_divOp, $1, $3);
    }
    |  term  MOD  factor {
 	$$ = A_Fuction_OpExp(A_modOp, $1, $3);
    }
    |  term  AND  factor {
	$$ = A_Fuction_OpExp(A_andOp, $1, $3);
    }
    |  factor {
	$$ = $1;
    }
;
factor: NAME {
	$$ = A_Fuction_NameExp(makeSymbol($1, NULL));
    }
    |  NAME  LP  args_list  RP {
	$$ = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol($1, NULL), $3));
    }
    |  SYS_FUNCT {
	    switch($1){
			case SYS_FUNCT_ABS: $$ = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("abs", NULL),NULL)); break;
			case SYS_FUNCT_CHR: $$ = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("char", NULL),NULL)); break;
			case SYS_FUNCT_ODD: $$ = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("odd", NULL),NULL)); break;
			case SYS_FUNCT_ORD: $$ = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("ord", NULL),NULL)); break;
			case SYS_FUNCT_PRED: $$ = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("pred", NULL),NULL)); break;
			case SYS_FUNCT_SQR: $$ = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("sqr", NULL),NULL)); break;
			case SYS_FUNCT_SQRT: $$ = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("sqrt", NULL),NULL)); break;
			case SYS_FUNCT_SUCC: $$ = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("succ", NULL),NULL)); break;
		}
    }
    |  SYS_FUNCT  LP  args_list  RP {
        switch($1){
			case SYS_FUNCT_ABS: $$ = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("abs", NULL),$3)); break;
			case SYS_FUNCT_CHR: $$ = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("char", NULL),$3)); break;
			case SYS_FUNCT_ODD: $$ = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("odd", NULL),$3)); break;
			case SYS_FUNCT_ORD: $$ = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("ord", NULL),$3)); break;
			case SYS_FUNCT_PRED: $$ = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("pred", NULL),$3)); break;
			case SYS_FUNCT_SQR: $$ = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("sqr", NULL),$3)); break;
			case SYS_FUNCT_SQRT: $$ = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("sqrt", NULL),$3)); break;
			case SYS_FUNCT_SUCC: $$ = A_Fuction_FuncExp(A_Fuction_Proc(makeSymbol("succ", NULL),$3)); break;
		}
    }
    |  const_value {
	$$ = A_Fuction_ConstExp($1);

    }
    |  LP  expression  RP {
	$$ = $2;
    }
    |  NOT  factor {
	$$ = A_Fuction_OpExp(A_notOp, NULL, $2);
    }
    |  MINUS  factor {
	$$ = A_Fuction_OpExp(A_negOp, NULL, $2);
    }
    |  NAME  LB  expression  RB {
	$$ = A_Fuction_VarExp(A_Fuction_ArrayElement(makeSymbol($1, NULL), $3));
    }
    |  NAME  DOT  NAME {
	$$ = A_Fuction_VarExp(A_Fuction_RecordField(makeSymbol($1, NULL), makeSymbol($3, NULL)));
    }
;
args_list:     args_list  COMMA  expression {
			$$ = A_Fuction_ExpList($3, $1);
            }
            |  expression {
			$$ = A_Fuction_ExpList($1, NULL);
            }
;


%%
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
