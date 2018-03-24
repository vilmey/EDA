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

//-----------------------------------------------
//TIPO DE ELEMENTOS DA ARVORE
typedef struct TNo_Municipio
{
	char 	Municipio[2];
	struct 	TNo_Municipio *Esquerda;
	struct 	TNo_Municipio *Direita;
}TNo_Municipio;


int menu();
void trata_menu(int opcao, char *arquivo, int *tipo_relatorio, char *relatorio_estado, char *pesquisa_municipio);



int main ()
{
	FILE * fd; 		//Descritor do arquivo
	char UF[2], relatorio_estado[2], municipio[100], arquivo[30]={"CFO_UF_municipios_brasil.csv"}, pesquisa_municipio[100];
	int tipo_relatorio = NULL, ret;
	int CDs = 0, EPAOs = 0, TPDs = 0, LBs = 0, TSBs = 0, ASBs = 0, APDs = 0, EPOs = 0, Total = 0;
	
	trata_menu(menu(), arquivo, &tipo_relatorio, relatorio_estado, pesquisa_municipio);

	fd = fopen(arquivo, "r");	//Abrindo o arquivo com informacoes de cliente

	while(1)
	{
		//Le a informacao formatada (PALAVRA) (PALAVRA) ...
		ret = fscanf(fd, "%[^;];%[^;];%d;%d;%d;%d;%d;%d;%d;%d;%d\n", UF, municipio, &CDs, &EPAOs, &TPDs, &LBs, &TSBs, &ASBs, &APDs, &EPOs, &Total);
		
		//Caso haja erro, sair do loop
		if(errno != 0)
		{
			perror("scanf:");
			break;
		}

		//Fim do arquivo, sair do loop
		else if(ret == EOF)
			break;

		//printf("[%d] UF: %s - Municipio: %s CDs %d, EPAOs %d, TPDs %d, LBs %d, TSBs %d, ASBs %d, APDs %d, EPOs %d, Total %d.\n", UF, municipio, CDs, EPAOs, TPDs, LBs, TSBs, ASBs, APDs, EPOs, Total);
		printf("[%d] Municipio: %s.\n", ret, municipio);		
	}

	close(fd);
}


//-----------------------------------------------
//VERIFICA SE A RAIZ ESTA VAZIA

bool Vazia(TNo_Municipio *p)
{
	if(p == NULL)
		return true;
	
	else
		return false;
}

//-

TNo_Municipio *cria_arvore(char *municipio)
{
	TNo_Municipio *p;

	p = cria_no (); 
  	
  	if (p) 
  	{ 
    	p->Municipio = municipio; 
    	return p; 
  	} 
  	
  	else 
  	{ 
    	puts("Faltou espaco para alocar no."); 
    	exit(1); 
  	} 
}

TNo_Municipio *cria_no()
{
	TNo_Municipio *p;

	if ((p = (tNo *) malloc(sizeof(tNo))) == NULL) 
    	return NULL; 
  
  	else
  	{ 
    	p->Esquerda = NULL; p->Direita = NULL; 
    	return p; 
	} 

}

TNo_Municipio p_esquerda(TNo_Municipio *p, char *municipio)
{
	TNo_Municipio aux;

	if(p->Esquerda)
		printf("Operacao legal\n");

	else
	{
		aux = cria_arvore(municipio);
		p->Esquerda = aux;
	}
}

TNo_Municipio p_direita(TNo_Municipio *p, char *municipio)
{
	TNo_Municipio aux;

	if(p->Direita)
		printf("Operacao legal\n");

	else
	{
		aux = cria_arvore(municipio);
		p->Direita = aux;
	}		
}



int menu()
{
	int opcao = 0;
	printf("[1] - Importar dados \n");
	printf("[2] - Relatórios\n");
	printf("[3] - Relatório de um estado\n");
	printf("[4] - Consultar municipio\n");
	printf("[5] - Sair\n");

	scanf("%d", &opcao);

	return opcao;
}

void trata_menu(int opcao, char *arquivo, int *tipo_relatorio, char *relatorio_estado, char *pesquisa_municipio)
{
	switch(opcao){
		
		case 1:
			printf("Digite o nome do arquivo :");
			scanf("%s", arquivo);
			break;

		case 2:
			printf("[1] - Municipio\n");
			printf("[2] - CD\n");
			printf("[3] - Total\n");
			scanf("%d", tipo_relatorio);
			break;

		case 3:
			printf("Digite a UF: ");
			scanf("%s", relatorio_estado);

		case 4:
			printf("Digite o municipio:");
			scanf("%s", pesquisa_municipio);
			break;

		case 5:
			printf("Limpando memoria ...\n");
			printf("Free da memoria ...\n");
			exit (0);
			break;
	}
}