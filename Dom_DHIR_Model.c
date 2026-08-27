// Dom_DHIR_Model
// 12/08/2026
 Daniel Luís de Amorim Mariano Santos,
Henrique Campos Rodrigues,
Isabella de Souza Fleury,
Rafaella Castro Zandona Alves de Lima */

 
#include "Dom_DHIR_Model.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
 

// Define o array
Peca pecas[28];
int numJogadores;
int mesaEsquerda;
int mesaDireita;
int quantidadeMesa;
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

void monteVazio(); //necessario criar a partir do status do monte

void primeiraJogada(Peca pecas[]){
	int i;
	int maior1 = 0;
	int numPeca1 = 0;
	
	for(i = 0; i < 7; i++){
		if (pecas[i].ladoE == pecas[i].ladoD){
			if (pecas[i].lado1 >= maior1)
				maior1 = pecas[i].lado1;
				numPeca1 = i;
		}
	}


	int i;
	int maior2 = 0;
	int numPeca2 = 0;
	
	for(i = 7; i < 14; i++){
		if (pecas[i].ladoE == pecas[i].ladoD){
			if (pecas[i].ladoE >= maior1)
				maior2 = pecas[i].lado1;
				numPeca2 = i;
		}
	}
	
	if (maior1 < maior2)
		pecas[numPeca2].status = 'T';
	else if (maior2 < maior1)
		pecas[numPeca1].status = 'T';
	else{
		for (i = 14; i < 28; i++)
			if (pecas[i].ladoE == pecas[i].ladoD && pecas[i].ladoE == 6)
				pecas[i].status = 'T';
	}
	
}
