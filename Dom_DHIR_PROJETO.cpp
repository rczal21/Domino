//Dom_DHIR_PROJETO.cpp - Projeto Domino

/*Daniel Luís de Amorim Mariano Santos,
Henrique Campos Rodrigues,
Isabella de Souza Fleury,
Rafaella Castro Zandona Alves de Lima*/

#include <stdlib.h>
#include <time.h>

#include "Dom_DHIR_Model.cpp"
#include "Dom_DHIR-Controller.cpp"

int main(){
	srand(time(NULL));
	gerarPecas();   //Model
	jogar();        //Controller

}
