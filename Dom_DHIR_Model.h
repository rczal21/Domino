// Dom_DHIR_Model.h

/* Daniel Luís de Amorim Mariano Santos,
Henrique Campos Rodrigues,
Isabella de Souza Fleury,
Rafaella Castro Zandona Alves de Lima */

#ifndef DOM_DHIR_MODEL_H
#define DOM_DHIR_MODEL_H

typedef struct {
    int ladoE;
    int ladoD;
    char status;
} Peca;

extern Peca pecas[28];
extern int qtdeJogadores;
extern int mesaE;
extern int mesaD;
extern int pontaE;
extern int pontaD;
extern int qtdeMesa;
extern int mesaPecas[55];
extern char jogadorComeca;

void embaralhar();
void gerarPeca();
void inicializarAleatorio();
void distribuir();
char primeiraJogada();
void jogarPecas(int i, char lado);
bool jogadaValida(int i, char lado);
int contarPecas(char jogador);
int tentarJogar(int indicePeca, char lado);
int comprarPeca(char jogador);

#endif

