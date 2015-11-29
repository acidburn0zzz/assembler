#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

#include "../parser/parser.h"
#include "analysis.h"

int main(int argn, char * const *argv)
{
	int a = 0;

	if (argn <= 1) {
		fprintf(stderr, "No files for parsing\n");
		return EINVAL;
	}

	for (a = 1; a < argn; a++) {
		FILE *input = fopen(argv[a], "r");
		if (!input) {
			fprintf(stderr, "Failed to open file '%s': %s\n", argv[a], strerror(errno));
			return errno;
		}

		while (!feof(input)) {
			char buf[1024] = "";
			struct operation* op = 0;

			if (!fgets(buf, sizeof(buf) - 1, input))
             		   	break;

			op = parse_code(buf);
			analise_condition(op);
			analise_operation(op);

			free((void *)op);
		}

		fclose(input);
	}

	return 0;
}
