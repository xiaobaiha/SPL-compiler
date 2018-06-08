#include <stdio.h>
#include <string.h>
#include "absyn.h"
#include "symbol.h"
#include "y.tab.h"

extern FILE *yyin;
extern A_pro root;

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
    printf("table_name: %s", get_sym_name(root->name));

    return 0;
};