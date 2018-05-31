#include "symbol.h"
#include "utils.h"

table_t make_table_t(char * name){
	table_t s;
	check_malloc(s, sizeof(*s));
	s->name = name;
	return s;
}

char *get_sym_name(table_t s){
	return s->name;
}