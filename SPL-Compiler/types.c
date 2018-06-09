#include "types.h"
#include "util.h"

//static struct Ty_ty_ tyarray = {Ty_array};

/*
static struct Ty_ty_ tybool = {Ty_boolean};
static struct Ty_ty_ tychar = {Ty_char};
static struct Ty_ty_ tyint = {Ty_integer};
static struct Ty_ty_ tyreal = {Ty_real};
static struct Ty_ty_ tystr = {Ty_string};


Ty_ty makeSysType(int flag)
{
    switch(flag){
        case TY__BOOLEAN:
            return &tybool; break;
        case TY_CHAR:
            return &tychar; break;
        case TY_INTEGER:
            return &tyint; break;
        case TY_REAL:
            return &tyreal; break;
        case TY_STRING:
            return &tystr; break;
    }
}

Ty_ty Ty_Array(Ty_ty ty)
{
    Ty_ty p = checked_malloc(sizeof(*p));
    p->kind=Ty_array;
    p->u.array=ty;
    return p;
}

Ty_ty Ty_Name(table_t sym, Ty_ty ty)
{   
    Ty_ty p = checked_malloc(sizeof(*p));
    p->kind = Ty_name;
    p->u.name.sym=sym;
    p->u.name.ty=ty;
    return p;
}

*/
