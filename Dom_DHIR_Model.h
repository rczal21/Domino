// Dom_DHIR_Model.h
// 12/08/2026
/* Daniel Luís de Amorim Mariano Santos,
Henrique Campos Rodrigues,
Isabella de Souza Fleury,
Rafaella Castro Zandona Alves de Lima */
 
#ifndef Dom_DHIR_Model_h
#define Dom_DHIR_Model_h
 
typedef struct
{
    int lado1;
    int lado2;
    char status;
} Peca;
 
extern Peca pecas[28];
extern int numJogadores;
extern int mesaEsquerda;
extern int mesaDireita;
extern int qtdMesa;
 
void embaralhar(Peca pecas[], int n);
void gerarPeca(Peca pecas[]);
void inicializarAleatorio();
void distribuir(Peca pecas[]);
void criarMesa();

extern char jogadorComeca;   
char definirComecar(Peca pecas[]);
 
#endif
