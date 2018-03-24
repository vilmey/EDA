#include <stdio.h>
#include <stdlib.h>


float Soma_fracao(float n)
{
	if(n == 0)
		return 0;

	else
	{
		
		return( ((n*n + 1)/(n+3)) + Soma_fracao(n-1) );
	}
}

int main ()
{
	float numero = 0;

	printf("Digite um mumero para calcular o valor de uma soma recursiva: ");
	scanf("%f", &numero);

	printf("O valor da soma recursiva é: %f\n", Soma_fracao(numero));

	return 0;
}