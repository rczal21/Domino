// Dom_DHIR_View

/* Daniel Luís de Amorim Mariano Santos, 
Henrique Campos Rodrigues, 
Isabella de Souza Fleury, 
Rafaella Castro Zandona Alves de Lima */ 


#include "Dom_DHIR_View.h"
#include <stdio.h>

void mostrarPecas(Peca pecas[], int n){
    for(int i = 0; i < n; i++){
        printf(" Peca %d: [%d|%d]\n", i, pecas[i].lado1, pecas[i].lado2);
    }
}

void mostrarMao(Peca pecas[]){
	for(int i = 0; i < 28; i++){
		if(pecas[i].status == '1') {
			printf("[%d|%d], ", pecas[i].lado1, pecas[i].lado2);
		}
	}
}

void menu(Peca pecas[]){
    int opcao;
    printf("Modo de jogo (1 ou 2):");
    scanf("%d", &opcao);
    if (opcao == 1)
        jogar(pecas);
    // else if (opcao == 2)
    //     jogarEli(pecas);   // ainda nao implementada
    else
        printf("Digite um valor valido");
}
