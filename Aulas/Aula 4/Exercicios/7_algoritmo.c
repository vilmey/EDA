#include <stdio.h>
#include <stdlib.h>

float CalculaSerie (int *lista, int n);
void NumeradorMenor (int *lista, int n);

int main()
{
	int n, i, *lista;
	float valor;

	printf("\nDigite o numero de variaveis (n):");
	scanf("%d", &n);

	lista = (int *)malloc(n * sizeof(int));

	for(i = 0; i < n; i++)
	{
		printf("\nDigite o caracter %d: ", i+1);
		scanf("%d", &lista[i]);
	}

	valor = CalculaSerie(lista,n);

	printf("\nO valor da serie e: %f\n",valor);
	NumeradorMenor(lista,n);

	free(lista);
}

float CalculaSerie (int *lista, int n)
{
	int i;
	float valor=0.00;

	for(i = 0; i < n; i++)
	{
		valor += ((float)i/(float)lista[i]);
		printf("i = %d, num %d, valor %f\n", i, lista[i], valor);
	}

	return valor;
}

void NumeradorMenor (int *lista, int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
		if(i < lista[i])
		{
			printf("Numerador %d inferior ao denominador %d\n", i, lista[i]);
		}
	}
}