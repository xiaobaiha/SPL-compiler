CC = gcc
OUT = tcc
OBJ = lex.yy.o y.tab.o util.o error.o
SCANNER = spl.l
PARSER = spl.y

build: $(OUT)

run: $(OUT)
	./$(OUT) < text_example/test1.spl > test.asm

clean:
	rm -f *.o *.asm lex.yy.c y.tab.c y.tab.h y.output $(OUT)

$(OUT): $(OBJ)
	$(CC) -o $(OUT) $(OBJ)

error.o: error.c error.h util.h
	$(CC) -g -c error.c

util.o: util.c util.h
	$(CC) -g -c util.c

lex.yy.o: lex.yy.c y.tab.h error.h util.h
	$(CC) -g -c lex.yy.c

lex.yy.c: $(SCANNER) y.tab.c
	flex $<

y.tab.c: $(PARSER)
	bison -vdty $<