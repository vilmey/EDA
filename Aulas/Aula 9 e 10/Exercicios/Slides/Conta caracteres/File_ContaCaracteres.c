#include<stdio.h>
main( )
{
  FILE *fp;
  char ch;
  int pqtdecar = 0, pqtdespco = 0, pqtdtab = 0, pqtdline = 0;
  fp = fopen ( "arquivo1.txt", "r" );
  while ( 1 )
  {
    ch = fgetc(fp);
	if(ch==EOF)
		break;

	if(ch == 0x20)
	{
		pqtdespco++;
	}
	
	if(ch == 0x09)
	{
		pqtdtab++;
	}

	if(ch == '\n')
	{
		pqtdline++;
	}
	pqtdecar++;
  }
  fclose ( fp );
  printf("Quantidade de Caracteres: %d\n",pqtdecar);
  printf("Quantidade de linhas: %d\n",pqtdline);
  printf("Quantidade de Tab: %d\n",pqtdtab);
  printf("Quantidade de espaço: %d\n",pqtdespco);
  return 0;
}
