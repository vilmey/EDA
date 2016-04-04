#include <stdio.h>
#include <stdlib.h>

char *EIgual(int *pveta, int *pvetb, int ptama, int ptamb)
{
	int i, flag = 0;
	char retorno[20] = "Falso";

	if(ptama == ptamb)
	{
		for(i = 0; i < ptama; i++)
		{
			if(pveta[i] != pvetb[i])
				flag = 0;
		}

		if(flag == 1)
		{
			strcpy(retorno,"Verdadeiro");
		}
	}

	return retorno;
}