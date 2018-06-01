/*
 * absyn.c - Abstract Syntax Functions. Most functions create an instance of an
 *           abstract syntax rule.
 */

#include <stdlib.h>
#include <stdio.h>
#include "absyn.h"
#include "symbol.h"
#include "util.h"

A_pro A_Program(A_pos pos, table_t name, A_routine routine)
{
	A_pro p = (A_pro)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->name = name;
	p->routine = routine;
	return p;
}

A_routine A_Routine(A_pos pos, A_routine_head head, A_stmtList compoundStmt)
{
	A_routine p = (A_routine)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->head = head;
	p->compoundStmt = compoundStmt;
	return p;
}

A_routine_head A_Routine_head(A_pos pos, A_decList constPart, A_decList typePart, A_decList varPart, A_decList routinePart)
{
	A_routine_head p = (A_routine_head)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->constPart = constPart;
	p->typePart = typePart;
	p->varPart = varPart; 
	p->routinePart = routinePart;
	return p;
}

A_decList A_DecList(A_dec head, A_decList next)
{
	A_decList p = (A_decList)checked_malloc(sizeof(*p));
	p->head = head;
	p->next = next;
	return p;
}

A_dec A_ConstDec(A_pos pos, table_t name, A_const value)
{
	A_dec p = (A_dec)checked_malloc(sizeof(*p));
	p->kind = A_constDec;
	p->pos = pos;
	p->name = name;
	p->u.value = value;
	return p;
}

A_dec A_TypeDec(A_pos pos, table_t name, A_type type)
{
	A_dec p = (A_dec)checked_malloc(sizeof(*p));
	p->kind = A_typeDec;
	p->pos = pos;
	p->name = name;
	p->u.type = type;
	return p;
}

A_dec A_VarDec(A_pos pos, A_varDecList var)
{
	A_dec p = (A_dec)checked_malloc(sizeof(*p));
	p->kind = A_varDec;
	p->pos = pos;
	p->u.var = var;
	return p;
}

A_dec A_RoutinePartDec(A_pos pos, A_routine_part routine)
{
	A_dec p = (A_dec)checked_malloc(sizeof(*p));
	p->kind = A_routineDec;
	p->pos = pos;
	p->u.routine = routine;
	return p;
}

A_const A_Integer(A_pos pos, int i)
{
	A_const p = (A_const)checked_malloc(sizeof(*p));
	p->kind = Ty_integer;
	p->pos = pos;
	p->u.integer = i;
	return p;
}

A_const A_Real(A_pos pos, double r)
{
	A_const p = (A_const)checked_malloc(sizeof(*p));
	p->kind = Ty_real;
	p->pos = pos;
	p->u.real = r;
	return p;
}

A_const A_Char(A_pos pos, char c)
{
	A_const p = (A_const)checked_malloc(sizeof(*p));
	p->kind = Ty_char;
	p->pos = pos;
	p->u.ch = c;
	return p;
}

A_const A_String(A_pos pos, char *s)
{
	A_const p = (A_const)checked_malloc(sizeof(*p));
	p->kind = Ty_string;
	p->pos = pos;
	p->u.str = s;
	return p;
}

A_const A_Bool(A_pos pos, int b)
{
	A_const p = (A_const)checked_malloc(sizeof(*p));
	p->kind = Ty_boolean;
	p->pos = pos;
	p->u.boolean = b;
	return p;
}

A_type A_SimpleType(A_pos pos, A_simple simple)
{
	A_type p = (A_type)checked_malloc(sizeof(*p));
	p->kind = A_simpleType;
	p->pos = pos;
	p->u.simple = simple;
	return p;
}

A_type A_ArrayType(A_pos pos, A_array array)
{
	A_type p = (A_type)checked_malloc(sizeof(*p));
	p->kind = A_arrayType;
	p->pos = pos;
	p->u.array = array;
	return p;
}

A_type A_RecordType(A_pos pos, A_fieldList fieldList)
{
	A_type p = (A_type)checked_malloc(sizeof(*p));
	p->kind = A_recordType;
	p->pos = pos;
	p->u.fieldList = fieldList;
	return p;
}

A_simple A_SimpleSysType(A_pos pos, A_sysType sysType)
{
	A_simple p = (A_simple)checked_malloc(sizeof(*p));
	p->kind = A_simpleSysType;
	p->pos = pos;
	p->u.sysType = sysType;
	return p;
}

A_simple A_SimpleRangeType(A_pos pos, A_range range)
{
	A_simple p = (A_simple)checked_malloc(sizeof(*p));
	p->kind = A_simpleRangeType;
	p->pos = pos;
	p->u.range = range;
	return p;
}

A_simple A_SimpleNameType(A_pos pos, table_t name)
{
	A_simple p = (A_simple)checked_malloc(sizeof(*p));
	p->kind = A_simpleNameType;
	p->pos = pos;
	p->u.name = name;
	return p;
}

A_simple A_SimpleNameListType(A_pos pos, A_nameList namelist)
{
	A_simple p = (A_simple)checked_malloc(sizeof(*p));
	p->kind = A_simpleNameListType;
	p->pos = pos;
	p->u.nameList = namelist;
	return p;
}

A_range A_ConstRange(A_pos pos, A_const lo, A_const up)
{
	A_range p = (A_range)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->kind = A_constRange;
	p->lower_u.lconst = lo;
	p->upper_u.uconst = up;
	return p;
}

A_range A_NameRange(A_pos pos, table_t lo, table_t up)
{
	A_range p = (A_range)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->kind = A_nameRange;
	p->lower_u.lname = lo;
	p->upper_u.uname = up;
	return p;
}

A_nameList A_NameList(A_name head, A_nameList next)
{
	A_nameList p = (A_nameList)checked_malloc(sizeof(*p));
	p->head=head;
	p->next=next;
	return p;
}

A_name A_Name(A_pos pos, table_t name)
{
	A_name p = (A_name)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->name = name;
	return p;
}

A_array A_Array(A_pos pos, A_range range, A_type type)
{
	A_array p = (A_array)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->range = range;
	p->type = type;
	return p;
}

A_fieldList A_FieldList(A_field head, A_fieldList next)
{
	A_fieldList p = (A_fieldList)checked_malloc(sizeof(*p));
	p->head=head;
	p->next=next;
	return p;
}

A_field A_Field(A_pos pos, A_nameList nameList, A_type type)
{
	A_field p = (A_field)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->nameList = nameList;
	p->type = type;
	return p;
}

A_varDecList A_VarDecList(A_pos pos, A_nameList nameList, A_type type)
{
	A_varDecList p = (A_varDecList)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->nameList = nameList;
	p->type = type;
	return p;
}

A_routine_part A_RoutinePart(A_routine_part_head head, A_routine subRoutine){
	A_routine_part p = (A_routine_part)checked_malloc(sizeof(*p));
	p->head = head;
	p->subRoutine = subRoutine;
	return p;
}

A_routine_part_head A_FuncHead(A_pos pos, table_t name, A_paraList parameters, A_simple simpleType)
{
	A_routine_part_head p = (A_routine_part_head)checked_malloc(sizeof(*p));
	p->kind = A_function;
	p->pos = pos;
	p->name = name;
	p->parameters = parameters;
	p->simpleType = simpleType;
	return p;
}

A_routine_part_head A_ProcHead(A_pos pos, table_t name, A_paraList parameters)
{
	A_routine_part_head p = (A_routine_part_head)checked_malloc(sizeof(*p));
	p->kind = A_function;
	p->pos = pos;
	p->name = name;
	p->parameters = parameters;
	p->simpleType = NULL;
	return p;
}

A_paraList A_ParaList(A_paraField field, A_paraList next){
	A_paraList p = (A_paraList)checked_malloc(sizeof(*p));
	p->field = field;
	p->next = next;
	return p;
}

A_paraField A_VarParaField(A_pos pos, A_nameList nameList, A_simple simpleType){
	A_paraField p = (A_paraField)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->nameList = nameList;
	p->simpleType = simpleType;
	p->kind = Var;
	return p;
}

A_paraField A_ValParaField(A_pos pos, A_nameList nameList, A_simple simpleType){
	A_paraField p = (A_paraField)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->nameList = nameList;
	p->simpleType = simpleType;
	p->kind = Value;
	return p;
}

A_var A_Var(A_pos pos, table_t ID){
	A_var p = (A_var)checked_malloc(sizeof(*p));
	p->ID = ID;
	p->kind = A_pureID;
	return p;
}

A_var A_ArrayElement(A_pos pos, table_t ID, A_exp subscript){
	A_var p = (A_var)checked_malloc(sizeof(*p));
	p->ID = ID;
	p->u.subscript = subscript;
	p->kind = A_arrayElement;
	return p;
}

A_var A_RecordField(A_pos pos, table_t ID, table_t fieldID){
	A_var p = (A_var)checked_malloc(sizeof(*p));
	p->ID = ID;
	p->u.fieldID = fieldID;
	p->kind = A_recordField;
	return p;
}

A_proc A_Proc(A_pos pos, table_t function, A_expList args)
{
	A_proc p = (A_proc)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->args = args;
	p->kind = A_function;
	p->name = function;
	return p;
}

A_stmtList A_StmtList(A_stmt head, A_stmtList next)
{
	A_stmtList p = (A_stmtList)checked_malloc(sizeof(*p));
	p->head = head;
	p->next = next;
	return p;
}

A_stmt A_LabelStmt(A_pos pos, int label, A_stmt stmt)
{
	stmt->label = label;
	return stmt;
}

A_stmt A_AssignStmt(A_pos pos, A_var var, A_exp exp)
{
	A_stmt p = (A_stmt)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->kind = A_assignStmt;
	p->label = -1;
	p->u.assignStmt.exp = exp;
	p->u.assignStmt.var = var;
	return p;
}

A_stmt A_ProcStmt(A_pos pos, A_proc proc)
{
	A_stmt p = (A_stmt)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->kind = A_procStmt;
	p->label = -1;
	p->u.procStmt = proc;
	return p;
}

A_stmt A_CompoundStmt(A_pos pos, A_stmtList substmtList)
{
	A_stmt p = (A_stmt)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->kind = A_compundStmt;
	p->label = -1;
	p->u.compoundStmt.substmtList = substmtList;
	return p;
}

A_stmt A_IfStmt(A_pos pos, A_exp test, A_stmt thenStmt, A_stmt elseStmt)
{
	A_stmt p = (A_stmt)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->kind = A_ifStmt;
	p->label = -1;
	p->u.ifStmt.elseStmt = elseStmt;
	p->u.ifStmt.test = test;
	p->u.ifStmt.thenStmt = thenStmt;
	return p;
}

A_stmt A_RepeatStmt(A_pos pos, A_exp test, A_stmtList body)
{
	A_stmt p = (A_stmt)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->kind = A_repeatStmt;
	p->label = -1;
	p->u.repeatStmt.body = body;
	p->u.repeatStmt.test = test;
	return p;
}

A_stmt A_WhileStmt(A_pos pos, A_exp test, A_stmt body)
{
	A_stmt p = (A_stmt)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->kind = A_whileStmt;
	p->label = -1;
	p->u.whileStmt.body = body;
	p->u.whileStmt.test = test;
	return p;
}

A_stmt A_ForStmt(A_pos pos, A_var var, A_exp initValue, int direction, A_exp finalValue, A_stmt body)
{
	A_stmt p = (A_stmt)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->kind = A_forStmt;
	p->label = -1;
	p->u.forStmt.body = body;
	p->u.forStmt.direction = direction;
	p->u.forStmt.finalValue = finalValue;
	p->u.forStmt.initValue = initValue;
	p->u.forStmt.var = var;
	return p;
}

A_stmt A_CaseStmt(A_pos pos, A_exp test, A_caseList caselist)
{
	A_stmt p = (A_stmt)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->kind = A_caseStmt;
	p->label = -1;
	p->u.caseStmt.test= test;
	p->u.caseStmt.caselist = caselist;
	return p;
}

A_stmt A_GotoStmt(A_pos pos, int label)
{
	A_stmt p = (A_stmt)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->kind = A_gotoStmt;
	p->label = -1;
	p->u.gotoStmt.label = label;
	return p;
}

A_caseList A_CaseList(A_case head, A_caseList next)
{
	A_caseList p = (A_caseList)checked_malloc(sizeof(*p));
	p->head = head;
	p->next = next;
	return p;
}

A_case A_Case(A_pos pos, A_const constValue, table_t name, A_stmt body)
{
	A_case p = (A_case)checked_malloc(sizeof(*p));
	p->constValue = constValue;
	p->body = body;
	p->name = name;
	return p;
}

A_expList A_ExpList(A_exp head, A_expList next)
{
	A_expList p = (A_expList)checked_malloc(sizeof(*p));
	p->next = next;
	p->head = head;
	return p;
}

A_exp A_NameExp(A_pos pos, table_t name)
{
	A_exp p = (A_exp)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->kind = A_nameExp;
	p->u.name = name;
	return p;
}

A_exp A_VarExp(A_pos pos, A_var var)
{
	A_exp p = (A_exp)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->kind = A_varExp;
	p->u.var = var;
	return p;
}

A_exp A_FuncExp(A_pos pos, A_proc func)
{
	A_exp p = (A_exp)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->kind = A_funcExp;
	p->u.func = func;
	return p;
}

A_exp A_ConstExp(A_pos pos, A_const constValue)
{
	A_exp p = (A_exp)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->kind = A_constExp;
	p->u.constValue = constValue;
	return p;
}

A_exp A_OpExp(A_pos pos, A_operation oper, A_exp left, A_exp right)
{
	A_exp p = (A_exp)checked_malloc(sizeof(*p));
	p->pos = pos;
	p->kind = A_opExp;
	p->u.op = (A_op)checked_malloc(sizeof(*(p->u.op)));
	p->u.op->left = left;
	p->u.op->right = right;
	p->u.op->oper = oper;
	return p;
}