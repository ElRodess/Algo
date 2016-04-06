#include <stdio.h>
//~ #include<conio.h>
#define INFINITY 9999
#define MAX 12
 
void dijikstra(int G[MAX][MAX], int n, int startnode, int arrivee);
 
int main(){
	int u, v;
	//~ clrscr();
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
	printf("\nEntrer le sommet de depart ");
	scanf("%d", &u);
	printf("\nEntrer le sommet d'arrivee: ");
	scanf("%d", &v);
	dijikstra(G,MAX,u,v);
	//~ getch();
	
	return 0;
}
 
void dijikstra(int G[MAX][MAX], int n, int startnode, int arrivee)
{
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i,j;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	
	for(i=0;i< n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count < n-1){
		mindistance=INFINITY;
		for(i=0;i < n;i++)
			if(distance[i] < mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=0;i < n;i++)
			if(!visited[i])
				if(mindistance+cost[nextnode][i] < distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			count++;
	}
	i = arrivee;
	//for(i=0;i < n;i++)
		if(i!=startnode)
		{
			printf("\nLa distance entre %d et %d est %d", startnode, arrivee, distance[i]);
			printf("\nSon cout est = %d", i);
			j=i;
			do
			{
				j=pred[j];
				printf(" <-%d", j);
			}
			while(j!=startnode);
		}
		printf("\n");
}
