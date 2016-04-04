#include <stdio.h>
#include <stdlib.h>


int main ()
{
	int x, y, *p;

	y=0;		//Y recebe 0
	p = &y;		//p aponta para o endereco de y
	x = *p;		//x recebe o valor armazenado no endereco do ponteiro
	x = 4;		//x recebe 4
	(*p)++;		//a variavel no endereco de p recebe +1
	x--;		// x-1
	(*p) += x;	//y = y + x

	printf("y = %d, x = %d\n", y, x);

	return 0;
}