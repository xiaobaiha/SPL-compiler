/*
 * util.h - commonly used utility functions Header
 */
#ifndef UTIL_H
#define UTIL_H

#include <assert.h>
#include <stdio.h>

typedef char *string;
typedef char *Bool;

#define TRUE 1
#define FALSE 0

void *checked_malloc(int);
string String(char *);
//void adjust(string text);

typedef struct U_boolList_ *U_boolList;
struct U_boolList_ {Bool head; U_boolList tail;};
U_boolList U_BoolList(Bool head, U_boolList tail);

#endif