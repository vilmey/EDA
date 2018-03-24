#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inclue(char *nome[])
{
	nome[7] = "4Ever";
}

int main()
{
	int i, tam;
	char *nome[100] = {"vilmey", "francisco", "romano", "Min", "Hu"};

	nome[5] = "Nomes";
	nome[6] = "Lovers";
	//strcpy(nome[5], "Nomes");
	//strcpy(nome[6], "Lovers");
	inclue(nome);

	//tam = strlen(nome[30]);
	//printf("%d\n", tam);

	for(i=0; i<8; i++)
	{
		printf("%s\n", nome[i]);
	}


	if((strcmp(nome[0], "vilmey")) ==0)
		printf("Igual !!\n");

	return 0;

}

