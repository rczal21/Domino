// Dom_DHIR_PROJETO - Projeto Domino
// 12/08/2026
/*Daniel Luís de Amorim Mariano Santos, 
Henrique Campos Rodrigues, 
Isabella de Souza Fleury, 
Rafaella Castro Zandona Alves de Lima*/

#include "Dom_DHIR_Model.h"
#include "Dom_DHIR_Controller.h"
#include "Dom_DHIR_View.h"
 
int main()
{
	inicializarAleatorio();
	gerarPeca(pecas);
	distribuir(pecas);
	menu(pecas);
 
	return 0;
}
