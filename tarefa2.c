#include<stdio.h>
#include<stdlib.h>

int main()
{
	int vfat[4], *ptr, i;

	ptr = vfat;

	for(i=0; i<4; i++)
	{

		printf("Digite o faturamento: ");
		scanf("%d", ptr++);
	}
	
	printf("O faturamento e:\n");


	for(i=3; i>=0; i--)
	{
		printf("%d - Faturamento %d\n",i, vfat[i]);
	}

	return 0;

}

