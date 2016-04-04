#include <stdio.h>
#include <stdlib.h>




int main()
{
	float vet[5] = {1.1,2.2,3.3,4.4,5.5};
	float *f;
	int i;
	f = vet;	// Todo array e um ponteiro, ponteiro recebe ponteiro
				// vet[i] == um float, vet == ponteiro para um float
				//vet aponta para o primeiro elemento to array
	printf("contador/valor/valor/endereco/endereco");
	
	for(i = 0 ; i < 5 ; i++)
	{
		printf("\ni = %d",i);
		printf(" vet[%d] = %.1f",i, vet[i]);
		printf(" *(f + %d) = %.1f",i, *(f+i));
		printf(" &vet[%d] = %X",i, &vet[i]);
		printf(" vet = %X", vet);
		printf(" (f + %d) = %X",i, f+i);
	}
}