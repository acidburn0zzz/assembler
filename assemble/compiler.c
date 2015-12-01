#include "../analysis/commands.h"
#include "../analysis/conditions.h"
#include "compiler.h"
#include "../analysis/analysis.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

struct cmd *assemble_operation(struct operation *op)
{
	struct cmd *result = (struct cmd *)calloc(1, sizeof(*result));
	char *args[3] = {op->arg0, op->arg1, op->arg2};
	unsigned int i = 0;

	if (!analise_operation(op) || !analise_condition(op))
		return 0;

	for (i = 0; i < NUM_COND; i++) {
		if (!strcmp(op->cond, conditions[i]))
			result->cond = i;
	}

	for (i = 0; i < NUM_CMDS; i++) {
		if (!strcmp(op->cmd, commands[i].cmd))
			result->opcode = i;
	}

	for (i = 0; i < 3; i++)
		result->types[i] = get_type(args[i]);

	for (i = 0; i < 3; i++)
		result->values[i] = atoi(args[i] + 1);

	return result;
}

void dump_to_file(FILE *out, struct cmd *command)
{
	int i;

	if (!out) {
		fprintf(stderr, "No out!\n");
		return;
	}

	if (!command) {
		fprintf(stderr, "No command!\n");
		return;
	}

	fprintf(out, "%d %d ", command->cond, command->opcode);

	for (i = 0; i < 3; i++)
		fprintf(out, "%d %d ", command->types[i], command->values[i]);

	fprintf(out, "\n");
}
