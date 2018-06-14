#ifndef CALCULATOR_MENU_H
#define CALCULATOR_MENU_H

#include "necessaryLibraries.h"
/**
 * zmienna określająca czy wyświetlać "krok po kroku"
 */
bool stepByStep;

/**
 * funkcja drukująca opcje wyboru - wyrażenie z klawiatuy czy z pliku
 */
void printMenu();

/**
 * funkcja pobierająca wybór użytkownika
 * @param choice
 * @return zwraca wartość 0 jeżeli użytkownik będzie wprowadzał dane z klawiatury, 1 - z pliku
 */
int menuChoice(int choice);  //zwraca 0 dla klawiatury, 1 dla pliku

/**
 *  funkcja pytająca czy użytkownik chce aby wyświetlić wersję "krok po kroku"
 * @return zwraca true gdy odpowiedź brzmi tak, false - gdy nie
 */
bool stepByStepVersion();

/**
 * funkcja pobierająca od użytkownika z klawiatury wyrażenie do obliczenia
 * @param phrase wyrażenie do obliczenia
 */
void phraseInput(char *phrase);

#endif //CALCULATOR_MENU_H
