#include <stdio.h>
#include <stdlib.h>


int soma(int a, int b);
int subtracao(int a, int b);
int multiplicacao(int a, int b);
int divisao(int a, int b);
int resto(int a, int b);
void procedimento(int a, int b, int(*pfuncao)(int N1, int N2));

int main ()
{
	int N1, N2, i;
	int opcao;

	printf("\nDigite o primeiro numero: ");
	scanf("%d", &N1);

	printf("Digite o segundo numero: ");
	scanf("%d", &N2);

	printf("Digite a operacao (soma(1), subtracao(2), multiplicacao(3), divisao(4) ou resto(5)): ");
	scanf("%d", &opcao);

	switch (opcao)
	{
		case 1:
			printf("soma\n");
			procedimento(N1, N2, soma);
			break;

		case 2:
			printf("subtracao\n");
			procedimento(N1, N2, subtracao);
			break;

		case 3:
			printf("multiplicacao\n");
			procedimento(N1, N2, multiplicacao);
			break;

		case 4:
			printf("divisao\n");
			procedimento(N1, N2, divisao);
			break;

		case 5:
			printf("resto\n");
			procedimento(N1, N2, resto);
			break;

		default:
			printf("Opcao invalida\n");
			break;
	}


	return 0;

}

int soma(int a, int b)
{
	int resultado;

	resultado = a + b;

	return resultado;
}

int subtracao(int a, int b)
{
	int resultado;

	resultado = a - b;
	return resultado;
}

int multiplicacao(int a, int b)
{
	int resultado;

	resultado = a * b;
	return resultado;
}

int divisao(int a, int b)
{
	int resultado;

	resultado = a / b;
	return resultado;
}

int resto(int a, int b)
{
	int resultado;

	resultado = a%b;
	return resultado;
}

//Funcao recebe dois inteiros e a funcao que deve ser implementada
void procedimento(int a, int b, int(*pfuncao)(int N1, int N2))
{
	//pfuncao representa a funcao passada como parametro (soma, sub ...)
	printf("O resultado : %d\n", pfuncao(a,b));
}