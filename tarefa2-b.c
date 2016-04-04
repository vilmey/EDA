#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr, i;

	ptr = (int *)malloc(4 * sizeof(int));

	for(i=0; i<4; i++)
	{

		printf("Digite o faturamento: ");
		scanf("%d", (ptr+i));
	}
	
	printf("O faturamento e:\n");


	for(i=0; i<4; i++)
	{
		printf("%d - Faturamento %d\n",i, (*ptr+i));
	}

	free(ptr);

	return 0;

}

/*
#include<stdio.h>
#include<stdlib.h>

int main(){

	int *ptr, vfat[4];

	ptr = (int *)malloc(4 * sizeof(int)); 	//Ponteiro aponta para uma estrutura de memoria 
									//com 4 elementos, o mesmo que (ptr = vfat;)

	int i;
	
	for(i = 0; i < 4; i++)
		scanf("%d",(ptr)++);	//Guarda os valores na memoria alocada

	for(i = 0; i < 4; i++)
		printf("valor = %d, endereco = %p\n" ,(*ptr)--, ptr--); //Printa informacao

	//(*ptr)-- 	Usa o ptr atual depois decrementa
	//*ptr-- 	Usa o valor de ptr decrementado
	//*(ptr--)	Usa o valor de ptr, depois decrementa duas vezes


	free(ptr); 	//Libera a memoria alocada na memoria
	return 0;
}
*/