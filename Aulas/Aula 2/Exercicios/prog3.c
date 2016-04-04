#include<stdio.h>
#include<stdlib.h>

int main()
{
	//Sum and print the numbers between two integers

	int i, num1, num2, bigger, smaller, sum = 0;

	printf("Type the first number: ");
	scanf("%d", &num1);

	printf("Type the second number: ");
	scanf("%d", &num2);

	if(num1 > num2)
	{
		bigger = num1;
		smaller = num2;
	}

	else
	{
		bigger = num2;
		smaller = num1;
	}

	for(i=smaller; i<=bigger; i++)
	{
		printf("%d,", i);
		sum += i;
	}

	printf("and the sum is: %d\n", sum);

	return 0;
}