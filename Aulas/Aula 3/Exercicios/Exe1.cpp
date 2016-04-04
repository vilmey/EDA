#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int i[3], *p;

	p = i;

	printf("Digite o valor de i:");
	scanf("%d", &i[0]);
	scanf("%d", &i[1]);
	scanf("%d", &i[2]);

	for(int j = 0; j<3; j++)
	{
		// p representa um pontero para inteiro.
		printf("O valor de p   %p = %d, i = %d\n", p, *p, i[j]);

		// p++ utiliza o valor atual do ponteiro, depois acrescenta 1 ao ENDERECO.
		printf("O valor de p++ %p , i = %d\n", p++, i[j]);
		printf("O valor de p   %p %d, i = %d\n\n", p, *p, i[j]);

		// (*p)++ printa o inteiro apontado pelo ponteiro, depois adiciona 1 ao INTEIRO apontado pelo ponteiro.
		printf("O valor de (*p)++ %d, i = %d\n", (*p)++, i[j]);
		printf("O valor de p   %p = %d, i = %d\n", p, *p, i[j]);

		// *(p++) printa o inteiro apontado pelo ponteiro, depois acrescenta 1 ao ENDERECO.
		printf("O valor de *(p++) %d, i = %d\n", *(p++), i[j]);
		printf("O valor de p   %p = %d, i = %d\n\n\n", p, *p, i[j]);
	}

	return 0;
}