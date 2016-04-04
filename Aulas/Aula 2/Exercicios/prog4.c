#include<stdio.h>
#include<stdlib.h>

int main()
{
	//Divisions

	int operations = 0;
	float dividend, divisor, quotient;
	char repeat = 'S';

	while((repeat == 'S') | (repeat == 's'))
	{
		printf("\nType the dividend: ");
		scanf("%f", &dividend);

		printf("Type the divisor: ");
		scanf("%f", &divisor);

		while(divisor == 0)
		{
			printf("INVALID, type again a valid value: ");
			scanf("%f", &divisor);
		}

		quotient = dividend / divisor;
		operations ++;

		printf("Result of the operation %.2f / %.2f = %.3f\n", dividend, divisor, quotient);
		printf("Do you want to do another operation ? (S/N): ");

		scanf("%s", &repeat);

		if((repeat == 'N') | (repeat == 'n'))
			break;
	}

	printf("Number of operations performed : %d\n", operations);
	return 0;
}