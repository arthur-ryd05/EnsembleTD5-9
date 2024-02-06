#include "TP10.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>


void ajouterEnTete(MLSC** const pListe, const int id, const char l){
    MLSC* nouv= malloc(sizeof(MLSC));
    nouv->id=id;
    nouv->lettre=l;
    nouv->next=*pListe;
    *pListe=nouv;
}

void ajouterEnFin(MLSC** const pListe, int id,  char lettre){
    //Alocation
    MLSC* nouv = malloc(sizeof(MLSC));

    nouv->id = id;
    nouv->lettre = lettre;
    nouv->next= NULL;

    //pointeur parcours
    MLSC* parcours = *pListe;

    if(parcours==NULL){
        *pListe =nouv;
    }
    else{
        while(parcours->next != NULL){
            parcours = parcours->next;
        }
        //on est sure d'etre a la fin
        parcours->next= nouv;
    }
}

void afficher(MLSC *m){
    MLSC* parcours= m;
    while(parcours!=NULL){
        printf("%d :  ",parcours->id);
        printf("%d :\n",parcours->lettre);
        parcours= parcours->next;
    }
}

void freeliste(MLSC** pListe){
    MLSC* parcours;
    while(*pListe != NULL){
        //on sauvegarde son voisin
        parcours= (*pListe)->next;
        // on efface la tete
        free(*pListe);
        *pListe = parcours;
    }
}

void ExoCours(){
    MLSC*liste= NULL;
    ajouterEnTete(&liste, 1,'a');
    ajouterEnTete(&liste, 2,'b');
    ajouterEnFin(&liste,3,'c');

    afficher(liste);

    freeliste(&liste);
    afficher(liste);
}

//CHANSON

Chanson* initChanson(char* titre, char* artiste, unsigned int duree){
    Chanson* MaChanson = NULL;
    //Allocation dynamique
    MaChanson = malloc(sizeof(Chanson));
    //initialisation
    MaChanson-> duree = duree;
    strcpy(MaChanson-> titre, titre);
    strcpy(MaChanson-> artiste, artiste);
    //return
    return MaChanson;
}

void lectureEnCours(Chanson* ajouer){
    printf("Titre en cours de lecture...\n");
    printf("%s\n",ajouer->titre);
    printf("%s\n",ajouer->artiste);
    sleep(ajouer->duree);
}

void ajouterFileAttente(Playlist* fileAttente, char* titre, char*artiste, unsigned int duree) {
    //Allocation
    Chanson *arajouter = initChanson(titre, artiste, duree);
}

void Spotify(){
    Playlist favoris=  NULL;
// A FINIR AVEC MONSIEUR GUZMALO
}

//TP COURS...

void creationPromo(Etudiant** promo, int* tailleLogique){
    printf("Combien d'etudiants font partie de la Promo\n");
    scanf("%d", tailleLogique);
    *promo = malloc((*tailleLogique)*sizeof (Etudiant));
    assert(*promo != NULL);
    for(int i =0;i<*tailleLogique; i++){
        printf("Saisir le nom de l'etudiant %d: ",i+1);
        getchar();
        fgets((*promo)[i].nom,101,stdin);
        if ((*promo)[i].nom[strlen((*promo)[i].nom)-1] == '\n'){
            (*promo)[i].nom[strlen((*promo)[i].nom)-1] = '\0';
        }
        printf("Saisir la moyenne de l'eleve numero %d:  ",i+1);
        scanf("%f",&((*promo)[i].moyenne));
    }
}

void ajoutEnFinDeTableau (Etudiant **promo, int *TailleLogique, char *nom, float moyenne ){
    *promo = realloc(*promo,(*TailleLogique + 1)*sizeof(Etudiant));
    strcpy((*promo)[*TailleLogique].nom,nom);
    (*promo)[*TailleLogique].moyenne = moyenne ;
    (*TailleLogique)++;
}

void ajoutEnDebutDeTableau (Etudiant **promo, int* TailleLogique, char *nom, float moyenne ){
    *promo = realloc(*promo, (*TailleLogique+1)* sizeof (Etudiant));
    for (int i = *TailleLogique; i > 0; i--) {
        (*promo)[i] = (*promo)[i-1];
    }
    strcpy((*promo)[0].nom, nom);
    (*promo)[0].moyenne = moyenne;
    (*TailleLogique)++;
}

void afficherTableau( Etudiant * promo, int TailleLogique ){
    for (int i = 0; i < TailleLogique ; i++) {
        printf("ETUDIANT NUMERO %d\n",i+1);
        printf("%f: Moyenne de %s", promo[i].moyenne, promo[i].nom);
    }
}

void creationCellule(Cellule ** promo, int* tailleLogique){
    printf("Combien d'etudiants font partie de la Promo");
    scanf("%d", tailleLogique);
    *promo = malloc((*tailleLogique)*sizeof (Cellule));
    assert(*promo != NULL);
    for(int i =0;i<*tailleLogique; i++) {
        printf("Saisir le nom de l'etudiant : %d", i + 1);
        fgets((*promo)[i].nom, 101, stdin);
        if ((*promo)[i].nom[strlen((*promo)[i].nom) - 1] == '\n') {
            (*promo)[i].nom[strlen((*promo)[i].nom) - 1] = '\0';
        }
        printf("Saisir la moyenne de l'eleve numero %d", i + 1);
        scanf("%f", &((*promo)[i].moyenne));
    }
    }

Cellule* funcAjoutEnTeteDeListe ( Cellule *liste, const char *nom, float moyenne ) {
    Cellule *nouv = malloc(sizeof(Cellule));
    nouv->moyenne= moyenne;
    strcpy(nouv->nom, nom);
    nouv->next = liste;
    liste = nouv;
    return liste;
}

void procAjoutEnTeteDeListe ( Cellule* *liste, const char *nom,float moyenne ){
    Cellule *nouv2 = malloc(sizeof(Cellule));
    nouv2->moyenne = moyenne;
    strcpy(nouv2->nom, nom);
    nouv2->next = *liste;
    *liste= nouv2;
}

Cellule* funcAjoutEnFinDeListe (Cellule *liste, const char *nom, float moyenne ){
    Cellule *nouv3 = malloc(sizeof(Cellule));
    nouv3->moyenne = moyenne;
    strcpy(nouv3->nom, nom);
    nouv3->next = NULL;

    Cellule* parcours = liste;

    if (parcours== NULL){
        nouv3->next = liste;
    }
    else{
        while(parcours->next != NULL){
            parcours = parcours->next;
        }
        parcours->next = nouv3;
    }
    return liste;
}

void procAjoutEnFinDeListe ( Cellule **promo, const char *nom, float moyenne ){
    Cellule *nouv4 = malloc(sizeof(Cellule));

    nouv4->moyenne = moyenne;
    strcpy(nouv4->nom,nom);
    nouv4-> next = NULL;

    // creation d'un pointeur parcours qui va parcourir l'ensemble du tableau
    Cellule* parcours = *promo;
    if(parcours == NULL){
        nouv4->next = *promo;
    }
    else{
        while(parcours->next != NULL){
            parcours = parcours->next;
        }
        parcours->next = nouv4;
    }
}

void afficherListeAvecWhile (Cellule *liste){
    Cellule* parcours = liste;
    while (parcours != NULL){
        printf("nom:  %s ", parcours->nom);
        printf("moyenne:  %f ", parcours->moyenne);
        parcours->next = parcours;
    }
}

void afficherListeAvecFor( Cellule *liste ){
    Cellule* parcours = liste;
    for(; parcours != NULL; parcours =parcours->next){
        printf("nom:  %s ", parcours->nom);
        printf("moyenne:  %f ", parcours->moyenne);
    }
}

int nombreElementsRecurs ( Cellule * liste ) {
    Cellule *parcours = liste;
    int recurence= 0;
    if(liste ==NULL){
        return 0;
    }
    for (int i = 0; parcours[i].next != NULL; i++) {
        parcours->next = parcours;
        recurence++;
    }
    return 4;
}

void libererListe(Cellule **pointeurSurListe) {
    Cellule *parcours = *pointeurSurListe;
    while (parcours != NULL) {
        Cellule *temp = parcours;
        parcours = parcours->next;
        free(temp);
    }
    *pointeurSurListe = NULL;
}

int TpListeChainerMain() {
    printf("\n********* Tableau dynamique *********\n\n");
    Etudiant *promo = NULL;
    int nbMoyennes = 0;
    int tailleLogique;
    creationPromo(&promo,&tailleLogique);
    ajoutEnDebutDeTableau(&promo, &nbMoyennes, "Toto", 12.4);
    ajoutEnDebutDeTableau(&promo, &nbMoyennes, "Tata", 10.4);
    ajoutEnFinDeTableau(&promo, &nbMoyennes, "Tutu", 15.32);
    ajoutEnFinDeTableau(&promo, &nbMoyennes, "Titi", 16.0);
    afficherTableau(promo, nbMoyennes);
    free(promo);
    printf("\n\n********* Liste simplement chaînée *********\n\n");
    Cellule *liste = NULL;
    int tailleLogique2;
    creationCellule(&liste,&tailleLogique2);
    liste = funcAjoutEnTeteDeListe(liste, "Toto", 12.4);
    procAjoutEnTeteDeListe(&liste, "Tata", 10.4);
    liste = funcAjoutEnFinDeListe(liste, "Tutu", 15.32);
    procAjoutEnFinDeListe(&liste, "Titi", 16.0);
    printf("Il y a %d cellules dans la liste chaînée.\n",nombreElementsRecurs(liste));
    afficherListeAvecWhile(liste);
    afficherListeAvecFor(liste);
    libererListe(&liste);
    return 0;
}

