#ifndef COMPILER_H
#define COMPILER_H

#include <stdio.h>
#include "../parser/parser.h"

struct cmd {
	int cond;
	int opcode;

	int types[3];
	double values[3];
};

struct cmd *assemble_operation(struct operation *op);
void dump_to_file(FILE *out, struct cmd *command);

#endif // COMPILER_H
