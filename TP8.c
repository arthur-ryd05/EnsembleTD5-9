#include "TP8.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <string.h>

#define NBmots 10
#define MAXCaractere 50

void creerTab(int** tableau, int* entier){
    printf("Combien d'entiers ?\n");
    scanf("%d",entier);
    *tableau = calloc(*entier,sizeof(int));
    assert(*tableau != NULL);
}

void libererTab(int **tab){
    free(*tab);
    tab= NULL;
}

void remplirTab(int *tab, int* taille){
    for(int i=0; i<*taille;i++){
        printf("Saisir la valeur numero %d: ", i+1);
        scanf("%d", &tab[i]);
    }
}
void afficherTabAD(int* tab, int* taille){
    for(int i=0; i<*taille;i++){
        printf("%d,", tab[i]);
    }
}

void TP8Ex1(){
    int* tableau = NULL;
    int taille;
    creerTab(&tableau, &taille);
    remplirTab(tableau,&taille);
    afficherTabAD(tableau,&taille);
    libererTab(tableau);
    printf("\n \n");
}

int creerTabNotes(int **tab, int *taille) {
    printf("Combien de notes a saisir: ");
    scanf("%d", taille);
    *tab = malloc(*taille * sizeof(int));
    assert(*tab != NULL);
}

void libererTabNotes(int **tableau) {
    free(*tableau);
    *tableau = NULL;
}

void calculMoyenne(int *NbNotes, int **tab, float *moyenne) {
    int somme = 0; // bien initialiser a 0 pour pas avoir somme incorect
    for (int i = 0; i < *NbNotes; i++) {
        printf("Saisissez la valeur %d: ", i + 1);
        scanf("%d", &(*tab)[i]);  // Utiliser le déréférencement pour accéder à la case mémoire correcte et ne pas créér d'erreur
        somme += (*tab)[i];       // Utiliser le déréférencement pour accéder à la valeur correcte et ne pas créér d'erreur
    }
    *moyenne = (float)somme / (float)*NbNotes;
}

//pour s'entrainer comme la correction on affiche préalablement les notes

void afficherNote(int** tableau, int* NbNotes){
    printf("Vos notes sont :\n");
    for(int i=0; i<*NbNotes; i++){
        printf("%d,", (*tableau)[i]);
    }
    printf("\n");
}

void TP8Ex2() {
    float moyenne;
    int NbNotes;
    int *tableau;
    creerTabNotes(&tableau, &NbNotes);
    calculMoyenne(&NbNotes, &tableau, &moyenne);
    afficherNote(&tableau,&NbNotes);
    printf("La moyenne des notes est de %.2f\n", moyenne);
    libererTabNotes(&tableau);
}

void tableau2D(int*** tableau2D, int* nbLigne, int* nbColonne){
    printf("Combien de ligne :\n");
    scanf("%d",nbLigne);
    printf("Combien de colone :\n");
    scanf("%d",nbColonne);

    // Allocation dynamique pour les pointeurs de lignes
    *tableau2D = (int**) calloc(*nbLigne,sizeof(int*)); // on commence par creer le tableau des ligne
    for(int i=0; i<*nbLigne ;i++){
        // Allocation dynamique pour chaque colonne de la ligne
        (*tableau2D)[i] = (int*)calloc(*nbColonne, sizeof(int)); // puis on creer le tableau des colones
    }
}

void remplirTableau2D(int*** tableau2D, int nbLigne, int nbColonne){
    for(int i=0; i<nbLigne; i++) {
        for (int j = 0; j <nbColonne; j++) { //attention a bien mettre les conditions pour parcurir tous le tableau
            (*tableau2D)[i][j] = rand() % (255 + 1);
        }
    }
}

void afficherTableau(int** tableau2D, int nbLigne, int nbColonne){
    for (int i = 0; i < nbLigne; ++i) {
        for (int j = 0; j < nbColonne; ++j) {
            printf("%d,", tableau2D[i][j]);
        }
        printf("\n");
    }
}

void tableauCroissant(){
//Pas reussie...
}

void libererMatrice(int ***matrice, int nbLignes) {
    for (int i = 0; i < nbLignes; i++) {
        free((*matrice)[i]);
        (*matrice)[i] = NULL;
    }
    free(*matrice);
    *matrice = NULL;
}


void TP8Ex3(){
    srand(time(NULL));
    int** matrice= NULL ;
    int nbLigne, nbColone;
    tableau2D(&matrice,&nbLigne,&nbColone);
    remplirTableau2D(&matrice,nbLigne,nbColone);
    afficherTableau(matrice, nbLigne, nbColone);
    libererMatrice(&matrice,nbLigne);
}

void SaisirMot(char* mot[], int nbMot){
    char str[MAXCaractere]; // on utilise un deuxieme tableau pour pouvoir ensuite le copier dans le tableau
    for (int i = 0; i <nbMot; i++) {
        printf("Veuillez saisir votre mot numero %d", i+1);
        scanf("%s",str);
        //Allocation dynamique utilisée ici pour que le mot rentrée dans str soit de la bonne taille, et pour qu'il ne prenne pas trop de place
        mot[i] = (char*)calloc((strlen(str)+1),sizeof(char)); // on fait +1 pour laisser une place pour le \0
        assert(*mot != NULL);
        strcpy(mot[i],str);
    }
}

void libererMot(char* mot[]){
    free(*mot);
    *mot=NULL;
}

void afficherMot(char* mots[], int nbMot){
    for (int i = 0; i <nbMot; ++i) {
        printf("%s", mots[i]);
        printf("\n");
    }
}



void TP8Ex4(){
getchar();
char* DiffMots = {0};
    SaisirMot(&DiffMots,NBmots);
    afficherMot(&DiffMots,NBmots);
    libererMot(&DiffMots);
}

