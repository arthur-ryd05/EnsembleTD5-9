#ifndef ENSEMBLETD_TP6_H
#define ENSEMBLETD_TP6_H

void InitialiserReelEntier(int* entier, float* reel);

void TP6Ex1();

void procedureQR(int a, int b, int* quotient, int* reste);
int fonctionQR(int a, int b, int* quotient);
int quotientRetourner(int a, int b, int* pReste);

void TP6Ex2();

void EchangeValeur(int *a, int *b);

void TP6Ex3();

int SommeEtProduitV2(int tableau [], int TailleLogique, int *pProduit);
int SommeEtProduitV1(int tableau [], int TailleLogique, int *pSomme);
void AficherTab(int tableau[], int TailleLogique);
void RemplirTableau(int tableau[], int TailleLogique);
void SaisirTailleLogique(int TaillePhysique, int* TailleLogique);

void TP6Ex4();

typedef struct{
    float x,y;} Point;

void AffichagePoint(Point* pA, Point* pB);
void EchangeStructure(Point* pA, Point* pB);

void TP6Ex5();

#endif
