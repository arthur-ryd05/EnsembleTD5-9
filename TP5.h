#ifndef ENSEMBLETD_TP5_H
#define ENSEMBLETD_TP5_H

#define MAX 100
#define MATRICE_LIGNE 3
#define MATRICE_COLONNE 4

typedef struct{
    int numerateur, denominateur;
}NombreRationnel;

NombreRationnel saisirNombreRationnel();
NombreRationnel Multiplication(NombreRationnel NR1, NombreRationnel NR2);
NombreRationnel Addition(NombreRationnel NR1, NombreRationnel NR2);
void afficherNombreRationnel(NombreRationnel);

void TP5Ex1();

int demandeTailleLogique(int TaillePhysique);
void remplirTableau(int TailleLogique, int tableau[]);
void afficherTab(int tableau[MAX], int taille);
int plusGrand(int tableau[], int TaillePhysque);

void TP5Ex2();

void RemplirMatrice(int MATRICE[MATRICE_LIGNE][MATRICE_COLONNE]);
void AfficherMatrice(int MATRICE[MATRICE_LIGNE][MATRICE_COLONNE]);
void MatriceTAB(int m[MATRICE_LIGNE][MATRICE_COLONNE], int tab[]);
void AfficherTableau(int tab[]);

void TP5Ex3();



#endif
