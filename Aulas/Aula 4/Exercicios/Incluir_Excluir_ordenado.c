#include <stdio.h>
#include <stdlib.h>

//Incluir elemento em vetores ordenados
char *IncluirOrdenado (int *pvetcar, int tamanho, int ocupacao, int valor)
{
	int i, flag = 0;
	char copia[tamanho], retorno[20]="Falso";

	if(ocupacao <= tamanho)
	{
		for (i = 0; i < tamanho; i++)
		{
			if((pvetcar[i] => valor) & (flag == 0))
			{
				copia[i] = valor;
				copia[i+1] = pvetcar[i];
				flag = 1;
			}

			if((pvetcar[i-1] > pvetcar[i]) & (flag == 0))
			{
				copia[i] = valor;
				flag = 1;
			}

			else
			{
				copia[i] = pvetcar[i];
			} 
		}

		for (i = 0; i < tamanho; i++)
		{
			pvetcar[i] = copia[i];
		}

		ocupacao +=1;
		strcpy(retorno, "Verdadeiro");
	}

	else
		printf("Memoria cheia\n");

	return retorno;
}

//Excluir elemento em vetores ordenados
char *ExcluirOrdenado (int *pvetcar, int tamanho, int ocupacao, int valor)
{
	int i, flag = 0;
	char copia[tamanho], retorno[20]="Falso";

	for(i=0; i<tamanho; i++)
	{
		if (pvetcar[i] != valor)
			copia[i] = pvetcar[i];

		else
		{
			flag = 1;
			ocupacao--;
			strcpy(retorno,"Verdadeiro");
		}
	}

	if(flag == 0)
		printf("Valor nao encontrado\n");

	for (i = 0; i < tamanho; i++)
	{
		pvetcar[i] = copia[i];
	}

	return retorno;
}
