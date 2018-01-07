#include <stdlib.h>
#include <stdio.h>
#include "pro.h"

int main (int argc, char* argv[]){

    Regle R=NULL;
    BC B;
    B->fait=R;
    int i;
    int n;
    
    int option;
    int prop;
    
    do{
        printf("====================================\n\n");
        afficher(R);
        affiche(B);
        printf("\n");
        printf("choisir une option\n");
        printf("1. Ajouter une proposition en fin de liste\n");
        printf("2. creer la conclusion de la regle\n");
        printf("3. Supprimer l'élément en tête \n");
        printf("4. Tester si un élément est dans liste\n");
        printf("5. Accéder à a première valeur de a liste\n");
        printf("6. Accéder à la conclusion de la regle\n");
        printf("7. Supprimer la conclusion de la regle\n");
        printf("8. Ajouter une regle en fin de base\n");
        printf("9. Accéder à la regle en tête de proposition\n");
        printf("10. Moteur d'interférence\n");
        printf("0. Quitter\n");
        scanf("%d",&option);
        
        
        switch(option){
            case 1:
                printf("Entrer la proposition à ajouter: ");
                scanf("%d", &prop);
                R=ajouterq(R,prop);
                break;
            case 2:
                printf("Entrer la conclusion de la regle: ");
                scanf("%d", &prop);
                R=conclusion(R,prop);
                break;    
            case 3:
                R=supprimert(R);
                break;
            case 4:
                printf("Entrer la valeur à rechercher:");
                scanf("%d", &prop);
                BOOL a=existe(R, prop);
                if (a){
                    printf("La valeur est présente\n");
                } else{
                    printf("La valeur n'est pas présente\n");
                }
                break;
           case 5: 
                printf("La valeur en tête est %d\n", proposition_tete(R));
                break;
           case 6: 
                printf("La conclusion de la règle est %d\n", acces_conclusion(R));
                break;
            case 7:
                R=supprimer_conclusion(R);
                break;
            case 8:
                B=ajouteR(B,R); 
           case 9: 
                printf("La regle en tête est:");
                en_tete(B);
                break;   
                            
            case 10:
                i=Moteur (n, R);
                break;
                 
                 
         }
   } while (option!=0);
  
   return EXIT_SUCCESS;
}
           

BOOL vide(Regle R)
{
    if (R==NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    /*
    Other option is to use
    return l== NULL;
    */
}

Regle creer()
{
    return NULL;
}

Regle ajout(Regle R, int e)
{
    Regle nouvEl;
    Regle T;
    nouvEl=(element*) malloc(sizeof(element));
    nouvEl->proposition=e;
    nouvEl->suivant=NULL;
    if(R==NULL)
    {
        R=nouvEl;
    }
    else
    {
        T=R;
        while (T->suivant !=NULL)
        {
            T=T->suivant;
        }
        T->suivant=nouvEl;
    }
    return R;
}

Regle ajouterq(Regle R, int e)
{
    R= ajout(R ,e);
    
    return R;
}

Regle conclusion(Regle R, int e)
{
    Regle new;
    Regle T;
    new=(element*) malloc(sizeof(element));
    new->proposition=e;
    new->suivant=NULL;
    if(R==NULL)
    {
        R=new;
    }
    else
    {
        T=R;
        while (T->suivant !=NULL)
        {
            T=T->suivant;
        }
        T->suivant=new;
    }
    return R;
}


Regle supprimert(Regle l)
{
    Regle p;
    if (l==NULL)
    {
        p=NULL;
    }
    else
    {
        p=l->suivant;
        free(l);
    }
    return p; 
}

Regle supprimer_conclusion(Regle l)
{
    if (l !=NULL){
        if (l->suivant==NULL)
        {
            free(l);
            l=NULL;
        }
        else
        {
            Regle p=l;
            while (p->suivant->suivant !=NULL)
            {
              p=p->suivant;
            }
            free(p->suivant);
            p->suivant=NULL;
        }
   }
   return l;
}

void afficher(Regle l)
{
    if(vide(l))
    {
        printf("*** Regle vide*** \n");
    }
    else
    {
        Regle p=l;
        printf("[");
        while (p->suivant !=NULL)
        {
            printf("%d ", p->proposition);
            if(p->suivant->suivant!=NULL)
            {
                printf("et ");
            }
            else
            {
                printf("=>");
            }
            p=p->suivant;
        }
        printf("%d]\n", p->proposition);
    }
}

int proposition_tete(Regle l)
{
    return l->proposition;
}

int acces_conclusion(Regle l)
{
    while(l->suivant!=NULL)
    {
        l=l->suivant;
    }
    return l->proposition;
}

BOOL existe(Regle l, int v)
{
    BOOL contient=FALSE;
    Regle p=l;
    while (!vide(p) && contient == FALSE)
    {
        if (proposition_tete(p)== v)
        {
            contient=TRUE;
        }
        else
        {
            p=p->suivant;
        }
    }
return contient;
}

BC creation()
{
    return NULL;
}

/*BC ajouteR(BC B, Regle R)
{
    BC K;
    int a;
    BC A;
    B->fait=R;
    while(!vide(B->fait))
    {
        K=B;
        K=K->next;
        printf("Ã§a va 2");
     }       
     printf("Entrer les proposition de la rÃ¨gle: ");
     scanf("%d", &a);
     R=ajout(R, a);
     printf("[\n");
     a=K->fait->proposition;
     printf("%d", a);

    return B;
}*/

BC ajouteR(BC B, Regle R)
{
    int a;
    printf("Entrer les proposition de la règle: ");
    scanf("%d", &a);
    
    if(empty(B))
    {
        B->fait=ajout(R,a);
    }    
    else
    {
        
        BC T= B;
        while(T->next!=NULL)
        {
            T=T->next;
        }
        T->fait=ajout(R,a);
     }
     return B;
}

/*BC ajouteR(BC B, Regle ajout(Regle R, int a))
{
    BC K;
    Regle R;
    int a;
    Regle new1;
    K=(composant*)malloc(sizeof(BC));
    K->fait=ajout(R, a);
    if(B==NULL)
    {
        B=K;
    }    
    else
    {
        
        BC T= B;
        while(T->next!=NULL)
        {
            T=T->next;
        }
        T->fait=K;
     }
     return B;
}*/       
    
    
BOOL empty(BC B)
{
    if (B->fait==NULL)
    {
        return TRUE;
    }
    else
    {   return FALSE;
    }

}

void affiche(BC B)
{
    if (empty(B))
    {
        printf("***la base est vide***\n");
    }
    else
    {
        BC T=B;
        while(!empty(B))
        {
            printf("[\n");
                while(T->fait!=NULL)
                {
                    printf("[%d]\n", T->fait->proposition);
                    T->fait=T->fait->suivant;
                 }
         }
         printf("]");
    }
    printf("\n");
}    
 
Regle en_tete(BC B)
{
    Regle K;
    K=B->fait;
    return K;
} 

int Moteur (int n, Regle R)

{
    Regle K;
    int e;
    int i;
    int r;
    Regle* tabBC;
    printf("Donnez le nombre de rÃ¨gles que contient la base de connaissance: ");
    scanf("%d", &r);
    tabBC=(Regle*)malloc(r * (sizeof(element*)));
    printf("Donnez le nombre de rÃ¨gles que contient la base de connaissance: ");
    for(i=0; i<n-1; i=i+1)
    {
        printf("Entrer la regle  %d de la base:", i);
        tabBC[i]=ajout(K, e);
    }
    printf("Entrez les faits: ");
    R=ajout(R, e);
    
        for(i=0; i<=n-1; i=i+1)
        {
            if(n==0)
            {
                printf("La base de connaissance est vide");
                r=0;
            }
            else if (!existe(tabBC[r], R->proposition))
           {
                printf("les faits ne sont pas vÃ©rifiÃ©s: ");
                r=0;
           }
                 else
                 {
                    while(R->suivant->suivant !=NULL)
                    {
                        R=R->suivant;
                    }
                     printf("la conclusion est %d: ", R->suivant->proposition);
                     r=1;
                   }
          }
    
         return r;
}
                  
                 
    
 
         
