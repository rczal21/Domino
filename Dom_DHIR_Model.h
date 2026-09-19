// Dom_DHIR_Model.h
//22/09/2026
/* Daniel Luis de Amorim Mariano Santos,
Henrique Campos Rodrigues,
Isabella de Souza Fleury,
Rafaella Castro Zandona Alves de Lima */

#ifndef DOM_DHIR_MODEL_H
#define DOM_DHIR_MODEL_H

#include <stdbool.h>

typedef struct {
    int ladoE;
    int ladoD;
    char status;
} Peca;

//estrutura que guarda a "situacao geral" do jogo no momento de salvar/carregar
typedef struct {
    int qtmesaJogo;   // qtde de pecas na mesa (qtdeMesa)
    char jogadorJogo; // de quem eh a vez ('1' ou '2')
    int modoJogo;     // 1 = contra o computador, 2 = dois jogadores
    int mesaDJogo;    // extremidade direita da mesa (mesaD)
    int mesaEJogo;    // extremidade esquerda da mesa (mesaE)
    int pontaEJogo;   // ponta esquerda do vetor mesaPecas (pontaE)
    int pontaDJogo;   // ponta direita do vetor mesaPecas (pontaD)
} SituacaoJogo;

extern Peca pecas[28];
extern SituacaoJogo sitJogo;
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

