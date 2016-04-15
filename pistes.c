#include <stdio.h>

int main(int argc, char **argv)
{
	char S[47][50];
	FILE *fichier = fopen("Sommets.txt","r");
	int i;
	
	for (i = 0; i < 47; i ++)
	{
		fscanf(fichier, "%s", S[i]);
	}
	
	printf("%s\n",S[0]);
	fclose(fichier);
	return 0;
}

