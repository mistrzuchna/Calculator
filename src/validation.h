#ifndef CALCULATOR_VALIDATION_H
#define CALCULATOR_VALIDATION_H

#include "necessaryLibraries.h"

/**
 * funkcja sprawdzająca czy wprowadzone wyrażenie jest w ONP
 * @param phrase wyrażenie do obliczenia
 * @return true - gdy jest w ONP, false - gdy nie jest
 */
bool isONP(char *phrase);

/**
 * funkcja sprawdzająca czy jest odpowiednia liczba operatorów
 * @param phrase wyrażenie do obliczenia
 * @return true - gdy jest poprawna, false - gdy niepoprawna
 */
bool isNumberOfOperatorsCorrect(char *phrase);

/**
 * funkcja sprawdzająca czy jest odpowiednia liczba i parowanie nawiasów
 * @param phrase wyrażenie do obliczenia
 * @return true - gdy jest poprawna, false - gdy niepoprawna
 */
bool isNumberOfBracketsCorrect(char *phrase);


#endif //CALCULATOR_VALIDATION_H
