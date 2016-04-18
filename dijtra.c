#include <stdio.h>
#define INFINITY 9999.00
 
void dijkstra(float G[47][47], int n, int depart, int arrivee);

int main(){
	int u, v;
	int choix = 0;
	int boolean = -1;
	FILE *fichier;
	
	while (boolean != 0)
	{
		printf("Si vous etes un skieur debutant, appuyer sur 1, sinon sur 2\n");
		scanf("%d",&choix);
		if (choix == 1  || choix == 2) boolean = 0;
		else boolean = 1;
	}
	
	if (choix == 1) fichier  = fopen("matrice_cout1","r");
	else fichier = fopen("matrice_cout2","r");
	
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
	printf("Entrer le sommet de depart: \n");
	scanf("%d", &u);
	printf("Entrer le sommet d'arrivee: \n");
	scanf("%d", &v);
	dijkstra(G,47,u,v);
	
	return 0;
}
 
void dijkstra(float G[47][47], int n, int depart, int arrivee)
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
			printf("\nLa distance entre %d et %d est %f", depart, arrivee, distance[i]);
			printf("\nLe trajet est = %d", i);
			j=i;
			do
			{
				j=pred[j];
				printf(" <- %d", j);
			}
			while(j!=depart);
		}
		printf("\n");
}
