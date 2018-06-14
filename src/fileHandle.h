#ifndef CALCULATOR_FILEHANDLE_H
#define CALCULATOR_FILEHANDLE_H

#include "necessaryLibraries.h"
#include "ONPCalculate.h"
#include "stackHandle.h"
#include "algebraicHandle.h"
#include "validation.h"

void countFromFile(struct stack *top, char *phrase, int counter);

void filePathNameChange(char *filePath, char *scorePath);

#endif //CALCULATOR_FILEHANDLE_H
