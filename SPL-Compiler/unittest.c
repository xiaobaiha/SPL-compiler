#include <stdio.h>
#include <string.h>
#include "absyn.h"
#include "symbol.h"
#include "y.tab.h"

extern FILE *yyin;
extern A_pro root;

void getStmt(A_stmt node)
{
    if (node) {
        printf("node is not NULL\n");
    }
        //return;
    //printf("node kind:%d\n", node->label);
    switch(node->kind){
        case A_assignStmt: printf("A_stmt->kind: A_assignStmt\n"); break;
        case A_procStmt: printf("A_stmt->kind: A_procStmt\n"); break;
        case A_compundStmt: printf("A_stmt->kind: A_compundStmt\n"); break;
        case A_ifStmt: printf("A_stmt->kind: A_ifStmt\n"); break;
        case A_repeatStmt:  printf("A_stmt->kind: A_repeatStmt\n"); break;
        case A_whileStmt:  printf("A_stmt->kind: A_whileStmt\n"); break;
        case A_forStmt:  printf("A_stmt->kind: A_forStmt\n"); break;
        case A_caseStmt:  printf("A_stmt->kind: A_caseStmt\n"); break;
        case A_gotoStmt:  printf("A_stmt->kind: A_gotoStmt\n"); break;
    }
}

void test_stmt(A_stmtList node)
{
    A_stmtList temp = node;
    while(temp->next){
        printf("a_stmtlist is not Null\n");
        temp = temp->next;
    }
}

void check_exp(A_exp subscript)
{
    printf("a_exp: kind: %d\n", subscript->kind);
}

void check_sysType(Ty_kind ty)
{
    printf("system type: %d\n", ty);
}

void test_assignment(A_stmt a_stmt)
{
    A_assign assignstmt = a_stmt->value.assignStmt;
    A_var v = assignstmt->var;
    A_exp e = assignstmt->exp;
    printf("assignment: v(size):%ld, e(size):%ld\n", sizeof(*v), sizeof(*e));
    printf("kind: %d\n", v->kind);

    if (v->kind == A_recordField){
        table_t aexp = v->value.fieldID;
        printf("table name:%s\n", aexp->name);
    }
    else if(v->kind == A_pureID) {
        printf("pureID: %s\n", v->ID->name);
    }
    else if(v->kind == A_arrayElement){
        A_exp subscript = v->value.subscript;
        printf("A_arrayElement\n");
        //print("a_exp: kind: %d\n", subscript->kind);
        check_exp(subscript);
        if (subscript->kind == A_constExp){
            printf("a constvalue\n");
            A_const convar = subscript->value.constValue;
            check_sysType(convar->kind);
            //test real
            if (convar->kind == Ty_real)
                printf("value: %f\n", convar->value.real);
        }
    }
}

int main(int argc, char *argv[])
{
    ++argv, --argc;    /* skip argv[0] */
    if (argc > 0) {
        yyin = fopen(argv[0], "r");
    } else {
        yyin = stdin;
    }
    printf("unittest: Start parsing...:\n\n");
    yyparse();

    printf("root size = %ld\n", sizeof(root));
    printf("routine_size = %ld\n", sizeof(root->routine));
    /*test symbol_table*/
    printf("table_name: %s\n", get_sym_name(root->name));

    /*test A_stmtList*/
    A_stmtList a_stmtlist_head = root->routine->compoundStmt;
    printf("A_stmtList: %ld\n", sizeof(*a_stmtlist_head));

    test_stmt(a_stmtlist_head);
    A_stmt a_stmt = a_stmtlist_head->head;
    if (!a_stmt)
        printf("lalala\n");
    getStmt(a_stmt);

    //check assignStmt
    if (a_stmt->kind == A_assignStmt){
        test_assignment(a_stmt);
    }
    
    


    return 0;
};