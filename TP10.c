#include "TP10.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>


void ajouterEnTete(MLSC** const pListe, const int id, const char l){
    MLSC* nouv= malloc(sizeof(MLSC));
    nouv->id = id;
    nouv->lettre = l;
    nouv->next = *pListe;
    *pListe = nouv;
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

Chanson *initChanson(char *titre, char *artiste, unsigned int duree) {
    Chanson *maChanson = NULL;
    // Allocation dynamique
    maChanson = malloc(sizeof(Chanson));

    // initialisation data
    strcpy(maChanson->titre, titre);
    strcpy(maChanson->artiste, artiste);
    maChanson->duree = duree;

    // initialisation lien
    maChanson->next = NULL;
    maChanson->prev = NULL;

    // return
    return maChanson;
}

void lectureEnCours(Chanson *ajouer) {
    int choix;
    while (ajouer != NULL) {
        printf("Titre en cours de  lecture \n");
        printf("%s \n", ajouer->titre);
        printf("%s \n", ajouer->artiste);
        sleep(ajouer->duree);
        printf("1: next, 2: prev, 3: exit \n");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                ajouer = ajouer->next;
                break;
            case 2:
                ajouer = ajouer->prev;
                break;
            case 3:
                return;
            default:
                break;
        }

        if(ajouer==NULL){
            printf("\n Fin de la playlist \n");
        }
    }
}


void addFirst(Playlist *fileAttente, char *titre, char *artiste, unsigned int duree) {
    // Allocation
    Chanson *arajouter = initChanson(titre, artiste, duree);
    arajouter->next = *fileAttente;
    if (*fileAttente != NULL) {
        (*fileAttente)->prev = arajouter;
    }
    *fileAttente = arajouter;
}


void addLast(Chanson **filaAttente, char *titre, char *artiste, unsigned int duree) {
    // Declaration d'un pointeur vers la tête de la liste
    Chanson *tail = *filaAttente;

    // Allocation
    Chanson *newChanson = initChanson(titre, artiste, duree);

    // recherche du dernier maillon
    while (tail->next != NULL) {
        tail = tail->next;
    }

    // on est sur d'etre à la fin
    tail->next = newChanson;
    newChanson->prev = tail;
}

void deletePlaylist(Chanson **fileattente) {
    // pointeur temporaire
    Chanson *temp = *fileattente;

    while (temp != NULL) {
        // mise à jour de la tête
        (*fileattente) = (*fileattente)->next;

        // liberation
        free(temp);

        temp = *fileattente;
    }

}

// Version pour list simplement chainée
void deleteByArtist(Chanson **playlist, char *artistName) {
    Chanson *prev = *playlist;

    if (*playlist != NULL) {
        // il y a au moins une chanson
        Chanson *aEffacer = prev->next;

        // on cherche dans tous les éléménts à droite du premier maillon
        while (aEffacer != NULL) {
            if (strcmp(aEffacer->artiste, artistName) == 0) {
                prev->next = aEffacer->next;
                free(aEffacer);
                aEffacer = prev->next;
            } else {
                prev = aEffacer;
                aEffacer = aEffacer->next;
            }
        }

        // on vérifie si le premier maillon doit être effacé.
        if (strcmp((*playlist)->artiste, artistName) == 0) {
            prev = *playlist;
            *playlist = (*playlist)->next;
            free(prev);
        }
    }
}

//TP COURS...

void creationPromo(Etudiant** promo, int* tailleLogique){
    printf("Combien d'etudiants font partie de la Promo\n");
    scanf("%d", tailleLogique);

    *promo = malloc((*tailleLogique) * sizeof(Etudiant));
    assert(*promo != NULL);

    for(int i = 0; i < *tailleLogique; i++){
        printf("Saisir le nom de l'etudiant %d: ", i+1);
        getchar();
        fgets((*promo)[i].nom, 101, stdin);
        if ((*promo)[i].nom[strlen((*promo)[i].nom)-1] == '\n'){
            (*promo)[i].nom[strlen((*promo)[i].nom)-1] = '\0';
        }
        printf("Saisir la moyenne de l'eleve numero %d: ", i+1);
        scanf("%f", &((*promo)[i].moyenne));
    }
}

void ajoutEnFinDeTableau (Etudiant **promo, int *TailleLogique, char *nom, float moyenne ){
    *promo = realloc(*promo, (*TailleLogique + 1) * sizeof(Etudiant));
    strcpy((*promo)[*TailleLogique].nom, nom);
    (*promo)[*TailleLogique].moyenne = moyenne;
    (*TailleLogique)++;
}

void ajoutEnDebutDeTableau (Etudiant **promo, int* TailleLogique, char *nom, float moyenne ){
    *promo = realloc(*promo, (*TailleLogique + 1) * sizeof(Etudiant));

    for (int i = *TailleLogique; i > 0; i--) {
        (*promo)[i] = (*promo)[i - 1];
    }

    strcpy((*promo)[0].nom, nom);
    (*promo)[0].moyenne = moyenne;
    (*TailleLogique)++;
}

void afficherTableau( Etudiant * promo, int TailleLogique ){
    for (int i = 0; i < TailleLogique ; i++) {
        printf("ETUDIANT NUMERO %d\n", i+1);
        printf("%f: Moyenne de %s", promo[i].moyenne, promo[i].nom);
    }
}

void creationCellule(Cellule ** promo, int* tailleLogique){
    printf("Combien d'etudiants font partie de la Promo");
    scanf("%d", tailleLogique);
    *promo = malloc((*tailleLogique) * sizeof(Cellule));
    assert(*promo != NULL);

    for(int i = 0; i < *tailleLogique; i++) {
        fflush(stdin);
        printf("Saisir le nom de l'etudiant : %d", i + 1);
        fgets((*promo)[i].nom, 101, stdin);
        if ((*promo)[i].nom[strlen((*promo)[i].nom) - 1] == '\n') {
            (*promo)[i].nom[strlen((*promo)[i].nom) - 1] = '\0';
        }
        printf("Saisir la moyenne de l'eleve numero %d", i + 1);
        scanf("%f", &((*promo)[i].moyenne));
    }
}

Cellule* funcAjoutEnTeteDeListe (Cellule *liste, const char *nom, float moyenne) {
    Cellule *nouv = malloc(sizeof(Cellule));
    nouv->moyenne= moyenne;
    strcpy(nouv->nom, nom);
    nouv->next = liste;
    liste = nouv;
    return liste;
}

void procAjoutEnTeteDeListe (Cellule* *liste, const char *nom, float moyenne){
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

    if (parcours == NULL){
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
    strcpy(nouv4->nom, nom);
    nouv4->next = NULL;

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
    for(; parcours != NULL; parcours = parcours->next){
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
