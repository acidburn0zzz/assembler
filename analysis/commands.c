#include "commands.h"

const int NUM_CMDS = 18;

const struct command commands[18] = {{"mov",    {AT_REG,  AT_VAL,  AT_NONE}},// Done
                                     {"push",   {AT_VAL,  AT_NONE, AT_NONE}},
                                     {"pop",    {AT_REG,  AT_NONE, AT_NONE}},
                                     {"cmp",    {AT_VAL,  AT_VAL,  AT_NONE}},
                                     {"swi",    {AT_VAL,  AT_NONE, AT_NONE}},
                                     {"and",    {AT_REG,  AT_VAL,  AT_VAL}},// Done
                                     {"or",     {AT_REG,  AT_VAL,  AT_VAL}},// Done
                                     {"xor",    {AT_REG,  AT_VAL,  AT_VAL}},// Done
                                     {"not",    {AT_REG,  AT_VAL,  AT_NONE}},// Done
                                     {"compl",  {AT_REG,  AT_VAL,  AT_NONE}},// Done
                                     {"add",    {AT_REG,  AT_VAL,  AT_VAL}},// Done
                                     {"sub",    {AT_REG,  AT_VAL,  AT_VAL}},// Done
                                     {"mul",    {AT_REG,  AT_VAL,  AT_VAL}},// Done
                                     {"seg",    {AT_REG,  AT_VAL,  AT_VAL}},// Done
                                     {"nop",    {AT_NONE, AT_NONE, AT_NONE}},// Done
                                     {"inc",    {AT_REG,  AT_NONE, AT_NONE}},// Done
                                     {"dec",    {AT_REG,  AT_NONE, AT_NONE}},// Done
                                     {"return", {AT_VAL, AT_NONE, AT_NONE}}};// Done
