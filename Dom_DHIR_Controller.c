// Dom_DHIR_Controller
// 12/08/2026
/* Daniel Luís de Amorim Mariano Santos,
Henrique Campos Rodrigues,
Isabella de Souza Fleury,
Rafaella Castro Zandona Alves de Lima*/
 
#include "Dom_DHIR_Controller.h"
#include "Dom_DHIR_View.c"
 
void jogar(Peca pecas[]){
	
	embaralhar(pecas, 28);   
	criarMesa();
	distribuir(pecas);       
 
	char quemComeca = definirComecar(pecas);
	mostrarQuemComeca(quemComeca);
 
	mostrarMao(pecas);
}
