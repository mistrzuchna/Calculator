#ifndef CALCULATOR_STACKHANDLE_H
#define CALCULATOR_STACKHANDLE_H

#include "necessaryLibraries.h"

/**
 * typ bazowy stosu
 */
struct stack;

/**
 * funkcja dodająca element na stos
 * @param top wierzchołek stosu
 * @param data dana do dodania
 * @return zwraca wierzchołek
 */
struct stack *push(struct stack *top, char *data);

/**
 * funkcja usuwająca aktualny wierzchołek stosu
 * @param top wierzchołek stosu
 * @param result
 * @return wartość usuniętego elementu
 */
struct stack *pop(struct stack *top, char *result);

/**
 * funkcja do podglądania wierzchołka stosu
 * @param top wierzchołek stosu
 * @return wartość na wierzchołku
 */
char *peek(struct stack *top);

/**
 * funkcja drukująca zawartość stosu
 * @param top wierzchołek stosu
 */
void stackViev(struct stack *top);

#endif //CALCULATOR_STACKHANDLE_H
