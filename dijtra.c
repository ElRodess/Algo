#include <stdio.h>
//~ #include<conio.h>
#define INFINITY 9999
#define MAX 12
 
void dijikstra(int G[MAX][MAX], int n, int startnode);
 
int main(){
	int n, u;
	//~ clrscr();
	printf("\nEnter the no. of vertices:: ");
	scanf("%d", &n);
	printf("\nEnter the adjacency matrix::\n");
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
	printf("\nEnter the starting node:: ");
	scanf("%d", &u);
	dijikstra(G,n,u);
	//~ getch();
	
	return 0;
}
 
void dijikstra(int G[MAX][MAX], int n, int startnode)
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
 
	for(i=0;i < n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of %d = %d", i, distance[i]);
			printf("\nPath = %d", i);
			j=i;
			do
			{
				j=pred[j];
				printf(" <-%d", j);
			}
			while(j!=startnode);
		}
}
