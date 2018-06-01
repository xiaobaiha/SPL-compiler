#ifndef ERROR_H
#define ERROR_H

extern bool EM_anyErrors;

void EM_newline(void);

extern int EM_tokPos;

void EM_error(int, string,...);
void EM_impossible(string,...);
void EM_reset(string filename);

void fatal_error(const char *fmt, ... );

#endif