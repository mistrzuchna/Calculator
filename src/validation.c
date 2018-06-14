#include "validation.h"

bool isONP(char *phrase) {
    char phraseCopy[100] = "", *token, s[] = " ";
    strcpy(phraseCopy, phrase);
    int counter = 0;

    token = strtok(phraseCopy, s);

    while (counter < 2) {
        if (atof(token) == 0)
            return false;
        counter++;
        token = strtok(NULL, s);
    }
    return true;
}

bool isNumberOfOperatorsCorrect(char *phrase) {

    char phraseCopy[40] = "";
    strcpy(phraseCopy, phrase);

    char *token;
    char s[] = " ";

    int digitsCounter = 0;
    int operatorsCounter = 0;

    token = strtok(phraseCopy, s);

    while (token != NULL) {

        if (atof(token) != 0) {
            digitsCounter++;
        } else if (*token == '(' || *token == ')') {}
        else if (*token == '+' || *token == '-' ||
                 *token == '*' || *token == '/' ||
                 *token == '%' || *token == '^' ||
                 *token == '=')
            operatorsCounter++;
        else {
            printf("Niepoprawny element w wyrazeniu! Sprawdz poprawnosc wpisanych danych.");
            return false;
        }
        token = strtok(NULL, s);
    }
    if (operatorsCounter == digitsCounter)
        return true;
    else {
        puts("Nieprawidlowa liczba operatorow w stosunku do ilosci liczb!");
        return false;
    }
}

bool isNumberOfBracketsCorrect(char *phrase) {
    char phraseCopy[100] = "";
    strcpy(phraseCopy, phrase);

    char *token;
    char s[] = " ";

    int leftBracketsCounter = 0, rightBracketsCounter = 0;

    token = strtok(phraseCopy, s);

    while (token != NULL) {

        if (*token == '(') {
            leftBracketsCounter++;
        } else if (*token == ')')
            if (leftBracketsCounter > 0) {      //najpierw musi być lewy nawias
                rightBracketsCounter++;
            } else {
                puts("Nieprawidlowe parowanie nawiasow!");
                return false;
            }
        token = strtok(NULL, s);
    }
    if (leftBracketsCounter == rightBracketsCounter)
        return true;
    else {
        puts("Nieprawidlowe parowanie nawiasow!");
        return false;
    }
}