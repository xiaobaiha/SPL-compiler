/* codgen.c       Generate Assembly Code for x86         07 May 18   */

/* Copyright (c) 2018 Gordon S. Novak Jr. and The University of Texas at Austin
    */

/* Starter file for CS 375 Code Generation assignment.           */
/* Written by Gordon S. Novak Jr.                  */

/* This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License (file gpl.text) for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "absyn.h"
//#include "token.h"
#include "symbol.h"
//#include "lexan.h"
#include "genasm.h"
#include "codegen.h"
#include "util.h"
//#include "pprint.h"

void genc(A_routine code);
void genstmt(A_stmtList stmt);

/* Set DEBUGGEN to 1 for debug printouts of code generation */
#define DEBUGGEN 0
#define NUM_INT_REGS 8
#define NUM_FP_REGS 24
#define NUM_REGS 32

int ASM_OFFSET = 32;
int nextlabel;    /* Next available label number */
int stkframesize; /* total stack frame size */
                  /* integer regs */
int used_regs[32] = {0, 0, 0, 0, 0, 0, 0, 0,
                     /* FP regs; r8d to r15d */
                     0, 0, 0, 0, 0, 0, 0, 0,
                     /* xmm0 to xmm15 */
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int arg_reg[4] = {EDI, ESI, EDX, ECX};
char *function_asm_code[] = {
    "	pushq	%rbp			# save base pointer on stack",
    "	movq	%rsp, %rbp		# move stack pointer to base pointer",
    "	subq	$32, %rsp		# make space for this stack frame",
    "",
};

/* Top-level entry for code generator.
   root    = pointer to code:  (program foo (output) (progn ...))
   varsize  = size of local storage in bytes
   maxlabel = maximum label number used so far

Add this line to the end of your main program:
    gencode(parseresult, blockoffs[blocknumber], labelnumber);
The generated code is printed out; use a text editor to extract it for
your .s file.
         */

void gencode(A_pro root, int varsize, int maxlabel)
{
    table_t name;
    A_routine routine;
    name = root->name;
    routine = root->routine;
    nextlabel = maxlabel + 1;
    stkframesize = asmentry(name->name, varsize);
    genc(routine);
    asmexit(name->name);
}

/* Generate code for a Statement from an intermediate-code form */
void genc(A_routine code)
{
    A_routine_head head;
    A_stmtList compoundStmt;
    head = code->head;
    genRoutineHead(head);
    compoundStmt = code->compoundStmt;
    genstmt(compoundStmt);
}

void genRoutineHead(A_routine_head head)
{
    if (!head)
        return;
    dealDecList(head->routinePart);
}

void genstmt(A_stmtList stmt)
{
    A_stmtList tList = stmt;
    int i = 0;
    while (tList){
        munchStm(tList->head);
        tList = tList->next;
    }
}

void munchStm(A_stmt aStmt)
{
    
    int k = aStmt->kind;
    switch (aStmt->kind)
    {
        case A_assignStmt:
        {
            dealAssignStmt(aStmt->value.assignStmt);
            break;
        }
        case A_procStmt:
        {
            dealProcStmt(aStmt->value.procStmt);
            break;
        }
        case A_compundStmt:
        {
            dealCompundStmt(aStmt);
            break;
        }
        case A_ifStmt:
        {
            dealIfStmt(aStmt);
            break;
        }
        case A_repeatStmt:
        {
            dealRepeatStmt(aStmt);
            break;
        }
        case A_whileStmt:
        {
            dealWhileStmt(aStmt);
            break;
        }
        case A_forStmt:
        {
            dealForStmt(aStmt->value.forStmt);
            break;
        }
        case A_caseStmt:
        {
            dealCaseStmt(aStmt);
            break;
        }
        case A_gotoStmt:
        {
            dealGotoStmt(aStmt);
            break;
        }
    }
}

/*.......................xtf....................*/

void dealIfStmt(A_stmt stmt)
{
    A_if node = stmt->value.ifStmt;
    A_exp testIf = node.test;
    int if_num = dealExp(testIf);
    int false_label_num, true_label_num;

    if (node.elseStmt)
        false_label_num = nextlabel++;
    true_label_num = nextlabel++;

    if (node.elseStmt)
    {
        asmjump(JMP, false_label_num); //exp is false
        asmlabel(if_num);
        munchStm(node.thenStmt);
        asmjump(JMP, true_label_num); //exp if true
        asmlabel(false_label_num);
        munchStm(node.elseStmt);
        asmlabel(true_label_num);
    }
    else
    {
        asmjump(JMP, true_label_num); //exp if true
        asmlabel(if_num);
        munchStm(node.thenStmt);
        asmlabel(true_label_num);
    }
    free_reg(if_num);
}

void dealCompundStmt(A_stmt stmt)
{
    A_compound compound = stmt->value.compoundStmt;
    if (compound)
    {
        A_stmtList stmtlist = compound->substmtList;
        genstmt(stmtlist);
    }
}

void dealRepeatStmt(A_stmt stmt)
{
    A_repeat repeatStmt = stmt->value.repeatStmt;
    int falseLabel = nextlabel++;
    asmlabel(falseLabel);
    genstmt(repeatStmt.body);
    int untilReg = dealExp(repeatStmt.test);
    asmjump(JMP, falseLabel);
    asmlabel(untilReg);
    free_reg(untilReg);
}

void dealWhileStmt(A_stmt stmt)
{
    A_while whilestmt = stmt->value.whileStmt;
    int true_label_num = nextlabel++;
    asmlabel(true_label_num);
    int whileReg = dealExp(whilestmt.test);
    int false_label_num = nextlabel++;
    asmjump(JMP, false_label_num);
    asmlabel(whileReg);
    munchStm(whilestmt.body);
    asmjump(JMP, true_label_num);
    asmlabel(false_label_num);
    free_reg(whileReg);
}

void dealCaseStmt(A_stmt stmt)
{
    A_caseStatement casestmt = stmt->value.caseStmt;
    A_exp test = casestmt.test;
    A_caseList casebody = casestmt.caselist;

    int caseReg = dealExp(casestmt.test);
}

void dealGotoStmt(A_stmt stmt)
{
    A_goto gotostmt = stmt->value.gotoStmt;
    asmjump(JMP, gotostmt.label);
}
/*..............................................*/

/***************** fzj **************/
void dealDecList(A_decList decList)
{
    //A_dec head = decList->head;
    if (decList)
    {
        A_dec head = decList->head;
        dealDecListHead(head);
        dealDecList(decList->next);
    }
}

void dealDecListHead(A_dec node)
{
    if (node && node->kind == A_routineDec)
    {
        dealRoutinePart(node->value.routine);
    }
}

void dealRoutinePart(A_routine_part routine_part)
{
    dealRoutinePartHead(routine_part->head);
    genc(routine_part->subRoutine);
}

void dealRoutinePartHead(A_routine_part_head head)
{
    cannedcode(function_asm_code);
    A_paraList argList = head->parameters;
    while (argList)
    {
        A_paraField field = argList->field;

        switch (field->kind)
        {
            case Var_type:
            {
                A_nameList namelist = field->nameList;
                dealNameList(namelist);
                break;
            }
            case Value_type:
            {
                break;
            }
        }
        argList = argList->next;
    }
}
void dealNameList(A_nameList namelist)
{
    int index = 0;
    while (namelist)
    {
        A_name name = namelist->head;
        int reg_num = arg_reg[index++];
        mark_reg_used(reg_num);
        asmst(MOVL, reg_num, ASM_OFFSET, name->name->name);
        namelist = namelist->next;
    }
}

void dealAssignStmt(A_assign assignStmt)
{
    A_var var = assignStmt->var;
    A_exp exp = assignStmt->exp;
    int k = var->kind;
    
    switch (k)
    {
        case A_pureID:
        {
            int reg_num;
            switch (exp->kind)
            {
                case A_constExp:
                {
                    A_const constvalue = exp->value.constValue;
                    if (constvalue->kind == Ty_real)
                    {
                        reg_num = getreg(Ty_real);
                        double realValue = constvalue->value.real;
                        asmst(MOVSD, reg_num, realValue, "");
                        free_reg(reg_num);
                    }
                    else if (constvalue->kind == Ty_integer)
                    {
                        reg_num = getreg(Ty_integer);
                        int intValue = constvalue->value.integer;
                        asmst(MOVL, reg_num, intValue, "");
                        free_reg(reg_num);
                    }
                    break;
                }
                case A_opExp:
                {
                    reg_num = dealExp(exp);
                    asmst(MOVL, reg_num, 0, "");
                    free_reg(reg_num);
                    break;
                }
                case A_funcExp: {
                    dealProcStmt(exp->value.func);
                    break;
                }
                case A_nameExp:{
                    reg_num = getreg(Ty_integer);
                    asmst(MOVL, reg_num, ASM_OFFSET, exp->value.name->name);
                    break;
                }
                case A_varExp:{
                    asmldrr(MOVL, ASM_OFFSET, dealVarExp(exp->value.var), dealVarExp(var),"move from reg1 to reg2");
                    break;
                }
            }
            break;
        }
        case A_arrayElement:
        {
            A_exp sub = var->value.subscript;
            table_t field_id = var->ID;
            int reg_temp = dealExp(sub);
            asmstrr(MOVL, reg_temp, 0, EAX, field_id->name);
            free_reg(reg_temp);
            break;
        }
        case A_recordField:
        {
            A_exp sub = var->value.subscript;
            table_t field_id = var->value.fieldID;
            int reg_num = dealExp(sub);
            asmstrr(MOVL, reg_num, ASM_OFFSET, EAX, field_id->name);
            break;
        }
    }
}

void dealProcStmt(A_proc procStmt)
{
    A_exp arg_temp;
    A_expList iter = procStmt->args;
    int arg_index = 0, temp_reg = 0;

    while (iter)
    {
        
        arg_temp = iter->head;
        temp_reg = dealExp(arg_temp);
        asmrr(MOVL, temp_reg, arg_reg[arg_index]); // score values into arg reg
        
        mark_reg_used(arg_reg[arg_index++]);
        iter = iter->next;
    }
    asmcall(procStmt->name->name);
    
    free_reg(arg_reg[0]);
    free_reg(arg_reg[1]);
    free_reg(arg_reg[2]);
    free_reg(arg_reg[3]);
}

void dealForStmt(A_for forStmt)
{
    int init_reg_num = dealExp(forStmt.initValue);
    int final_reg_num = dealExp(forStmt.finalValue);
    int for_start_label = nextlabel++;
    int direction = forStmt.direction;
    // define a const value 1
    A_const one_const = (A_const)checked_malloc(sizeof(*one_const));
    one_const->kind = Ty_integer;
    one_const->value.integer = 1;
    // end of define const value
    int one_const_reg = dealConstExp(one_const);
    asmlabel(for_start_label);
    if (direction == 1)
    {
        asmrr(ADDL, one_const_reg, init_reg_num);
    }
    else
    {
        asmrr(SUBL, one_const_reg, init_reg_num);
    }
    asmrr(CMPL, init_reg_num, final_reg_num);
    int for_end_label = nextlabel++;
    asmjump(JGE, for_end_label);
    munchStm(forStmt.body);
    asmjump(JMP, for_start_label);
    asmlabel(for_end_label);
    free_reg(init_reg_num);
    free_reg(final_reg_num);
}

// return reg index number
int dealExp(A_exp aExp)
{
    int out_reg_num = 0;
    switch (aExp->kind)
    {
        case A_opExp:
        {
            out_reg_num = dealOpExp(aExp->value.op);
            break;
        }
        case A_funcExp:
        {
            out_reg_num = dealFuncExp(aExp->value.func);
            break;
        }
        case A_nameExp:
        {
            out_reg_num = dealNameExp(aExp->value.name);
            break;
        }
        case A_varExp:
        {
            out_reg_num = dealVarExp(aExp->value.var);
            break;
        }
        case A_constExp:
        {
            out_reg_num = dealConstExp(aExp->value.constValue);
            break;
        }
    }
    return out_reg_num;
}

// return reg index number
int dealOpExp(A_op op)
{
    int left_reg_num = 0;
    int right_reg_num = 0;
    int out_reg_num = 0;
    int float_flag = 0;

    left_reg_num = dealExp(op->left);
    right_reg_num = dealExp(op->right);

    switch (op->oper)
    {
    case A_plusOp:
    {
        if (float_flag)
        {
            asmrr(ADDSD, left_reg_num, right_reg_num);
        }
        else
        {
            asmrr(ADDL, left_reg_num, right_reg_num);
        }
        out_reg_num = right_reg_num;
        free_reg(left_reg_num);
        break;
    };
    case A_minusOp:
    {
        if (left_reg_num > 15 && left_reg_num < NUM_REGS)
        {
            asmfneg(left_reg_num, getreg(Ty_real));
            right_reg_num = left_reg_num;
        }
        else if (float_flag)
        {
            asmrr(SUBSD, right_reg_num, left_reg_num);
        }
        else
        {
            asmrr(SUBL, right_reg_num, left_reg_num);
        }
        out_reg_num = left_reg_num;
        free_reg(right_reg_num);
        break;
    };
    case A_mulOp:
    {
        if (float_flag)
        {
            asmrr(MULSD, right_reg_num, left_reg_num);
        }
        else
        {
            asmrr(IMULL, right_reg_num, left_reg_num);
        }
        out_reg_num = left_reg_num;
        free_reg(right_reg_num);
        break;
    };
    case A_divOp:
    {
        if (float_flag)
        {
            asmrr(DIVSD, right_reg_num, left_reg_num);
        }
        else
        {
            asmrr(DIVL, right_reg_num, left_reg_num);
        }
        out_reg_num = left_reg_num;
        free_reg(right_reg_num);
        break;
    };
    case A_modOp:
    {
        int temp_reg = getreg(Ty_integer);
        asmrr(MOVL, left_reg_num, temp_reg);
        asmrr(DIVL, right_reg_num, left_reg_num);
        asmrr(IMULL, right_reg_num, left_reg_num);
        asmrr(SUBL, left_reg_num, temp_reg);
        out_reg_num = temp_reg;
        free_reg(left_reg_num);
        free_reg(right_reg_num);
        break;
    };
    case A_eqOp:
    {
        out_reg_num = nextlabel++;
        asmrr(CMPL, right_reg_num, left_reg_num);
        asmjump(JE, out_reg_num);
        free_reg(left_reg_num);
        free_reg(right_reg_num);
        break;
    };
    case A_neqOp:
    {
        out_reg_num = nextlabel++;
        asmrr(CMPQ, right_reg_num, left_reg_num);
        asmjump(JNE, out_reg_num);
        free_reg(left_reg_num);
        free_reg(right_reg_num);
        break;
    };
    case A_ltOp:
    {
        out_reg_num = nextlabel++;
        asmrr(CMPL, right_reg_num, left_reg_num);
        asmjump(JL, out_reg_num);
        free_reg(left_reg_num);
        free_reg(right_reg_num);
        break;
    };
    case A_gtOp:
    {
        out_reg_num = nextlabel++;
        asmrr(CMPL, right_reg_num, left_reg_num);
        asmjump(JG, out_reg_num);
        free_reg(left_reg_num);
        free_reg(right_reg_num);
        break;
    };
    case A_leOp:
    {
        out_reg_num = nextlabel++;
        asmrr(CMPL, right_reg_num, left_reg_num);
        asmjump(JLE, out_reg_num);
        free_reg(left_reg_num);
        free_reg(right_reg_num);
        break;
    };
    case A_geOp:
    {
        out_reg_num = nextlabel++;
        asmrr(CMPL, right_reg_num, left_reg_num);
        asmjump(JGE, out_reg_num);
        free_reg(left_reg_num);
        free_reg(right_reg_num);
        break;
    };
    case A_orOp:
    {
        asmrr(ORL, right_reg_num, left_reg_num);
        out_reg_num = left_reg_num;
        free_reg(right_reg_num);
        break;
    };
    case A_andOp:
    {
        asmrr(ANDL, right_reg_num, left_reg_num);
        out_reg_num = left_reg_num;
        free_reg(right_reg_num);
        break;
    };
    case A_notOp:
    {
        asmrr(NOTQ, right_reg_num, left_reg_num);
        out_reg_num = left_reg_num;
        free_reg(right_reg_num);
        break;
    };
    case A_negOp:
    {
        asmrr(NEGL, right_reg_num, left_reg_num);
        out_reg_num = left_reg_num;
        free_reg(right_reg_num);
        break;
    };
    }
    return out_reg_num;
}

// return reg index number
int dealFuncExp(A_proc proc)
{
    int out_reg_num = 0;
    asmcall(proc->name->name);
    out_reg_num = getreg(Ty_integer);
    if (out_reg_num != EAX)
        asmrr(MOVL, EAX, out_reg_num);
    return out_reg_num;
}

int dealNameExp(table_t name)
{
    int out_reg_num = getreg(Ty_integer);
    asmld(MOVL, ASM_OFFSET, out_reg_num, name->name);
    return out_reg_num;
}

int dealVarExp(A_var var)
{
    int out_reg_num = -1;
    switch (var->kind)
    {
    case A_pureID:
    {
        out_reg_num = getreg(Ty_integer);
        asmld(MOVL, ASM_OFFSET, out_reg_num, var->ID->name);
        break;
    }
    case A_arrayElement:
    {
        out_reg_num = getreg(Ty_integer);
        asmld(MOVL, ASM_OFFSET, out_reg_num, var->ID->name);
        break;
    }
    case A_recordField:
    {
        A_exp sub = var->value.subscript;
        table_t field_id = var->value.fieldID;
        out_reg_num = dealExp(sub);
        asmstrr(MOVL, out_reg_num, ASM_OFFSET, EAX, field_id->name);
        break;
    }
    }
    return out_reg_num;
}

int dealConstExp(A_const constValue)
{
    int out_reg_num = -1;
    if (constValue->kind == Ty_real)
    {
        out_reg_num = getreg(Ty_real);
        double realValue = constValue->value.real;
        asmst(MOVSD, out_reg_num, realValue, "");
    }
    else
    {
        out_reg_num = getreg(Ty_integer);
        int intValue = constValue->value.integer;
        asmst(MOVL, out_reg_num, intValue, "");
    }
    return out_reg_num;
}
/* Trivial version: always returns RBASE + 0 */
/* Get a register.   */
/* Need a type parameter or two versions for INTEGER or REAL */
int getreg(Ty_kind kind)
{

    /*     ***** NAIVE IMPLEMENTATION *****   */

    int i = 0;
    int stop = NUM_INT_REGS;
    if (kind != Ty_integer)
    {
        //        i = 8;
        i = 16;
        stop = NUM_REGS;
    }

    for (; i < 7; i++)
    {
        if (used_regs[i] == 0)
        {
            if (i == EDI || i == ESI || i == EDX || i == ECX)
                continue;
            used_regs[i] = 1;
            return i;
        }
    }
    if (i >= stop)
        printf("Regster Overflow.\n");

    return RBASE;
}

void reset_regs()
{
    int i;
    for (i = 0; i < NUM_REGS; i++)
    {
        used_regs[i] = 0;
    }
}

void free_reg(int reg_num)
{
    if (reg_num < 0 || reg_num >= NUM_REGS)
    {
        printf("Error: cannot free register number %d\n", reg_num);
        return;
    }
    used_regs[reg_num] = 0;
}

void mark_reg_used(int reg_num)
{
    if (reg_num < 0 || reg_num >= NUM_REGS)
    {
        printf("2 Error: register %d out of bounds\n", reg_num);
        return;
    }
    used_regs[reg_num] = 1;
}
/************ end of fzj **************/
/*..............................................*/
