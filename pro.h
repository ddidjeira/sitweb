#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int n;

typedef int BOOL;

typedef struct elem {
    int proposition;
    struct elem*suivant;
} element;

typedef element * Regle;


typedef struct comp{
                    Regle fait;
                    struct comp* next;
                    }composant;               
            
typedef composant* BC;

BOOL vide(Regle l);
Regle creer();
Regle ajout(Regle R, int e);
Regle ajouterq(Regle l, int e);
Regle conclusion(Regle l, int e);
Regle supprimert(Regle l);
Regle supprimer_conclusion(Regle l);
void afficher(Regle l);
void affiche(BC B);
int proposition_tete(Regle l); // Cette fonction requiert que la liste ne soit pas vide
BOOL existe(Regle l, int v);
int acces_conclusion(Regle l);
BOOL empty(BC B);
BC ajouteR(BC B, Regle R);
Regle en_tete(BC B);
int Moteur (int n, Regle R);
