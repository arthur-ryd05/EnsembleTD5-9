#include "TP5.h"
#include <stdio.h>
#define MAX 100
#define MATRICE_LIGNE 3
#define MATRICE_COLONNE 4


NombreRationnel saisirNombreRationnel(){
    NombreRationnel n;
    printf("Saisissez un numerateur: \n");
    scanf("%d", &n.numerateur);
    printf("Saisissez un denominateur: \n");
    scanf("%d", &n.denominateur);
    return n;
}

void afficherNombreRationnel(NombreRationnel n){
    printf("numerateur= %d, denominateur= %d\n",n.numerateur,n.denominateur);
}

NombreRationnel Multiplication(NombreRationnel NR1, NombreRationnel NR2){
    NombreRationnel res;
    res.numerateur = NR1.numerateur * NR2.numerateur;
    res.denominateur = NR2.denominateur * NR2.denominateur;
    return res;
}

NombreRationnel Addition(NombreRationnel NR1, NombreRationnel NR2){
    NombreRationnel res;
    res.numerateur = NR1.numerateur*NR2.denominateur + NR2.numerateur*NR1.numerateur;
    res.denominateur = NR1.denominateur*NR2.denominateur;
    return res;
}


void TP5Ex1 () {
    NombreRationnel n1;
    NombreRationnel n2;
    n1 = saisirNombreRationnel();
    n2 = saisirNombreRationnel();
    printf("Votre nombre 1 est : \n");
    afficherNombreRationnel(n1);
    printf("Votre nombre 2 est : \n");
    afficherNombreRationnel(n2);

    printf("l'addition des deux nous donne : \n");
    NombreRationnel resAdition = Addition(n1,n2);
    afficherNombreRationnel(resAdition);

    printf("la multiplication des deux nous donne : \n");
    NombreRationnel resMul = Multiplication(n1, n2);
    afficherNombreRationnel(resMul);
}


int demandeTailleLogique(int TaillePhysique) {
    int TailleLogique;
    do {
        printf("Quel est la taille logique de votre tableau \n");
        scanf("%d", &TailleLogique);
    } while (TailleLogique < 0 || TailleLogique > TaillePhysique);

}

void remplirTableau(int TailleLogique, int tableau[]){
    for(int i = 0; i<TailleLogique; i++){
        printf("Quel est votre %deme nombre\n",i+1);
        scanf("%d", &tableau[i]);
    }
}

void afficherTab(int tableau[MAX], int TailleLogique) {
    for (int i = 0; i < TailleLogique ; i++) {
        printf("%d, ", tableau[i]);
    }
    printf("%d.\n", tableau[TailleLogique]);
}

int plusGrand(int tableau[], int TailleLogique) {
    int plusGrandEntier = -1;
    if (TailleLogique > 0) {// si le tableau n'est pas vide,
        // on cherche la plus grande valeur.
        // Sans cela, tableau[0] aurait pu provoquer un bug
        plusGrandEntier = tableau[0];
        for (int i = 1; i < TailleLogique; i++) {
            if (plusGrandEntier < tableau[i])
                plusGrandEntier = tableau[i];
        }
        return plusGrandEntier;
    }
}


void TP5Ex2 () {
    int tableau[MAX], TailleLogique;
    TailleLogique = demandeTailleLogique(MAX);
    remplirTableau(TailleLogique,tableau);
    afficherTab(tableau, TailleLogique);
    printf("Le plus grand entier dans le tableau est : %d \n", plusGrand(tableau, TailleLogique));
}

void RemplirMatrice(int MATRICE[MATRICE_LIGNE][MATRICE_COLONNE]){
    for(int i=0; i<MATRICE_LIGNE; i++){
        for(int j=0; j<MATRICE_COLONNE;j++){
            printf("Donner la valeur a mettre dans la mattrice ligne %d, colonne %d\n ",i+1, j+1);
            scanf("%d",&MATRICE[i][j]);
        }
    }
}

void AfficherMatrice(int MATRICE[MATRICE_LIGNE][MATRICE_COLONNE]){
    for(int i=0; i<MATRICE_LIGNE; i++){
        for(int j=0; j<MATRICE_COLONNE;j++){
            printf("%d", MATRICE[i][j]);
        }
        printf("\n");
    }
}

void MatriceTAB(int m[MATRICE_LIGNE][MATRICE_COLONNE], int tab[]){
    for(int i=0, k =0; i<MATRICE_LIGNE; i++){
        for(int j=0; j<MATRICE_COLONNE;j++){
            tab[k++] = m[i][j];
        }
    }

}

void AfficherTableau(int tab[]){
    for(int k=0; k<12; k++){
        printf("%d",tab[k]);
    }
}

void TP5Ex3(){
    int m[MATRICE_LIGNE][MATRICE_COLONNE]; int tab[MATRICE_LIGNE*MATRICE_COLONNE];
    RemplirMatrice(m);
    MatriceTAB(m,tab);
    printf("Matrice :\n \n");
    AfficherMatrice(m);
    printf("Tableau 1D: \n \n");
    AfficherTableau(tab);
    printf("\n \n");
}













