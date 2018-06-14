#ifndef CALCULATOR_MENU_H
#define CALCULATOR_MENU_H

#include "necessaryLibraries.h"

bool stepByStep;

void printMenu();

int menuChoice(int choice);  //zwraca 0 dla klawiatury, 1 dla pliku

bool stepByStepVersion();

void phraseInput(char *phrase);

#endif //CALCULATOR_MENU_H
