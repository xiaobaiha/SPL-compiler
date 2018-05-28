#ifndef TOKEN_H
#define TOKEN_H

enum TokenType {
    LP = 256, RP, LB, RB, DOT, COMMA, COLON, 
    MUL, DIV, UNEQUAL, NOT, PLUS, MINUS,
    GE, GT, LE, LT, EQUAL, ASSIGN, MOD, DOTDOT,
    SEMI, AND, 
    ARRAY, BEGIN_TOKEN, CASE, CONST, DO, DOWNTO, ELSE, END,
    FOR, FUNCTION, GOTO, IF, IN, 
    OF, OR, PACKED, PROCEDURE, 
    PROGRAM, RECORD, REPEAT, SET, THEN, 
    TO, TYPE, UNTIL, VAR, WHILE, WITH,
    SYS_CON, SYS_FUNCT, SYS_PROC, SYS_TYPE,
    NAME, INTEGER, FLOAT_NUM
};

static void print_token(int token) {
    static char* token_strs[] = {
        "LP", "RP", "LB", "RB", "DOT", "COMMA", "COLON", 
        "MUL", "DIV", "UNEQUAL", "NOT", "PLUS", "MINUS",
        "GE", "GT", "LE", "LT", "EQUAL", "ASSIGN", "MOD", "DOTDOT",
        "SEMI", "AND", 
        "ARRAY", "BEGIN_TOKEN", "CASE", "CONST", "DO", "DOWNTO", "ELSE", "END",
        "FOR", "FUNCTION", "GOTO", "IF", "IN", 
        "OF", "OR", "PACKED", "PROCEDURE", 
        "PROGRAM", "RECORD", "REPEAT", "SET", "THEN", 
        "TO", "TYPE", "UNTIL", "VAR", "WHILE", "WITH",
        "SYS_CON", "SYS_FUNCT", "SYS_PROC", "SYS_TYPE",
        "NAME", "INTEGER", "FLOAT_NUM"
    };

    if (token < 256) {
        printf("%-20c", token);
    } else {
        printf("%-20s", token_strs[token-256]);
    }
}

#endif