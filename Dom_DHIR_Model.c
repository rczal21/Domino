// Dom_DHIR_Model
// 12/08/2026
/* Daniel Luís de Amorim Mariano Santos,
Henrique Campos Rodrigues,
Isabella de Souza Fleury,
Rafaella Castro Zandona Alves de Lima */
 
#include "Dom_DHIR_Model.h"
#include <stdlib.h>
#include <time.h>
 
// Define o array
Peca pecas[28];
int numJogadores;
int mesaEsquerda;
int mesaDireita;
int qtdMesa;
char jogadorComeca;
 
// Embaralha as pecas
void embaralhar(Peca pecas[], int n){
	for(int i = 27; i > 0; i--){
		int j = rand() % (i + 1);
		Peca temp = pecas[i];
		pecas[i] = pecas[j];
		pecas[j] = temp;
	}
}
 
void gerarPeca(Peca pecas[]){
	int indice = 0;
	for(int i = 0; i < 7; i++){
		for(int j = i; j < 7; j++){
			pecas[indice].lado1 = i;
			pecas[indice].lado2 = j;
			indice++;
		}
	}
}
 
void inicializarAleatorio() {
	srand(time(NULL));
}
 
void distribuir(Peca pecas[]){
	
	for(int i = 0; i < 7; i++){
		pecas[i].status = '1';
	}
	for(int i = 7; i < 14; i++){
		pecas[i].status = '2';
	}
	for(int i = 14; i < 28; i++){
		pecas[i].status = 'M';  // monte
	}
}

void criarMesa(){
	mesaEsquerda = -1;   // -1 = ainda nao tem peca na mesa
	mesaDireita = -1;
	qtdMesa = 0;
}
char jogadorComeca;

char definirComecar(Peca pecas[]){
    int maiorDobro = -1;
    char jogador = '1';   //caso ninguem tenha dobro

    for(int i = 0; i < 28; i++){
        if(pecas[i].lado1 == pecas[i].lado2){          
            if(pecas[i].lado1 > maiorDobro){
                maiorDobro = pecas[i].lado1;
                jogador = pecas[i].status;
            }
        }
    }

    jogadorComeca = jogador;
    return jogador;
}

bool comprarPeca(char jogador){
	for(int i = 0; i < 28; i++){
		if(pecas[i].status == 'M'){
			pecas[i].status = jogador; 
			return true;
		}
	}
	return false;
}

bool jogadaValida(Peca peca, int extremidade){
	return (peca.lado1 == extremidade || peca.lado2 == extremidade);
}
