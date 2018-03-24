/*
Universidade de Brasília - UnB
Faculdade de Engenharias do Gama - FGA
Estruturas de Dados e Algoritmos - EDA
Autoria: Prof. Dr. Nilton Correia da Silva, 2013.
GeoLib: Biblioteca para Uso de Structs e Arranjos de Structs
*/

#include <stdio.h>
#include <stdlib.h>
#include <string>
//#include <conio.h> //getch()


//Funções auxiliares para alocação dinâmica:

char **Aloca(int m, int n)
{
  char **v;  /* ponteiro para a matriz */
  int   i;    /* variavel auxiliar      */
  if (m < 1 || n < 1) /* verifica parametros recebidos */
  {
    printf ("** Erro: Parametro invalido **\n");
    return (NULL);
  }
  /* aloca as linhas da matriz */
  v = (char **) malloc (m*sizeof(char *));
  if (v == NULL) 
	{
    printf ("** Erro: Memoria Insuficiente **");
    return (NULL);
  }
  /* aloca as colunas da matriz */
  for ( i = 0; i < m; i++ ) 
	{
      v[i] = (char*) malloc (n*sizeof(char));
      if (v[i] == NULL) 
			{
        printf ("** Erro: Memoria Insuficiente **");
        return (NULL);
      }
  }
  return (v); /* retorna o ponteiro para a matriz */
}

char **Desaloca(int m, int n, char **v)
{
  int  i;  /* variavel auxiliar */
  if (v == NULL) 
	  return (NULL);
  if (m < 1 || n < 1)  /* verifica parametros recebidos */
  {
    printf ("** Erro: Parametro invalido **\n");
    return (v);
  }
  for (i=0; i<m; i++) 
	  free (v[i]); /* libera as linhas da matriz */
  free (v);      /* libera a matriz */
  return (NULL); /* retorna um ponteiro nulo */
}

//Tipo de dado (Struct) para representar o gráfico de plotagem

struct TTela
{
  int QX, QY;  //QX: unidades do eixo X (colunas), QY: unidades do eixo Y (linhas).
	char **Grid;
	TTela(int pQX = 60, int pQY = 30)
	{
		QX = pQX;
		QY = pQY;
		Grid = Aloca(QY, QX);
		for(int py=0;py<QY;py++)
  		for(int px=0;px<QX;px++)
  		  Grid[py][px] = '.';
	}	
};


//Tipos de dados (Structs) de formas geométricas:
	
struct TPonto
{
  int X, Y;  //Coordenada
	TPonto(int pX = 0, int pY = 0)
	{
		X = pX;
		Y = pY;
	}	
};

struct TVPontos
{
	TPonto Elementos[5];
	int Qtde;
	TVPontos()
	{
		Qtde = 0;
	}
};

//Funções de Desenho de formas geométricas:

void PlotaPonto(TTela *pTela, TPonto *ptr, char psimbolo)
{
	pTela->Grid[ptr->Y][ptr->X] = psimbolo;
}

//Lista pontos na tela do computador:
void MostraPontos(TVPontos *ppontos)
{
  int pind;	
  system("cls"); //Limpa a tela
  printf("Ponto: (X, Y)\n");
  for(pind=0;pind<ppontos->Qtde;pind++)
  {
 	  printf("%d: (%d, %d)",pind, ppontos->Elementos[pind].X,ppontos->Elementos[pind].Y);
  	printf("\n");
  }
}

//Lista pontos na tela do computador:
bool ExcluirPonto(TVPontos *ppontos, int pi)
{
  int pind;	
  if(pi>=ppontos->Qtde)
    return false;
  for(pind=pi; pind<ppontos->Qtde-1; pind++)
  {
  	ppontos->Elementos[pind] = ppontos->Elementos[pind+1];
  }
  ppontos->Qtde--;
  return true;
}


//Plotar o gráfico (pTela) na tela do computador:
void VisualizaGrafico(TTela *pTela)
{
  int px, py;	
  system("cls"); //Limpa a tela
  for(py=0;py<pTela->QY;py++)
  {
    printf("%d\t",py);
  	for(px=0;px<pTela->QX;px++)
  	  printf("%c",pTela->Grid[py][px]);
  	printf("\n");
  }
	getchar();
}

void AtualizaGrafico(TTela *pTela, TVPontos *ppontos, char psimbolo)
{
	int px, py, pind;
//Resetar Tela (Retirar todas geometrias atualmente desenhadas):
  for(py=0;py<pTela->QY;py++)
  	for(px=0;px<pTela->QX;px++)
  	  pTela->Grid[py][px] = '.';
	
//Plotar todos os pontos contidos em ppontos:
  for(pind=0;pind<ppontos->Qtde;pind++)
	  PlotaPonto(pTela, &(ppontos->Elementos[pind]), psimbolo); 
	  
}

