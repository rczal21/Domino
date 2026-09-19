// Dom_DHIR_Controller.h
//22/09/2026
/* Daniel Luis de Amorim Mariano Santos, 
Henrique Campos Rodrigues, 
Isabella de Souza Fleury, 
Rafaella Castro Zandona Alves de Lima*/

#ifndef DOM_DHIR_CONTROLLER_H
#define DOM_DHIR_CONTROLLER_H



void jogar();
void prepararJogo();
void executarPartida(int modoDeJogo);
void rodarPartida(int modoDeJogo, char jogadorInicial);
void continuarPartida();
int gravarJogo(char jogadorAtual, int modoDeJogo);
int carregarJogo();


#endif
