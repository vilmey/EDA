#include <stdio.h>
#include <stdlib.h>


int X(int n, int m)
{
	
	if((n == m)||(n==0))
	{
		return 1;
	}

	else
	{
		return (X(n-1,m)+X(n-1,m+1));
	}
}


int main ()
{
	int n, m;
	
	while(1)
	{
		printf("\nDigite o valor inteiro ou (-1): ");
		scanf("%d", &n);
		scanf("%d", &m);

		if((n == -1) || (m == -1))
		{
			printf("Exit !\n");
			break;
		}

		printf("Resultado: %d\n", X(n, m));
	}
	return 0;
}