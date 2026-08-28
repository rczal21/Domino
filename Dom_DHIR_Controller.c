// Dom_DHIR_Controller.c

/* Daniel Luís de Amorim Mariano Santos,
Henrique Campos Rodrigues,
Isabella de Souza Fleury,
Rafaella Castro Zandona Alves de Lima */

#include "Dom_DHIR_Controller.h"
#include "Dom_DHIR_View.h"
#include "Dom_DHIR_Model.h"

void prepararJogo(){
    gerarPeca();
    embaralhar();
    distribuir();
    primeiraJogada();
}

void jogar(){
    int opcao;
    do {
        opcao = menuPrincipal();

        switch(opcao) {
            case 1:
            case 2:
                prepararJogo();
                mostrarMesa();
                mostrarMao('1');
                break;
            case 3:
                mostrarRegras();
                break;
            case 0:
                break;
            default:
                mostrarOpcaoInvalida();
                break;
        }
    } while (opcao != 0);
}
