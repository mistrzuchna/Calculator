#include "algebraicHandle.h"


void algebraicToONP(char *phraseInAlgebraicForm, struct stack *top, char *ONPFromAlgebraic) {

    char *temp = calloc(40, sizeof(char));
    char *token;
    char s[] = " ";
    token = strtok(phraseInAlgebraicForm, s);
    if (stepByStep)
        printf("Wprowadzone wyrazenie jest w postaci algebraicznej. Rozpoczecie konwersji na postac w ONP.\n");
    while (token != NULL) {
        if (atof(token) != 0) {
            // jeśli element jest liczbą odłóż na "wyjście" -- dopisz do ONPFromAlgebraic[]
            strcat(ONPFromAlgebraic, token);
            strcat(ONPFromAlgebraic, s);
            if (stepByStep) {
                printf("Dopisanie liczby %s do tworzonej przez program postaci ONP.\n", token);
                printf("Dotychczasowe ONP po operacji:\n");
                printf("%s\n", ONPFromAlgebraic);
                printf("Stos po operacji:\n");
                stackViev(top);
            }
        } else if (*token == '+' || *token == '-' ||
                   *token == '*' || *token == '/' ||
                   *token == '%') {
            doAppropriateSteps(token, &top, ONPFromAlgebraic);
        } else if (*token == '^') { //nie ma potrzeby sprawdzać, bo nie ma ważniejszego operatora
            top = push(top, token);
        } else if (*token == '(') {
            top = push(top, token);
        } else if (*token == ')') {
            while (*peek(top) != '(') {
                top = pop(top, temp);
                strcat(ONPFromAlgebraic, temp);
                strcat(ONPFromAlgebraic, s);
            }
            top = pop(top, temp);
            if (stepByStep) {
                printf("Dopisanie operatora %s do nowej postaci ONP.\n", token);
                printf("Dotychczasowe ONP po operacji:\n");
                printf("%s", ONPFromAlgebraic);
                printf("Stos po operacji:\n");
                stackViev(top);
            }
        } else if (*token == '=') {
            while (top != NULL) {
                top = pop(top, temp);
                strcat(ONPFromAlgebraic, temp);
                strcat(ONPFromAlgebraic, s);
            }
            strcat(ONPFromAlgebraic, token);
            if (stepByStep) {
                printf("Operator = oznacza koniec wyrazenia.\n");
                printf("ONP po operacji:\n");
                printf("%s\n", ONPFromAlgebraic);
                printf("Stos po operacji:\n");
                stackViev(top);
            }
        }
        token = strtok(NULL, s);
        if (stepByStep)
            getchar();
    }
    if (stepByStep)
        printf("Postac naszego wyrazenia po przeksztalceniu na postac w ONP: %s\n", ONPFromAlgebraic);
}


void doAppropriateSteps(char *operator, struct stack **top,
                        char *ONPFromAlgebraic) { //dalej w programie token po prostu
    char *temp = calloc(40, sizeof(char));
    char space[] = " ";
    if (getPriority(operator) <= getPriority(peek(*top))) {
        while (*top != NULL) {
            *top = pop(*top, temp);
            strcat(ONPFromAlgebraic, temp);
            strcat(ONPFromAlgebraic, space);
            if (stepByStep)
                printf("Dopisanie operatora %s do nowej postaci ONP.\n", operator);
        }
    }
    *top = push(*top, operator);
    if (stepByStep) {
        printf("Odlozenie operatora %s na stos.\n", operator);
        printf("Dotychczasowe ONP po operacji:\n");
        printf("%s\n", ONPFromAlgebraic);
        printf("Stos po operacji:\n");
        stackViev(*top);
    }
}

int getPriority(const char *operator) {
    if (operator == NULL)
        return -1;
    if (*operator == '(')
        return 0;
    else if (*operator == '+' || *operator == '-')
        return 1;
    else if (*operator == '*' || *operator == '/' || *operator == '%')
        return 2;
    else if (*operator == '^')
        return 3;
}