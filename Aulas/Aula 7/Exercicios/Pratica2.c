#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct TContatos {
	char Nome[50];
	int Idade;
	float Altura;

	//Contructor
	//TContatos(char N, int I, float A)
	//{Nome = N; Idade = I; Altura = A;}
};

void Incluir(struct TContatos *Contato);
void Listar(struct TContatos Contato, int posicao);

int main() 
{
	char opcao;
	struct TContatos Contato[3];

	//printf("Digite a opcao desejada: Incluir(I), Excluir(E), Alterar(A), Listar(L)");

	scanf("%c", &opcao);

	switch (opcao)
	{
		case 'I':
			Incluir(Contato);
			break;

		// case 'E':
		// 	//Excluir();
		// 	break;

		// case 'A':
		// 	//Alterar();
		// 	break;

		// case 'L'
		// 	//Listar();
		// 	break;

		default:
			printf("Opcao invalida\n");
			break;
	}

}

void Incluir(struct TContatos *Contato)
{
	int posicao, read,len;

	printf("Digite a posicao: \n");
	scanf("%d", &posicao);

	printf("Digite o nome: \n");
	read = getline(&Contato[posicao].Nome, &len, stdin);
	//scanf("%s", &Contato[posicao].Nome);

	printf("Digite a idade: \n");
	scanf("%d", &Contato[posicao].Idade);

	printf("Digite a altura: \n");
	scanf("%f", &Contato[posicao].Altura);

	Listar(Contato,posicao);
}

void Listar(struct TContatos Contato, int posicao)
{
	printf("Nome: %s\n", Contato[posicao].Nome);
	printf("Idade: %d\n", Contato[posicao].Idade);
	printf("Altura: %f\n", Contato[posicao].Altura);
}