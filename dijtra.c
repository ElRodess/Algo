#include <stdio.h>
#define INFINITY 9999
#define MAX 12
 
void dijkstra(int G[MAX][MAX], int n, int depart, int arrivee);
 
int main(){
	int u, v;
	 int G[MAX][MAX] = {
	{0,2,0,0,13,0,0,0,0,0,7,10},
	{0,0,0,0,0,0,1,0,0,0,0,0},
	{0,0,0,1,0,0,1,0,0,2,0,0},
	{0,0,0,0,0,8,0,4,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,5,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,5,0,0,0,2,0,0,0,3},
	{0,0,0,0,0,10,0,0,4,7,0,0},
	{0,0,0,0,0,5,0,0,0,0,0,0},
	{0,0,0,0,0,1,0,0,9,0,0,0},
	{0,0,3,0,8,0,0,0,0,0,5,0},
	{10,6,0,0,0,0,12,0,0,0,0,0},};
	printf("Entrer le sommet de depart: \n");
	scanf("%d", &u);
	printf("Entrer le sommet d'arrivee: \n");
	scanf("%d", &v);
	dijkstra(G,MAX,u,v);
	
	return 0;
}
 
void dijkstra(int G[MAX][MAX], int n, int depart, int arrivee)
{
	int cout[MAX][MAX], distance[MAX], pred[MAX];
	int visite[MAX], compteur, mindistance, prochain, i,j;
	/**
	 * Initialisation de la matrice du cout avec la valeur 0 remplacee par INFINITY
	 **/ 
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(G[i][j]==0)
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
		visite[i]=0;
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
			printf("\nLa distance entre %d et %d est %d", depart, arrivee, distance[i]);
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
