#include <stdio.h>
#include <stdlib.h>

//Vetores nao ordenados
int incluir (char *pvetcar, int tamanho, int ocupacao, char valor)
{

	if(ocupacao <= tamanho)
	{
		pvetcar[ocupacao] = valor;
	}

	else
		printf("Memoria cheia\n");

	ocupacao +=1;
	return ocupacao;
}

int excluir (char *pvetcar, int tamanho, int ocupacao, char valor)
{
	int i;
	char copia[tamanho];

	for(i=0; i<tamanho; i++)
	{
		if(pvetcar[i] == valor)

		else
			copia[i] = pvetcar[i];

	}

	ocupacao --;
	return ocupacao;
}


//Vetores ordenados
int incluir_ordenado (int *pvalores, int pcapacidade, int ptamanho, int pv)
{
	int i;

	for(i=0; i<ptamanho; i++)
	{}


}







int main ()
{
	char *pvetcar;
	int tam = 0, ptammax, pqtd=0, i;

	scanf("%d", &ptammax);

	pvetcar = (char *) malloc(ptammax * sizeof(char));

	tam = incluir(pvetcar, ptammax, tam, 'a');
	tam = incluir(pvetcar, ptammax, tam, 'b');
	tam = incluir(pvetcar, ptammax, tam, 'c');


	printf("Tamanho %d\n", tam);

	for(i=0; i<tam; i++)
		printf("Data : %c\n", pvetcar[i]);

	return 0;

}