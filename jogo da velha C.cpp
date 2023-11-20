#include <stdio.h>
#include <locale.h>

char tabuleiro[3][3]; 

void inicializarTabuleiro() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            tabuleiro[i][j] = ' ';
        }
    }
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

int main() {
	setlocale(0, "Portuguese");
	
    int jogadorAtual = 1; 
    int linha, coluna;

    inicializarTabuleiro();

    do {
        mostrarTabuleiro();

        printf("Jogador %c, faça sua jogada escolhendo a linha e a coluna (ex: 1 2): ", (jogadorAtual == 1) ? 'X' : 'O');
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha >= 3 || coluna < 0 || coluna >= 3 || tabuleiro[linha][coluna] != ' ') {
            printf("Esse local está ocupado ou não existe. Por favor, tente de novo.\n");
            continue;
        }

        tabuleiro[linha][coluna] = (jogadorAtual == 1) ? 'X' : 'O';

        int result = verificarVitoria();

        if (result == 1) {
            mostrarTabuleiro();
            printf("Jogador %c venceu!\n", (jogadorAtual == 1) ? 'X' : 'O');
            break;
        } else if (result == -1) {
            mostrarTabuleiro();
            printf("Deu Velha :(\n");
            break;
        }
        jogadorAtual = (jogadorAtual == 1) ? 2 : 1; 

    } while (1); 

    return 0;
}

