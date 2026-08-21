// Dom_DHIR_Controller
// 12/08/2026
/* Daniel Luís de Amorim Mariano Santos, 
Henrique Campos Rodrigues, 
Isabella de Souza Fleury, 
Rafaella Castro Zandona Alves de Lima*/

#include "Dom_DHIR_Controller.h"
#include "Dom_DHIR_Model.h"
#include "Dom_DHIR_View.cpp"
 
void jogarSolo(Peca pecas[]){
	inicializarMesa();  // REQ09: mesa começa vazia a cada partida
 
	for(int i = 0; i < 10; i++)
		mostrarPecas(pecas, 28);
	embaralhar(pecas, 28);
}
 
void jogarDoisJogadores(Peca pecas[]){
// essa função ainda não foi implementada de verdade, só existe
// pra compilar. O menu() chama ela na opção 2 (modo dois jogadores).
}
