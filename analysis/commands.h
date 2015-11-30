#ifndef COMMANDS_H
#define COMMANDS_H

struct command {
    char cmd[32];

#define AT_MEM 0
#define AT_VAL 1
#define AT_NONE 2
#define AT_ERROR -1
    int arg_types[3];
};

extern const int NUM_CMDS;
extern const struct command commands[17];

#endif // COMMANDS_H
