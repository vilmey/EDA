#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i=0;
	char string[100], minusculo[100], maiusculo[100], formatado[100], palavras[100];


	printf("\n\nDigite a string a ser convertida: ");
	//getchar();
	fgets(string, 100, stdin);
	string[strcspn(string, "\n")] = ' ';

	printf("Antes: (%s)\n", string);

	while(string[i])
	{
		minusculo[i] = (tolower(string[i]));
		maiusculo[i] = (toupper(string[i]));

		if (i == 0)
		{
			formatado[i] = (toupper(string[i]));
			palavras[i] = (toupper(string[i]));
		}

		else
			formatado[i] = (tolower(string[i]));


		if(string[i] == ' ')
		{
			palavras[i] = string[i];
			palavras[i+1] = (toupper(string[i+1]));
		}

		else if((string[i-1] != ' ') & (i != 0))
			palavras[i] = (tolower(string[i]));

		i++;
	}

	printf("Depois: (%s)\n", minusculo);
	printf("Depois: (%s)\n", maiusculo);
	printf("Depois: (%s)\n", formatado);
	printf("Depois: (%s)\n", palavras);

	return 0;
}