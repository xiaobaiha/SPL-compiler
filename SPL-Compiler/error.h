//#ifndef ERROR_H
//#define ERROR_H


extern char EM_anyErrors;

void EM_newline(void);

extern int EM_tokPos;

void EM_error(int, char *,...);
//void EM_lex_error(char *message, ...);
void EM_impossible(char *,...);
void EM_reset(char * filename);

void fatal_error(const char *fmt, ... );

//#endif