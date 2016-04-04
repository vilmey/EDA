#include<stdio.h>
#include<stdlib.h>

int main()
{
	//Write the sum of the two biggest numbers
	
	int num1,num2,num3,sum;

	printf("\nWrite the first number: ");
	scanf("%d", &num1);
	
	printf("Write the second number: ");
	scanf("%d", &num2);
	
	printf("Write the third number: ");
	scanf("%d", &num3);

	if((num1 > num2) & (num1 > num3))
	{
		if(num3 > num2)
			sum = num1 + num3;

		else
			sum = num1 + num2;
	}

	if((num2 > num1) & (num2 > num3))
	{
		if (num1 > num3)
			sum = num2 + num1;

		else
			sum = num2 + num3;
	}

	else
	{
		if (num1 > num2)
			sum = num3 + num1;

		else
			sum = num3 + num2;
	}

	printf("The sum is: %d\n\n", sum);

	return 0;
}