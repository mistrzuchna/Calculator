#include "ONPCalculate.h"

void ONPCalculations(char *phraseInONP, struct stack *top) {
    char *token;
    char s[] = " ";
    if (stepByStep)
        printf("Liczenie wyrazenia z postaci w ONP.\n");
    token = strtok(phraseInONP, s);
    char *temp = calloc(40, sizeof(char));

    while (token != NULL) {
        double first = 0, second = 0, result = 0;

        if (atof(token) != 0) {            // jeśli element jest liczbą
            top = push(top, token);
            if (stepByStep) {
                printf("Odlozenie liczby %s na stos.\n", token);
                printf("Stos po operacji:\n");
                stackViev(top);
            }
        } else if (*token == '+') {
            // zdejmij 2 elementy ze stosu i dodaj, potem odloz wynik na stos
            char output[40] = "";
            top = pop(top, temp);
            first = atof(temp);
            top = pop(top, temp);
            second = atof(temp);
            result = first + second;
            snprintf(output, 50, "%lf", result);
            top = push(top, output);
            if (stepByStep) {

                printf("Zdemowanie dwoch liczb ze stosu i wykonanie dodawania.\n");
                printf("Stos po operacji:\n");
                stackViev(top);
            }
        } else if (*token == '-') {
            // zdejmij 2 elementy ze stosu i dodaj, potem odloz wynik na stos
            char output[40] = "";
            top = pop(top, temp);
            first = atof(temp);
            top = pop(top, temp);
            second = atof(temp);
            result = second - first;
            snprintf(output, 50, "%lf", result);
            top = push(top, output);
            if (stepByStep) {

                printf("Zdemowanie dwoch liczb ze stosu i wykonanie odejmowania.\n");
            }
        } else if (*token == '*') {
            char output[40] = "";
            top = pop(top, temp);
            first = atof(temp);
            top = pop(top, temp);
            second = atof(temp);
            result = first * second;
            snprintf(output, 50, "%lf", result);
            top = push(top, output);
            if (stepByStep) {

                printf("Zdemowanie dwoch liczb ze stosu i wykonanie mnozenia.\n");
            }
        } else if (*token == '/') {
            char output[40] = "";
            top = pop(top, temp);
            first = atof(temp);
            top = pop(top, temp);
            second = atof(temp);
            result = second / first;
            snprintf(output, 50, "%lf", result);
            top = push(top, output);
            if (stepByStep) {

                printf("Zdemowanie dwoch liczb ze stosu i wykonanie dzielenia.\n");
            }
        } else if (*token == '^') {
            char output[40] = "";
            top = pop(top, temp);
            first = atof(temp);
            top = pop(top, temp);
            second = atof(temp);
            result = pow(second, first);
            snprintf(output, 50, "%lf", result);
            top = push(top, output);
            if (stepByStep) {

                printf("Zdemowanie dwoch liczb ze stosu i wykonanie potegowania.\n");
                stackViev(top);
            }
        } else if (*token == '%') {
            char output[40] = "";
            top = pop(top, temp);
            first = atof(temp);
            top = pop(top, temp);
            second = atof(temp);
            result = (int) second % (int) first;
            snprintf(output, 50, "%lf", result);
            top = push(top, output);
            if (stepByStep) {
                printf("Zdemowanie dwoch liczb ze stosu i wykonanie modulo.\n");
            }
        } else if (*token == '=') {
            if (stepByStep) {
                printf("Napotkano znak rownosci, wiec jedyny element na stosie jest naszym wynikiem.\n");
            }
            finalResult = atof(peek(top));
            printf("Wynik wprowadzonego wyrazenia wynosi: %.2f", finalResult);
        }
        token = strtok(NULL, s);
        if (stepByStep)
            getchar();
    }
}

