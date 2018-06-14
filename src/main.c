#include "necessaryLibraries.h"
#include "stackHandle.h"
#include "algebraicHandle.h"
#include "validation.h"
#include "ONPCalculate.h"
#include "fileHandle.h"

int main() {
    struct stack *top = NULL;
    int option, whatToDo = 1, counter = 0;
    char ONPFromAlgebraicForm[100] = "";


    while (whatToDo == 1) {
        printMenu();
        scanf("%d", &option);
        int userChoice = menuChoice(option);
        stepByStep = stepByStepVersion();
        if (userChoice == 0) {
            char phrase[100] = "";
            phraseInput(phrase);

            if (isONP(phrase)) {
                if (isNumberOfOperatorsCorrect(phrase)) {
                    ONPCalculations(phrase, top);
                    printf("\nWynik: %lf\n", finalResult);
                }
            } else if (!isONP(phrase) && isNumberOfOperatorsCorrect(phrase)
                       && isNumberOfBracketsCorrect(phrase)) {
                algebraicToONP(phrase, top, ONPFromAlgebraicForm);
                ONPCalculations(ONPFromAlgebraicForm, top);
                printf("\nWynik: %lf\n", finalResult);

            }
        } else if (userChoice == 1) {
            countFromFile(top, ONPFromAlgebraicForm, counter);
        }
        strcpy(ONPFromAlgebraicForm, "");
        printf("\n\nCo dalej?\n");
        printf("Wybierz 1 dla pownownego obliczania.\nWybierz 2 dla zakonczenia programu.\n");
        scanf("%d", &whatToDo);
    }
    return 0;
}
