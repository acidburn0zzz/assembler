FLAGS:=-g -O0

PARSER:=parser/parser.h parser/parser.c
ALANYSIS:=analysis/conditions.h analysis/conditions.c analysis/commands.h analysis/commands.c analysis/analysis.h analysis/analysis.c
ASSEMBLE:=assembler/compiler.h assembler/compiler.c assembler.c

all: assembler

assembler:
	gcc $(FLAGS) $(PARSER) $(ANALYSIS) $(ASSEMBLE) -o assembler
