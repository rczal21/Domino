//DHIR - Projeto Domino 

/*O sistema deverá montar as peças do dominó com a numeração correta do jogo
Deverá permitir ao usuário embaralhar as peças do dominó, e permitir ao usuário a 
iniciar uma nova partida embaralhando novamente as peças
O sistema deverá permitir ao usuário mostrar todas as peças do dominó na tela
de forma organizada (em ordem) e tambem embaralhada. (modo texto)
O sistema deverá estar estruturado no modelo MVC.
O sistema deverá ser projetado de forma suficientemente modularizada para 
facilitar a manutenção e alterações sem impactar os demais módulos do sistema.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

	// Modelo de peca
	struct Peca
			{
				int lado1;
				int lado2;
				char status;
			} pecas[28];
	
	// Apresenta as pecas no momento atual de embaralhamento
	void mostrarPecas(Peca pecas[], int n){
		for(int i = 0; i < n; i++){
			printf(" Peca %d: [%d|%d]\n", i , pecas[i].lado1, pecas[i].lado2);
		}
}
	
	// Embaralha as pecas
	void embaralhar(Peca pecas[], int n){
		for(int i = 27; i > 0; i--){
			int j = rand() % (i + 1);	
				Peca temp = pecas[i];
				pecas[i] = pecas[j];
				pecas[j] = temp;
		}
	}
	
	void organizar(Peca pecas[]){
			int indice = 0;
			for(int i = 0; i < 7; i ++){
				for(int j = i; j < 7; j++){
					pecas[indice].lado1 = i;
					pecas[indice].lado2 = j;
					indice++;
				}
			}
		}
	
	
	int main(){
		srand(time(NULL)); // Muda o sorteio toda vez que o código é inicializado
		organizar(pecas);
			
/*			int resposta;
			for(int i = 0; i <= 4; i++){
				printf("Mostrar pecas em ordem ou embaralhadas? (digite 1 ou 2)\n");
				scanf("%d",  &resposta);
			
			
				if(resposta == 1){
					organizar(pecas);
					mostrarPecas(pecas, 28);
				}
				
				else {
					embaralhar(pecas, 28);
					mostrarPecas(pecas, 28);
				}
			}
			
*/	
}
	
