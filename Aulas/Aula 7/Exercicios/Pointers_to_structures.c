#include <stdio.h>
#include <string.h>
 
struct TContacts {
   char  name[50];
   float  height;
   int  age;
};

/* function declaration */
void printContact( struct TContacts *Clista, int *declarados);
void IncludeContact( struct TContacts *contato, int *declarados, int codigo);
void ExcludeContact ( struct TContacts *contato, int *declarados, int codigo);
void ChangeContact( struct TContacts *contato, int *declarados, int codigo);


int main( ) {

   int option, codigo, current_declared[3];
   char buffer[60];
   struct TContacts C[3];        /* Declare C of type TContacts */
   
   while(1)
   {

      printf("(1)Incluir Contato\n");
      printf("(2)Excluir Contato\n");
      printf("(3)Listar Contato\n");
      printf("(4)Alterar Contato\n");
      printf("Digite a opção: ");
      scanf("%d", &option);
      system("clear");


      switch(option)
      {
         case 1:
            printf("\nDigite o código: ");
            scanf("%d", &codigo);
            //current_declared[codigo] = codigo;
            IncludeContact(&C[codigo], current_declared, codigo);
            break;

         case 2:
            printf("\nDigite o código: ");
            scanf("%d", &codigo);
            ExcludeContact(&C[codigo], current_declared, codigo);
            break;

         case 3:
            printContact(C, current_declared);
            break;

         case 4:
            printf("\nDigite o código: ");
            scanf("%d", &codigo);
            ChangeContact(&C[codigo], current_declared, codigo);
            break;

         default:
            printf("Opção Inválida !!\n");

      }
   }

   return 0;
}

void printContact( struct TContacts *Clista, int *declarados) {

   int i, flag = 0;

   for(i=0; i<3; i++)
   {
      if(i == declarados[i])
      {
         flag = 1;
         printf("\n================ Lista ================\n");
         printf( "Contato -[%d] name : %s\n", i, Clista[i].name);
         printf( "Contato -[%d] height : %f\n", i, Clista[i].height);
         printf( "Contato -[%d] age : %d\n", i, Clista[i].age);
         printf("================  Fim  ================\n\n");
      }
   }

   if(flag == 0)
      printf("\nNão há contatos !\n\n");
}

void IncludeContact( struct TContacts *contato, int *declarados, int codigo)
{
   char buffer[60];

   if(declarados[codigo] != codigo)
   {
      declarados[codigo] = codigo;

      printf("Digite o nome: ");
      fgetc(stdin);
      fgets(buffer, 60, stdin);
      buffer[strcspn(buffer, "\n")] = 0;
      strcpy( contato->name, buffer);
      
      printf("Digite a altura: ");
      scanf("%f", &contato->height);

      printf("Digite a idade: ");
      scanf("%d",&contato->age);
   }

   else
      printf("Posição já ocupada !!\n");

}

void ExcludeContact ( struct TContacts *contato, int *declarados, int codigo)
{
   char buffer[60] = "";

   if(declarados[codigo] == codigo)
   {
      strcpy( contato->name, buffer);
      contato->height = -1;
      contato->age = -1;
      declarados[codigo] = -1;
   }

   else
      printf("Posição não declarada !\n");
}

void ChangeContact( struct TContacts *contato, int *declarados, int codigo)
{
   char buffer[60];

   if(declarados[codigo] == codigo)
   {
      printf("Digite o nome: ");
      fgetc(stdin);
      fgets(buffer, 60, stdin);
      buffer[strcspn(buffer, "\n")] = 0;
      strcpy( contato->name, buffer);
      
      printf("Digite a altura: ");
      scanf("%f", &contato->height);

      printf("Digite a idade: ");
      scanf("%d",&contato->age);
   }
   else
      printf("Posição não declarada !\n");
}