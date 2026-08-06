# Domino
Projeto Jogo de dominó em C para o Laboratório de Programação  

Regras do Jogo

Adotaremos as regras mais simples do jogo: apenas 2 jogadores e cada jogador inicia com sete peças obtidas aleatoriamente e pode “comprar” quantas vezes for necessário sempre que precisar de uma peça para poder jogar ou se quiser “blefar”. O jogo inicia-se com o jogador que tiver a peça “seis-seis”. Caso ninguém tenha essa peça, o jogo inicia-se com o jogador que tiver a peça com os números repetidos mais altos, ou seja, “cinco-cinco”, “quatro-quatro”, e assim sucessivamente. Os jogadores vão se alternando e na sua vez devem colocar peças que tenham os mesmos números das peças que se encontram nas 2 extremidades da mesa do jogo. Um conceito importante para a estratégia do dominó é que o jogador que começa a partida leva vantagem.
Antes de cada jogada o jogador pode “comprar” quantas peças quiser do depósito de peças ainda disponíveis, lembrando sempre que perde a partida aquele que no final tiver maior quantidade de peças.
Cada jogador, no seu turno, deve colocar uma das suas peças em uma das 2 extremidades abertas na mesa, de forma que os pontos de um dos lados coincidam com os pontos da extremidade onde está sendo colocada. As peças dobradas são colocadas de maneira transversal para facilitar sua localização (este detalhe não será levado em conta em nossa tela tipo texto). Quando o jogador coloca sua peça sobre a mesa, seu turno se acaba e passa-se então ao próximo jogador.
Se um jogador não puder jogar, deverá “comprar” do depósito das peças ainda disponíveis tantas peças quanto forem necessárias. Se não houver mais peças disponíveis, passará o turno ao outro jogador. Portanto, o jogador só poderá passar a jogada para o seu adversário nessas 2 condições: se ele não possuir nenhuma peça possível de ser colocada na mesa e se não houver mais peças livres a serem compradas.

A partida continua com os jogadores colocando suas peças sobre a mesa até que o estoque de peças disponíveis a serem compradas esteja vazio e além disso, ainda se apresente alguma das seguintes situações:
* Quando um jogador coloca sua última pedra na mesa, essa ação é chamada de bater e ele torna-se o vencedor do jogo.
* Existem casos onde nenhum dos jogadores pode continuar a partida. Isto ocorre quando nenhum dos jogadores tem peça possível de ser lançada na mesa e também o depósito de peças a comprar está vazio (número das extremidades já saiu 7 vezes). Nesse momento se diz que a partida está fechada. Vence aquele que tiver menos peças em seu poder. No caso de empate, os jogadores contarão os pontos (lado1 + lado2) das peças que ficaram; o jogador com menos pontos vence a partida.

Portanto, via de regra: Ao terminar, vence o jogador que tiver a menor quantidade de peças (ou se houver empate, a menor contagem total de pontos).
A única condição da partida terminar empatada (caso raro) é quando os 2 jogadores tiverem a mesma quantidade de peças e a soma (lado1 + lado2) de suas peças forem iguais.
