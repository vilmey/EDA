#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int N1, N2, i;
	int opcao;

	printf("\nDigite o primeiro numero: ");
	scanf("%d", &N1);

	printf("Digite o segundo numero: ");
	scanf("%d", &N2);

	printf("Digite a operacao (soma(1), subtracao(2), divisao(3) ou resto(4)): ");
	scanf("%d", &opcao);

	switch (opcao)
	{
		case 1:
			printf("soma\n");
			break;

		case 2:
			printf("subtracao\n");
			break;

		case 3:
			printf("divisao\n");
			break;

		case 4:
			printf("resto\n");
			break;

		default:
			printf("Opcao invalida\n");
			break;
	}


	return 0;

}