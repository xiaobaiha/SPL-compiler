#include "symbol.h"
#include "util.h"
#include <string.h>

SymbolTable* symbolTable;


/*
 *	Interface of SymbolTable
 *	Four main API:
 *	makeSymbol: para(key, value), return single symbol
 *	get_sym_name: para(symbol), return name of symbol
 * 	lookupSymbolTable: para(symbol), return the symbol found OR NULL
 * 	addToSymbolTable: para(symbol, size), return the name of symbo;
 */
table_t makeSymbol(char* name, void* val)
{
	table_t s;
	s = (table_t)checked_malloc(sizeof(*s));
    s->name = name;
    s->value = val;
	return s;
}

char *get_sym_name(table_t s)
{
	return s->name;
}

int initSymbolTable()
{
	symbolTable = checked_malloc(sizeof(*symbolTable));
    symbolTable -> head = 0;
    return 0;
}

table_t lookupSymbolTable(table_t symbol_p)
{
	struct table_s* symbol = symbolTable -> head;
    while (symbol)
    {
        if (strcmp((char *) symbol -> name, (char *)symbol_p->name) == 0)
            return symbol;
        symbol = symbol -> next;
    }

    return NULL;
}

char* addToSymbolTable(table_t sym, size_t length)
{
    add(symbolTable, sym, sizeof(char)*length);
    return (char *)(symbolTable -> head -> name);
}

table_t popFromSymbolTable()
{
	return pop(symbolTable);
}


//Just for use in this file
int add(SymbolTable* list, void *data, int size)
{
    struct table_s* addition = malloc(sizeof(*addition));
    addition -> name = checked_malloc(size);
    addition -> next = (list -> head);

    for (int i = 0; i < size; i++)
        *(char *) (addition -> name + i) = *(char *) (data + i);
    list -> size++;

    list -> head = addition;//add to header

    return list -> size;
}

void* pop(SymbolTable* list)
{
    struct table_s* head = list -> head;
    struct table_s* next = head -> next;

    void* data = head -> name;
    list -> head = next;
    list -> size--;

    return data;
}