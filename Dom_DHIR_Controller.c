// Dom_DHIR_Controller

/* Daniel Luís de Amorim Mariano Santos, 
Henrique Campos Rodrigues, 
Isabella de Souza Fleury, 
Rafaella Castro Zandona Alves de Lima*/

#include "Dom_DHIR_Controller.h"
#include "Dom_DHIR_View.c"

void jogar(Peca pecas[]){
	for(int i = 0; i < 10; i++)
		mostrarPecas(pecas, 28);
	embaralhar(pecas, 28);
}
