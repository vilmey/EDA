/*
Universidade de Bras�lia - UnB
Faculdade de Engenharias do Gama - FGA
Estruturas de Dados e Algoritmos - EDA
Autoria: Prof. Dr. Nilton Correia da Silva, 2013.
PlotaFigGeometricas: Exemplo de Uso de Structs e Arranjos de Structs
*/
#include <stdlib.h>
#include <stdio.h>
#include "GeoLib.h"
int main()
{
	int opcao=0, pind;
	TTela Tela;
	TVPontos Pontos;
	while (opcao!=10)
	{
//Menu de op��es:
	  system("cls");
		printf("---------------- PLOTAGEM DE FIGURAS GEOMETRICAS --------------------");
		printf("\n");
		printf("\n");
		printf("Coordenadas de Tela: Y:[0..%d] x X:[0..%d]",Tela.QX, Tela.QY);
		printf("\n");
		printf("\n");
		printf("%s%c%c%s","Selecione uma Op", 135, 132, "o:");
		printf("\n");
		printf("\n");
		printf("\n 1 - Incluir Ponto");
		printf("\n 2 - Excluir Ponto");
		printf("\n 3 - Incluir Linha");
		printf("\n 4 - Excluir Linha");
		printf("\n 5 - Incluir Triangulo");
		printf("\n 6 - Excluir Triangulo");
		printf("\n 7 - Incluir Retangulo");
		printf("\n 8 - Excluir Retangulo");
		printf("\n 9 - Exibir Gr�fico");
		printf("\n 10 - Sair");
		printf("\n");
		scanf("%d",&opcao);
		if((opcao>=1)&&(opcao<=10))
		{
	  	switch (opcao)
	  	{
	  		case 1: //Inclus�o de ponto
				  if(Pontos.Qtde==5)
					{
						printf("Quantidade de pontos excedida!!!");
					}
					else
					{
        		printf("\n Entre com a Coordenada X,Y: ");
	  	      scanf("%d%d",&(Pontos.Elementos[Pontos.Qtde].X),&(Pontos.Elementos[Pontos.Qtde].Y));//Falta validar...
            Pontos.Qtde++;
            AtualizaGrafico(&Tela, &Pontos, 'P');	  	
					} 
				  break;
	  		case 2: //Exclus�o de ponto
				  if(Pontos.Qtde==0)
					{
						printf("Nao ha Nenhum ponto!!!");
						getchar();  
					}
					else
					{
						MostraPontos(&Pontos);
        		printf("\n Entre com o Numero do Ponto Que Deseja Excluir: ");
	  	      scanf("%d",&pind);
            if(ExcluirPonto(&Pontos, pind))
            {
//Atualizar Tela ap�s exclus�o do ponto:						  
              AtualizaGrafico(&Tela, &Pontos, 'X');	
						  printf("\n Ponto %d Excluido!!!",pind);
						}
						else
						  printf("\n Falha da Exclusao do Ponto %d !!!",pind);
						getchar();  
					} 
				  break;
	  		case 9: //Atualizar gr�fico na tela:
          VisualizaGrafico(&Tela);
					break;		  
	  	}
		}			
	}
//Desalocar mem�ria antes de sair do sistema:
  Tela.Grid = Desaloca(Tela.QY, Tela.QX, Tela.Grid);
	return 0;		  
}
