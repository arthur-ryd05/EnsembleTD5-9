#include "TP9.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARACTERE 50
#define NB_ETUDIANT 5

void Saisir(etudiant etudiant[], int* nbEtudiant){
    printf("Saisir le nombre d'eleves :\n");
    scanf("%d",nbEtudiant);
    fflush(stdin); //histoire de vider le buffer pour le fgets
    for(int i=0; i<*nbEtudiant; i++){
        printf("Saisir le nom de l'eleve %d:\n", i+1);
        fgets(etudiant[i].prenom,MAX_CARACTERE,stdin);
        if(etudiant[i].prenom[ strlen (etudiant[i].prenom) - 1 ] == '\n'){ // permet de remplacer le dernier caractere par un caracter de fin de chaine
            etudiant[i].prenom[ strlen(etudiant[i].prenom)-1]= '\0';
        }
        printf("Saisir les notes d'elec, de maths, de physique, d'info \n(mettre un point pour les notes reel.)");
        scanf("%f" "%f" "%f" "%f",&etudiant[i].noteElec,&etudiant[i].noteMaths,&etudiant[i].notePhysique,&etudiant[i].noteInfo);
        fflush(stdin);// pour retrouver un menu correct
    }
}

void Afficher(etudiant etudiant[], int nbEtudiant){
    for(int i=0; i<nbEtudiant; i++) {
        printf("%s: %f %f %f %f\n",etudiant[i].prenom,etudiant[i].noteElec,etudiant[i].noteMaths,
               etudiant[i].notePhysique,etudiant[i].noteInfo);
    }
}

void SauvegarderTexte(etudiant etudiant[], int nbEtudiant){
    FILE* pf = fopen ("../notes.txt","w");
    if(pf!=NULL){
        fprintf(pf,"Nombre d'etudiant : %d\n",nbEtudiant);
        for (int i = 0; i <nbEtudiant; i++) {
            fprintf(pf,"%s: %f %f %f %f\n",etudiant[i].prenom,etudiant[i].noteElec,etudiant[i].noteMaths,
                    etudiant[i].notePhysique,etudiant[i].noteInfo );
        } }
    else{
        printf("Erreur d'ouverture de fichier \n");
    }
    fclose(pf);
    pf=NULL;
}
void chargerTexte(etudiant etudiant[], int *nbEtudiant) {
    FILE *pf = fopen("../notes.txt", "r");
    if (pf != NULL) {
        fscanf(pf, "Nombre d'etudiant : %d\n", nbEtudiant);
        for (int i = 0; i < *nbEtudiant; i++) {
            fprintf(pf, "%s: %f %f %f %f\n", etudiant[i].prenom, etudiant[i].noteElec, etudiant[i].noteMaths,
                    etudiant[i].notePhysique, etudiant[i].noteInfo); // pas compris pourquoi comme dans la def
            // du cour ici on ne va pas chercher tous simplement l'adresse de chaque variable
        }
    }
    else{
        printf("FIchier Introuvable\n");
    }
    fclose(pf);
    pf=NULL;
}

void SauvergarderBinaire(etudiant etudiant[], int nbEtudiant) {
    FILE *pf = fopen("../notes.etus", "w"); // ce n'est donc maintenant plus un fichier txt donc on s'en fiche de son. ...
    fwrite(&nbEtudiant,sizeof(int),1,pf);
    fwrite(etudiant,sizeof(etudiant),nbEtudiant,pf);
    fclose(pf);
    pf=NULL;
}

void ChargerBinaire(etudiant etudiant[], int *nbEtudiant){
    FILE *pf = fopen("../notes.etus", "r");
    fread(nbEtudiant,sizeof(int),1,pf);
    fread(etudiant,sizeof(etudiant),*nbEtudiant,pf);
    fclose(pf);
    pf=NULL;
}

void TP9Ex1(){
    int fin = 0;
    int nbEtudiant; int choix=0;
    etudiant etudiant[NB_ETUDIANT];
    while (!fin) {
        printf("Choisissez une section :\n1.Saisir\n2.Afficher\n3.SauvegarderTexte\n4.chargerTexte\n5.SauvergarderBinaire\n6.ChargerBinaire\n7.QUITTER\n\n\n\n");
        scanf("%d",&choix);
        switch (choix) {
            case 1: { Saisir(etudiant,&nbEtudiant); break; }
            case 2 : { Afficher(etudiant,nbEtudiant); break;}
            case 3: { SauvegarderTexte(etudiant,nbEtudiant); break; }
            case 4: { chargerTexte(etudiant,&nbEtudiant); break; }
            case 5: { SauvergarderBinaire(etudiant,nbEtudiant); break; }
            case 6: { ChargerBinaire(etudiant,&nbEtudiant); break;}
            case 7: { printf("Vous quittez l'exercice...\n\n"); fin=1; break;}
            default: { printf("Saisissez un nombre valide parmi ceux fourni.\n"); break;}

        }

    }

}
