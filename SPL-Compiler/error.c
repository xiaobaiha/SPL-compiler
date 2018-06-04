#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "error.h"
#include "util.h"
#include "absyn.h"
#include "y.tab.h"

Bool anyErrors = (char *)FALSE;

static string fileName = "";

static int lineNum = 1;

int EM_tokPos=0;

extern FILE *yyin;

typedef struct intList {int i; struct intList *rest;} *IntList;

//支持可变参数
void fatal_error(const char *fmt, ... )
{
	va_list vl;
  
	va_start(vl,fmt);
	vfprintf(stderr,fmt,vl);
	va_end(vl);
	fprintf(stderr,"at line number:\n");
	exit(1);
}

static IntList intList(int i, IntList rest) 
{
	IntList l= checked_malloc(sizeof(*l));
 	l->i=i; l->rest=rest;
 	return l;
}

static IntList linePos=NULL;

void lex_newline(void)
{
	lineNum++;
 	linePos = intList(EM_tokPos, linePos);
}

void general_error(int pos, char *message,...)
{
	va_list ap;
 	IntList lines = linePos; 
 	int num=lineNum;
 
	anyErrors=(char*)TRUE;
	while (lines && lines->i >= pos) 
		{lines=lines->rest; num--;}

	if (fileName) 
		fprintf(stderr,"%s:",fileName);
	fprintf(stderr,"at line number: %d.%d: ", num, pos-lines->i);
	va_start(ap,message);
	vfprintf(stderr, message, ap);
	va_end(ap);
	fprintf(stderr,"\n");

}

void EM_reset(string fname)
{
	anyErrors=FALSE; 
	fileName=fname; 
	lineNum=1;
	linePos=intList(0,NULL);
	yyin = fopen(fname,"r");
	if (!yyin) {
		general_error(0,"cannot open"); 
		exit(1);
	}
}

void lexError(int lineCnt, int tok, char *message, ...) {
	//printf("at line %d\n", lineCnt);
	//general_error(tok, message);
	//fprintf(stderr,"at line number: %d.%s: \n", lineCnt, message);
	va_list ap;
	va_start(ap, message);
	general_error(tok, message);
	va_end(ap);
}