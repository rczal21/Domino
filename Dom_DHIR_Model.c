/* Dom_DHIR_Model

 Daniel Luís de Amorim Mariano Santos,
Henrique Campos Rodrigues,
Isabella de Souza Fleury,
Rafaella Castro Zandona Alves de Lima */

 
#include "Dom_DHIR_Model.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
 

// Define o array
Peca pecas[28];
int qtdeJogadores;
int mesaE = -1;
int mesaD = -1;

int pontaE = 27; // serve para marcar a ponta da mesa, para mostrar a mesa na ordem das jogadas
int pontaD = 27;

int qtdeMesa;
int mesaPecas[55]; // para caber uma possivel partida de 28 peças de um unico lado do array
char jogadorComeca;
 
// Embaralha as pecas
void embaralhar(){
    for(int i = 27; i > 0; i--){
        int j = rand() % (i + 1);
        Peca temp = pecas[i];
        pecas[i] = pecas[j];
        pecas[j] = temp;
    }
}
 
void gerarPeca(){
    int indice = 0;
    for(int i = 0; i < 7; i++){
        for(int j = i; j < 7; j++){
            pecas[indice].ladoE = i;
            pecas[indice].ladoD = j;
            pecas[indice].status = 'M'; // manda direto pra monte
            indice++;
        }
    }
}
 
void inicializarAleatorio() {
    srand(time(NULL));
}
 
void distribuir(){
    
    for(int i = 0; i < 7; i++){
        pecas[i].status = '1';
    }
    for(int i = 7; i < 14; i++){
        pecas[i].status = '2';
    }
    for(int i = 14; i < 28; i++){
        pecas[i].status = 'M';  // monte
    }
}


char primeiraJogada(){
    int i;
    int maior1 = -1;
    int numPeca1 = -1;
    pontaE = 27;
    pontaD = 27;
    
    
    for(i = 0; i < 7; i++){
            if (pecas[i].ladoE == pecas[i].ladoD){
                if (pecas[i].ladoE >= maior1){
                    maior1 = pecas[i].ladoE;
                    numPeca1 = i; // enumera a maior peca
                }
            }
        }
    
    
    
    int maior2 = -1;
    int numPeca2 = -1;
    
    for(i = 7; i < 14; i++){
        if (pecas[i].ladoE == pecas[i].ladoD){
            if (pecas[i].ladoE >= maior2){
                maior2 = pecas[i].ladoE;
                numPeca2 = i;
            }
        }
    }
    
    if (maior1 < maior2){
        pecas[numPeca2].status = 'T';
        mesaE = pecas[numPeca2].ladoE;
        mesaD = pecas[numPeca2].ladoD;
        jogadorComeca = '2';
        qtdeMesa = 1;
        mesaPecas[27] = numPeca2;
    }
        
    else if (maior2 < maior1) {
        pecas[numPeca1].status = 'T';
        mesaE = pecas[numPeca1].ladoE;
        mesaD = pecas[numPeca1].ladoD;
        jogadorComeca = '1';
        qtdeMesa = 1;
        mesaPecas[27] = numPeca1;
    }
        
    else{
        for (i = 0; i < 7; i++){
            if (pecas[i].ladoE + pecas[i].ladoD > maior1){
                maior1 = pecas[i].ladoE + pecas[i].ladoD;
                numPeca1 = i;
            }
        }
        
        for (i = 7; i < 14; i++){
            if (pecas[i].ladoE + pecas[i].ladoD > maior2){
                maior2 = pecas[i].ladoE + pecas[i].ladoD;
                numPeca2 = i;
            }
        }
        
        if (maior1 > maior2){
            pecas[numPeca1].status = 'T';
            mesaE = pecas[numPeca1].ladoE;
            mesaD = pecas[numPeca1].ladoD;
            jogadorComeca = '1';
            qtdeMesa = 1;
            mesaPecas[27] = numPeca1;
        }
            
        else {
            pecas[numPeca2].status = 'T';
            mesaE = pecas[numPeca2].ladoE;
            mesaD = pecas[numPeca2].ladoD;
            jogadorComeca = '2';
            qtdeMesa = 1;
            mesaPecas[27] = numPeca2;
        }
    }
    
    return jogadorComeca; //devolve o numero do jogador inicial
}

void jogarPecas(int i, char lado){
    if (lado == 'D'){
        int pontaAtual = mesaD;
        if (pecas[i].ladoE == pontaAtual){
            mesaD = pecas[i].ladoD ;
        }
        else if(pecas[i].ladoD == pontaAtual){
            int temp = pecas[i].ladoD; //inverte a peca
            pecas[i].ladoD = pecas[i].ladoE;
            pecas[i].ladoE = temp;
            mesaD = pecas[i].ladoD;
        }
    
        pontaD++;
        mesaPecas[pontaD] = i;
        qtdeMesa++;
    }
    else if (lado == 'E'){
        int pontaAtual = mesaE;
        if (pecas[i].ladoE == pontaAtual){
            int temp = pecas[i].ladoE; //inverte a peca
            pecas[i].ladoE = pecas[i].ladoD;
            pecas[i].ladoD = temp;
            mesaE = pecas[i].ladoE;
        } else if(pecas[i].ladoD == pontaAtual){
            mesaE = pecas[i].ladoE;
        }
        
        pontaE--;
        mesaPecas[pontaE] = i;
        qtdeMesa++;
    }
    pecas[i].status = 'T';
}

bool jogadaValida(int i, char lado){
    if (lado == 'D'){
        if (pecas[i].ladoE == mesaD || pecas[i].ladoD == mesaD){
            return true;
        }
    
        else{
            return false;
        }
    }
    else if(lado == 'E'){
        if (pecas[i].ladoE == mesaE || pecas[i].ladoD == mesaE){
            return true;
        }
            
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
int tentarJogar(int indicePeca, char lado) {
    if (lado == 'E' || lado == 'e') {
        int valorMesa = pecas[mesaPecas[pontaE]].ladoE;
        
        if (pecas[indicePeca].ladoD == valorMesa) {
            pontaE--;
            mesaPecas[pontaE] = indicePeca;
            pecas[indicePeca].status = 'M';
            return 1;
        } 
        else if (pecas[indicePeca].ladoE == valorMesa) {
            int temp = pecas[indicePeca].ladoE;
            pecas[indicePeca].ladoE = pecas[indicePeca].ladoD;
            pecas[indicePeca].ladoD = temp;
            
            pontaE--;
            mesaPecas[pontaE] = indicePeca;
            pecas[indicePeca].status = 'M';
            return 1;
        }
    } 
    else if (lado == 'D' || lado == 'd') {
        int valorMesa = pecas[mesaPecas[pontaD]].ladoD;
        
        if (pecas[indicePeca].ladoE == valorMesa) {
            pontaD++;
            mesaPecas[pontaD] = indicePeca;
            pecas[indicePeca].status = 'M';
            return 1;
        } 
        else if (pecas[indicePeca].ladoD == valorMesa) {
            int temp = pecas[indicePeca].ladoE;
            pecas[indicePeca].ladoE = pecas[indicePeca].ladoD;
            pecas[indicePeca].ladoD = temp;
            
            pontaD++;
            mesaPecas[pontaD] = indicePeca;
            pecas[indicePeca].status = 'M';
            return 1;
        }
    }
    
    return 0;
}

int comprarPeca(char jogador) {
    for (int i = 0; i < 28; i++) {
        if (pecas[i].status == 'M') {
            pecas[i].status = jogador;
            return 1;
        }
    }
    return 0;
}

int contarPecas(char jogador) {
    int contador = 0;
    for (int i = 0; i < 28; i++) {
        if (pecas[i].status == jogador) {
            contador++;
        }
    }
    return contador;
}

