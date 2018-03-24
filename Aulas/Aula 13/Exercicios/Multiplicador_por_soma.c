#include <stdio.h>
#include <stdlib.h>

int Multiplicador_por_soma(int multiplicando, int multiplicador)
{
	if(multiplicador == 0)
		return 0;

	else
	{
		return multiplicando + Multiplicador_por_soma(multiplicando, multiplicador - 1);
	}
}


int main()
{
	int multiplicando, multiplicador;
	
	printf("Digite o multiplicando: ");
	scanf("%d", &multiplicando);

	printf("Digite o multiplicador: ");
	scanf("%d", &multiplicador);

	printf("O produto é: %d\n", Multiplicador_por_soma(multiplicando, multiplicador));

}