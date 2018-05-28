CC = gcc
OUT = tcc
OBJ = lex.yy.o y.tab.o
SCANNER = spl.l
PARSER = spl.y

build: $(OUT)

run: $(OUT)
	./$(OUT) < text_example/test2.spl > test.asm

clean:
	rm -f *.o lex.yy.c y.tab.c y.tab.h y.output $(OUT)

$(OUT): $(OBJ)
	$(CC) -o $(OUT) $(OBJ)

lex.yy.c: $(SCANNER) y.tab.c
	flex $<

y.tab.c: $(PARSER)
	bison -vdty $<