#include "TP6.h"
#include "stdio.h"
#define TAILLE_PHYSIQUE 100

void InitialiserReelEntier(int* entier, float* reel){
    *entier= 0; *reel= 0;
}

void TP6Ex1(){
    int entier; float reel;
    printf("Avant initialisation : \n ");
    printf ("Entier = %d, Reel=  %.2f \n \n", entier, reel);
    InitialiserReelEntier(&entier, &reel);
    printf("Apres initialisation : \n ");
    printf ("Entier = %d, Reel=  %f.2f", entier, reel);
}

void procedureQR(int a, int b, int* quotient, int* reste){
    *quotient = a/b;
    *reste = a%b;
}

int fonctionQR(int a, int b, int* quotient){
    *quotient = a/b;
    return a%b;
}

int quotientRetourner(int a, int b, int* pReste) {
    *pReste = a % b;
    return a / b;
}

void TP6Ex2(){
    //Version 1 avec Fonction
    int quotient1 = -1;
    int reste1 = -1;
    reste1 = fonctionQR(5, 3, &quotient1);
    printf("La division de 5 par 3 nous donne comme reste %d et quotient %d\n",reste1, quotient1);

    //Version 2 avec Procedure
    int quotient2 = -1;
    int reste2 = -1;
    procedureQR(5, 3, &quotient2, &reste2);
    printf("La division de 5 par 3 nous donne comme reste %d et quotient %d \n",reste2, quotient2);

    //Version 3 en retournant le quotient ou non
    int quotient3 = -1;
    int reste3 = -1;                    // on est obligé d'avoir un entier pour pouvoir donner son adresse à quotientRetourner ()
    quotientRetourner(5, 2, &reste3);       // on ignore le quotient qui est retourné
    printf("Pour 5/2, le quotient est %d et le reste est %d.\n", quotient3, reste3);
    quotient3 = reste3 = -1;         // on les remet à -1 pour voir si elles vont être modifiées
    quotient3 = quotientRetourner(8, 3, &reste3);       // on n'ignore pas le quotient qui est retourné
    printf("Pour 8/3, le quotient est %d et le reste est %d.\n", quotient3, reste3);

}

void EchangeValeur(int *a, int *b){
    int aTP= *a;
    *a= *b;
    *b= aTP;
}

void TP6Ex3(){
    int a= 5; int b=8;
    printf("Avant Echange de Valeur:\n ");
    printf("a= %d et b= %d\n",a, b);
    EchangeValeur(&a,&b);
    printf("Apres Echange de Valeur:\n ");
    printf("a= %d et b= %d\n", a, b);
}
void SaisirTailleLogique(int TaillePhysique, int *TailleLogique) {
    do {
        printf("Combien d'element dans votre tableau entre 0 et 100 : \n");
        scanf("%d", TailleLogique);
    } while (*TailleLogique < 0 || *TailleLogique > TaillePhysique);
}

void RemplirTableau(int tableau[], int TailleLogique) {
    for (int i = 0; i < TailleLogique; i++) {
        printf("Saisir la case %d du tableau \n", i + 1);
        scanf("%d", &tableau[i]);
    }
}

void AficherTab(int tableau[], int TailleLogique) {
    for (int i = 0; i < TailleLogique - 1; i++) {
        printf("%d ", tableau[i]);
    }
    printf("%d\n", tableau[TailleLogique - 1]);
}

int SommeEtProduitV1(int *tableau, int TailleLogique, int *pSomme) {
    int produit = 1;
    *pSomme = 0;
    for (int i = 0; i < TailleLogique; i++) {
        *pSomme += tableau[i];
        produit *= tableau[i];
    }
    return produit;
}

int SommeEtProduitV2(int tableau[], int TailleLogique, int *pProduit) {
    int somme = 0;
    *pProduit = 1;
    for (int i = 0; i < TailleLogique; i++) {
        *pProduit *= tableau[i];
        somme += tableau[i];
    }
    return somme;
}

void TP6Ex4() {
    int tableau[TAILLE_PHYSIQUE];
    int TailleLogique, somme, produit = 0;
    SaisirTailleLogique(TAILLE_PHYSIQUE, &TailleLogique);
    RemplirTableau(tableau, TailleLogique);
    AficherTab(tableau, TailleLogique);
    produit = SommeEtProduitV1(tableau, TailleLogique, &somme);
    printf("Produit des termes : %d\n", produit);
    printf("Somme des termes : %d\n", somme);
}


void AffichagePoint(Point* pA, Point* pB){
    printf("Coordonee en x du point A\n");
    scanf("%f", &(pA->x));
    printf("Coordonee en y du point B\n");
    scanf("%f", &(pA->y));

    printf("Coordonee en x du point A\n");
    scanf("%f", &(pB->x));
    printf("Coordonee en y du point B\n");
    scanf("%f", &(pB->y));

}


void EchangeStructure(Point* pA, Point* pB){
    Point Intermediaire;
    Intermediaire.x = pA -> x;
    Intermediaire.y = pA -> y;
    *pA = *pB;
    *pB = Intermediaire;
}

void TP6Ex5(){
    Point pA; Point pB;
    AffichagePoint(&pA,&pB);
    EchangeStructure(&pA,&pB);
    printf("Coordonee point A :\n x= %.2f, y= %.2f\n\n", pA.x, pA.y);
    printf("Coordonee point B :\n x= %.2f, y= %.2f\n\n", pB.x, pB.y);
}


