#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void PrintMenu();

float AreaTriRet();
float AreaTriIso();
float AreaQua();
float AreaTra();
float AreaCir();

void Calcular(int divisor, float (*forma)());

int main()
{
	char menu;

	while(1)
	{

		PrintMenu();
		
		fflush(stdin);
		scanf("%c", &menu);
		//menu = getchar();
		printf("Recebido |%c|\n", menu);
		fflush(stdin);

		switch(menu)
		{
			case 'T':
				printf("Triangulo\n");
				Calcular(2, AreaTriRet);
				break;

			case 'I':
				printf("Isoceles\n");
				Calcular(2, AreaTriIso);
				break;

			case 'Q':
				printf("Quadrado\n");
				Calcular(1, AreaQua);
				break;

			case 'R':
				printf("Trapezio\n");
				Calcular(2, AreaTra);
				break;

			case 'C':
				printf("Circulo\n");
				Calcular(1, AreaCir);
				break;

			default :
				printf("Opcao Invalida !\n");
				break;
		}
	}

}


void PrintMenu()
{
	printf("[T] Area Triangulo Retangulo\n");
	printf("[I] Area Triangulo Isoceles\n");
	printf("[Q] Area Quadrado\n");
	printf("[R] Area Trapezio\n");
	printf("[C] Area Circulo\n");
}


float AreaTriRet()
{
	float base = 0.0, altura = 0.0, resultado = 0.0;

	printf("\nDigite o valor da base: ");
	scanf("%g", &base);

	printf("\nDigite o valor da altura: ");
	scanf("%g", &altura);

	resultado = (base*altura);

	return resultado;
}


float AreaTriIso()
{
	float h, lado, base;

	printf("\nDigite o valor da base: ");
	scanf("%f", &base);

	printf("\nDigite o valor de um dos lados iguais: ");
	scanf("%f", &lado);

	h = sqrt((lado*lado) - (base*base)/4);

	return (base*h);
}


float AreaQua()
{
	float base;

	printf("\nDigite o valor da base: ");
	scanf("%f", &base);

	return (base*base);
}


float AreaTra()
{
	float base, base_2, altura;

	printf("\nDigite o valor da base maior: ");
	scanf("%f", &base);

	printf("\nDigite o valor da base menor: ");
	scanf("%f", &base_2);

	printf("\nDigite o valor da altura: ");
	scanf("%f", &altura);

	return ((base + base_2)* altura);
}


float AreaCir()
{
	float raio;

	printf("\nDigite o valor do raio: ");
	scanf("%f", &raio);

	return(raio*raio*3.141516);
}


void Calcular(int divisor, float (*forma)())
{
	float resultado;

	resultado = ((forma())/divisor);

	printf("A area e: %.2f\n", resultado);
}
