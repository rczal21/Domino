// Dom_DHIR_Controller.cpp
//22/09/2026
/* Daniel Luis de Amorim Mariano Santos,
Henrique Campos Rodrigues,
Isabella de Souza Fleury,
Rafaella Castro Zandona Alves de Lima */

#include "Dom_DHIR_Controller.h"
#include "Dom_DHIR_View.cpp"
#include <stdio.h>

#define CHANCE_BLEFE 15 //chance a cada turno do computador de comprar uma peca mesmo podendo jogar (15%)

void prepararJogo(){
    gerarPeca();
    embaralhar();
    distribuir();
    primeiraJogada();
}

/*Loop principal de uma partida. Recebe o modo de jogo e quem comeca a jogar,
para que tanto uma partida nova (executarPartida) quanto uma partida
recuperada de arquivo (continuarPartida) possam reaproveitar o mesmo codigo.*/
void rodarPartida(int modoDeJogo, char jogadorInicial) {
    int fimDeJogo = 0;
    char jogadorAtual = jogadorInicial;
    
        while (fimDeJogo == 0) {
        mostrarMesa();
        
        if (modoDeJogo == 1 && jogadorAtual == '2') {   //vez do computador
            printf("\n--- VEZ DO COMPUTADOR ---\n");
            int jogou = 0;
            
            /* BLEFE: de vez em quando (nao sempre) o computador prefere comprar uma
            peca por opcao, mesmo podendo jogar, como ocorre igual e permitido ao jogador
            humano, para nao ficar previsivel. CHANCE_BLEFE eh a % de chance*/
            if ((rand() % 100) < CHANCE_BLEFE) {
                int comprou = comprarPeca('2');
                if (comprou == 1) {
                    printf("\nO Computador comprou uma peca.\n");
                }
            }
            
            //o computador checa a própria mão tentando achar uma peça que encaixe
            for (int i = 0; i < 28; i++) {
                if (pecas[i].status == '2') {
                    if (tentarJogar(i, 'E') == 1) { //encaixe na esquerda
                        mostrarPecaEncaixada('E');
                        jogou = 1;
                        break;
                    }
                    else if (tentarJogar(i, 'D') == 1) { //encaixe na direita
                        mostrarPecaEncaixada('D');
                        jogou = 1;
                        break;
                    }
                }
            }
            
            //verifica qual foi o resultado da tentativa de jogada
            if (jogou == 1) {
                //verifica se ele bateu.
                if (contarPecas(jogadorAtual) == 0) {
                    mostrarVencedor(jogadorAtual);
                    fimDeJogo = 1;
                    continue;
                }
                //se não bateu, o código desce direto para a troca de turno lá embaixo.
            } 
            else {
                //se não achou peça que sirva, ele tenta comprar
                int sucesso = comprarPeca('2');
                if (sucesso == 1) {
                    printf("\nO Computador comprou uma peca. Ele vai tentar jogar novamente...\n");
                    system("pause"); //da um tempo para o usuario ler
                    continue; //'continue' faz o turno recomeçar SEM trocar de jogador
                } else {
                    //se não tem peça e o monte acabou, ele é obrigado a passar a vez
                    printf("\nO monte esta vazio. O Computador passou a vez.\n");
                }
            }
            system("pause");
        }
        
        
        else {   //vez do usuario
            mostrarMao(jogadorAtual);
            char acao = subMenu(jogadorAtual);
            
            //jogar peca
            if (acao == 'J' || acao == 'j') {
                int pecaEscolhida = lerIndicePeca(); 
                char ladoEscolhido = lerLadoPeca();  
                
                if (pecaEscolhida < 0 || pecaEscolhida > 27 || pecas[pecaEscolhida].status != jogadorAtual) {
                    mostrarPecaInvalidaMao(); 
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
            //comprar peca
            else if (acao == 'C' || acao == 'c') {
                int sucesso = comprarPeca(jogadorAtual); 
                
                if (sucesso == 1) {
                    mostrarCompraSucesso(); 
                } else {
                    mostrarMonteVazio(); 
                }
                continue; 
            } 
            //passar a vez
            else if (acao == 'P' || acao == 'p') {
                mostrarPassouVez(jogadorAtual); 
            }
            //gravar partida e sair
            else if (acao == 'G' || acao == 'g') {
                int sucesso = gravarJogo(jogadorAtual, modoDeJogo);
                
                if (sucesso == 1) {
                    mostrarJogoSalvo(); 
                } else {
                    mostrarErroGravar(); 
                }
                fimDeJogo = 1; 
                continue;
            }
            //sair do jogo sem gravar
            else if (acao == 'S' || acao == 's') {
                mostrarSaindoDoJogo(); 
                fimDeJogo = 1; 
                continue;
            }
            else {
                mostrarOpcaoInvalida();
                continue; 
            }
        }

        if (jogadorAtual == '1') {  //troca de jogadores 
            jogadorAtual = '2';
        } else {
            jogadorAtual = '1';
        }
        
        pausarTrocaDeJogador(jogadorAtual);
    }
}

void executarPartida(int modoDeJogo) {
    prepararJogo();
    rodarPartida(modoDeJogo, '1');
}

//recupera uma partida salva e retoma o jogo de onde parou
void continuarPartida() {
    int sucesso = carregarJogo();

     if (sucesso == 0) {
        mostrarErroCarregar(); //caso o jogo nao tenha sido salvo ou os arquivos estejam corrompidos
        return;
    }
    
    mostrarJogoCarregado(); 
    rodarPartida(sitJogo.modoJogo, sitJogo.jogadorJogo);
}

// grava a situacao atual do jogo em 3 arquivos (pecas, mesa e situacao geral),
int gravarJogo(char jogadorAtual, int modoDeJogo) {
    FILE *fp;  //arquivo das pecas
    FILE *fpm; //arquivo da mesa
    FILE *fps; //arquivo da situacao geral
    int i;
    
    //grava situacao das 28 pecas
    fp = fopen("CAD_DOMINO.dat", "wb");
    if (fp == NULL) {
        mostrarErroArquivo();
        return 0;
    }
    for (i = 0; i < 28; i++) {
        if (fwrite(&pecas[i], sizeof(Peca), 1, fp) != 1) {
            mostrarErroGravar();
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    
    //grava a situacai da mesa 
    fpm = fopen("CAD_MESA.dat", "wb");
    if (fpm == NULL) {
        mostrarErroArquivo();
        return 0;
    }
    for (i = 0; i < 55; i++) {
        if (fwrite(&mesaPecas[i], sizeof(int), 1, fpm) != 1) {
            mostrarErroGravar();
            fclose(fpm);
            return 0;
        }
    }
    fclose(fpm);
    
    //monta e grava a struct com a situacao geral do jogo
    sitJogo.qtmesaJogo = qtdeMesa;
    sitJogo.jogadorJogo = jogadorAtual;
    sitJogo.modoJogo = modoDeJogo;
    sitJogo.mesaDJogo = mesaD;
    sitJogo.mesaEJogo = mesaE;
    sitJogo.pontaEJogo = pontaE;
    sitJogo.pontaDJogo = pontaD;
    
    fps = fopen("CAD_JOGO.dat", "wb");
    if (fps == NULL) {
        mostrarErroArquivo();
        return 0;
    }
    if (fwrite(&sitJogo, sizeof(SituacaoJogo), 1, fps) != 1) {
        mostrarErroGravar();
        fclose(fps);
        return 0;
    }
    fclose(fps);
    
    return 1;
}

//le os 3 arquivos gravados por gravarJogo() e restaura as variaveis globais do Model
int carregarJogo() {
    FILE *fp;  
    FILE *fpm;
    FILE *fps; 
    int i;
    
    //le as 28 pecas
    fp = fopen("CAD_DOMINO.dat", "rb");
    if (fp == NULL) {
        return 0;
    }
    for (i = 0; i < 28; i++) {
        if (fread(&pecas[i], sizeof(Peca), 1, fp) != 1) {
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    
    //le a mesa
    fpm = fopen("CAD_MESA.dat", "rb");
    if (fpm == NULL) {
        return 0;
    }
    for (i = 0; i < 55; i++) {
        if (fread(&mesaPecas[i], sizeof(int), 1, fpm) != 1) {
            fclose(fpm);
            return 0;
        }
    }
    fclose(fpm);
    
    //le a situacao geral do jogo
    fps = fopen("CAD_JOGO.dat", "rb");
    if (fps == NULL) {
        return 0;
    }
    if (fread(&sitJogo, sizeof(SituacaoJogo), 1, fps) != 1) {
        fclose(fps);
        return 0;
    }
    fclose(fps);
    
    //restaura as variaveis globais do Model a partir da struct lida
    qtdeMesa = sitJogo.qtmesaJogo;
    mesaD = sitJogo.mesaDJogo;
    mesaE = sitJogo.mesaEJogo;
    pontaE = sitJogo.pontaEJogo;
    pontaD = sitJogo.pontaDJogo;
    
    return 1;
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
            case 4:
                continuarPartida();
                break;
            case 0:
                break;
            default:
                mostrarOpcaoInvalida();
                break;
        }
    } while (opcao != 0);
}
