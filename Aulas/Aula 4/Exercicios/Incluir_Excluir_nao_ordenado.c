#include <stdio.h>
#include <stdlib.h>


//Incluir elemento em vetores nao ordenados
int IncluirNaoOrdenado (char *pvetcar, int tamanho, int ocupacao, char valor)
{
	if(ocupacao <= tamanho)
		pvetcar[ocupacao] = valor;

	else
		printf("Memoria cheia\n");

	ocupacao +=1;
	return	ocupacao;
}

//Excluir elemento em vetores nao ordenados
int ExcluirNaoOrdenado (char *pvetcar, int tamanho, int ocupacao, char valor)
{
	int i, flag = 0;
	char copia[tamanho];

	for(i=0; i<tamanho; i++)
	{
		if (pvetcar[i] != valor)
			copia[i] = pvetcar[i];

		else
		{
			flag = 1;
			ocupacao--;
		}
	}

	if(flag == 0)
		printf("Valor nao encontrado\n");

	for (i = 0; i < tamanho; i++)
	{
		pvetcar[i] = copia[i];
	}

	return ocupacao;
}
