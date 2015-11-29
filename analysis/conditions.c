#include "conditions.h"

const int NUM_COND = 7;

const char *conditions[7] = {"eq", // compare flag is 'equals'
                             "ne", // compare flag is 'not equals'
                             "ae", // compare flag is 'above or equals'
                             "le", // compare flag is 'less or equals'
                             "ls", // compare flag is 'less'
                             "av", // compare flag is 'above'
                             "al"};// no flag, ignored by soft-processor
