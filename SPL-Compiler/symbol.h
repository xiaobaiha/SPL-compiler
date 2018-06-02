#ifndef SYMBOL_H
#define SYMBOL_H 
#include <stdlib.h>

typedef struct table_s *table_t;
struct table_s
{
	char* name;
	void* value;
	table_t next;
};

typedef struct symbol_table {
    struct table_s* head;
    int size;
} SymbolTable;

table_t makeSymbol(char * name, void* val);

char *get_sym_name(table_t s);

int initSymbolTable();
table_t lookupSymbolTable(table_t symbol);
char* addToSymbolTable(table_t symbol, size_t length);
table_t popFromSymbolTable();

int add(SymbolTable* list, void *data, int size);
void* pop(SymbolTable* list);

#endif