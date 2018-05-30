#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "error.h"

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