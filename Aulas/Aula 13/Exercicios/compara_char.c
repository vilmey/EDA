#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Compara_string(char * str1, char find, int i)
{

	if((str1[i]== '\0'))
	{
		return -1;
	}

	else
	{
		if(str1[i] == find)
			return i;
		
		else
		{
			i++;
			return(Compara_string(str1,find, i));
		}
	}
}


int main ()
{
	char str1[] = {"Essa e a string"}, find = 't';


	printf("Resultado: %d\n", Compara_string(str1, find, 0));


	return 0;
}