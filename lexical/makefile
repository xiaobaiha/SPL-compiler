out: scanner

scanner: lex.yy.c token.h
	gcc -o $@ $<

lex.yy.c: spl.l
	flex $<