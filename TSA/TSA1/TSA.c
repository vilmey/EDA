#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//Struct para salvar as informacoes da palavra
struct TPalavra
{
	char palavra[30];
	int quantidade;
	float percentual;
};

void IncludePalavra(char string[30], struct TPalavra *palavra);
void AtualizaPalavra(char string[30], struct TPalavra *palavra);
int Existe( char string[30], struct TPalavra *palavra, const int * ocupacao, int * posicao);
void Porcentagem( int ocupacao, struct TPalavra *palavra, int ocorrencias);
void Exportar (int ocupacao, struct TPalavra *palavra, int ocorrencias);
void Sort( struct TPalavra *palavra, int ocupacao);


int main ()
{
	FILE * fd; 		//Descritor do arquivo
	char buffer[30];
	int i=0, ocupacao = 0, posicao = 0, ocorrencias = 0;
	struct TPalavra Palavras[200];		//Criando um array de struct de palavras
	fd = fopen("teste.txt", "r");	//Abrindo o arquivo com informacoes de cliente

	while(1)
	{
		//Le a informacao formatada (PALAVRA) (PALAVRA) ...
		int ret = fscanf(fd, "%s", buffer);

		//Caso haja erro, sair do loop
		if(errno != 0)
		{
			perror("scanf:");
			break;
		}

		//Fim do arquivo, sair do loop
		else if(ret == EOF)
			break;

		//Palavras com mais de 3 caracteres
		if(strlen(buffer) > 3)
		{
			if (Existe(buffer, Palavras, &ocupacao, &posicao) == 0)
			{
				IncludePalavra(buffer, &Palavras[ocupacao]);
				ocupacao ++;
				ocorrencias ++;
			}

			else
			{
				AtualizaPalavra(buffer, &Palavras[posicao]);
				ocorrencias ++;
			}
		}	
	}

	close(fd);
	Sort(Palavras, ocorrencias);
	Porcentagem(ocupacao, Palavras, ocorrencias);
	Exportar(ocupacao, Palavras, ocupacao);
}

void IncludePalavra(char string[30], struct TPalavra *palavra)
{
    strcpy( palavra->palavra, string);
    palavra->quantidade = 1;
    printf("Primeira declaracao: %s\n", palavra->palavra);
}


void AtualizaPalavra(char string[30], struct TPalavra *palavra)
{
	palavra->quantidade += 1;
	printf("Quantidade %d: %s\n", palavra->quantidade, palavra->palavra);
}


int Existe(char string[30], struct TPalavra *palavra, const int * ocupacao, int * posicao)
{
	int i=0;
	printf("Existe %s - %d - %d\n", string, *ocupacao, *posicao);

	for(i=0; i< *ocupacao; i++)
	{
		printf("Posicao %d Palavra %s\n", i, palavra[i].palavra);
		if(strcmp(string, palavra[i].palavra) == 0)
		{
			printf("posicao %d\n", *posicao);
			*posicao = i;
			return 1;
			break;
		}
	}
	
	return 0;
}

void Porcentagem( int ocupacao, struct TPalavra *palavra, int ocorrencias)
{
	int i=0;
	printf("Ocupacao %d\n", ocupacao);

	for(i=0; i< ocupacao; i++)
	{
		palavra[i].percentual =  (100*((float)palavra[i].quantidade))/((float)ocorrencias);
	}
}

void Exportar (int ocupacao, struct TPalavra *palavra, int ocorrencias)
{
	
	int i,j;
	FILE *fd = fopen("bagofwords.csv", "w+");

	for(i=0; i<ocupacao; i++)
	{
			fprintf(fd, "%s; %d; \t %.2f \n", palavra[i].palavra, palavra[i].quantidade,  palavra[i].percentual);	
	}

	close(fd);

}

void Sort( struct TPalavra *palavra, int ocupacao)
{
	int i, j;
	struct TPalavra Temp;

	 for (i = 1; i < ocupacao; i++)
      for (j = 0; j < (ocupacao - i); j++) {
         if ((palavra[j].quantidade) < (palavra[j + 1].quantidade)) {
            Temp = palavra[j];
            palavra[j] = palavra[j + 1];
            palavra[j + 1] = Temp;
         }
      }
}