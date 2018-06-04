#include <stdio.h>
#include <string.h>
#include "absyn.h"
#include "symbol.h"
#include "y.tab.h"

extern A_pro root;

int main() {

	int res;
	res = yyparse();

	//codegen(root);
	//codeGen(parseresult, blockoffs[blocknumber], labelnumber-1);
	return 0;
}