/*
 * absyn.c - Abstract Syntax Functions. Most functions create an instance of an
 *           abstract syntax rule.
 */

#include <stdlib.h>
#include <stdio.h>
#include "absyn.h"
#include "symbol.h"
#include "util.h"
#include "types.h"

A_pro A_Fuction_Program(table_t name, A_routine routine)
{
	A_pro p = (A_pro)checked_malloc(sizeof(*p));
	p->name = name;
	p->routine = routine;
	return p;
}

A_routine A_Fuction_Routine(A_routine_head head, A_stmtList compoundStmt)
{
	A_routine p = (A_routine)checked_malloc(sizeof(*p));
	p->head = head;
	p->compoundStmt = compoundStmt;
	return p;
}

A_routine_head A_Routine_head(A_decList constPart, A_decList typePart, A_decList varPart, A_decList routinePart)
{
	A_routine_head p = (A_routine_head)checked_malloc(sizeof(*p));
	p->constPart = constPart;
	p->typePart = typePart;
	p->varPart = varPart; 
	p->routinePart = routinePart;
	return p;
}

A_decList A_Fuction_ExprList(A_dec head, A_decList next)
{
	A_decList p = (A_decList)checked_malloc(sizeof(*p));
	p->head = head;
	p->next = next;
	return p;
}

A_dec A_Fuction_ConstDec(table_t name, A_const value)
{
	A_dec p = (A_dec)checked_malloc(sizeof(*p));
	p->kind = A_constDec;
	p->name = name;
	p->value.value = value;
	return p;
}

A_dec A_Fuction_TypeDec(table_t name, A_type type)
{
	A_dec p = (A_dec)checked_malloc(sizeof(*p));
	p->kind = A_typeDec;
	p->name = name;
	p->value.type = type;
	return p;
}

A_dec A_Fuction_VarDec(A_varDecList var)
{
	A_dec p = (A_dec)checked_malloc(sizeof(*p));
	p->kind = A_varDec;
	p->value.var = var;
	return p;
}

A_dec A_Fuction_RoutinePartDec(A_routine_part routine)
{
	A_dec p = (A_dec)checked_malloc(sizeof(*p));
	p->kind = A_routineDec;
	p->value.routine = routine;
	return p;
}

A_const A_Fuction_Integer(int i)
{
	A_const p = (A_const)checked_malloc(sizeof(*p));
  p->kind = TY_INTEGER;
	p->value.integer = i;
	return p;
}

A_const A_Fuction_Real(double r)
{
	A_const p = (A_const)checked_malloc(sizeof(*p));
	p->kind = TY_REAL;
	p->value.real = r;
	return p;
}

A_const A_Fuction_Char(char c)
{
	A_const p = (A_const)checked_malloc(sizeof(*p));
	p->kind = TY_CHAR;
	p->value.ch = c;
	return p;
}

A_const A_Fuction_String(char *s)
{
	A_const p = (A_const)checked_malloc(sizeof(*p));
	p->kind = TY_STRING;
	p->value.str = s;
	return p;
}

A_const A_Fuction_Bool(int b)
{
	A_const p = (A_const)checked_malloc(sizeof(*p));
	p->kind = TY__BOOLEAN;
	p->value.boolean = b;
	return p;
}

A_type A_Fuction_SimpleType(A_simple_type simple)
{
	A_type p = (A_type)checked_malloc(sizeof(*p));
	p->kind = A_simpleType;
	p->value.simple = simple;
	return p;
}

A_type A_Fuction_ArrayType(A_array array)
{
	A_type p = (A_type)checked_malloc(sizeof(*p));
	p->kind = A_arrayType;
	p->value.array = array;
	return p;
}

A_type A_Fuction_RecordType(A_fieldList fieldList)
{
	A_type p = (A_type)checked_malloc(sizeof(*p));
	p->kind = A_recordType;
	p->value.fieldList = fieldList;
	return p;
}

A_simple_type A_Fuction_SimpleSysType(A_sysType sysType)
{
	A_simple_type p = (A_simple_type)checked_malloc(sizeof(*p));
	p->kind = A_simpleSysType;
	p->value.sysType = sysType;
	return p;
}

A_simple_type A_Fuction_SimpleRangeType(A_range range)
{
	A_simple_type p = (A_simple_type)checked_malloc(sizeof(*p));
	p->kind = A_simpleRangeType;
	p->value.range = range;
	return p;
}

A_simple_type A_Fuction_SimpleNameType(table_t name)
{
	A_simple_type p = (A_simple_type)checked_malloc(sizeof(*p));
	p->kind = A_simpleNameType;
	p->value.name = name;
	return p;
}

A_simple_type A_Fuction_SimpleNameListType(A_nameList namelist)
{
	A_simple_type p = (A_simple_type)checked_malloc(sizeof(*p));
	p->kind = A_simpleNameListType;
	p->value.nameList = namelist;
	return p;
}

A_range A_Fuction_ConstRange(A_const lo, A_const up)
{
	A_range p = (A_range)checked_malloc(sizeof(*p));
	p->kind = A_constRange;
	p->lower_value.con = lo;
	p->upper_value.con = up;
	return p;
}

A_range A_Fuction_NameRange(table_t lo, table_t up)
{
	A_range p = (A_range)checked_malloc(sizeof(*p));
	p->kind = A_nameRange;
	p->lower_value.name = lo;
	p->upper_value.name = up;
	return p;
}

A_nameList A_Fuction_NameList(A_name head, A_nameList next)
{
	A_nameList p = (A_nameList)checked_malloc(sizeof(*p));
	p->head=head;
	p->next=next;
	return p;
}

A_name A_Fuction_Name(table_t name)
{
	A_name p = (A_name)checked_malloc(sizeof(*p));
	p->name = name;
	return p;
}

A_array A_Fuction_Array(A_range range, A_type type)
{
	A_array p = (A_array)checked_malloc(sizeof(*p));
	p->range = range;
	p->type = type;
	return p;
}

A_fieldList A_Fuction_FieldList(A_field head, A_fieldList next)
{
	A_fieldList p = (A_fieldList)checked_malloc(sizeof(*p));
	p->head=head;
	p->next=next;
	return p;
}

A_field A_Fuction_Field(A_nameList name_list, A_type type_decl)
{
	A_field p = (A_field)checked_malloc(sizeof(*p));
	p->name_list = name_list;
	p->type_decl = type_decl;
	return p;
}

A_varDecList A_Fuction_VarDecList(A_nameList name_list, A_type type_decl)
{
	A_varDecList p = (A_varDecList)checked_malloc(sizeof(*p));
	p->name_list = name_list;
	p->type_decl = type_decl;
	return p;
}

A_routine_part A_Fuction_RoutinePart(A_routine_part_head head, A_routine subRoutine){
	A_routine_part p = (A_routine_part)checked_malloc(sizeof(*p));
	p->head = head;
	p->subRoutine = subRoutine;
	return p;
}

A_routine_part_head A_Fuction_FuncHead(table_t name, A_paraList parameters, A_simple_type simpleType)
{
	A_routine_part_head p = (A_routine_part_head)checked_malloc(sizeof(*p));
	p->name = name;
	p->parameters = parameters;
	p->simpleType = simpleType;
	return p;
}

A_routine_part_head A_Fuction_ProcHead(table_t name, A_paraList parameters)
{
	A_routine_part_head p = (A_routine_part_head)checked_malloc(sizeof(*p));
	p->name = name;
	p->parameters = parameters;
	p->simpleType = NULL;
	return p;
}

A_paraList A_Fuction_ParaList(A_paraField field, A_paraList next){
	A_paraList p = (A_paraList)checked_malloc(sizeof(*p));
	p->field = field;
	p->next = next;
	return p;
}

A_paraField A_Fuction_VarParaField(A_nameList nameList, A_simple_type simpleType){
	A_paraField p = (A_paraField)checked_malloc(sizeof(*p));
	p->nameList = nameList;
	p->simpleType = simpleType;
	p->kind = Var_type;
	return p;
}

A_paraField A_Fuction_ValParaField(A_nameList nameList, A_simple_type simpleType){
	A_paraField p = (A_paraField)checked_malloc(sizeof(*p));
	p->nameList = nameList;
	p->simpleType = simpleType;
	p->kind = Value_type;
	return p;
}

A_var A_Fuction_Var(table_t ID){
	A_var p = (A_var)checked_malloc(sizeof(*p));
	p->ID = ID;
	p->kind = A_pureID;
	return p;
}

A_var A_Fuction_ArrayElement(table_t ID, A_exp subscript){
	A_var p = (A_var)checked_malloc(sizeof(*p));
	p->ID = ID;
	p->value.subscript = subscript;
	p->kind = A_arrayElement;
	return p;
}

A_var A_Fuction_RecordField(table_t ID, table_t fieldID){
	A_var p = (A_var)checked_malloc(sizeof(*p));
	p->ID = ID;
	p->value.fieldID = fieldID;
	p->kind = A_recordField;
	return p;
}

A_proc A_Fuction_Proc(table_t function, A_expList args)
{
	A_proc p = (A_proc)checked_malloc(sizeof(*p));
	p->args = args;
	p->name = function;
	return p;
}

A_stmtList A_Fuction_StatementList(A_stmt head, A_stmtList next)
{
	A_stmtList p = (A_stmtList)checked_malloc(sizeof(*p));
	p->head = head;
	p->next = next;
	return p;
}

A_stmt A_Fuction_LabelStatement(int label, A_stmt stmt)
{
	stmt->label = label;
	return stmt;
}

A_stmt A_Fuction_AssignStatement(A_var var, A_exp exp)
{
	//printf("xtf1\n");
	A_stmt p = (A_stmt)checked_malloc(sizeof(*p));
	p->kind = A_assignStmt;
	p->label = -1;
	p->value.assignStmt = (A_assign)checked_malloc(sizeof(*(p->value.assignStmt)));
	//printf("xtf3, %ld\n", sizeof(p->value.assignStmt->exp));
	//printf("xtf3.1\n");
	p->value.assignStmt->exp = NULL;
	//printf("xtf4\n");
	p->value.assignStmt->var = var;
	//printf("xtf2\n");
	return p;
}

A_stmt A_Fuction_ProcStatement(A_proc proc)
{
	A_stmt p = (A_stmt)checked_malloc(sizeof(*p));
	p->kind = A_procStmt;
	p->label = -1;
	p->value.procStmt = proc;
	return p;
}

A_stmt A_Fuction_CompoundStatement(A_stmtList substmtList)
{
	A_stmt p = (A_stmt)checked_malloc(sizeof(*p));
	p->kind = A_compundStmt;
	p->label = -1;
	p->value.compoundStmt = (A_compound)checked_malloc(sizeof(*(p->value.compoundStmt)));
	p->value.compoundStmt->substmtList = substmtList;
	return p;
}

A_stmt A_Fuction_IfStatement(A_exp test, A_stmt thenStmt, A_stmt elseStmt)
{
	A_stmt p = (A_stmt)checked_malloc(sizeof(*p));
	p->kind = A_ifStmt;
	p->label = -1;
	p->value.ifStmt.elseStmt = elseStmt;
	p->value.ifStmt.test = test;
	p->value.ifStmt.thenStmt = thenStmt;
	return p;
}

A_stmt A_Fuction_RepeatStatement(A_exp test, A_stmtList body)
{
	A_stmt p = (A_stmt)checked_malloc(sizeof(*p));
	p->kind = A_repeatStmt;
	p->label = -1;
	p->value.repeatStmt.body = body;
	p->value.repeatStmt.test = test;
	return p;
}

A_stmt A_Fuction_WhileStatement(A_exp test, A_stmt body)
{
	A_stmt p = (A_stmt)checked_malloc(sizeof(*p));
	p->kind = A_whileStmt;
	p->label = -1;
	p->value.whileStmt.body = body;
	p->value.whileStmt.test = test;
	return p;
}

A_stmt A_Fuction_ForStatement(A_var var, A_exp initValue, int direction, A_exp finalValue, A_stmt body)
{
	A_stmt p = (A_stmt)checked_malloc(sizeof(*p));
	p->kind = A_forStmt;
	p->label = -1;
	p->value.forStmt.body = body;
	p->value.forStmt.direction = direction;
	p->value.forStmt.finalValue = finalValue;
	p->value.forStmt.initValue = initValue;
	p->value.forStmt.var = var;
	return p;
}

A_stmt A_Fuction_CaseStatement(A_exp test, A_caseList caselist)
{
	A_stmt p = (A_stmt)checked_malloc(sizeof(*p));
	p->kind = A_caseStmt;
	p->label = -1;
	p->value.caseStmt.test= test;
	p->value.caseStmt.caselist = caselist;
	return p;
}

A_stmt A_Fuction_GotoStatement(int label)
{
	A_stmt p = (A_stmt)checked_malloc(sizeof(*p));
	p->kind = A_gotoStmt;
	p->label = -1;
	p->value.gotoStmt.label = label;
	return p;
}

A_caseList A_Fuction_CaseList(A_case head, A_caseList next)
{
	A_caseList p = (A_caseList)checked_malloc(sizeof(*p));
	p->head = head;
	p->next = next;
	return p;
}

A_case A_Fuction_Case(A_const constValue, table_t name, A_stmt body)
{
	A_case p = (A_case)checked_malloc(sizeof(*p));
	p->constValue = constValue;
	p->body = body;
	p->name = name;
	return p;
}

A_expList A_Fuction_ExpList(A_exp head, A_expList next)
{
	A_expList p = (A_expList)checked_malloc(sizeof(*p));
	p->next = next;
	p->head = head;
	return p;
}

A_exp A_Fuction_NameExp(table_t name)
{
	A_exp p = (A_exp)checked_malloc(sizeof(*p));
	p->kind = A_nameExp;
	p->value.name = name;
	return p;
}

A_exp A_Fuction_VarExp(A_var var)
{
	A_exp p = (A_exp)checked_malloc(sizeof(*p));
	p->kind = A_varExp;
	p->value.var = var;
	return p;
}

A_exp A_Fuction_FuncExp(A_proc func)
{
	A_exp p = (A_exp)checked_malloc(sizeof(*p));
	p->kind = A_funcExp;
	p->value.func = func;
	return p;
}

A_exp A_Fuction_ConstExp(A_const constValue)
{
	A_exp p = (A_exp)checked_malloc(sizeof(*p));
	p->kind = A_constExp;
	p->value.constValue = constValue;
	return p;
}

A_exp A_Fuction_OpExp(A_operation oper, A_exp left, A_exp right)
{
	A_exp p = (A_exp)checked_malloc(sizeof(*p));
	p->kind = A_opExp;
	p->value.op = (A_op)checked_malloc(sizeof(*(p->value.op)));
	p->value.op->left = left;
	p->value.op->right = right;
	p->value.op->oper = oper;
	return p;
}