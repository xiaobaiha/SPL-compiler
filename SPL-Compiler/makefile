CC = gcc
OUT = main
OBJ = main.o lex.yy.o y.tab.o util.o error.o symbol.o types.o absyn.o
SCANNER = spl.l
PARSER = spl.y

build: $(OUT)

run: $(OUT)
	./$(OUT) < text_example/test1.spl > test.asm

clean:
	rm -f *.o *.asm y.output $(OUT)

$(OUT): $(OBJ)
	$(CC) -o $(OUT) $(OBJ)

main.o: main.c absyn.h y.tab.c symbol.h
	$(CC) -g -c main.c

unittest.o: unittest.c absyn.h y.tab.c symbol.h
	$(CC) -g -c unittest.c

y.tab.o: y.tab.c
	$(CC) -g -c y.tab.c

error.o: error.c error.h util.h
	$(CC) -g -c error.c

lex.yy.o: lex.yy.c y.tab.h error.h util.h absyn.h 
	$(CC) -g -c lex.yy.c

lex.yy.c: $(SCANNER) y.tab.c
	flex $<

util.o: util.c util.h
	$(CC) -g -c util.c

absyn.o: absyn.c symbol.h types.h util.h types.h
	$(CC) -g -c absyn.c

types.o: types.c types.h symbol.h util.h
	$(CC) -g -c types.c

symbol.o: symbol.c symbol.h util.h
	$(CC) -g -c symbol.c

y.tab.c: $(PARSER)
	bison -vdty $<