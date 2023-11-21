#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Jogador {
    char nome[50];
    char simbolo;
    int pontuacao;
};

struct Jogador jogador1, jogador2;

char tabuleiro[3][3];

void inicializarTabuleiro() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void preencherJogadores() {
    printf("Digite o nome do Jogador 1: ");
    scanf("%s", jogador1.nome);
    jogador1.simbolo = 'X';
    jogador1.pontuacao = 0;

    printf("Digite o nome do Jogador 2: ");
    scanf("%s", jogador2.nome);
	jogador2.simbolo = 'O';	
    jogador2.pontuacao = 0;
}

void mostrarTabuleiro() {
    printf("  0 1 2\n");
    for (int i = 0; i < 3; ++i) {
        printf("%d ", i);
        for (int j = 0; j < 3; ++j) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int verificarVitoria() {
    for (int i = 0; i < 3; ++i) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return 1;
        }
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
            return 1; 
        }
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return 1; 
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return 1; 
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tabuleiro[i][j] == ' ') {
                return 0; 
            }
        }
    }
    return -1; 
}

void mostrarRanking() {
    printf("\n--- RANKING ---\n");
    printf("%s: %d ponto(s)\n", jogador1.nome, jogador1.pontuacao);
    printf("%s: %d ponto(s)\n", jogador2.nome, jogador2.pontuacao);
    printf("---------------\n");
}

int main() {
    setlocale(0, "Portuguese");

    int jogadorAtual = 1;
    int linha, coluna;

    inicializarTabuleiro();
    preencherJogadores();

    int opcao;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Jogar\n");
        printf("2. Ver Ranking\n");
        printf("3. Créditos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                do {
                    mostrarTabuleiro();

                    printf("Jogador %s, faça sua jogada escolhendo a linha e a coluna (ex: 1 2): ", (jogadorAtual == 1) ? jogador1.nome : jogador2.nome);
                    scanf("%d %d", &linha, &coluna);

                    if (linha < 0 || linha >= 3 || coluna < 0 || coluna >= 3 || tabuleiro[linha][coluna] != ' ') {
            			printf("Esse local está ocupado ou não existe. Por favor, tente de novo.\n");
            			continue;
        			}
        			
					tabuleiro[linha][coluna] = (jogadorAtual == 1) ? 'X' : 'O';

        			int result = verificarVitoria();

			        if (result == 1) {
			            mostrarTabuleiro();
			            printf("Jogador %s venceu!\n", (jogadorAtual == 1) ? jogador1.nome : jogador2.nome);
			            
			            if (jogadorAtual == 1) {
					    	jogador1.pontuacao++;
					    } else {
					        jogador2.pontuacao++;
					    }
					    
					    inicializarTabuleiro();
					    
			            break;
			        } else if (result == -1) {
			            mostrarTabuleiro();
			            printf("Deu Velha :(\n");
			            
			            inicializarTabuleiro();
			            
			            break;
			        }
			        jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
			        
				} while (1);
                break;
            	
            case 2:
                mostrarRanking();
                break;

            case 3:
                printf("\n------------- CRÉDITOS -------------\n");
                printf("Desenvolvido por:\nErick Chianca \nIsaac Adryan \nMatheus Ramalho \nRyan de Souza\n");
                printf("--------------------------------------\n");
                break;

            case 4:
                printf("Saindo do jogo!\n");
                break;

            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 4);

    return 0;
}

