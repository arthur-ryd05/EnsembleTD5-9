#ifndef ENSEMBLETD_TP9_H
#define ENSEMBLETD_TP9_H
#define MAX_CARACTERE 50


typedef struct {
    float noteMaths, noteInfo, notePhysique, noteElec;
    char prenom[MAX_CARACTERE];
}Etudiant;

void Saisir(Etudiant etudiant[], int* nbEtudiant);
void Afficher(Etudiant etudiant[], int nbEtudiant);
void SauvegarderTexte(Etudiant etudiant[], int nbEtudiant);
void chargerTexte(Etudiant etudiant[], int *nbEtudiant);
void SauvergarderBinaire(Etudiant etudiant[], int nbEtudiant);
void ChargerBinaire(Etudiant etudiant[], int *nbEtudiant);

void TP9Ex1();




#endif
