# Domino
Projeto Jogo de dominó em C para o Laboratório de Programação  

Este projeto é uma implementação completa e interativa do clássico Jogo de Dominó para o terminal. Desenvolvido como requisito da disciplina de Laboratório de Programação do 2º período da faculdade, o sistema foi construído utilizando a arquitetura MVC (Model-View-Controller) para garantir a separação rigorosa entre dados, interface e lógica de controle.   

Principais Funcionalidades 

Modos de Jogo: Suporte para partidas entre 2 Jogadores Humanos ou 1 Jogador vs. Computador.   

Inteligência Artificial (PC): O computador simula um oponente real, varrendo apenas a própria mão para decidir a jogada, realizando compras automaticamente e passando a vez quando necessário, sem acessar dados ocultos do jogador adversário.   

Regras Clássicas Aplicadas: O jogo inicia automaticamente pelo jogador que possuir a maior peça dupla (carroça) ou a maior soma. As validações de extremidades esquerda e direita são feitas em tempo real.   

Sistema de Compra: O jogador é obrigado a comprar do monte (caso não tenha peças compatíveis) até encontrar uma peça válida ou até o monte esvaziar.   

Condições de Vitória e Empate: O sistema reconhece vitória por "batida" (0 peças na mão) ou trancamento do jogo (ambos passam a vez, vencendo a menor soma de pontos).   

Salvar e Continuar: Possibilidade de gravar a situação exata da partida (mesa, mãos, jogador da vez e monte) em arquivos binários (.dat) e retomar o jogo posteriormente.   

Estrutura do Projeto (MVC Adaptado)
O projeto está dividido em exatos 7 arquivos, seguindo a estrutura modular exigida:   

Dom_DHIR_PROJETO.cpp: O arquivo principal (Main). Contém apenas as inicializações básicas e o gerador de aleatoriedade (srand), servindo como ponto de partida para o Controlador.   

Dom_DHIR_Model.h / Dom_DHIR_Model.cpp: O coração dos dados. Gerencia a estrutura (struct) das peças, o vetor da mesa, as pontas livres (Esquerda/Direita) e a validação matemática das jogadas. Não possui nenhuma interação com o teclado ou tela.   

Dom_DHIR_View.h / Dom_DHIR_View.cpp: A interface com o usuário. Responsável exclusivamente por exibir os menus, desenhar a mesa, mostrar as peças da mão do jogador atual e capturar opções via teclado (printf e scanf).   

Dom_DHIR_Controller.h / Dom_DHIR_Controller.cpp: O "maestro" do jogo. Faz a ponte entre a View e o Model, gerenciando o fluxo de turnos, o loop da partida, a execução das jogadas do computador e a gravação/leitura de arquivos.   

Instruções de Compilação (Ambiente Dev-C++)
O projeto foi estruturado utilizando uma solução específica de "includes" orientada para o ambiente Dev-C++. Ainda é possível compilar em outros ambientes, como o VS Code. Para rodar o jogo corretamente no Dev C++, siga estritamente os passos abaixo:   

Abra o Dev-C++.
Mantenha todos os 7 arquivos do projeto dentro da mesma pasta.
Abra o arquivo Dom_DHIR_PROJETO.cpp.
Importante: Não tente compilar a partir das abas da View, Model ou Controller. Com a aba do arquivo Dom_DHIR_PROJETO.cpp ativa na tela, pressione F11 (Compilar e Executar).   

O compilador irá ler os cabeçalhos e agrupar os arquivos em memória automaticamente conforme a ordem estabelecida no arquivo principal.
Controles de Jogo
Durante um turno (Jogador Humano), as seguintes opções estarão disponíveis:   

J (Jogar): Solicita o índice da peça desejada e a extremidade (E - Esquerda / D - Direita) para encaixe na mesa.
C (Comprar): Puxa uma peça do monte, caso esteja disponível.
P (Passar): Encerra o turno sem jogar. Só é permitido se o jogador não tiver peças compatíveis e o monte estiver vazio.
G (Gravar e Sair): Salva o estado do jogo nos arquivos CAD_DOMINO.dat, CAD_MESA.dat e CAD_JOGO.dat e retorna ao menu principal.
S (Sair): Abandona a partida em andamento e retorna ao menu inicial sem salvar.
