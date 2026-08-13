// Dom_DHIR_Model
// 12/08/2026
/* Daniel Luís de Amorim Mariano Santos, 
Henrique Campos Rodrigues, 
Isabella de Souza Fleury, 
Rafaella Castro Zandona Alves de Lima */

#include "Dom_DHIR_Model.h"

#include<time.h>

// Modelo de peca
struct Peca
		{
			int lado1;
			int lado2;
			char status;
		} pecas[28];
	
// Embaralha as pecas
void embaralhar(Peca pecas[], int n){
	for(int i = 27; i > 0; i--){
		int j = rand() % (i + 1);	
			Peca temp = pecas[i];
			pecas[i] = pecas[j];
			pecas[j] = temp;
	}
}
	
void organizar(Peca pecas[]){
		int indice = 0;
		for(int i = 0; i < 7; i ++){
			for(int j = i; j < 7; j++){
				pecas[indice].lado1 = i;
				pecas[indice].lado2 = j;
				indice++;
			}
		}
	}

