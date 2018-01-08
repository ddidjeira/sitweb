// Produit par DIDJEIRA Dimanna Augustin && DJOUSSE William
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bc.h"


int main ()
{
  BOOL existeconclusion;	// cette variable teste si une conclusion existe avant tout accès à elle
  system ("clear");
  int rep2;
  char *p = malloc(256 * sizeof(*p));
  char rep[1];
  regle L;
  BF F;
  F = NULL;
  BC base;
  base = creerB ();
  do
    {
      printf
	("\n		#################################################");
      printf
	("\n		######### OPERATIONS SUR SYSTEME EXPERT #########");
      printf
	("\n		#################################################");


      printf ("\n\n                Que voulez-vous faire?\n\n");
      printf ("1-Ajouter une base de connaissance\n");
      printf
	("2-Entrer des faits en utilisant une base de connaissance prédéfinie\n");
      printf ("3-Quitter le programme\n");
      printf ("\n                  Votre choix?: ");
      scanf ("%s", rep);
      rep2 = atoi (rep);
      if (rep2 == 1 || rep2 == 2 || rep2 == 3)
	{
	}
      else
	{
	  system ("clear");
	}
    }
  while (rep2 < 1 || rep2 > 3);

  switch (rep2)
    {

    case 1:
      {
	printf ("               MENU AJOUT, SUPPRESSION ET TEST DE REGLES");
	L = creerR ();
	existeconclusion = FAUX;
	do
	  {
	    do
	      {
		if (vide (L))
		  {
		    existeconclusion = FAUX;
		  }
		system ("clear");
		printf("\n\nLe programme est sensible à la casse. Merci aussi d'éviter les caractères spéciaux les espaces\n\n");
		printf ("\n\n                Que voulez-vous faire?\n\n");
		printf ("1-Ajouter une proposition\n");
		printf ("2-Supprimer un proposition\n");
		printf ("3-Ajouter une conclusion\n");
		printf
		  ("4-Tester si une proposition appartient à une règle\n");
		printf ("5-Fin de saisie de la règle");
		printf ("\n                  Votre choix?: ");
		scanf ("%s", rep);
		rep2 = atoi (rep);
	      }
	    while (rep2 < 1 || rep2 > 5);

	    switch (rep2)
	      {
	      case 1:
		{
		  printf ("\nProposition à ajouter: ");
		  scanf ("%s", p);
		  L = ajouterPRO (L, p);
		  system ("clear");
		  afficher (L, existeconclusion);
		  break;
		}

	      case 2:
		{
		  printf ("\nProposition à supprimer: ");
		  scanf ("%s", p);
		  L = supprimer (L, p);
		  afficher (L, existeconclusion);
		  break;
		}
	      case 3:
		{
		  printf ("\nEntrez la conclusion: ");
		  scanf ("%s", p);
		  L = ajouterCON (L, p);
		  existeconclusion = VRAI;
		  system ("clear");
		  afficher (L, existeconclusion);
		  break;
		}
	      case 4:
		{
		  printf ("Proposition à tester: ");
		  scanf ("%s", p);
		  system ("clear");
		  afficher (L, existeconclusion);
		  if (test (L, p))
		    {
		      printf
			("  Cette proposition appartient à la premisse");
		    }
		  else
		    {
		      printf
			("  Cette proposition n'appartient à la premisse");
		    }
		  break;
		}
	      case 5:
		{
		  do
		    {
		      base = ajouterR (base, L);
		      printf ("\nVoulez-vous entrer une nouvelle règle?");
		      printf ("\n10-OUI");
		      printf ("\n20-NON");
		      printf ("\nChoix: ");
		      scanf ("%s", rep);
		      rep2 = atoi (rep);
		      if (existeconclusion == FAUX)
			{
			  printf
			    ("\nUne regle sans conlusion ne peut pas être ajouter à la base");
			  printf ("\nEntrez la conclusion: ");
			  scanf ("%s", p);
			  L = ajouterCON (L, p);
			  existeconclusion = VRAI;
			}
		      if (rep2 == 10 || rep2 == 20)
			{
			  L = creerR ();
			}
		      else
			{
			  system ("clear");
			}
		    }
		  while (rep2 < 10 || rep2 > 20);
		  break;
		}
	      }
	  }

	while (rep2 != 20);
	system ("clear");
	printf ("                             BASE DE CONNAISSANCES\n");
	afficherbase (base);
	printf ("                             AJOUT DES FAITS\n");
	do
	  {
	    printf ("Entrez un fait: ");
	    scanf ("%s", p);
	    F = ajouterF (F, p);

	    do
	      {
		printf ("Voulez vous ajouter un nouveau fait: ");
		printf ("\n1-OUI");
		printf ("\n2-NON");
		printf ("\nChoix: ");
		printf ("\n                  Votre choix?: ");
		scanf ("%s", rep);
		rep2 = atoi (rep);
		if (rep2 == 1 || rep2 == 2)
		  {
		  }
		else
		  {
		    system ("clear");
		  }
	      }
	    while (rep2 < 1 || rep2 > 2);
	  }
	while (rep2 != 2);
	system ("clear");
	printf ("                                   ___________");
	printf ("\n                                  | 	      |");
	printf ("\n                                  | RESULTATS |");
	printf ("\n                                  |___________|\n\n");
	afficherbase (base);
	printf ("\nAnciens faits: ");
	afficherfaits (F);
	F = MI (base, F);
	if (F == NULL)
	  {
	    printf
	      ("\n\nLe moteur d'inférence n'a déduit aucun nouveau fait. Vérifer les faits entrés et la base de connaissances.");
	  }
	else
	  {
	    printf ("\n\nNouveaux faits: ");
	    afficherfaits (F);
	  }
	printf ("\n\n");
	break;
      }
    case 2:
      {
	system ("clear");
	base=initialiserbase(base);
        printf("\n\nLe programme est sensible �|  la casse. Merci aussi d'éviter les caractères spéciaux les espaces\n\n");
        printf ("                             BASE DE CONNAISSANCES\n");
	afficherbase (base);
	printf ("    	                      AJOUT DES FAITS\n");
	do
	  {
	    printf ("Entrez un fait: ");
	    scanf ("%s", p);
	    F = ajouterF (F, p);

	    do
	      {
		printf ("Voulez vous ajouter un nouveau fait?");
		printf ("\n1-OUI");
		printf ("\n2-NON");
		printf ("\nChoix: ");
		printf ("\n                  Votre choix?: ");
		scanf ("%s", rep);
		rep2 = atoi (rep);
	      }
	    while (rep2 < 1 || rep2 > 2);
	  }
	while (rep2 != 2);
	system ("clear");
	printf ("                                   ___________");
	printf ("\n                                  |           |");
	printf ("\n                                  | RESULTATS |");
	printf ("\n                                  |___________|\n\n");
	afficherbase (base);
	printf ("Anciens faits: ");
	afficherfaits (F);
	F = MI (base, F);
	if (F == NULL)
	  {
	    printf
	      ("\n\nLe moteur d'inférence n'a déduit aucun nouveau fait. Vérifer les faits entrés et la base de connaissances.");
	  }
	else
	  {
	    printf ("\n\nNouveaux faits: ");
	    afficherfaits (F);
      }
	printf ("\n\n");
	break;
      }

    case 3:
      {
	return EXIT_SUCCESS;
	break;
      }
    }
return EXIT_SUCCESS;
}
