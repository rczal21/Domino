// Dom_DHIR_View
// 12/08/2026
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
