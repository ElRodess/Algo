#include "stdio.h"
//#include "conio.h"
#define infinity 999
 
void dij(int n,int v,int cost[12][12],int dist[])
{
 int i,u,count,w,flag[12],min;
 for(i=0;i<n;i++)
  flag[i]=0,dist[i]=cost[v][i];
 count=2;
 while(count<n)
 {
  min=99;
  for(w=0;w<n;w++)
   if(dist[w]<min && !flag[w])
    min=dist[w],u=w;
  flag[u]=1;
  count++;
  for(w=0;w<n;w++)
   if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
    dist[w]=dist[u]+cost[u][w];
 }
}
 
int main()
{
 int n,v,i,j,dist[12],w;
 //clrscr();
 printf("\n Enter the number of nodes:");
 scanf("%d",&n);
 printf("\n Enter the cost matrix:\n");
 int cost[12][12] = {
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
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  {
   //scanf("%d",&cost[i][j]);
   if(cost[i][j]==0)
    cost[i][j]=infinity;
  }
 printf("\n Enter the source matrix:");
 scanf("%d",&v);
  printf("\n Entrez l'arrivee du graphe:");
 scanf("%d",&w);
 dij(n,v,cost,dist);
 printf("\n Shortest path:\n");
 //for(i=0;i<n;i++)
  //if(i!=v)
   printf("%d->%d,cost=%d\n",v,w,dist[w]);
 //getch();
 
 return 0;
}
