#include "conditions.h"
#include "commands.h"
#include "analysis.h"
#include <stdio.h>
#include <string.h>

#define CRASH(fmt, ...) \
fprintf(stderr, "Error occured while analysis:\n" fmt, __VA_ARGS__);

static int str_digit(char *str)
{
    unsigned int i = 0, l = strlen(str);
    for (i = 0; i < l; i++)
        if (!isdigit(str[i]))
            return 0;

    return 1;
}

static int str_reg(char *str)
{
    return (*str == 'r' && atoi(str + 1) < 32);
}

static int str_xdigit(char *str)
{
    unsigned int i = 0, l = strlen(str);
    for (i = 0; i < l; i++)
        if (!isxdigit(str[i]))
            return 0;

    return 1;
}

int get_type(char *str)
{
    switch (*str) {
        case '#':
            return ((str_digit(str + 1))?(AT_VAL):(AT_ERROR));
        break;

        case 'r':
            return ((str_reg(str))?(AT_MEM):(AT_ERROR));
        break;

        case '$':
        case '@':
        case 'm':
            return ((str_xdigit(str + 1))?(AT_MEM):(AT_ERROR));
        break;

        case '\0':
            return AT_NONE;
        break;

        default:
        break;
    }

    return AT_ERROR;
}

int analise_condition(struct operation *op)
{
	int i = 0, result = 0;
	for (i = 0; i < NUM_COND; i++)
		if (!strcmp(op->cond, conditions[i])) {
			result = 1;
			break;
		}

	if (!result)
		CRASH("Condition %s was not declared in this scope!\nLook up to the documentation, please!\n", op->cond);

	return result;
}

int analise_operation(struct operation *op)
{
	char *args[3] = {op->arg0, op->arg1, op->arg2};
	int found = ~0;
	int i = 0;

    for (i = 0; i < NUM_CMDS; i++)
        if (!strcmp(commands[i].cmd, op->cmd)) {
            found = i;
            break;
        }

	if (found == ~0) {
		CRASH("Command %s was not declared in this scope!\nLook up to the documentation, please!\n", op->cmd);
		return 0;
	}

	for (i = 0; i < 3; i++)
		if (commands[found].arg_types[i] < get_type(args[i]) || get_type(args[i]) == AT_ERROR) {
			CRASH("Invalid arg #%d type!\n", i);
			return 0;
		}

	return 1;
}
