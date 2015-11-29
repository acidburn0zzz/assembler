#include "commands.h"

const int NUM_CMDS = 15;

const struct command commands[15] = {{"mov",   {AT_MEM,  AT_VAL,  AT_NONE}},
                                     {"push",  {AT_VAL,  AT_NONE, AT_NONE}},
                                     {"pop",   {AT_MEM,  AT_NONE, AT_NONE}},
                                     {"cmp",   {AT_VAL,  AT_VAL,  AT_NONE}},
                                     {"swi",   {AT_VAL,  AT_NONE, AT_NONE}},
                                     {"and",   {AT_MEM,  AT_VAL,  AT_VAL}},
                                     {"or",    {AT_MEM,  AT_VAL,  AT_VAL}},
                                     {"xor",   {AT_MEM,  AT_VAL,  AT_VAL}},
                                     {"not",   {AT_MEM,  AT_VAL,  AT_NONE}},
                                     {"compl", {AT_MEM,  AT_VAL,  AT_NONE}},
                                     {"add",   {AT_MEM,  AT_VAL,  AT_VAL}},
                                     {"sub",   {AT_MEM,  AT_VAL,  AT_VAL}},
                                     {"mul",   {AT_MEM,  AT_VAL,  AT_VAL}},
                                     {"seg",   {AT_MEM,  AT_VAL,  AT_VAL}},
                                     {"nop",   {AT_NONE, AT_NONE, AT_NONE}}};
