#ifndef ENSEMBLETD_TP9_H
#define ENSEMBLETD_TP9_H

#define MAX_CARACTERE 50


typedef struct {
    float noteMaths, noteInfo, notePhysique, noteElec;
    char prenom[MAX_CARACTERE];
}etudiant;

void Saisir(etudiant etudiant[], int* nbEtudiant);
void Afficher(etudiant etudiant[], int nbEtudiant);
void SauvegarderTexte(etudiant etudiant[], int nbEtudiant);
void chargerTexte(etudiant etudiant[], int *nbEtudiant);
void SauvergarderBinaire(etudiant etudiant[], int nbEtudiant);
void ChargerBinaire(etudiant etudiant[], int *nbEtudiant);

void TP9Ex1();




#endif
