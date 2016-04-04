#include <stdio.h>
#include <stdlib.h>
#include "exe1.c"


int main()
{
	int tamanho, *pvet;

	printf("\nDigite o tamanho da memoria alocada: ");
	scanf("%d", &tamanho);

	pvet = CriaVetInt(tamanho);

	printf("Endereco = %p\n", pvet);

	free(pvet);

}