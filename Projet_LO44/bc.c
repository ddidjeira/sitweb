// Produit par DIDJEIRA Dimanna Augustin && DJOUSSE William
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bc.h"
regle nouvP (regle temp)
{
  return temp = (proposition *) malloc (sizeof (proposition));
}


BC nouvC (BC temp)
{
  return temp = (base_connaissances *) malloc (sizeof (base_connaissances));
}


BF nouvF (BF temp)
{
  return temp = (fait *) malloc (sizeof (fait));
}

regle creerR ()
{
  return NULL;
}

BC creerB ()
{
  return NULL;
}

int compterP (regle R)
{
  int compteur = 0;
  if (vide (R))
    {
      return 0;
    }
  else
    {
      while (R != NULL)
	{
	  compteur++;
	  R = R->next;
	}
      return compteur;
    }
}

int compterR (BC base)
{
  int compteur = 0;
  if (base == NULL)
    {
      return 0;
    }
  else
    {
      while (base != NULL)
	{
	  compteur++;
	  base = base->next;
	}
      return compteur;
    }
}


regle ajouterPRO (regle R, char * pro)
{
  regle new, I, temp;
  I = R;
  new = nouvP (new);
  new->valeur = malloc(256 * sizeof(*new->valeur));
  strcpy (new->valeur, pro);
  if (vide (I))
    {
      return new;
    }
  else
    {
      while (I->next != NULL)
	{
	  I = I->next;
	}
      temp = I->next;
      I->next = new;
      new->next = temp;
      return R;
    }

}

regle ajouterCON (regle R, char * con)
{
  regle new, I;
  I = R;
  new = nouvP (new);
  new->valeur = malloc(256 * sizeof(*new->valeur));
  strcpy (new->valeur, con);
  if (vide (I))
    {
      return new;
    }
  else
    {
      while (I->next != NULL)
	{
	  I = I->next;
	}
      I->next = new;
      new->next = NULL;
      return R;
    }

}


BOOL vide (regle R)
{
  if (R == NULL)
    {
      return VRAI;
    }
  else
    {
      return FAUX;
    }
}


char * conclusion (regle R)
{
  regle I;
  I = R;
  while (I->next != NULL)
    {
      I = I->next;
    }
  return I->valeur;
}

regle tete (regle R)
{
  return R;
}



regle supprimer (regle R, char * pro)
{
  regle temp, I;
  I = R;
  if (R == NULL)
    {
      return NULL;
    }
  if (!strcmp (R->valeur, pro))
    {
      R = I->next;
      free (I);
      return R;
    }
  temp = I->next;

  while (temp != NULL)
    {
      if (!strcmp (temp->valeur, pro))
	{
	  I->next = temp->next;
	  free (temp);
	  return R;
	}
      I = temp;
      temp = temp->next;
    }
  return R;

}

void afficher (regle R, BOOL a)
{
  int nb = compterP (R);
  if (vide (R))
    printf ("La regle est vide");
  else if (nb == 1)
    printf ("%s ", R->valeur);
  else if (a == VRAI)
    {
      while (!vide (R))
	{
	  if (R->next != NULL)
	    {
	      if (R->next->next == NULL)
		{
		  printf ("%s ", R->valeur);
		}
	      else
		{
		  printf ("%s ", R->valeur);
		  printf ("et ");
		}
	    }
	  else
	    {
	      printf ("=> ");
	      printf ("%s ", R->valeur);
	    }
	  R = R->next;

	}
    }
  else
    {
      while (!vide (R))
	{
	  printf ("%s ", R->valeur);
	  if (R->next != NULL)
	    {
	      printf ("et ");
	    }
	  R = R->next;

	}

    }
}

BC ajouterR (BC base, regle R)
{

  BC new, temp;
  temp = base;
  new = nouvC (new);
  new->rule = R;
  if (base == NULL)
    {
      return new;
    }
  else
    {
      while (base->next != NULL)
	{
	  base = base->next;
	}
      base->next = new;
      new->next = NULL;
      return temp;
    }
}

void afficherbase (BC base)
{
  int i = 1;
  BOOL a = VRAI;
  if (base == NULL)
    {
      printf ("La base est vide");
    }
  else
    {
      while (base != NULL)
	{
	  printf ("R%d: ", i);
	  afficher (base->rule, a);
	  printf ("\n");
	  base = base->next;
	  i = i + 1;
	}

    }
}


void afficherfaits (BF faits)
{
  if (faits == NULL)
    {
      printf ("La base est vide");
    }
  else
    {
      while (faits != NULL)
	{
	  printf ("%s ", faits->valeur);
	  faits = faits->next;
	}

    }
}



regle reste (regle R)
{
  if (R->next->next == NULL)
    {
      return NULL;
    }
  else
    {
      return R->next;
    }
}

BOOL test (regle R, char * pro)
{
  if (vide (R))
    {
      return FAUX;
    }
  else
    {
      if (!strcmp (R->valeur, pro))
	{
	  return VRAI;
	}
      else
	{
	  return test (reste (R), pro);
	}
    }
}


BOOL existe (BF faitss, char * pro)
{
  if (faitss == NULL)
    {
      return FAUX;
    }
  else
    {
      if (!strcmp (faitss->valeur, pro))
	{
	  return VRAI;
	}
      else
	{
	  return existe (faitss->next, pro);
	}
    }
}



BF ajouterF (BF F, char * faits)
{
  BF new, I, temp;
  I = F;
  new = nouvF (new);
  new->valeur = malloc(256 * sizeof(*new->valeur));
  strcpy (new->valeur, faits);
  if (I == NULL)
    {
      return new;
    }
  else
    {
      while (I->next != NULL)
	{
	  I = I->next;
	}
      temp = I->next;
      I->next = new;
      new->next = temp;
      return F;
    }

}


BF MI (BC base, BF faits)
{
  BF newfaits, temp;
  BC tempb;
  int a;
  newfaits=NULL;
  BOOL add;
  add = VRAI;
  while (add == VRAI)
    {
      tempb = base;
      while (tempb != NULL)
	{
	  a = 0;
	  temp = faits;
	  while (temp != NULL)
	    {
            if (test (tempb->rule, temp->valeur))
		{
		  a = a + 1;
		}
	      temp = temp->next;
	    }
	  if (a == compterP (tempb->rule) - 1)
	    {
	      if (!existe (faits, conclusion (tempb->rule)))
		{
		  newfaits = ajouterF (newfaits, conclusion (tempb->rule));
		  add = VRAI;
		  faits = ajouterF (faits, conclusion (tempb->rule));
		}
	      else
		{
		  add = FAUX;
		}

	    }
	  tempb = tempb->next;
	}
      if (newfaits == NULL)
	{
	  add = FAUX;
	}
    }
  return newfaits;
}

BC initialiserbase(BC base)
{
  regle L;
  L = creerR ();
  L = ajouterPRO (L, "a");
  L = ajouterPRO (L, "b");
  L = ajouterPRO (L, "c");
  base = ajouterR (base, L);
  L = creerR (); 
  L = ajouterPRO (L, "c");
  L = ajouterPRO (L, "d");
  L = ajouterPRO (L, "e");
  base = ajouterR (base, L);
  L = creerR (); 
  L = ajouterPRO (L, "t");
  L = ajouterPRO (L, "z");
  L = ajouterPRO (L, "b");
  base = ajouterR (base, L);
  return base;
}
