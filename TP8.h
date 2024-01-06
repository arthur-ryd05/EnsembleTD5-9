#ifndef ENSEMBLETD_TP8_H
#define ENSEMBLETD_TP8_H

void TP8Ex1();

void creerTab(int** tableau, int* entier);
void libererTab(int **tab);
void remplirTab(int *tab, int* taille);
void afficherTabAD(int* tab, int* taille);

void TP8Ex2();

int returnTabNotes(int *tab, int* taille);
void calculMoyenne(int* NbNotes, int* *tab, float* moyenne);
void libererTabNotes(int **tableau);
void afficherNote(int** tableau, int* NbNotes);

void TP8Ex3();

void tableau2D(int*** tableau2D, int* nbLigne, int* nbColonne);
void remplirTableau2D(int*** tableau2D, int nbLigne, int nbColonne);
void afficherTableau(int** tableau2D, int nbLigne, int nbColonne);
void tableauCroissant();
void libererMatrice(int ***matrice, int nbLignes);

void TP8Ex4();

void SaisirMot(char* mot[], int nbMot);
void libererMot(char* mot[]);
void afficherMot(char* mots[], int nbMot);

#endif
