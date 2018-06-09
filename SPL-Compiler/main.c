#include <stdio.h>
#include <string.h>
#include "absyn.h"
#include "symbol.h"
#include "y.tab.h"
#include "genasm.h"
#include "codegen.h"

extern A_pro root;

int main() {

	int res;
	res = yyparse();

	gencode(root, 32, 32);
	//codeGen(parseresult, blockoffs[blocknumber], labelnumber-1);
	return 0;
}