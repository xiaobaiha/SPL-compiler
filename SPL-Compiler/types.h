#ifndef TYPES_H
#define TYPES_H
#include "symbol.h"

#define TY__BOOLEAN 1
#define TY_CHAR 2
#define TY_INTEGER 3
#define TY_REAL 4
#define TY_STRING 5

typedef struct Ty_ty_ *Ty_ty;
typedef enum {
  Ty_boolean,
  Ty_char,
  Ty_integer,
  Ty_real,
  Ty_string,
  Ty_array,
  Ty_name
} Ty_kind;

struct Ty_ty_
{
  Ty_kind kind;
  union {
    //Ty_fieldList record;
    Ty_ty array;
    struct
    {
      table_t sym;
      Ty_ty ty;
    } name;
  } u;
};

Ty_ty makeSysType(int flag);
Ty_ty Ty_Array(Ty_ty ty);
Ty_ty Ty_Name(table_t sym, Ty_ty ty);

#endif