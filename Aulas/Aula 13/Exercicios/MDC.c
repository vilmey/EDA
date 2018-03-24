#include <stdio.h>
#include <stdlib.h>


int MDC(int p, int q)
{
	if(q == 0)
		return p;

	else
		return(MDC(q,p%q));
}



int main ()
{
	int num1, num2;

	printf("\nDigite o primeiro numero do MDC: ");
	scanf("%d", &num1);

	printf("Digite o segundo numero do MDC: ");
	scanf("%d", &num2);

	printf("Máximo Divisor Comun: %d\n\n", MDC(num1, num2));
}