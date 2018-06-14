#ifndef CALCULATOR_STACKHANDLE_H
#define CALCULATOR_STACKHANDLE_H

#include "necessaryLibraries.h"

struct stack;

struct stack *push(struct stack *top, char *data);

struct stack *pop(struct stack *top, char *result);

char *peek(struct stack *top);

void stackViev(struct stack *top);

#endif //CALCULATOR_STACKHANDLE_H
