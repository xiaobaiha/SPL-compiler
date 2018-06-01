/*
 * absyn.h - Abstract Syntax Header
 *
 * All types and functions declared in this header file begin with "A_"
 * Linked list types end with "..List"
 */

#include "symbol.h"
#include "type.h"

#ifndef _ABSYN_H
#define _ABSYN_H

/* Type Definitions */
typedef int A_pos;
typedef struct A_pro_st *A_pro;
typedef struct A_routine_st *A_routine;
typedef struct A_routine_head_st *A_routine_head;
typedef struct A_dec_st *A_dec;
typedef struct A_const_st *A_const;
typedef struct A_type_st *A_type;
typedef struct A_simple_st *A_simple;
typedef struct A_array_st *A_array;
typedef struct A_range_st *A_range;
typedef struct A_name_st *A_name;
typedef struct A_field_st *A_field;
typedef struct A_varDecList_st *A_varDecList;
typedef struct A_routine_part_st *A_routine_part;
typedef struct A_routine_part_head_st *A_routine_part_head;
typedef struct A_paraList_st *A_paraList;
typedef struct A_paraField_st *A_paraField;
typedef struct A_stmt_st *A_stmt;
typedef struct A_case_st *A_case;
typedef struct A_proc_st *A_proc;
typedef struct A_exp_st *A_exp;
typedef struct A_var_st *A_var;
typedef struct A_decList_st *A_decList;
typedef struct A_nameList_st *A_nameList;
typedef struct A_fieldList_st *A_fieldList;
typedef struct A_stmtList_st *A_stmtList;
typedef struct A_caseList_st *A_caseList;
typedef struct A_expList_st *A_expList;
typedef struct A_assignStmt_st {A_var var; A_exp exp;} A_assignS;
typedef struct A_compoundStmt_st {A_stmtList substmtList;} A_compoundS;
typedef struct A_ifStmt_st {A_exp test; A_stmt thenStmt; A_stmt elseStmt;} A_ifS;
typedef struct A_repeatStmt_st {A_exp test; A_stmtList body;} A_repeatS;
typedef struct A_whileStmt_st {A_exp test; A_stmt body;} A_whileS;
typedef struct A_forStmt_st {A_var var; A_exp initValue; int direction; A_exp finalValue; A_stmt body;} A_forS;
typedef struct A_caseStmt_st {A_exp test; A_caseList caselist;} A_caseS;
typedef struct A_gotoStmt_st {int label;} A_gotoS;
typedef struct A_op_st {A_operation oper; A_exp left; A_exp right;} *A_op;

typedef enum {
	boolean = 1,
	character = 2,
	integer = 3,
	real = 4,
	string = 5,
} A_sysType;

typedef enum {
	A_plusOp, 
  A_minusOp, 
  A_mulOp, 
  A_modOp, 
  A_divOp,
	A_eqOp, 
  A_neqOp, 
  A_ltOp, 
  A_leOp, 
  A_gtOp, 
  A_geOp, 
  A_orOp,
	A_andOp, 
  A_notOp, 
  A_negOp,
} A_operation;

typedef enum {
  Var, 
  Value,
} A_paraKind;

typedef enum {
  A_function, 
  A_procedure
} routineKind;

struct A_pro_st{
	A_pos pos;
	table_t name;
	A_routine routine;
};

struct A_routine_st{
	A_pos pos;
	A_routine_head head;
	A_stmtList compoundStmt;
};

struct A_routine_head_st{
	A_pos pos;
	A_decList constPart;
	A_decList typePart;
	A_decList varPart; 
	A_decList routinePart;
};

struct A_dec_st{
	enum {
		A_constDec,
		A_typeDec,
		A_varDec,
		A_routineDec,
	} kind;
	A_pos pos;
	table_t name;
	union {
		A_const value;
		A_type type;
		A_varDecList var;
		A_routine_part routine;
	} u;
};

struct A_const_st {
	A_pos pos;
	A_sysType kind;
	union {
		int integer;
		double real;
		char ch;
		char *str;
		int boolean;
	} u;
};

struct A_range_st{
	enum {A_constRange, A_nameRange} kind;
	A_pos pos;
	union {
		A_const lconst;
		table_t lname;
	} lower_u;
	union {
		A_const uconst;
		table_t uname;
	} upper_u;
};

struct A_simple_st{
	enum {
		A_simpleSysType, 
		A_simpleNameType, 
		A_simpleNameListType, 
		A_simpleRangeType
	} kind;
	A_pos pos;
	union {
		A_sysType sysType;
		table_t name;
		A_nameList nameList;
		A_range range;
	} u;
};

struct A_array_st{
	A_pos pos;
	A_range range;
	A_type type;
};

struct A_type_st {
	enum {
		A_simpleType,
		A_arrayType,
		A_recordType
	} kind;
	A_pos pos;
	union {
		A_simple simple;
		A_array array;
		A_fieldList fieldList;
	} u;			
};

struct A_name_st {
	A_pos pos;
	table_t name;
};

struct A_field_st {
	A_pos pos;
	A_nameList nameList;
	A_type type;
};

struct A_varDecList_st {
	A_pos pos;
	A_nameList nameList;
	A_type type;
};

struct A_routine_part_st {
	A_routine_part_head head;
	A_routine subRoutine;
};

struct A_routine_part_head_st {
	routineKind kind;
	A_pos pos;
	table_t name;
	A_paraList parameters;
	A_simple simpleType;
};


struct A_paraList_st {
	A_paraField field;
	A_paraList next;
};

struct A_paraField_st
{
	A_paraKind kind;
	A_pos pos;
	A_simple simpleType;
	A_nameList nameList;
};

struct A_stmt_st { 
	enum {
		A_assignStmt, A_procStmt, A_compundStmt,
		A_ifStmt, A_repeatStmt, A_whileStmt,
		A_forStmt, A_caseStmt, A_gotoStmt
	} kind;
	A_pos pos;
	int label;
	union{
		A_assignS assignStmt;
		A_proc procStmt;
		A_ifS ifStmt;
		A_repeatS repeatStmt;
		A_whileS whileStmt;
		A_forS forStmt;
		A_caseS caseStmt;
		A_gotoS gotoStmt;
		A_compoundS compoundStmt;
	} u;
};

struct A_case_st {
	A_pos pos;
	A_const constValue;
	table_t name;
	A_stmt body;
};

struct A_exp_st {
	enum {A_funcExp, A_nameExp, A_varExp, A_constExp, A_opExp} kind;
	A_pos pos;
	A_type valueType;
	union{
		A_proc func;
		A_var var;
		A_const constValue;
		A_op op;
		table_t name;
	}u;
};

struct A_proc_st {
	routineKind kind;
	A_pos pos;
	table_t name;
	A_expList args;
};

struct A_var_st
{
	enum {A_pureID, A_arrayElement, A_recordField} kind;
	table_t ID;
	A_type valueType;
	union{
		A_exp subscript;
		table_t fieldID;
	}u;
};

// List
struct A_decList_st {
	A_dec head;
	struct A_decList_st *next;
};

struct A_nameList_st {
	A_name head;
	struct A_nameList_st *next;
};

struct A_fieldList_st {
	A_field head;
	struct A_fieldList_st *next;
};
struct A_stmtList_st {
	A_stmt head;
	struct A_stmtList_st *next;
};

struct A_caseList_st {
	A_case head;
	struct A_caseList_st *next;
};

struct A_expList_st {
	A_exp head;
	struct A_expList_st *next;
};


A_pro A_Program(A_pos pos, table_t name, A_routine routine);
A_routine A_Routine(A_pos pos, A_routine_head head, A_stmtList compoundStmt);
A_routine_head A_Routine_head(A_pos pos, A_decList constPart, A_decList typePart, A_decList varPart, A_decList routinePart);
A_decList A_DecList(A_dec head, A_decList next);
A_dec A_ConstDec(A_pos pos, table_t name, A_const value);
A_const A_Integer(A_pos pos, int i);
A_const A_Real(A_pos pos, double r);
A_const A_Char(A_pos pos, char c);
A_const A_String(A_pos pos, char *s);
A_const A_Bool(A_pos pos, int b);
A_dec A_TypeDec(A_pos pos, table_t name, A_type type);
A_type A_SimpleType(A_pos pos, A_simple simple);
A_simple A_SimpleSysType(A_pos pos, A_sysType systype);
A_simple A_SimpleRangeType(A_pos pos, A_range range);
A_simple A_SimpleNameType(A_pos pos, table_t name);
A_simple A_SimpleNameListType(A_pos pos, A_nameList namelist);
A_range A_ConstRange(A_pos pos, A_const lo, A_const up);
A_range A_NameRange(A_pos pos, table_t lo, table_t up);
A_nameList A_NameList(A_name head, A_nameList next);
A_name A_Name(A_pos pos, table_t name);
A_array A_Array(A_pos pos, A_range range, A_type type);
A_type A_ArrayType(A_pos pos, A_array array);
A_type A_RecordType(A_pos pos, A_fieldList fieldList);
A_fieldList A_FieldList(A_field head, A_fieldList next);
A_field A_Field(A_pos pos, A_nameList nameList, A_type type);
A_dec A_VarDec(A_pos pos, A_varDecList var);
A_varDecList A_VarDecList(A_pos pos, A_nameList nameList, A_type type);
A_dec A_RoutinePartDec(A_pos pos, A_routine_part routine);
A_routine_part A_RoutinePart(A_routine_part_head head, A_routine subRoutine);
A_routine_part_head A_FuncHead(A_pos pos, table_t name, A_paraList parameters, A_simple simpleType);
A_routine_part_head A_ProcHead(A_pos pos, table_t name, A_paraList parameters);
A_paraList A_ParaList(A_paraField field, A_paraList next);
A_paraField A_VarParaField(A_pos pos,A_nameList nameList, A_simple simpleType);
A_paraField A_ValParaField(A_pos pos, A_nameList nameList, A_simple simpleType);
A_var A_Var(A_pos pos, table_t ID);
A_var A_ArrayElement(A_pos pos, table_t ID, A_exp subscript);
A_var A_RecordField(A_pos pos, table_t ID, table_t fieldID);
A_proc A_Proc(A_pos pos, table_t function, A_expList args);
// stmt
A_stmtList A_StmtList(A_stmt head, A_stmtList next);
A_stmt A_LabelStmt(A_pos pos, int label, A_stmt stmt);
A_stmt A_AssignStmt(A_pos pos, A_var var, A_exp exp);
A_stmt A_ProcStmt(A_pos pos, A_proc proc);
A_stmt A_CompoundStmt(A_pos pos, A_stmtList substmtList);
A_stmt A_IfStmt(A_pos pos, A_exp test, A_stmt thenStmt, A_stmt elseStmt);
A_stmt A_RepeatStmt(A_pos pos, A_exp test, A_stmtList body);
A_stmt A_WhileStmt(A_pos pos, A_exp test, A_stmt body);
A_stmt A_ForStmt(A_pos pos, A_var var, A_exp initValue, int direction, A_exp finalValue, A_stmt body);
A_stmt A_CaseStmt(A_pos pos, A_exp test, A_caseList caselist);
A_stmt A_GotoStmt(A_pos pos, int label);
A_caseList A_CaseList(A_case head, A_caseList next);
A_case A_Case(A_pos pos, A_const constValue, table_t name, A_stmt body); // const or name
// Expression
A_expList A_ExpList(A_exp head, A_expList next);
A_exp A_NameExp(A_pos pos, table_t name);
A_exp A_VarExp(A_pos pos, A_var var);
A_exp A_FuncExp(A_pos pos, A_proc func);
A_exp A_ConstExp(A_pos pos, A_const constValue);
A_exp A_OpExp(A_pos pos, A_operation oper, A_exp left, A_exp right);

#endif