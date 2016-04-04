#include<stdlib.h>
#include<stdio.h>

int main()
{
	//Conversao de Fahrenheit to Celcius

	float ftemp, ctemp;
	
	printf("\nInsert a temperature in Fahrenheit:");
	scanf("%f",&ftemp);

	ctemp = (5*(ftemp-32))/9;

	printf("Temperature in Celcius : %.2f\n",ctemp);

	return 0;


}