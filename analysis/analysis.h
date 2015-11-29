#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "../parser/parser.h"

int get_type(char *str);
int analise_condition(struct operation *op);
int analise_operation(struct operation *op);

#endif // ANALYSIS_H
