#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


//Struct para salvar as informacoes do cliente
struct TCliente
{
	int codigo;
	float salario;
	int idade;
};

//Declaracao das Funcoes
void AprovacaoCredito(const struct TCliente *cliente, int *analisados, int tamanho);
void Reprovados(const struct TCliente *cliente, int *analisados, int tamanho);
void Aprovados(const struct TCliente *cliente, int *analisados, int tamanho);

int main ()
{

	FILE * fd; 		//Descritor do arrquivo de clientes
	char ch;
	int i=0, tamanho = 0, analisados[30];
	struct TCliente Cliente[30];		//Criando um array de clientes
	fd = fopen("clientes.csv", "r");	//Abrindo o arquivo com informacoes de cliente

	while(1)
	{
		//Le a informacao formatada (CODIGO) (SALARIO) (IDADE)
		int ret = fscanf(fd, "%d;%f;%d", &Cliente[i].codigo, &Cliente[i].salario, &Cliente[i].idade);
		
		//Se nao possuir um dos campos sai do processo
		if(ret != 3)
			break;

		//Caso haja erro, sair do loop
		else if(errno != 0)
		{
			perror("scanf:");
			break;
		}

		//Fim do arquivo, sair do loop
		else if(ret == EOF)
		{
			break;
		}

		//Acrescentamos o indice e tamanho
		i++;
		tamanho++;
			
	}

	printf("# Clientes %d \n", tamanho);

	for(i=0; i<tamanho; i++)
	{
		printf("%d, %.2f, %d\n", Cliente[i].codigo, Cliente[i].salario, Cliente[i].idade);
	}

	//Fecha arquivo
	close(fd);

	//Para as funcoes sao passados o ponteiro da struct,
	//um ponteiro para o array de analizados,
	//e o numero de clientes
	AprovacaoCredito(Cliente, analisados, tamanho);
	Reprovados(Cliente, analisados, tamanho);
	Aprovados(Cliente, analisados, tamanho);

	return 0;
}

void AprovacaoCredito(const struct TCliente *cliente, int *analisados, int tamanho)
{
	int i;

	for(i=0; i<tamanho; i++)
	{
		if((cliente[i].salario >= 2000) | (cliente[i].idade <= 30))
			analisados[i] = 1;

		else
			analisados[i] = 0;
	}
}

void Reprovados(const struct TCliente *cliente, int *analisados, int tamanho)
{
	int i;
	FILE *fd = fopen("negados.csv", "w+");

	for(i=0; i<tamanho; i++)
	{
		if(analisados[i] == 0)
			fprintf(fd, "%d; %f\n", cliente[i].codigo, cliente[i].salario);	
	}

	close(fd);
	
}

void Aprovados(const struct TCliente *cliente, int *analisados, int tamanho)
{
	int i;
	FILE *fd = fopen("aprovados.csv", "w+");

	for(i=0; i<tamanho; i++)
	{
		if(analisados[i] == 1)
			fprintf(fd, "%d; %f; %f\n", cliente[i].codigo, cliente[i].salario, ((30*cliente[i].salario)/100));	
	}

	close(fd);
	
}
