#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 10, x = 0;

	//scanf("%d", &n);

	for (int i = 1; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			for (int k = 1; k < j-i; k++)
			{
				x++;
				printf("i %d, j %d, k %d\n", i, j, k);
			}
		}
	}

	printf("X %d\n", x);
}