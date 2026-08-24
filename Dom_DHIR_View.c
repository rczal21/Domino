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

void mostrarMao(Peca pecas[], char jogador){
	for(int i = 0; i < 28; i++){
		if(pecas[i].status == jogador) {
			printf("[%d|%d], ", pecas[i].lado1, pecas[i].lado2);
		}
	}
	printf("\n");
}

void menu(Peca pecas[]){
    int opcao;
    printf("1 - Iniciar jogo\n");
    printf("4 - Ver regras do jogo\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1)
        jogar(pecas);
    else if (opcao == 4)
        mostrarRegras();
    else if (opcao == 0)
        return;
    else
        printf("Digite um valor valido\n");
}


void mostrarRegras(){
    printf("Regras do jogo:\n");
    printf("1. Cada jogador recebe 7 peças.\n");
    printf("2. O jogador que tiver a peça dupla mais alta começa o jogo.\n");
    printf("3. Os jogadores se revezam colocando peças na mesa, combinando os números nas extremidades.\n");
    printf("4. Se um jogador não puder jogar, ele deve comprar uma peça do monte.\n");
    printf("5. O jogo termina quando um jogador coloca todas as suas peças ou quando nenhum jogador puder jogar.\n");
}

void mostrarQuemComeca(char jogador){
    printf("O jogador %c comeca a partida!\n", jogador);
}

char submenuJogada(char jogador){
	char opcao;
	printf("\nVez do jogador %c\n"), jogador);
	printf("J - Jogar peca\n");
	printf("C- Comprar\n");
	printf("Opcao: ");
	scanf(" %c", &opcao);
	return opcao;
}

void mostrarMesa(int mesaEsquerda, int mesaDireita){
    printf("\n--- Mesa: [%d | %d] ---\n", mesaEsquerda, mesaDireita);
}
 
int pedirIndicePeca(){
    int indice;
    printf("Digite o indice da peca que deseja jogar: ");
    scanf("%d", &indice);
    return indice;
}
 
void mostrarPecaInvalida(){
    printf("Peca invalida.\n");
}
 
void mostrarPecaAbriuMesa(int lado1, int lado2){
    printf("Peca [%d|%d] colocada na mesa.\n", lado1, lado2);
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
 
void mostrarResultadoCompra(bool sucesso){
    if(sucesso)
        printf("Peca comprada.\n");
    else
        printf("Monte vazio, nao ha mais pecas para comprar.\n");
}
 
void mostrarVencedor(char jogador){
    printf("\nJogador %c bateu e venceu o jogo!\n", jogador);
}
