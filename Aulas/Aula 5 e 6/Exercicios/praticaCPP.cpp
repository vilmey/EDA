#include <stdio.h>
#include <stdlib.h>


void ordena (int &a, int &b, int &c);
int main ()
{
	int N1=3, N2=5, N3=1;

	printf("Antes %d %d %d\n", N1, N2, N3);
	ordena(N1, N2, N3);
	printf("Depois %d %d %d\n", N1, N2, N3);

	return 0;
}

void ordena (int &a, int &b, int &c)
{
	int t,i;

	for(i=0; i<2; i++)
	{
		if(a > b)
		{
			t = b;
			b = a;
			a = t;
		}

		if(b > c)
		{
			t = c;
			c = b;
			b = t;	
		}
	}
}