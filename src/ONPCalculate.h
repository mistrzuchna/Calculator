#ifndef CALCULATOR_ONPCALCULATE_H
#define CALCULATOR_ONPCALCULATE_H

#include "necessaryLibraries.h"
#include "stackHandle.h"
#include "menu.h"

/**
 * zmienna globalna, do której zapisywany jest wynik obliczonego wyrażenia
 */
double finalResult;

/**
 * funkcja obliczająca wyrażenie w postaci ONP
 * @param phraseInONP wyrażenie w postaci ONP
 * @param top wierzchołek stosu
 */
void ONPCalculations(char *phraseInONP, struct stack *top);

#endif //CALCULATOR_ONPCALCULATE_H
