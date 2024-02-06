#include "TP7.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX 101

void SaisireCharacter(char* c){
    printf("Veuillez saisir le charactere a rechercher: \n");
    scanf("%c",c);
    getchar(); // pour qu'il n'est pas un "\n" qui fasse bugger le fgets
}

void SaisirPhrase(char* str, int TailleMax){
    printf("Saisissez une Phrase: \n");
    fgets(str,TailleMax,stdin); // a cause de fgets on a un retour automatique a la ligne
    if(str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0'; // on fait ca ici pour enlever le retour a la ligne on aurais pus le condenser en une ligne*
        // car on sait que le terme d'un fgets est toujours \n
    }
}
int compteOccurence(char* str, char c){
    int compteur= 0;
    for(int i=0; str[i] != '\0'; i++){
        if(str[i]== 'c'){
            compteur++;
        }
    }
    return compteur;
}



void TP7Ex1() {

    char charactereCompter;
    char str[MAX];
    int compteur;

    SaisirPhrase(str, MAX);
    SaisireCharacter(&charactereCompter);

    compteur = compteOccurence(&str,charactereCompter);
    printf("Le charactere %c est present %d fois dans : \n(%s). \n ",charactereCompter, compteur, str);
}

void saisirMinMax(int *min, int *max){
    printf("Saisir l'entier minimum\n");
    scanf("%d", min);
    printf("Saisir un l'entier maximum\n");
    scanf("%d", max); // ne pas oublier que & et * s'annule donc ici on a rien dans le scanf
}

int getRandomInteger(int *min, int *max){
    return (rand() % (*max - *min + 1) + *min); // on a ici le reste de la division de rand() par (max - min + 1) + min)
    // on est obliger de caster un int pour que la fonction nous renvoie bien un entier et pas autre chose
    // ne pas oublier les etoiles pour les pointeurs sinon on ne retourne pas une valeur numerique mais seulement l'adresse
}

void TP7Ex2(){
    int min, max;
    saisirMinMax(&min,&max);
    srand(time(NULL));
    for(int i= 0; i<14; i++){
        printf("Tirage %d sur 15 (entre %d et %d) : %d \n",i+1, min, max, getRandomInteger(&min, &max));
    }
    printf("\n \n");
}

void TP7Ex3(){
    int but, min, max, choix;
    saisirMinMax(&min, &max);
    srand(time(NULL));
    but = getRandomInteger(&min, &max);
    do {
        printf("Choisissez un entier a tester :\n");
        scanf("%d",&choix);
    if(choix>but)
        printf("Plus petit\n");
    else if(choix<but)
        printf("Plus grand\n");
    else if(choix<min || choix>max)
        printf("Votre nombre n'est pas dans l'intervalle choisie\n");
    }
    while(choix != but);
printf("Bravo, vous avez trouvee le bon nombre\n");
}
