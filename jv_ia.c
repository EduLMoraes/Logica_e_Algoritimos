#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void escreve_tab(char t[3][3]);
int vitoria(char tab[3][3], char vez);
int empate(char t[3][3]);
int gerar_score(char t[3][3]);
int minmax(char t[3][3], int maximizar);

int main() {
	char t[3][3];
	for (int L=0 ; L<3 ; L++)
		for (int C=0 ; C<3 ; C++)
			t[L][C] = ' ';
	int qtd_jogadas = 0;
	char vez = 'X';
	
	while (1) {
		escreve_tab(t);
		
		int L, C;
		if (vez == 'X') { // Se for a vez do jogador humano...
			do {
				printf("Turno do %c. Escolha uma posição: ", vez);
				scanf("%d %d", &L, &C);
			} while (L<0 || L>2 || C<0 || C>2 || t[L][C]!=' '); // Trata jogadas inválidas.
		}
		else { // Se for a vez do jogador IA...
			printf("Turno do %c. Processando scores: {", vez);
			
			// Inicia o minmax.
			L = C = -1;
			int melhor_score = -2;
			for (int i=0 ; i<3 ; i++) { // Navega no tabuleiro procurando espaços vazios para jogar.
				for (int j=0 ; j<3 ; j++) {
					if (t[i][j] == ' ') {
						t[i][j] = 'O';               // Marca uma posição disponível.
						int score = minmax(t, 0);    // Avalia essa posição (recursivamente).
						printf("%d, ", score);
						usleep(100000);
						t[i][j] = ' ';               // Desfaz a jogada (pois estou fazendo no próprio tabuleiro).
						
						if (score > melhor_score) {  // Melhor jogada até o momento.
							melhor_score = score;
							
							L = i;
							C = j;
						}
					}
				}
			}
			printf("\b\b} Pronto!\n");
			sleep(1);
		}
		
		// Marca a jogada no tabuleiro.
		if (L == -1 || C == -1) // Nunca deve acontecer, mas...
			return -1;
		t[L][C] = vez;
		
		// Testa as 8 condições de vitória.
		if (vitoria(t, vez)) {
			escreve_tab(t);
			printf("Vitória do %c!\n", vez);
			break;
		}
		else if (empate(t)) {
			escreve_tab(t);
			printf("Empate.\n");
			break;
		}
			
		if (vez == 'X')
			vez = 'O';
		else // vez=='O'
			vez = 'X';
	}
}

void escreve_tab(char t[3][3]) {
	// Apaga a tela antes de começar um novo turno.
	printf("\033[2J"); // ANSI escape sequence to clear screen
	printf("\033[H");  // Move cursor to the home position
	
	printf("     |     |\n");
	printf("  %c  |  %c  |  %c\n", t[0][0], t[0][1], t[0][2]);
	printf("_____|_____|_____\n");
	printf("     |     |\n");
	printf("  %c  |  %c  |  %c\n", t[1][0], t[1][1], t[1][2]);
	printf("_____|_____|_____\n");
	printf("     |     |\n");
	printf("  %c  |  %c  |  %c\n", t[2][0], t[2][1], t[2][2]);
	printf("     |     |\n\n");
}

int vitoria(char t[3][3], char vez) {
	for (int i=0 ; i<3 ; i++)
		if (t[i][0]==vez && t[i][1]==vez && t[i][2]==vez)
			return 1;
	for (int i=0 ; i<3 ; i++)
		if (t[0][i]==vez && t[1][i]==vez && t[2][i]==vez)
			return 1;
	if (t[0][0]==vez && t[1][1]==vez && t[2][2]==vez ||
		t[0][2]==vez && t[1][1]==vez && t[2][0]==vez)
		return 1;
	
	return 0;
}

int empate(char t[3][3]) {
	for (int i=0 ; i<3 ; i++)
		for (int j=0 ; j<3 ; j++)
			if (t[i][j] == ' ')
				return 0;
	return 1;
}

int gerar_score(char t[3][3]) {
	if (vitoria(t, 'O'))
		return 1;
	else if (vitoria(t, 'X'))
		return -1;
	else
		return 0;
}	

int minmax(char t[3][3], int maximizar) {
	int score = gerar_score(t);
	
	if (score != 0)
		return score;
	if (empate(t))
		return 0;
	
	if (maximizar) {
		int melhor_score = -1;
		for (int i=0 ; i<3 ; i++) { // Navega no tabuleiro procurando espaços vazios para jogar.
			for (int j=0 ; j<3 ; j++) {
				if (t[i][j] == ' ') {
					t[i][j] = 'O';               // Marca uma posição disponível.
					int score = minmax(t, 0);    // Avalia essa posição (recursivamente).
					t[i][j] = ' ';               // Desfaz a jogada (pois estou fazendo no próprio tabuleiro).
					
					if (score > melhor_score) {  // Melhor jogada até o momento.
						melhor_score = score;
					}
				}
			}
		}
		return melhor_score;
	}
	else {
		int pior_score = 1;
		for (int i=0 ; i<3 ; i++) {
			for (int j=0 ; j<3 ; j++) {
				if (t[i][j] == ' ') {
					t[i][j] = 'X';
					int score = minmax(t, 1);
					t[i][j] = ' ';
					
					if (score < pior_score) {
						pior_score = score;
					}
				}
			}
		}
		return pior_score;
	}
}