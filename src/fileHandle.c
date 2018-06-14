#include "fileHandle.h"


void countFromFile(struct stack *top, char *phrase, int counter) {
    char filePath[100] = "", scorePath[100] = "";

    printf("Podaj sciezke do pliku.\n");
    scanf("%s", filePath);
    FILE *file = fopen(filePath, "r+");
    char singleLine[50] = "";

    filePathNameChange(filePath, scorePath);
    FILE *scoreFile = fopen(scorePath, "w");


    while (!feof(file)) {
        fgets(singleLine, 50, file);
        puts("\n---------------");
        printf("%s\n", singleLine);

        if (isONP(singleLine)) {
            if (isNumberOfOperatorsCorrect(singleLine)) {
                ONPCalculations(singleLine, top);
                fprintf(scoreFile, "%d) %.3lf\n", counter, finalResult);
                counter++;
            }
        } else if (!isONP(singleLine) && isNumberOfOperatorsCorrect(singleLine)
                   && isNumberOfBracketsCorrect(singleLine)) {
            algebraicToONP(singleLine, top, phrase);
            ONPCalculations(phrase, top);
            fprintf(scoreFile, "%d) %.3lf\n", counter, finalResult);
            counter++;
        }
        strcpy(phrase, "");
    }
    printf("\nWyniki wyrazen z pliku znajdziesz w %s", scorePath);
    puts("");
}

void filePathNameChange(char *filePath, char *scorePath) {
    char *token, s[] = ".txt", filePathCopy[100];
    strcpy(filePathCopy, filePath);
    token = strtok(filePath, s);
    while (token != NULL) {
        strcpy(scorePath, token);
        token = strtok(NULL, s);
    }
    strcat(scorePath, "Wyniki.txt");
}