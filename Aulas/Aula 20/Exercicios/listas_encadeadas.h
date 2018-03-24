//PROTOTIPO DE FUNCOES


//-----------------------------------------------
//INCLUSAO DE ELEMENTOS NA CABECA  - O(1)

TNo *IncluiCabeca(TNo *pLista, int pValor);
//-----------------------------------------------
//EXCLUSAO DE ELEMENTOS NA CABECA - O(1)

TNo *ExcluiCabeca(TNo *pLista);
//-----------------------------------------------
//INCLUSAO DE ELEMENTOS NA CALDA - O(N)

TNo *IncluiCalda(TNo *pLista, int pValor);
//-----------------------------------------------
//EXCLUSAO DE ELEMENTOS NA CALDA - O(N)

TNo *ExcluiCalda(TNo *pLista);
//-----------------------------------------------
//EXCLUSAO DE CHAVE - O(N) no pior dos casos

TNo *ExcluiChave(TNo *pLista, int pChave);
//-----------------------------------------------
//INCLUI ANTES DA CHAVE - O(N)

TNo *IncluiAntes(TNo *pLista, int pChave, int pValor);