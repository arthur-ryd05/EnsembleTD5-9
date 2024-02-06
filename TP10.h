#ifndef ENSEMBLETD_TP10_H
#define ENSEMBLETD_TP10_H

struct MLSC{
    //data
    int id;
    char lettre;

    //link
    struct MLSC* next;
};
typedef struct MLSC MLSC;

void ajouterEnTete(MLSC** const pListe, const int id, const char lettre);
void ajouterEnFin(MLSC** const pListe, int id,  char lettre);
void afficher(MLSC *m);

void ExoCours();
void freeliste(MLSC** pListe);

//CHANSON...

typedef struct c{
    //data
    char titre [50];
    char artiste[30];
    unsigned int duree;
    //link
    struct c* next;
}Chanson;

typedef Chanson* Playlist;
Chanson* initChanson(char* titre, char* artiste,
                     unsigned int duree);

void lectureEnCours(Chanson* ajouer);
void ajouterFileAttente(Playlist* fileAttente,
                        char* titre, char*artiste, unsigned int duree);

//TP COURS...

typedef struct{
    char nom [101];
    float moyenne;
}Etudiant;

typedef struct C{
    char nom [101];
    float moyenne;
    struct C* next;
}Cellule;

void creationPromo(Etudiant** promo, int* tailleLogique);
void ajoutEnFinDeTableau (Etudiant **promo, int *TailleLogique, char *nom, float moyenne );
void ajoutEnDebutDeTableau (Etudiant **promo, int* TailleLogique, char *nom, float moyenne );
void afficherTableau(Etudiant * promo, int TailleLogique );



void creationCellule(Cellule ** promo, int* tailleLogique);
Cellule* funcAjoutEnTeteDeListe ( Cellule *liste,
                                  const char *nom,
                                  float moyenne );
void procAjoutEnTeteDeListe ( Cellule **liste,
                              const char *nom,
                              float moyenne );
Cellule* funcAjoutEnFinDeListe ( Cellule *liste,
                                 const char *nom,
                                 float moyenne );
void procAjoutEnFinDeListe ( Cellule **promo,
                             const char *nom,
                             float moyenne );

void afficherListeAvecWhile ( Cellule *liste );
void afficherListeAvecFor ( Cellule *liste );
void libererListe ( Cellule **pointeurSurListe );
int nombreElementsRecurs ( Cellule * liste );

int TpListeChainerMain();

#endif
