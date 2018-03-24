#include <stdio.h>
#include <stdlib.h>

int Exponencial(int base, int expoente)
{
	if(expoente == 0)
	{
		return 1;
	}

	else
	{
		expoente --;
		return base*Exponencial(base, expoente);
	}
}


int main()
{
	int base, expoente, resultado;

	while(1)
	{	
		printf("Digite a base: ");
		scanf("%d", &base);
	
		printf("Digite o expoente: ");
		scanf("%d", &expoente);
	
		resultado = Exponencial(base, expoente);
		printf("Resultado : %d\n", resultado);
	}

	return 0;
}