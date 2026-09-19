// Dom_DHIR_View.h
//22/09/2026
/* Daniel Luis de Amorim Mariano Santos,
Henrique Campos Rodrigues,
Isabella de Souza Fleury,
Rafaella Castro Zandona Alves de Lima */

#ifndef DOM_DHIR_VIEW_H
#define DOM_DHIR_VIEW_H


void mostrarPecas(Peca pecas[], int n);
void mostrarMao(char jogador);
int menuPrincipal();
void mostrarRegras();
void mostrarQuemComeca(char jogador);
char subMenu(char jogador);
void mostrarMesa();
void mostrarPecaInvalida();
void mostrarPecaEncaixada(char lado);
void mostrarPecaNaoEncaixa();
void mostrarOpcaoInvalida();
void mostrarVencedor(char jogador);
int lerIndicePeca();
char lerLadoPeca();
void mostrarPecaInvalidaMao();
void mostrarCompraSucesso();
void mostrarMonteVazio();
void mostrarPassouVez(char jogador);
void mostrarSaindoDoJogo();
void mostrarJogoSalvo();
void mostrarErroGravar();
void mostrarErroArquivo();
void mostrarJogoCarregado();
void mostrarErroCarregar();
void limparTela();
void pausarTrocaDeJogador(char proximoJogador);

#endif

