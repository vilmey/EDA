#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Inverte_string(char * str1, char * swap, int posicao, int tamanho)
{
	

	if((str1[posicao]== '\0'))
	{
		swap[tamanho+1]= '\0';
		strcpy(str1, swap);
		return 1;
	}

	else
	{
		swap[tamanho-posicao] = str1[posicao];
		posicao++;
		return(Inverte_string(str1, swap, posicao, tamanho));
	}
}


int main ()
{
	int i;
	char str1[] = {"Essa e a string a qual vamos inverter !!!"};
	char swap[strlen(str1)];

	printf("\nEntrada: %s\n", str1);
	Inverte_string(str1, swap, 0, (strlen(str1)-1));
	printf("\nSaida: %s\n", str1);

	return 0;
}
