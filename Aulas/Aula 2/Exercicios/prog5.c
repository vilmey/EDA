#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *plist, value, i, list[10];

	plist = list;

	printf("\nType the value to be compared: ");
	scanf("%d", &value);

	for(i=0; i<10; i++)
	{
		printf("Type the #%d of the array: ", i);
		scanf("%d", plist++);

	}

	for(i=0; i<10; i++)
	{
		if(value == list[i])
			printf("Element %d equals to value %d\n", i, value);
	}

	return 0;
}