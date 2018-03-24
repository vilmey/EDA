#include <stdio.h>
#include <stdlib.h>


int Soma(int n)
{
	
	if(n==0)
	{
		return 0;
	}

	else
	{
		return (n + Soma(n-1));
	}
}


int main ()
{
	int num;
	
	while(1)
	{
		printf("\nDigite o valor inteiro ou (-1): ");
		scanf("%d", &num);

		if(num == -1)
		{
			printf("Exit !\n");
			break;
		}

		printf("Resultado: %d\n", Soma(num));
	}
	return 0;
}