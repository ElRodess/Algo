#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct arete Arete;

typedef struct sommet
{
        char nom;
        Arete* suivants;
}Sommet;

typedef struct arete
{
	char* nom;
	int poids;
	Sommet depart[25];
	Sommet arrivee[25];
}Arete;



/*
int nombre_de_ligne (FILE *fichier)
{
	int i = 0;
	char test[20];
	while (fgets(test,20,fichier) != NULL)
	{
		i ++;
	}
	return i;
}

void affiche_arete(Arete a)
{
	printf("nom: %s",a.nom);
	printf("type: %s",a.type);
	printf("depart: %s",a.depart);
	printf("arrivee: %s\n",a.arrivee);
}
*/
int main(int argc, char **argv)
{
	//~ Arete A[5];
	//~ int i = 0;
	//~ int j = 0;
	//~ FILE *fichier  = fopen("test.txt","r");
	//~ int compteur = nombre_de_ligne(fichier);
	//~ rewind(fichier);
	//~ 
	//~ while(j != compteur)
	//~ {
		//~ fgets(A[i].nom,10,fichier);
		//~ j ++;
		//~ fgets(A[i].type,10,fichier);
		//~ j ++;
		//~ fgets(A[i].depart,10,fichier);
		//~ j ++;
		//~ fgets(A[i].arrivee,10,fichier);
		//~ j ++;
		//~ affiche_arete(A[i]);
		//~ i++;
	//~ }
	//~ 
	//~ fclose(fichier);
	
	return 0;
}
