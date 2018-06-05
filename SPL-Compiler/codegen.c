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
#include "token.h"
#include "symbol.h"
//#include "lexan.h"
#include "genasm.h"
#include "codegen.h"
//#include "pprint.h"

void genc(A_routine code);
void genstmt(A_stmtList stmt);

/* Set DEBUGGEN to 1 for debug printouts of code generation */
#define DEBUGGEN 0

int nextlabel;    /* Next available label number */
int stkframesize;   /* total stack frame size */

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
    stkframesize = asmentry(name->name,varsize);
    genc(routine);
    asmexit(name->name);
}

/* Generate code for a Statement from an intermediate-code form */
void genc(A_routine code)
{  
    A_routine_head head;
    A_stmtList compoundStmt;
    head = code->head;
    compoundStmt = code->compoundStmt;
    genstmt(compoundStmt);
}

void genstmt(A_stmtList stmt)
{
    A_stmtList tList = stmt;
    for (; tList; tList = tList->next)
        munchStm(tList->head);
}

void munchStm(A_stmt aStmt)
{
    switch(aStmt->kind) {
        case A_assignStmt: { break;}
        case A_procStmt: { break;}
        case A_compundStmt:{ break;}
        case A_ifStmt: { break;}
        case A_repeatStmt:{ break;}
        case A_whileStmt:{ break;}
        case A_forStmt:{ break;}
        case A_caseStmt:{ break;}
        case A_gotoStmt:{ break;}
    }
}

/*..............................................*/



