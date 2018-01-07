// Produit par DIDJEIRA Dimanna Augustin && DJOUSSE William
#ifndef BCC
#define BCC
#include <stdio.h>
#define VRAI 1
#define FAUX 0

//Declaration du type booléen
typedef int BOOL;

//Declaration du type proposition qui est composé d'une valeur et d'un pointeur sur la proposition suivante
typedef struct prop
{
  char * valeur;
  struct prop *next;
} proposition;

// Déclaration d'un type regle qui est une liste de proposition
typedef proposition *regle;

//Declaration du type base de connaissance qui est composé d'une rgele et d'un pointeur sur la regle suivante
typedef struct con
{
  regle rule;
  struct con *next;
} base_connaissances;

//Declaration d'un pointeur BC qui est une liste de regle
typedef base_connaissances *BC;

//Declaration d'un type fait qui est composé d'une valeur et d'un élément sur le fait suivant
typedef struct fact
{
  char * valeur;
  struct fact *next;
} fait;

//Déclaration du type BF qui est une liste de faits
typedef fait *BF;

//La fonction nouvP fait un malloc pour une proposition
regle nouvP (regle temp);

//La fonction nouvC fait un malloc d'un element de la base de connaissance
BC nouvC (BC temp);

//La fonction nouvF fait un malloc d'un element de la base de fait
BF nouvF (BF temp);

//La fonction ajouterPRO ajoute une proposition à la prémisse d'une regle
regle ajouterPRO (regle R, char * pro);

// Lafonction ajouterCON ajoute une conclusion à une règle
regle ajouterCON (regle R, char * con);

//La fonction creerR crée une règle vide
regle creerR ();

//La fconftion créerB crée une base vide 
BC creerB ();

//Cette fonction teste si la premisse est vide, donc si la regle est vide
BOOL vide (regle R);

//cette fonction permet d'accéder à la conclusion d'une règle. On accède à une conlusion si la regle existe,si la conclusion existe et si elle à une premisse.Pas de premisse, pas de conclusion.
char *conclusion (regle R);

//cette fonction permet d'acceder à la proposition en tête d'une premisse
regle tete (regle R);

// Fonction permettant de renvoyer le reste d'une règle pour les fonctions reccurssives
regle reste (regle R);

//Fonction permettant d'ajouter une règle à une base
BC ajouterR (BC base, regle R);

//cette fonction test de manière recurssive si une proposition appartient à la premisse d'une règle
BOOL test (regle R, char * pro);

//Fonction qui teste si un fait appartient à la base de faits
BOOL existe (BF faitss, char * pro);

//Cette fonction ajoute un fait à la base de fait;
BF ajouterF (BF F, char * faits);

// Cette fonction compte nombre de proposition d'une règle y compris la conclusion
int compterP (regle R);

//cette fonction supprime une proposition de la premisse d'une règle
regle supprimer (regle R, char * pro);

//cette fonction permmet d'afficher un règle.elle prend un booléen qui vérifie si la conclusion existe ou pas. selon qu'elle existe ou pas l'affichage diffère
void afficher (regle R, BOOL a);

//Cette fonction permet d'afficher les éléments de la base de connaissance
void afficherbase (BC base);

//Cette fonction permet d'afficher les éléments de la base de faits
void afficherfaits (BF faits);


//cette fonction compte le nombre de règle dans la base de connaissances
int compterR (BC base);
//Cette fonction est le moetru d'inférence.elle prend en paramètre la base de connaissance et la base de faits.on considère que la base n'est pas vide et que toutes les règles possèdent une premisse et une conclusion. Elle retourne un base de faits ne contenant que les nouveaux faits.
BF MI (BC base, BF faits);

// Cette conftion permet de créer une base de connaissance prédéfinie
BC initialiserbase(BC base);
#endif
