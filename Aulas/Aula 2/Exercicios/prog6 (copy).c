#include <stdio.h>
#include <stdlib.h>




void menu();
void insert();
void delete();
void compare();
void reordenate();
void print();


int list[5] = {-1,-1,-1,-1,-1}, option;


int main()
{
	

	while(1)
	{
		menu();

		scanf("%d", &option);
		//system(cls);

		switch (option)
		{
			case 1:
				insert();
				break;

			case 2:
				delete();
				break;

			case 3:
				compare();
				break;

			case 4:
				print();
				break;

			default:
				printf("Invalid Entry\n");
		}
	}
}

void menu()
{
	printf("1 - Inserir\n");
	printf("2 - Excluir\n");
	printf("3 - Comparar\n");
	printf("4 - Imprimir\n");
}

void insert()
{
	int value, position;

	printf("Type the value: ");
	scanf("%d", &value);
	printf("Position: ");
	scanf("%d", &position);

	list[position] = value;
}

void delete()
{
	int position;

	printf("Type the postition to delete: ");
	scanf("%d", &position);

	list[position] = -1;
	reordenate();
}

void compare()
{

	int i, search_val, hit = 0;

	printf("Digite o valor da busca: ");
	scanf("%d", &search_val);

	for(i=0; i<=4; i++)
	{
		if (list[i] == search_val)
		{
			printf("Valor encontrado na posicao %d = %d\n", i, search_val);
			hit = 1;
		}
	}

	if(hit != 1)
		printf("Valor nao encontrado\n");
	hit = 0;
}

void print()
{
	int i;

	printf("\n");

	for (i = 0; i <= 4; i++)
	{
		printf("%d,",list[i]);
	}
	printf("\n");
}

void reordenate()
{
	int i,j,k;
	for(k=0; k<=4; k++)
	{

		for(i=0; i<=4; i++)
		{
			printf("i %d\n", i);
			if(list[i] == -1)
			{
				for(j=i; j<=3; j++)
				{
					list[j] = list[j+1];
					printf("j-%d, i-%d\n", j, i);
				}
				list[4] = -1;
			}
		}
	}
}

void QuickSort( int a[], int left, int right)
{
	int j;

	if( left < right ) 
   	{
   		// divide and conquer
       	j = Partition( a, left, right);
       	
       	QuickSort( a, left, j-1);
       	QuickSort( a, j+1, right);
   	}
	
}



int Partition( int a[], int left, int right) {

	int pivot, i, j, t;
   
	pivot = a[left];
  	i = left; 
  	j = right+1;
		
   	while(1)
   	{
   		do ++i; while( a[i] <= pivot && i <= right );
   		do --j; while( a[j] > pivot );
   		if( i >= j ) break;
   		t = a[i]; a[i] = a[j]; a[j] = t;
   	}
   
 	t = a[left]; a[left] = a[j]; a[j] = t;
   	return j;
}


