#include <stdio.h>
#include <stdlib.h>

int * CriaVetInt(int quantidade)
{
	int *vet;

	vet = (int *)malloc(quantidade * sizeof(int));

	return vet;
}

int * CriaVetFloat(int quantidade)
{
	float *vet;

	vet = (float *)malloc(quantidade * sizeof(float));

	return vet;
}