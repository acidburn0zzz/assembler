#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "parser.h"

#define SON(x) (((x) && (*(x) != '\0'))?(x):"NONE")

void dump_operation(struct operation *op)
{
	if (!op) {
		printf("OP: NULL\n");
		return;
	}

	printf("COND: \"%s\"\nOP: \"%s\"\nARGS: \"%s\", \"%s\", \"%s\"\n\n",
               SON(op->cond), SON(op->cmd), SON(op->arg0),
               SON(op->arg1), SON(op->arg2));
}

static inline const char *skip(const char *line, char *skips)
{
	line += strlen(skips);
	while ((*line == ' ') || (*line == ','))
		line++;

	if ((*line == '\0') || (*line == '\n') || (*line == ';'))
		return 0;

	return line;
}

static inline void str_to_lower(char *str)
{
	unsigned int l = strlen(str);
	unsigned int i = 0;

	for (i = 0; i < l; i++)
		str[i] = (char)tolower(str[i]);
}

struct operation *parse_code(const char *code)
{
	struct operation *op = (struct operation*)calloc(1, sizeof(*op));
	char *tokens[5] = {op->cond, op->cmd, op->arg0, op->arg1, op->arg2};
	unsigned int i = 0;

	for (i = 0; i < 5; i++) {
        	if (sscanf(code, "%[0-9a-zA-Z@#$]", tokens[i]) <= 0) {
			free((void *)op);
			return 0;
        	}

		str_to_lower(tokens[i]);

		code = skip(code, tokens[i]);

		if (!code)
            		break;
	}

	return op;
}
