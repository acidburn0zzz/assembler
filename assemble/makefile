FLAGS:=-g -O0
OUT:=-o assembler.elf
FILES:=assembler.c ../analysis/analysis.c ../analysis/analysis.h ../analysis/commands.h ../analysis/conditions.h ../analysis/conditions.c ../analysis/commands.c ../parser/parser.c ../parser/parser.h compiler.c compiler.h

all: assembler

assembler:
	gcc $(FLAGS) $(FILES) $(OUT)
