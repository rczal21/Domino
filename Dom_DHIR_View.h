// Dom_DHIR_View.h

/* Daniel Luís de Amorim Mariano Santos,
Henrique Campos Rodrigues,
Isabella de Souza Fleury,
Rafaella Castro Zandona Alves de Lima */
 
#ifndef Dom_DHIR_View_h
#define Dom_DHIR_View_h
 
#include "Dom_DHIR_Model.h"
 
void mostrarPecas(Peca pecas[], int n);
void mostrarMao(Peca pecas[]);
void menu(Peca pecas[]);
void mostrarRegras();
void mostrarQuemComeca(char jogador);
char submenuJogada(char jogador);

void mostrarMesa(int mesaEsquerda, int mesaDireita);
int pedirIndicePeca();
void mostrarPecaInvalida();
void mostrarPecaAbriuMesa(int lado1, int lado2);
void mostrarPecaEncaixada(char lado);
void mostrarPecaNaoEncaixa();
void mostrarOpcaoInvalida();
void mostrarResultadoCompra(bool sucesso);
void mostrarVencedor(char jogador);

#endif
