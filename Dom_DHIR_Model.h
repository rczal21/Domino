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

#endif
