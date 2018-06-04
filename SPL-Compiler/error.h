//#ifndef ERROR_H
//#define ERROR_H


extern char EM_anyErrors;

void lex_newline(void);

extern int EM_tokPos;

void general_error(int, char *,...);
//void EM_lex_error(char *message, ...);
void EM_impossible(char *,...);
void EM_reset(char * filename);

void fatal_error(const char *fmt, ... );

void lexError(int, int ,char *,...);

//#endif