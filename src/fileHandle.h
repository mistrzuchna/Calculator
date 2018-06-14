#ifndef CALCULATOR_FILEHANDLE_H
#define CALCULATOR_FILEHANDLE_H

#include "necessaryLibraries.h"
#include "ONPCalculate.h"
#include "stackHandle.h"
#include "algebraicHandle.h"
#include "validation.h"

/**
 * funkcja obsługująca wczytywanie i obliczanie wyrażeń z pliku
 * @param top wierzchołek stosu
 * @param phrase łańcuch znaków na przekształconą z postaci algebraicznej postać ONP
 * @param counter licznik potrzebnu do numeracji wyników wpisywanych do nowego pliku z wynikami
 */
void countFromFile(struct stack *top, char *phrase, int counter);

/**
 * funkcja tworząca łańcuch znaków zawierających ścieżkę do nowego pliku z wyknikami
 * @param filePath łańcuch znaków zawierający ścieżkę do pliku z wyrażeniami do obliczenia
 * @param scorePath łańcuch znaków zawierający ścieżkę do nowego pliku z wyknikami
 */
void filePathNameChange(char *filePath, char *scorePath);

#endif //CALCULATOR_FILEHANDLE_H
