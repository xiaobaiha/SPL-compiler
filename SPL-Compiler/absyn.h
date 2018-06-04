/*
 * absyn.h - Abstract Syntax Header
 *
 * All types and functions declared in this header file begin with "A_"
 * Linked list types end with "..List"
 */

#include "symbol.h"
#include "types.h"

#ifndef _ABSYN_H
#define _ABSYN_H

/* Type Definitions */
typedef int A_pos;
typedef struct A_pro_ *A_pro;
typedef struct A_routine_ *A_routine;
typedef struct A_routine_head_ *A_routine_head;
typedef struct A_dec_ *A_dec;
typedef struct A_const_ *A_const;
typedef struct A_type_ *A_type;
typedef struct A_simple_type_ *A_simple_type;
typedef struct A_array_ *A_array;
typedef struct A_range_ *A_range;
typedef struct A_name_ *A_name;
typedef struct A_field_ *A_field;
typedef struct A_stmt_ *A_stmt;
typedef struct A_case_ *A_case;
typedef struct A_proc_ *A_proc;
typedef struct A_exp_ *A_exp;
typedef struct A_var_ *A_var;
typedef struct A_routine_part_head_ *A_routine_part_head;
typedef struct A_routine_part_ *A_routine_part;
typedef struct A_varDecList_ *A_varDecList;
typedef struct A_paraList_ *A_paraList;
typedef struct A_paraField_ *A_paraField;
typedef struct A_decList_ *A_decList;
typedef struct A_nameList_ *A_nameList;
typedef struct A_fieldList_ *A_fieldList;
typedef struct A_stmtList_ *A_stmtList;
typedef struct A_caseList_ *A_caseList;
typedef struct A_expList_ *A_expList;
typedef struct A_assignStmt_ *A_assign;
typedef struct A_compoundStmt_ *A_compound;
typedef struct A_ifStmt_ A_if;
typedef struct A_repeatStmt_ A_repeat;
typedef struct A_whileStmt_ A_while;
typedef struct A_forStmt_ A_for;
typedef struct A_caseStmt_  A_caseStatement;
typedef struct A_gotoStmt_ A_goto;
typedef struct A_op_* A_op;
typedef Ty_kind A_sysType;
typedef enum
{
  A_plusOp,
  A_minusOp,
  A_mulOp,
  A_divOp,
  A_modOp,
  A_eqOp,
  A_neqOp,
  A_ltOp,
  A_gtOp,
  A_leOp,
  A_geOp,
  A_orOp,
  A_andOp,
  A_notOp,
  A_negOp,
} A_operation;

struct A_assignStmt_
{
  A_var var;
  A_exp exp;
};
struct A_compoundStmt_
{
  A_stmtList substmtList;
} ;

struct A_ifStmt_
{
  A_exp test;
  A_stmt thenStmt;
  A_stmt elseStmt;
};

struct A_repeatStmt_
{
  A_exp test;
  A_stmtList body;
};

struct A_whileStmt_
{
  A_exp test;
  A_stmt body;
};

struct A_forStmt_
{
  A_var var;
  A_exp initValue;
  int direction;
  A_exp finalValue;
  A_stmt body;
};

struct A_caseStmt_
{
  A_exp test;
  A_caseList caselist;
};

struct A_gotoStmt_
{
  int label;
};

struct A_op_
{
  A_operation oper;
  A_exp left;
  A_exp right;
};

struct A_pro_
{
  A_pos pos;
  table_t name;
  A_routine routine;
};

struct A_routine_
{
  A_pos pos;
  A_routine_head head;
  A_stmtList compoundStmt;
};

struct A_routine_head_
{
  A_pos pos;
  A_decList constPart;
  A_decList typePart;
  A_decList varPart;
  A_decList routinePart;
};

struct A_dec_
{
  enum
  {
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
  } value;
};

struct A_const_
{
  A_pos pos;
  A_sysType kind;
  union {
    int integer;
    double real;
    char ch;
    char *str;
    int boolean;
  } value;
};

typedef union {
  A_const con;
  table_t name;
} A_range_value;

struct A_range_
{
  enum
  {
    A_constRange,
    A_nameRange
  } kind;
  A_pos pos;
  A_range_value lower_value;
  A_range_value upper_value;
};

struct A_simple_type_
{
  A_pos pos;
  enum
  {
    A_simpleSysType,
    A_simpleNameType,
    A_simpleNameListType,
    A_simpleRangeType
  } kind;
  union {
    A_sysType sysType;
    table_t name;
    A_nameList nameList;
    A_range range;
  } value;
};

struct A_array_
{
  A_pos pos;
  A_range range;
  A_type type;
};

struct A_type_
{
  enum
  {
    A_simpleType,
    A_arrayType,
    A_recordType
  } kind;
  A_pos pos;
  union {
    A_simple_type simple;
    A_array array;
    A_fieldList fieldList;
  } value;
};

struct A_name_
{
  A_pos pos;
  table_t name;
};

struct A_field_
{
  A_pos pos;
  A_nameList name_list;
  A_type type_decl;
};

struct A_varDecList_
{
  A_pos pos;
  A_nameList name_list;
  A_type type_decl;
};

struct A_routine_part_head_
{
  A_pos pos;
  table_t name;
  A_paraList parameters;
  A_simple_type simpleType;
};

struct A_routine_part_
{
  A_routine_part_head head;
  A_routine subRoutine;
};

struct A_paraList_
{
  A_paraField field;
  A_paraList next;
};

struct A_paraField_
{
  enum{Var_type, Value_type} kind;
  A_pos pos;
  A_simple_type simpleType;
  A_nameList nameList;
};

struct A_stmt_
{
  enum
  {
    A_assignStmt,
    A_procStmt,
    A_compundStmt,
    A_ifStmt,
    A_repeatStmt,
    A_whileStmt,
    A_forStmt,
    A_caseStmt,
    A_gotoStmt
  } kind;
  A_pos pos;
  int label;
  union {
    A_assign assignStmt;
    A_proc procStmt;
    A_if ifStmt;
    A_repeat repeatStmt;
    A_while whileStmt;
    A_for forStmt;
    A_caseStatement caseStmt;
    A_goto gotoStmt;
    A_compound compoundStmt;
  } value;
};

struct A_case_
{
  A_pos pos;
  A_const constValue;
  table_t name;
  A_stmt body;
};

struct A_exp_
{
  enum
  {
    A_funcExp,
    A_nameExp,
    A_varExp,
    A_constExp,
    A_opExp
  } kind;
  A_pos pos;
  A_type valueType;
  union {
    A_proc func;
    A_var var;
    A_const constValue;
    A_op op;
    table_t name;
  } value;
};

struct A_proc_
{
  int kind;
  A_pos pos;
  table_t name;
  A_expList args;
};

struct A_var_
{
  enum
  {
    A_pureID,
    A_arrayElement,
    A_recordField
  } kind;
  table_t ID;
  A_type valueType;
  union {
    A_exp subscript;
    table_t fieldID;
  } value;
};

// List
struct A_decList_
{
  A_dec head;
  A_decList next;
};

struct A_nameList_
{
  A_name head;
  A_nameList next;
};

struct A_fieldList_
{
  A_field head;
  A_fieldList next;
};
struct A_stmtList_
{
  A_stmt head;
  A_stmtList next;
};

struct A_caseList_
{
  A_case head;
  A_caseList next;
};

struct A_expList_
{
  A_exp head;
  A_expList next;
};

// Function declaration
A_pro A_Fuction_Program(A_pos pos, table_t name, A_routine routine);
A_routine A_Fuction_Routine(A_pos pos, A_routine_head head, A_stmtList compoundStmt);
A_routine_head A_Routine_head(A_pos pos, A_decList constPart, A_decList typePart, A_decList varPart, A_decList routinePart);
A_decList A_Fuction_DecList(A_dec head, A_decList next);
A_dec A_Fuction_ConstDec(A_pos pos, table_t name, A_const value);
A_const A_Fuction_Integer(A_pos pos, int i);
A_const A_Fuction_Real(A_pos pos, double r);
A_const A_Fuction_Char(A_pos pos, char c);
A_const A_Fuction_String(A_pos pos, char *s);
A_const A_Fuction_Bool(A_pos pos, int b);
A_dec A_Fuction_TypeDec(A_pos pos, table_t name, A_type type);
A_type A_Fuction_SimpleType(A_pos pos, A_simple_type simple);
A_simple_type A_Fuction_SimpleSysType(A_pos pos, A_sysType systype);
A_simple_type A_Fuction_SimpleRangeType(A_pos pos, A_range range);
A_simple_type A_Fuction_SimpleNameType(A_pos pos, table_t name);
A_simple_type A_Fuction_SimpleNameListType(A_pos pos, A_nameList namelist);
A_range A_Fuction_ConstRange(A_pos pos, A_const lo, A_const up);
A_range A_Fuction_NameRange(A_pos pos, table_t lo, table_t up);
A_nameList A_Fuction_NameList(A_name head, A_nameList next);
A_name A_Fuction_Name(A_pos pos, table_t name);
A_array A_Fuction_Array(A_pos pos, A_range range, A_type type);
A_type A_Fuction_ArrayType(A_pos pos, A_array array);
A_type A_Fuction_RecordType(A_pos pos, A_fieldList fieldList);
A_fieldList A_Fuction_FieldList(A_field head, A_fieldList next);
A_field A_Fuction_Field(A_pos pos, A_nameList nameList, A_type type);
A_dec A_Fuction_VarDec(A_pos pos, A_varDecList var);
A_varDecList A_Fuction_VarDecList(A_pos pos, A_nameList nameList, A_type type);
A_dec A_Fuction_RoutinePartDec(A_pos pos, A_routine_part routine);
A_routine_part A_Fuction_RoutinePart(A_routine_part_head head, A_routine subRoutine);
A_routine_part_head A_Fuction_FuncHead(A_pos pos, table_t name, A_paraList parameters, A_simple_type simpleType);
A_routine_part_head A_Fuction_ProcHead(A_pos pos, table_t name, A_paraList parameters);
A_paraList A_Fuction_ParaList(A_paraField field, A_paraList next);
A_paraField A_Fuction_VarParaField(A_pos pos, A_nameList nameList, A_simple_type simpleType);
A_paraField A_Fuction_ValParaField(A_pos pos, A_nameList nameList, A_simple_type simpleType);
A_var A_Fuction_Var(A_pos pos, table_t ID);
A_var A_Fuction_ArrayElement(A_pos pos, table_t ID, A_exp subscript);
A_var A_Fuction_RecordField(A_pos pos, table_t ID, table_t fieldID);
A_proc A_Fuction_Proc(A_pos pos, table_t function, A_expList args);
// Statement
A_stmtList A_Fuction_StatementList(A_stmt head, A_stmtList next);
A_stmt A_Fuction_LabelStatement(A_pos pos, int label, A_stmt stmt);
A_stmt A_Fuction_AssignStatement(A_pos pos, A_var var, A_exp exp);
A_stmt A_Fuction_ProcStatement(A_pos pos, A_proc proc);
A_stmt A_Fuction_CompoundStatement(A_pos pos, A_stmtList substmtList);
A_stmt A_Fuction_IfStatement(A_pos pos, A_exp test, A_stmt thenStmt, A_stmt elseStmt);
A_stmt A_Fuction_RepeatStatement(A_pos pos, A_exp test, A_stmtList body);
A_stmt A_Fuction_WhileStatement(A_pos pos, A_exp test, A_stmt body);
A_stmt A_Fuction_ForStatement(A_pos pos, A_var var, A_exp initValue, int direction, A_exp finalValue, A_stmt body);
A_stmt A_Fuction_CaseStatement(A_pos pos, A_exp test, A_caseList caselist);
A_stmt A_Fuction_GotoStatement(A_pos pos, int label);
A_caseList A_Fuction_CaseList(A_case head, A_caseList next);
A_case A_Fuction_Case(A_pos pos, A_const constValue, table_t name, A_stmt body); // const or name
// Expression
A_expList A_Fuction_ExpList(A_exp head, A_expList next);
A_exp A_Fuction_NameExp(A_pos pos, table_t name);
A_exp A_Fuction_VarExp(A_pos pos, A_var var);
A_exp A_Fuction_FuncExp(A_pos pos, A_proc func);
A_exp A_Fuction_ConstExp(A_pos pos, A_const constValue);
A_exp A_Fuction_OpExp(A_pos pos, A_operation oper, A_exp left, A_exp right);

#endif