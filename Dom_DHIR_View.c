// Dom_DHIR_View.c

/* Daniel Luís de Amorim Mariano Santos, 
Henrique Campos Rodrigues, 
Isabella de Souza Fleury, 
Rafaella Castro Zandona Alves de Lima */ 

#include "Dom_DHIR_View.h"
#include "Dom_DHIR_Model.h"
#include <stdio.h>

void mostrarPecas(Peca pecas[], int n){
    for(int i = 0; i < n; i++){
        printf(" Peca %d: [%d|%d]\n", i, pecas[i].ladoE, pecas[i].ladoD);
    }
}

void mostrarMao(char jogador){
    printf("\nMao do Jogador %c:\n", jogador);
    for(int i = 0; i < 28; i++){
        if(pecas[i].status == jogador) {
            printf("[%d|%d] ", pecas[i].ladoE, pecas[i].ladoD);
        }
    }
    printf("\n");
}

int menuPrincipal(){
    int opcao;
    printf("\n=== DOMINO ===\n");
    printf("1 - Vs. COM\n");
    printf("2 - Multiplayer (Dois jogadores)\n");
    printf("3 - Ver regras do jogo\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

void mostrarRegras(){
    printf("\nRegras do jogo:\n");
    printf("1. Cada jogador recebe 7 pecas.\n");
    printf("2. O jogador que tiver a peca dupla mais alta comeca o jogo.\n");
    printf("3. Os jogadores se revezam colocando pecas na mesa, combinando os numeros nas extremidades.\n");
    printf("4. Se um jogador nao puder jogar, ele deve comprar uma peca do monte.\n");
    printf("5. O jogo termina quando um jogador coloca todas as suas pecas ou quando nenhum jogador puder jogar.\n");
}

void mostrarQuemComeca(char jogador){
    printf("O jogador %c comeca a partida!\n", jogador);
}

char subMenu(char jogador){
    char opcao;
    printf("\nVez do jogador %c\n", jogador);
    printf("J - Jogar peca\n");
    printf("C - Comprar\n");
    printf("Opcao: ");
    scanf(" %c", &opcao);
    return opcao;
}

void mostrarMesa(){
    int i;
    int indice;
	printf("\n\t\t--- MESA ---\n");
    for (i = pontaE; i <= pontaD; i++){
    	indice = mesaPecas[i]; // associa ao indice a peça da posicao do vetor
    	printf("[%d|%d] ", pecas[indice].ladoE, pecas[indice].ladoD);
	}
	printf("\n\n");
}


void mostrarPecaInvalida(){
    printf("Peca invalida.\n");
}

void mostrarPecaEncaixada(char lado){
    if(lado == 'E')
        printf("Peca encaixada na esquerda.\n");
    else
        printf("Peca encaixada na direita.\n");
}

void mostrarPecaNaoEncaixa(){
    printf("Essa peca nao encaixa em nenhuma extremidade.\n");
}

void mostrarOpcaoInvalida(){
    printf("Opcao invalida.\n");
}

void mostrarVencedor(char jogador){
    printf("\nJogador %c bateu e venceu o jogo!\n", jogador);
}
