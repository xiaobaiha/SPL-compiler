/* codegen.h     Gordon S. Novak Jr.    */
/* 15 Aug 13 */

/* Top-level entry for code generator.
   pcode    = pointer to code = parseresult: (program foo (output) (progn ...))
   varsize  = size of local storage in bytes = blockoffs[blocknumber]
   maxlabel = maximum label number used so far = labelnumber    */
void gencode(A_pro root, int varsize, int maxlabel);

void genc(A_routine code);

void genstmt(A_stmtList stmt);

void genRoutineHead(A_routine_head head);

void munchStm(A_stmt aStmt);

void dealIfStmt(A_stmt stmt);

void dealCompundStmt(A_stmt stmt);

void dealRepeatStmt(A_stmt stmt);

void dealWhileStmt(A_stmt stmt);

void dealCaseStmt(A_stmt stmt);

void dealGotoStmt(A_stmt stmt);

void dealDecList(A_decList decList);

void dealDecListHead(A_dec node);

void dealRoutinePart(A_routine_part routine_part);

void dealRoutinePartHead(A_routine_part_head head);

void dealNameList(A_nameList namelist);

void dealAssignStmt(A_assign assignStmt);

void dealProcStmt(A_proc procStmt);

void dealForStmt(A_for forStmt);

int dealExp(A_exp aExp);

int dealOpExp(A_op op);

int dealFuncExp(A_proc proc);

int dealNameExp(table_t name);

int dealVarExp(A_var var);

int dealConstExp(A_const constValue);

int getreg(Ty_kind kind);

void reset_regs();

void free_reg(int reg_num);

void mark_reg_used(int reg_num);