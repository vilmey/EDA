#include <stdio.h>
#include <stdlib.h>




void menu(int vetor[], int tamanho);
void insert(int vetor[], int tamanho);
void delete(int vetor[], int tamanho);
void compare(int vetor[], int tamanho);
void print(int vetor[], int tamanho);
void insert_vector(int vetor[], int tamanho);
void QuickSort( int vetor[], int left, int right, int tamanho);
int Partition( int vetor[], int left, int right);


#define tamanho_vetor	10


int main()
{
	
	printf("O tamanho do vetor é 10 \n");
	int list[tamanho_vetor] = {[0 ... (tamanho_vetor - 1)] = -1};
	
	
	while(1)
	{
		menu(list, tamanho_vetor);
	}
}

void menu(int vetor[], int tamanho)
{
	int option;
	
	printf("1 - Inserir\n");
	printf("2 - Inserir\n");
	printf("3 - Excluir\n");
	printf("4 - Comparar\n");
	printf("5 - Imprimir\n");
	printf("6 - Ordenar\n");
	
	scanf("%d", &option);

	switch (option)
	{
		case 1:
			insert(vetor, tamanho);
			break;
			
		case 2:
			insert_vector(vetor, tamanho);
			break;

		case 3:
			delete(vetor, tamanho);
			break;

		case 4:
			compare(vetor, tamanho);
			break;

		case 5:
			print(vetor, tamanho);
			break;
				
		case 6:
			QuickSort(vetor, 0, tamanho-1, tamanho);
			break;

		default:
			printf("Invalid Entry\n");
		}
}

void insert(int vetor[], int tamanho)
{
	int value, position;

	printf("Type the value: ");
	scanf("%d", &value);
	printf("Position: ");
	scanf("%d", &position);

	vetor[position] = value;
}

void insert_vector(int vetor[], int tamanho)
{
	int i, num;
	for(i=0; i<tamanho; i++)
	{
		printf("Digite o #%d: ", i);
		scanf("%d", &num);
		vetor[i] = num;
	}
}

void delete(int vetor[], int tamanho)
{
	int position;

	printf("Type the postition to delete: ");
	scanf("%d", &position);

	vetor[position] = -1;
	QuickSort(vetor, 0, tamanho-1, tamanho);
	print(vetor, tamanho);
}

void compare(int vetor[], int tamanho)
{

	int i, search_val, hit = 0;

	printf("Digite o valor da busca: ");
	scanf("%d", &search_val);

	for(i=0; i< tamanho; i++)
	{
		if (vetor[i] == search_val)
		{
			printf("Valor encontrado na posicao %d = %d\n", i, search_val);
			hit = 1;
		}
	}

	if(hit != 1)
		printf("Valor nao encontrado\n");
	hit = 0;
}


void print(int vetor[], int tamanho)
{
	int i;

	printf("\n");

	for (i = 0; i < tamanho; i++)
	{
		printf("%d ",vetor[i]);
	}
	printf("\n");
}

void QuickSort( int vetor[], int left, int right, int tamanho)
{
	int j;

	if( left < right ) 
   	{
   		// divide and conquer
       	j = Partition( vetor, left, right);
       	
       	QuickSort( vetor, left, j-1, tamanho);
       	QuickSort( vetor, j+1, right, tamanho);
   	}
   	
   	print(vetor, tamanho);
	
}



int Partition( int vetor[], int left, int right)
{

	int pivot, i, j, t;
   
	pivot = vetor[left];
  	i = left; 
  	j = right+1;
		
   	while(1)
   	{
   		do ++i; while( vetor[i] <= pivot && i <= right );
   		do --j; while( vetor[j] > pivot );
   		if( i >= j ) break;
   		t = vetor[i]; vetor[i] = vetor[j]; vetor[j] = t;
   	}
   
 	t = vetor[left]; vetor[left] = vetor[j]; vetor[j] = t;
   	return j;
}


