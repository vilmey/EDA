#include <stdio.h>
#include <stdlib.h>

Struct TContatos
{
	char Nome[30];
	int Idade;
	float Altura;

	//Contructor
	TContatos(char N, int I, float A)
	{Nome = N; Idade = I; Altura = A;}
};

int main() 
{
	char opcao;
	TContatos Contato[3];

	printf("Digite a opcao desejada: Incluir(I), 
		Excluir(E), Alterar(A), Listar(L)");

	scanf("%c", &opcao);

	switch (opcao)
	{
		case 'I':
			Incluir(Contato);
			break;

		case 'E':
			//Excluir();
			break;

		case 'A':
			//Alterar();
			break;

		case 'L'
			//Listar();
			break;

		default:
			printf("Opcao invalida\n");
			break;
	}

}

void Incluir(TContatos *Contato)
{
	int posicao;

	printf("Digite a posicao: \n");
	scanf("%d", posicao);

	printf("Digite o nome: \n");
	scanf("%s", Contato[posicao].Nome);

	printf("Digite a idade: \n");
	scanf("%s", Contato[posicao].Idade);

	printf("Digite a altura: \n");
	scanf("%s", Contato[posicao].Altura);

	Listar(Contato,posicao);
}

void Listar(TContatos &Contato, int posicao)
{
	printf("Nome: %s\n", Contato[posicao].Nome);
	printf("Idade: %d\n", Contato[posicao].Idade);
	printf("Altura: %f\n", Contato[posicao].Altura);
}