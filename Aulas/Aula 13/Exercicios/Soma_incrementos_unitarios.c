#include <stdio.h>
#include <stdlib.h>

int Soma_incrementos_unitarios (int numero_1, int numero_2)
{
	if(numero_2 == 0)
		return numero_1;

	else
	{
		return Soma_incrementos_unitarios(numero_1+1, numero_2-1);
	}
}


int main ()
{
	int numero_1, numero_2;

	printf("Digite o primeiro numero :");
	scanf("%d", &numero_1);

	printf("Digite o segundo numero :");
	scanf("%d", &numero_2);

	printf("Resultado da soma : %d\n", Soma_incrementos_unitarios(numero_1, numero_2));
}