// Dom_DHIR_Controller
// 12/08/2026
/* Daniel Luís de Amorim Mariano Santos,
Henrique Campos Rodrigues,
Isabella de Souza Fleury,
Rafaella Castro Zandona Alves de Lima*/

#include "Dom_DHIR_Controller.h"
#include "Dom_DHIR_View.c"
 
void jogar(Peca pecas[]){
 
	embaralhar(pecas, 28);
	criarMesa();
	distribuir(pecas);
 
	char jogadorAtual = definirComecar(pecas);
	mostrarQuemComeca(jogadorAtual);
 
	int jogoAcabou = 0;
	while(!jogoAcabou){
 
		mostrarMesa(mesaEsquerda, mesaDireita);
		mostrarMao(pecas, jogadorAtual);
 
		char opcao = submenuJogada(jogadorAtual);
 
		if(opcao == 'C' || opcao == 'c'){
			bool comprou = comprarPeca(jogadorAtual);
			mostrarResultadoCompra(comprou);
		}
		else if(opcao == 'J' || opcao == 'j'){
			int indice = pedirIndicePeca();
 
			if(indice < 0 || indice >= 28 || pecas[indice].status != jogadorAtual){
				mostrarPecaInvalida();
			}
			else if(qtdMesa == 0){
				// mesa vazia: a primeira peca abre o jogo, nao precisa validar extremidade
				mesaEsquerda = pecas[indice].lado1;
				mesaDireita = pecas[indice].lado2;
				pecas[indice].status = 'X';  // 'X' = peca na mesa
				qtdMesa++;
				mostrarPecaAbriuMesa(pecas[indice].lado1, pecas[indice].lado2);
			}
			else if(jogadaValida(pecas[indice], mesaEsquerda)){
				mesaEsquerda = (pecas[indice].lado1 == mesaEsquerda) ? pecas[indice].lado2 : pecas[indice].lado1;
				pecas[indice].status = 'X';
				qtdMesa++;
				mostrarPecaEncaixada('E');
			}
			else if(jogadaValida(pecas[indice], mesaDireita)){
				mesaDireita = (pecas[indice].lado1 == mesaDireita) ? pecas[indice].lado2 : pecas[indice].lado1;
				pecas[indice].status = 'X';
				qtdMesa++;
				mostrarPecaEncaixada('D');
			}
			else{
				mostrarPecaNaoEncaixa();
			}
		}
		else{
			mostrarOpcaoInvalida();
		}
 
		// verifica se o jogador atual bateu (ficou sem pecas)
		int qtdMaoAtual = 0;
		for(int i = 0; i < 28; i++){
			if(pecas[i].status == jogadorAtual) qtdMaoAtual++;
		}
		if(qtdMaoAtual == 0){
			mostrarVencedor(jogadorAtual);
			jogoAcabou = 1;
		}
		else{
			jogadorAtual = (jogadorAtual == '1') ? '2' : '1';
		}
	}
}
 
