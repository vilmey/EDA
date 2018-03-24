#include <stdio.h>
#include <stdlib.h>

// LISTAS SIMPLESMENTE ENCADEADAS COM DESCRITOR

//-----------------------------------------------
//TIPO DE ELEMENTOS DA LISTA ENCADEADA

struct TNo
{
	int 	Numero;
	struct 	TNo *Prox;
};

// DESCRITOR DA LISTA
struct TLista
{
	struct 	TNo *Primeiro;
	int 	Quantidade;
	struct 	TNo *Ultimo;
};

//-----------------------------------------------
// TNo = STRUCT TNo

typedef struct TNo TNo;
typedef struct TLista TLista;

//-----------------------------------------------
//VERIFICA SE A CABECA ESTA VAZIA

bool Vazia(TLista *pLista)
{
	if(pLista->Quantidade == 0)
		return true;
	
	else
		return false;
}

//-----------------------------------------------
//INCLUSAO DE ELEMENTOS NA CABECA  - O(1)

TNo *IncluiCabeca(TLista *pLista, int pValor)
{
	//Caso exista um ponteiro para estrutura TNo valida
	if(Vazia(pLista) == false)
	{
		TNo *pNovoNo;									//Declara um ponteiro para a nova estrutura
		pNovoNo = (TNo *) malloc(sizeof(TNo));			//Aloca o tamanho da estrutura para o ponteiro
		pNovoNo->Numero = pValor;						//Campo Numero = pValor
		pNovoNo->Prox = pLista;							//Campo Proximo No = pLista(Cabeca atual)
		
		pLista->Primeiro = pNovoNo;						//Atualizacao do descritor
		pLista->Quantidade += 1;
	}

	else
	{
		TNo *pNovoNo;
		pNovoNo = (TNo *) malloc(sizeof(TNo));
		pNovoNo->Numero = pValor;
		pNovoNo->Prox = NULL;							//Unico elemento da lista
		
		pLista->Primeiro = pNovoNo;						//Atualizacao do descritor
		pLista->Quantidade = 1;
		pLista->Ultimo = pNovoNo;
	}

	return pLista;
}

//-----------------------------------------------
//EXCLUSAO DE ELEMENTOS NA CABECA - O(1)

TNo *ExcluiCabeca(TLista *pLista)
{
	if( Vazia(pLista) == false)
	{
		TNo *pAux;
		pAux = pLista;
		
		pLista->Primeiro = pLista->Primeiro->Prox;		//Recebe o ponteiro do segundo elemento da lista
		pLista->Quantidade -= 1;
		free(pAux);		
	}

	return pLista;
}

//-----------------------------------------------
//INCLUSAO DE ELEMENTOS NA CALDA - O(1)

TNo *IncluiCalda(TLista *pLista, int pValor)
{
	if(Vazia(pLista) == true)
	{
		return (IncluiCabeca(pLista, pValor));
	}

	else
	{
		TNo *pNovoNo;
		pNovoNo = (TNo *) malloc(sizeof(TNo));
		pNovoNo->Numero = pValor;
		pNovoNo->Prox = NULL;

		pLista->Ultimo->Prox = pNovoNo;				//Antigo ultimo no aponta para o novo ultimo
		pLista->Ultimo = pNovoNo;					//Atualiza pLista
		pLista->Quantidade += 1;

		return pLista;
	}
}


//-----------------------------------------------
//EXCLUSAO DE ELEMENTOS NA CALDA - O(N)

TNo *ExcluiCalda(TLista *pLista)
{
	if(Vazia(pLista) == false)
	{	
		TNo *pAux;
		pAux = pLista->Primeiro;

		while (pAux->Prox->Prox != NULL)
			pAux = pAux->Prox;
		
		free(pAux->Prox);
		pAux->Prox = NULL;

		pLista->Ultimo = pAux;
		pLista->Quantidade -= 1;
	}

	return pLista;
}

//-----------------------------------------------
//EXCLUSAO DE CHAVE - O(N) no pior dos casos

TNo *ExcluiChave(TLista *pLista, int pChave)
{
	if(Vazia(pLista) == false)
	{
		TNo *pAnt, *pPost;
		pAnt = pLista->Primeiro;
		
		while ((pAnt->Prox->Numero != pChave) || (pAnt->Prox->Prox == NULL))
			pAnt = pAnt->Prox;
		
		if((pAnt->Prox->Prox == NULL) && (pAnt->Prox->Numero != pChave))
		{
			printf("Chave nao localizada\n");
			return pLista;
		}

		if(pAnt->Prox->Prox == NULL)
		{
			ExcluiCalda(pLista);
			return pLista;
		}
	
		pPost = pAnt->Prox->Prox;		//pPost recebe um elemento depois da chave
		free(pAnt->Prox);				//Exclui chave
		pAnt->Prox = pPost ;			//Link entre elemento antes e depois da chave exclida

		pLista->Quantidade -=1;
	}

	return pLista;
}

//-----------------------------------------------
//INCLUI ANTES DA CHAVE - O(N)

TNo *IncluiAntes(TLista *pLista, int pChave, int pValor)
{
	if(Vazia(pLista) == false)
	{
		TNo *pAnt;
		pAnt = pLista->Primeiro;

		//Temos que checar se a chave se encontra na cabeca !!
		
		while ((pAnt->Prox->Numero != pChave) || (pAnt->Prox->Prox == NULL))
			pAnt = pAnt->Prox;
		
		if((pAnt->Prox->Prox == NULL) && (pAnt->Prox->Numero != pChave))
		{
			printf("Chave nao localizada\n");
			return pLista;
		}

		if(pAnt->Prox->Prox == NULL)
		{
			IncluiCalda(pLista, pValor);
			return pLista;
		}
		
		TNo *pNovoNo;								//Declara um ponteiro para a nova estrutura
		pNovoNo = (TNo *) malloc(sizeof(TNo));			//Aloca o tamanho da estrutura para o ponteiro
		pNovoNo->Numero = pValor;						//Campo Numero = pValor
		pNovoNo->Prox = pAnt->Prox;						//Campo Proximo No = pAnt-> prox, inclui antes da chave
		pAnt->Prox = pNovoNo;							//pAnt aponta para o novo elemento antes da chave

		pLista->Quantidade += 1;

	}
	
	return pLista;
}