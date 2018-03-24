#include <stdio.h>
#include <stdlib.h>

//--------------------------------------------------------------------------------------------
/*Função que implementa a recursividade*/

int Dividir_para_conquistar(int x, int *f)
{	
	/*Condição de parada*/
	if(x == 0)
	{
		f[0] = 1;
		return 1;
	}

	else
	{
		f[x] = 3*x*f[x/10];						//Calculo do valor da posição
		printf("%d\n", f[x]);					
		x --;									//Decrementa a atual do array
		return Dividir_para_conquistar(x, f);	//Chama a função novamente para a posição x-1
	}
}

//--------------------------------------------------------------------------------------------

int main()
{
	/*Declaração de um vetor int nao ordenado*/ 
	int f[20] = {1, 10, 3, 6, 8, 7, 9, 4, 3, 5, 1, 0, 3, 6, 8, 7, 9, 4, 3, 5};


	/*Chamada da função*/
	Dividir_para_conquistar(15, f);

	/*Imprime novo array*/	
	for (int i = 0; i < 20; i++)
	{
		printf("%d ",f[i]);
	}
	
	printf("\n");

	return 0;
}