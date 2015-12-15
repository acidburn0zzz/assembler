#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "../parser/parser.h"
#include "compiler.h"

int main(int argn, char * const *argv)
{
	int a = 0;

	if (argn <= 1) {
		fprintf(stderr, "No files for compiling\n");
		return EINVAL;
	}

	for (a = 1; a < argn; a++) {
		FILE *input = fopen(argv[a], "r");

		char out[strlen(argv[a]) + 8];
		sprintf(out, "%s.object", argv[a]);
		FILE *output = fopen(out, "w");

		if (!input) {
			fprintf(stderr, "Failed to open file '%s': %s\n", argv[a], strerror(errno));
			return errno;
		}

		while (!feof(input)) {
			char buf[1024] = "";
			struct operation *op = 0;
			struct cmd *command = 0;

			if (!fgets(buf, sizeof(buf) - 1, input))
             		   	break;

			if (*buf == '\n')
				continue;

			op = parse_code(buf);
			dump_operation(op);

			command = assemble_operation(op);
			dump_to_file(output, command);

			free((void *)op);
			free((void *)command);
		}

		fclose(input);
		fclose(output);
	}

	return 0;
}
