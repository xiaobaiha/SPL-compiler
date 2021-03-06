#ifndef SYMBOL_H
#define SYMBOL_H 
#include <stdlib.h>

#define MAXBLOCKS 50
#define HASHSIZE 53

typedef struct table_s *table_t;
typedef enum {
  Basic_kind_boolean,
  Basic_kind_char,
  Basic_kind_integer,
  Basic_kind_real,
} Basic_kind;

struct table_s
{
	char* name;
	void* value;
	int offset;
	int blockind;
	Basic_kind kind;
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

int hash(const char *str);
table_t insertsymat(char *name, int blockind);

#endif