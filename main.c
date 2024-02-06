#include <stdio.h>
#include "TP5.h"
#include "TP6.h"
#include "TP7.h"
#include "TP8.h"
#include "TP9.h"
#include "TP10.h"

int main() {
    int choixTP, choixEx;
    do {
        printf("Quel TP ? (0 pour quitter)\n");
        scanf("%d", &choixTP);
        switch (choixTP) {
            case 5: {
                do {
                    printf("Quel Exercice ? (0 pour quitter)\n");
                    scanf("%d", &choixEx);
                    switch (choixEx) {
                        case 1: {
                            TP5Ex1();
                            break;
                        }
                        case 2: {
                            TP5Ex2();
                            break;
                        }
                        case 3: {
                            TP5Ex3();
                            break;
                        }
                        case 0: {
                            break;
                        }
                        default: {
                            printf("Cet exercice n'existe pas.\n");
                            break;
                        }
                    }
                } while (choixEx != 0); // Ajout de l'accolade fermante ici
                break;
            }
            case 6: {
                do {
                    printf("Quel Exercice ? (0 pour quitter)\n");
                    scanf("%d", &choixEx);
                    switch (choixEx) {
                        case 1: { TP6Ex1(); break; }
                        case 2: { TP6Ex2(); break; }
                        case 3: { TP6Ex3(); break; }
                        case 4: { TP6Ex4(); break; }
                        case 5: { TP6Ex5(); break; }
                        case 0: { break; }
                        default: { printf("Cet exercice n'existe pas.\n"); break; }
                    }
                } while (choixEx != 0);
                break;
            }
            case 7: {
                do {
                    printf("Quel Exercice ? (0 pour quitter)\n");
                    scanf("%d", &choixEx);
                    getchar(); // On rajoute ici un getchar() car sinon les termes d'avant sont consommée par le fgets et donc on ne peut pas bien executer le programme
                              // D'apres def : La fonction getchar() est souvent utilisée pour consommer des caractères de nouvelle ligne ('\n') ou d'autres caractères indésirables
                              // qui peuvent rester dans le flux d'entrée après l'utilisation de certaines fonctions de saisie telles que scanf().
                    switch (choixEx) {
                        case 1: {
                            TP7Ex1();
                            break;
                        }
                        case 2: {
                            TP7Ex2();
                            break;
                        }
                        case 3: {
                            TP7Ex3();
                            break;
                        }
                        case 0: {
                            break;
                        }
                        default: {
                            printf("Cet exercice n'existe pas.\n");
                            break;
                        }
                    }
                } while (choixEx != 0);
                break;
            }
            case 8: {
                do {
                    printf("Quel Exercice ? (0 pour quitter)\n");
                    scanf("%d", &choixEx);
                    switch (choixEx) {
                        case 1: { TP8Ex1(); break; }
                        case 2: { TP8Ex2(); break; }
                        case 3: { TP8Ex3(); break; }
                        case 4: { TP8Ex4(); break; }
                        case 0: { break; }
                        default: { printf("Cet exercice n'existe pas.\n"); break; }
                    }
                } while (choixEx != 0);
                break;
            }
            case 9: {
                do {
                    printf("Quel Exercice ? (0 pour quitter)\n");
                    scanf("%d", &choixEx);
                    switch (choixEx) {
                        case 1: { TP9Ex1(); break; }
                        case 0: { break; }
                        default: { printf("Cet exercice n'existe pas.\n"); break; }
                    }
                } while (choixEx != 0);
                break;
            }
            case 10: {
                do {
                    printf("Quel Exercice ? (0 pour quitter)\n");
                    scanf("%d", &choixEx);
                    switch (choixEx) {
                        case 1: {ExoCours(); break; }
                        case 2: {TpListeChainerMain(); break; }
                        case 0: { break; }
                        default: { printf("Cet exercice n'existe pas.\n"); break; }
                    }
                } while (choixEx != 0);
                break;
            }
            case 0: { return 0; }
            default: { printf("Ce TP n'existe pas.\n"); break; }
        }
    } while (choixTP != 0);
    return 0;
}
