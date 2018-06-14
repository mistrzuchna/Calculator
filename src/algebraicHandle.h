#ifndef CALCULATOR_ALGEBRAICHANDLE_H
#define CALCULATOR_ALGEBRAICHANDLE_H
#include "necessaryLibraries.h"
#include "stackHandle.h"
#include "menu.h"

void algebraicToONP(char *phraseInAlgebraicForm, struct stack *top, char *ONPFromAlgebraic);

void doAppropriateSteps(char *operator, struct stack **top, char *ONPFromAlgebraic);

int getPriority(const char *operator);

#endif //CALCULATOR_ALGEBRAICHANDLE_H
