#include "menu.h"

void printMenu() {
    printf("\n      ---------MENU--------\n");
    printf("Uzytkowniku, chcesz wprowadzac wyrazenia z klawiatury czy z pliku?\n");
    printf("Wybierz 1 dla kalawiatury.\nWybierz 2 dla pliku.\n");
}


int menuChoice(int choice) {
    if (choice == 1){
        return 0;
    }
    else if (choice == 2) {
        return 1;
    }
    else{
        printf("Zly numer, sprobuj ponownie.\n");
        scanf("%d", &choice);
        menuChoice(choice);
    }
}

bool stepByStepVersion(){
    printf("         TRYB EDUKACYJNY\n");
    printf("Czy wyswietlic wersje \"Krok po kroku\"?\n");
    printf("Wybierz 1 jesli tak.\nWybierz 2 jesli nie.\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Przechodz do kolejnych krokow klikajac \"Enter\".\n");
        return true;
    }
    else if (choice == 2)
        return false;
}

void phraseInput(char *phrase){
    printf("Wprowadz wyrazenie. Pmaietaj o oddzieleniu liczb i operatorow spacjami."
                   "\nZakoncz znakiem rownosci.\n");
    scanf(" %[^\n]s", phrase);
}