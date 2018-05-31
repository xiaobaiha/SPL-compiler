#ifndef SYMBOL_H
#define SYMBOL_H 

typedef struct table_s *table_t;
struct table_s
{
	char* name;	
};

table_t make_table_s(char * name);

char *get_sym_name(table_t s);

#endif