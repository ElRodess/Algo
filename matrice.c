#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
	char nom[50];
	float temps;
}Pistes;

int main(int argc, char **argv)
{
	FILE *fichier  = fopen("Matrice.txt","r");
	FILE *fichier1  = fopen("Pistes2.txt","r");
	
	char matrice[47][47][50];
	int i,j;
	i = 0;
	
	for (i = 0; i < 47; i ++)
	{
		for (j = 0; j < 47; j ++)
		{
				fscanf(fichier, "%s",(matrice[i][j]));
		}
	}
	fclose(fichier);
	
	Pistes p[99];
	int n;
	for (n = 0; n < 99; n ++)
	{
		fscanf(fichier1,"%s %f", (p[n].nom), &(p[n].temps));
	}
	//~ for (n = 0; n < 99; n ++)
	//~ {
		//~ printf("%s %f \n",p[n].nom, (p[n].temps));
	//~ }
	
	//printf("%s\n",matrice[0][0]);
	
	fclose(fichier1);
	
	FILE *matricefichier = fopen("matrice_cout2","w");
	float cout[47][47];
	int test = 0;
	for (i = 0; i < 47; i++)
	{
		for (j = 0; j < 47; j ++)
		{
			if (strcmp(matrice[i][j],"null") == 0) cout[i][j] = 0;
			else 
			{
				test =0;
				for(n = 0;n < 99; n ++)
				{
					if(strcmp(matrice[i][j],(p[n].nom)) == 0) 
					//if (matrice[i][j] == p[n].nom)
					{
						cout[i][j] = p[n].temps;
						test = 1;
					}
				}
				if (test == 0)cout[i][j] = -1;
			}
		}
	}
	
	for(i= 0; i<47; i++)
	{
		for (j = 0; j < 47; j ++)
		{
			fprintf(matricefichier,"%f ",cout[i][j]);
		}
		fprintf(matricefichier,"\n");
		
	}
	fclose(matricefichier);
	return 0;
}

