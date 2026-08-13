// Dom_DHIR_View
// 12/08/2026
/* Daniel Luís de Amorim Mariano Santos, 
Henrique Campos Rodrigues, 
Isabella de Souza Fleury, 
Rafaella Castro Zandona Alves de Lima */ 

#include "Dom_DHIR_View.h"

#include<stdio.h>
#include<stdlib.h>

// Apresenta as pecas no momento atual de embaralhamento
void mostrarPecas(Peca pecas[], int n){
	for(int i = 0; i < n; i++){
		printf(" Peca %d: [%d|%d]\n", i , pecas[i].lado1, pecas[i].lado2);
	}
}

int main(){
		srand(time(NULL)); // Muda o sorteio toda vez que o código é inicializado
		organizar(pecas);
			
/*			
	int resposta;
		for(int i = 0; i <= 4; i++){
			printf("Mostrar pecas em ordem ou embaralhadas? (digite 1 ou 2)\n");
			scanf("%d",  &resposta);
		
		
			if(resposta == 1){
				organizar(pecas);
				mostrarPecas(pecas, 28);
			}
		
			else {
				embaralhar(pecas, 28);
				mostrarPecas(pecas, 28);
			}
		}
			
*/	
}
