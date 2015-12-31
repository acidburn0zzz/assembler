#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "parser/parser.h"
#include "analysis/analysis.h"
#include "assemble/compiler.h"

void usage(void);
int is_flag(char * const str);

const int IN = 0,
          OUT = 1;

char * const *flags = {"-i",
                       "-o"};

#define NUM_FLAGS 2

char * const default_out = "out.object";

int main(int argn, char * const *argv)
{
	int i = 0;
	char **paths = {0};
	int request_flag = ~0;
	FILE *data[3] = {0};

	if (argn < 3) {
		usage();
		return EINVAL;
	}

	for (i = 1; i < argn; i++) {
		if (request_flag > 0) {
			paths[i] = argv[i];		
			request_flag = ~0;
		}

		else {
			if (!is_flag(argv[i])) {
				usage();
				return EINVAL;
			}
		}
	}

	for (i = 0; i < NUM_FLAGS; i++) {
		if (!paths[i] && i == OUT)
			paths[i] = default_out;

		else if (i == IN && !paths[i]) {
			fprintf(stderr, "No input!\n");
			usage();
			return EINVAL;
		}

		data[i] = fopen(paths[i], "a+");
		if (!data[i]) {
			fprintf(stderr, "Error!\nCan't open file '%s': '%s'!\n", paths[i], strerror(errno));
			return errno;
		}
	}

	while (!feof(data[IN])) {
		char buf[1024] = "";
		struct operation *op = 0;
		struct cmd *command = 0;

		if (!fgets(buf, sizeof(buf) - 1, data[IN])) {
			break;
		}
		
		if (*buf == '\n' || *buf == ';') {
			continue;
		}

		op = parse_code(buf);
		command = assemble_operation(op);	
		dump_to_file(data[OUT], command);
	}
}

void usage(void)
{
	fprintf(stderr, "Usage:\n"
                        "\"-i\" place it before the path to input program file\n"
                        "\"-o\" place it before the path to output for generated object code\n");
}

int is_flag(char *const str)
{
	int i;
	for (i = 0; i < NUM_FLAGS; i++) {
		if (!strcmp(str, flags[i])) {
			return i;
		}
	}

	return ~0;
}
