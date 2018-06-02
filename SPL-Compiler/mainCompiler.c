#include <stdio.h>
#include <string.h>
#include "y.tab.h"

extern A_pro;

int main() {

	int res;
	res = yyparse();

	
	//codeGen(parseresult, blockoffs[blocknumber], labelnumber-1);
	return 0;
}