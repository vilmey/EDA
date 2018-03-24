#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MatematicaLib.h"

void MostraSerie(float *pserie, int pqtde)
{
    int pind;
//Mostrar Nova Série Gerada:
    //system("clear");
    printf("#######################          SERIE (%d Termos)         ###################################", pqtde);
    printf("\n\n");
    for(pind=0; pind<pqtde; pind++)
        printf("%do. Termo: \t%.6f\n", pind+1, pserie[pind]);
    printf("\n\n##########################################################################################\n");
    //system("pause");
}

char MontaTela(int *popers, int pqtde, float *pserie, int pqtde2)
{
    int popmenu;
    int pind;
//Gerar série inicial:
    GeraSerieAleatoria(pserie, pqtde2);
//Desmarcar todas estatisticas:
    for(pind=0; pind<pqtde; pind++)
        popers[pind] = -1;
    //system("clear");
    printf("####################### ESTATISTICAS DE SERIES ###################################");
    printf("\n\n\n");
    printf("#######################          MENU          ###################################");
    printf("\n\n\n");
    printf("\n(1) - [G] - Gerar nova Serie");
    printf("\n(2) - [T] - Todas Estatisticas");
    printf("\n(3) - [S] - Soma");
    printf("\n(4) - [M] - Media");
    printf("\n(5) - [D] - Desvio Padrao");
    printf("\n(6) - [P] - Soma de Potencias");
    printf("\n(7) - [Q] - Soma dos Quadrados");
    printf("\n(8) - [Qualquer Outra Tecla] - Encerrar");
    printf("\nDigite a Opcao Desejada: ");
    
    //popmenu = getchar();
    scanf("%d",&popmenu);
    printf("\nRecebido |%d|\n", popmenu);
    printf("Fim !\n");

    switch (popmenu)
    {
    case 1:
        GeraSerieAleatoria(pserie, pqtde2);
        MostraSerie(pserie, pqtde2);
        break;
    case 2:
//Marcar todas estatisticas:
        for(pind=0; pind<pqtde; pind++)
            popers[pind] = pind;
        break;
    case 3:
        popers[0] = 0;
        break;
    case 4:
        popers[0] = 1;
        break;
    case 5:
        popers[0] = 2;
        break;
    case 6:
        popers[0] = 3;
        break;
    case 7:
        popers[0] = 4;
        break;
    default:
        system("clear");
        printf("####################### ESTATISTICAS DE SERIES ###################################");
        printf("\n\n\n");
        printf("Programa Encerrado...\n\n\n");
        popmenu = 8; //Encerrar
        break;
    }
    return (popmenu);
}

void CalculaEMostra(float (*pOperacoes[])(float *, int), char *pNomes[], int *pSelecionados, int pqtde, float *pserie, int pqtde2)
{
    int pp, pindoper, ptemcalculo = 0;
    float pvalor;

//Verificar se há pelo menos um valor a ser impresso:
    for(pp=0; pp<pqtde; pp++)
    {
        pindoper = pSelecionados[pp];
        if(pindoper>=0)
        {
            ptemcalculo = 1;
            break;
        }
    }
    if(ptemcalculo)
    {
//Cálculo e visualização de Estatísticas Selecionadas:
        //system("clear");
        printf("\n\n####################### ESTATISTICAS ###################################");
        for(pp=0; pp<pqtde; pp++)
        {
            pindoper = pSelecionados[pp];
            if(pindoper>=0)
            {
                pvalor = pOperacoes[pindoper](pserie, pqtde2);
                printf("\n\n%s: \t%.6f\n", pNomes[pindoper], pvalor);
            }
        }
        printf("\n\n########################################################################\n");
        //system("pause");
    }
}

int main()
{
    int Selecao[5], menu; 
    float Serie[20], (*Operacoes[])(float *pnumeros, int pqtde)={Soma, Media, DesvioPadrao, SomaPotencias, SomaQuadrados};
    char *Nomes[]={"Soma", "Media", "DesvioPadrao", "SomaPotencias", "SomaQuadrados"};



    do
    {
        menu = MontaTela(Selecao, 5, Serie, 20);
        CalculaEMostra(Operacoes, Nomes, Selecao, 5, Serie, 20);
    }
    while(menu != 8);

    return 0;
}
