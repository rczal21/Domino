// Dom_DHIR_PROJETO - Projeto Domino
/*Daniel Luís de Amorim Mariano Santos,
Henrique Campos Rodrigues,
Isabella de Souza Fleury,
Rafaella Castro Zandona Alves de Lima*/

#include "Dom_DHIR_Model.c"
#include "Dom_DHIR_Controller.c"

int main()
{
	inicializarAleatorio();
	gerarPeca(pecas);   //Fica no Model
	jogar(pecas);       //Fica no Controller
	return 0;
}
