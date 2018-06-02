#include <stdio.h>
#include <string.h>
#include "y.tab.h"

int main() {

	int res;
	res = yyparse();

	//codeGen(parseresult, blockoffs[blocknumber], labelnumber-1);
	return 0;
}