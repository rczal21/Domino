// Dom_DHIR_Model.h
// 12/08/2026
/* Daniel Luís de Amorim Mariano Santos, 
Henrique Campos Rodrigues, 
Isabella de Souza Fleury, 
Rafaella Castro Zandona Alves de Lima */

typedef struct
{
    int lado1;
    int lado2;
    char status;
} Peca;

extern Peca pecas[28];

void embaralhar(Peca pecas[], int n);
void gerarPeca(Peca pecas[]);
void inicializarAleatorio();
void distribuir(Peca pecas[]);

#endif
