#ifndef CALCULATOR_ALGEBRAICHANDLE_H
#define CALCULATOR_ALGEBRAICHANDLE_H
#include "necessaryLibraries.h"
#include "stackHandle.h"
#include "menu.h"


/**
 * funkcja zamieniająca postać algebraiczną na wyrażenie w postaci ONP
 * @param phraseInAlgebraicForm wyrażenie w postaci algebraicznej wprowadzona przez uzytkownika lub z pliku
 * @param top wierzcholek stosu
 * @param ONPFromAlgebraic łańcuch znaków na przekształconą z postaci algebraicznej postać ONP
 */
void algebraicToONP(char *phraseInAlgebraicForm, struct stack *top, char *ONPFromAlgebraic);

/**
 * funkcja określająca, jakie kroki ma podjąć program napotykając dany w parametrze operator
 * @param operator operator działania, według którego należy określić odpowiednie kroki
 * @param top wierzchołek stosu
 * @param ONPFromAlgebraic łańcuch znaków na przekształconą z postaci algebraicznej postać ONP
 */
void doAppropriateSteps(char *operator, struct stack **top, char *ONPFromAlgebraic);
/**
 * funkcja określająca priorytet każdego operatora
 * @param operator operator, którego priortyet ma zostać określony
 * @return zwraca liczbę typu int odpowiadającą priorytetowi danego operatora
 */
int getPriority(const char *operator);

#endif //CALCULATOR_ALGEBRAICHANDLE_H
