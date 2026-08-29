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

void executarPartida(int modoDeJogo) {
    prepararJogo();
    
    int fimDeJogo = 0;
    char jogadorAtual = '1';
    
    while (fimDeJogo == 0) {
        mostrarMesa();
        mostrarMao(jogadorAtual);
        
        char acao = subMenu(jogadorAtual);
        
        // 1. JOGAR PEÇA
        if (acao == 'J' || acao == 'j') {
            int pecaEscolhida = lerIndicePeca(); 
            char ladoEscolhido = lerLadoPeca();  
            
            if (pecaEscolhida < 0 || pecaEscolhida > 27 || pecas[pecaEscolhida].status != jogadorAtual) {
                mostrarPecaInvalidaMao(); // <--- Chamada para a View
                continue; 
            }

            int jogadaValida = tentarJogar(pecaEscolhida, ladoEscolhido);
            
            if (jogadaValida == 1) {
                mostrarPecaEncaixada(ladoEscolhido);
                
                if (contarPecas(jogadorAtual) == 0) {
                    mostrarVencedor(jogadorAtual);
                    fimDeJogo = 1; 
                    continue;
                }
            } else {
                mostrarPecaNaoEncaixa();
                continue; 
            }
        } 
        
        // 2. COMPRAR PEÇA
        else if (acao == 'C' || acao == 'c') {
            int sucesso = comprarPeca(jogadorAtual); 
            
            if (sucesso == 1) {
                mostrarCompraSucesso(); // <--- Chamada para a View
            } else {
                mostrarMonteVazio(); // <--- Chamada para a View
            }
            continue; 
        } 
        
        // 3. PASSAR A VEZ
        else if (acao == 'P' || acao == 'p') {
            mostrarPassouVez(jogadorAtual); // <--- Chamada para a View
        }
        
        // 4. SAIR DO JOGO
        else if (acao == 'S' || acao == 's') {
            mostrarSaindoDoJogo(); // <--- Chamada para a View
            fimDeJogo = 1; 
            continue;
        }
        
        else {
            mostrarOpcaoInvalida();
            continue; 
        }
        
        // TROCA O TURNO 
        if (jogadorAtual == '1') {
            jogadorAtual = '2';
        } else {
            jogadorAtual = '1';
        }
    }
}

void jogar(){
    int opcao;
    do {
        opcao = menuPrincipal();

        switch(opcao) {
            case 1:
            case 2:
               executarPartida(opcao); 
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
