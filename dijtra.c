#include <stdio.h>
#include <string.h> 
#define INFINITY 9999.00
 
void dijkstra(float G[47][47], int n, int depart, int arrivee, char sommets[47][50]);
void rentre_sommets (char sommets[47][50]);
void affiche_sommets();
int choix_sommets(char sommets[47][50]);

int main(){
	int depart, arrivee;
	int choix = 0;
	int boolean = -1;
	FILE *fichier;
	char sommets[47][50];
	
	while (boolean != 0)
	{
		printf("Si vous etes un skieur debutant, appuyer sur 1, sinon sur 2\n");
		scanf("%d",&choix);
		if (choix == 1  || choix == 2) boolean = 0;
		else boolean = 1;
	}
	
	if (choix == 1) fichier  = fopen("matrice_cout1","r");
	else fichier = fopen("matrice_cout2","r");
	
	rentre_sommets(sommets);
	
	float G[47][47];
	int i,j;
	i = 0;
	
	for (i = 0; i < 47; i ++)
	{
		for (j = 0; j < 47; j ++)
		{
				fscanf(fichier, "%f",&(G[i][j]));
		}
	}
	fclose(fichier);
	affiche_sommets();
	printf("Entrer le sommet de depart: \n");
	depart = choix_sommets(sommets);
	if (depart == -1)
	{
		printf("Le sommet rentre comme depart est incorrect\n");
		return -1;
	}
	printf("Entrer le sommet d'arrivee: \n");
	arrivee = choix_sommets(sommets);
	if (arrivee == -1)
	{
		printf("Le sommet rentre comme arrive est incorect\n");
		return -1;
	}
	dijkstra(G,47,depart,arrivee,sommets);
	
	return 0;
}
 
void dijkstra(float G[47][47], int n, int depart, int arrivee, char sommets[47][50])
{
	float cout[47][47], distance[47], pred[47];
	float visite[47], compteur, mindistance ; 
	int i,j,prochain;
	/**
	 * Initialisation de la matrice du cout avec la valeur 0 remplacee par INFINITY
	 **/ 
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(G[i][j]==0.0)
				cout[i][j]=INFINITY;
			else
				cout[i][j]=G[i][j];
	/**
	 * Initialisation de tableau des distances
	 * */
	for(i=0;i< n;i++)
	{
		distance[i]=cout[depart][i];
		pred[i]=depart;
		visite[i]=0.0;
	}
	distance[depart]=0;
	visite[depart]=1;
	compteur=1;
	/**
	 * Algo de dijtra
	 * */
	while(compteur < n-1){
		mindistance=INFINITY;
		for(i=0;i < n;i++)
			if(distance[i] < mindistance&&!visite[i])
			{
				mindistance=distance[i];
				prochain=i;
			}
		visite[prochain]=1;
		for(i=0;i < n;i++)
			if(!visite[i])
				if(mindistance+cout[prochain][i] < distance[i])
				{
					distance[i]=mindistance+cout[prochain][i];
					pred[i]=prochain;
				}
			compteur++;
	}
	i = arrivee;
	/**
	 * Affichage de la distance et du chemin 
	 **/
		if(i!=depart)
		{
			printf("\nLa distance entre %s et %s est %f", sommets[depart], sommets[arrivee], distance[i]);
			printf("\nLe trajet est = %s", sommets[i]);
			j=i;
			do
			{
				j=pred[j];
				printf(" <- %s", sommets[j]);
			}
			while(j!=depart);
		}
		printf("\n");
}

void rentre_sommets(char sommets[47][50])
{
	FILE *fichier = fopen("Sommets.txt","r");
	int i;
	for (i = 0; i < 47; i ++)
	{
		fscanf(fichier, "%s", sommets[i]);
	}
	
	fclose(fichier);
}

void affiche_sommets()
{
	printf("Vous pouvez partir des sommets suivants:\n");
	printf("La-Villette\n");
	printf("MontFrais\n");
	printf("Vaujany\n");
	printf("Alpette\n");
	printf("Dome-Des-Petites-Rousses\n");
	printf("Pic-Blanc\n");
	printf("Glacier-De-Sarenne\n");
	printf("Clocher-De-Macle\n");
	printf("Plat-Des-Marmottes\n");
	printf("Alpe-D-Huez\n");
	printf("Oz-En-Oisans\n");
	printf("Signal\n");
	printf("Villard-Reculas\n");
	printf("Huez\n");
	printf("Signal-De-L-Homme\n");
	printf("Auris-En-Oisans\n");
	printf("Le-Chatelard\n");
	printf("Enversin\n");
}

int choix_sommets(char sommets[47][50])
{
	char chaine[50];
	scanf("%s",chaine);
	if (strcmp(chaine,sommets[0]) == 0) return 0;
	else if (strcmp(chaine,sommets[1]) == 0) return 1;
	else if (strcmp(chaine,sommets[3])== 0) return 3;
	else if (strcmp(chaine,sommets[4]) == 0) return 4;
	else if (strcmp(chaine,sommets[8]) == 0) return 8;
	else if (strcmp(chaine,sommets[13]) == 0) return 13;
	else if (strcmp(chaine,sommets[14]) == 0) return 14;
	else if (strcmp(chaine,sommets[17]) == 0) return 17;
	else if (strcmp(chaine,sommets[19]) == 0) return 19;
	else if (strcmp(chaine,sommets[20]) == 0) return 20;
	else if (strcmp(chaine,sommets[23]) == 0) return 23;
	else if (strcmp(chaine,sommets[28]) == 0) return 28;
	else if (strcmp(chaine,sommets[29]) == 0) return 29;
	else if (strcmp(chaine,sommets[36]) == 0) return 36;
	else if (strcmp(chaine,sommets[38]) == 0) return 38;
	else if (strcmp(chaine,sommets[43]) == 0) return 43;
	else if (strcmp(chaine,sommets[44]) == 0) return 44;
	else return -1;
}
