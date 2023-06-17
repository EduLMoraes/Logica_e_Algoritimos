#include <stdio.h>

int checkVictory(char tab[3][3], char turn)
{
    int vit[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Linhas
        {0, 3, 6},{1, 4, 7},{2, 5, 8}, // Colunas
        {0, 4, 8},{2, 4, 6} // Diagonais
    };

    for (int i = 0; i < 8; i++)
    {
        if (tab[vit[i][0] / 3][vit[i][0] % 3] == tab[vit[i][1] / 3][vit[i][1] % 3] &&
            tab[vit[i][1] / 3][vit[i][1] % 3] == tab[vit[i][2] / 3][vit[i][2] % 3] &&
            tab[vit[i][0] / 3][vit[i][0] % 3] == turn)
            return 1;
    }

    return 0;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}


int minmax(char tab[][3], int depth, int is_maximizing_depth, int jogadas)
{
    int max_depth = 6;
    if (depth >= max_depth)
    {
        return 0;
    }
    if (checkVictory(tab, 'X'))
    {
        return -1;
    }
    else if (checkVictory(tab, 'O'))
    {
        return 1;
    }
    else if (jogadas == 9)
    {
        return 0;
    }

    if (is_maximizing_depth){
        int max_eval = -1000000000;

        for (int i = 0; i < 9; i++){
            if (tab[i / 3][i % 3] == ' '){
                tab[i / 3][i % 3] = 'O';
                int eval = minmax(tab, depth + 1, 0, jogadas+1);

                tab[i / 3][i % 3] = ' ';
                max_eval = max(max_eval, eval);
            }
        }
        return max_eval;
    }
    else{
        int min_eval = 1000000000;

        for (int i = 0; i < 9; i++){
            if (tab[i / 3][i % 3] == ' '){
                tab[i / 3][i % 3] = 'X';
                int eval = minmax(tab, depth + 1, 1, jogadas+1);

                tab[i / 3][i % 3] = ' ';
                min_eval = min(min_eval, eval);
            }
        }
        return min_eval;
    }
}

void make_move(char (*tab)[3], int jogadas)
{
    int best_eval = -1000000000;
    int best_move = 0;

    for (int i = 0; i < 9; i++){
        if (tab[i / 3][i % 3] == ' '){
            tab[i / 3][i % 3] = 'O';
            int eval = minmax(tab, 0, 0, jogadas);

            tab[i / 3][i % 3] = ' ';

            if (eval > best_eval){
                best_eval = eval;
                best_move = i;
            }
        }
    }
    tab[best_move / 3][best_move % 3] = 'O';
}

int main()
{
    char tab[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tab[i][j] = ' ';
        }
    }

    printf("     |     |\n");
    printf("  %c  |  %c  |  %c\n", tab[0][0], tab[0][1], tab[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |\n");
    printf("  %c  |  %c  |  %c\n", tab[1][0], tab[1][1], tab[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |\n");
    printf("  %c  |  %c  |  %c\n", tab[2][0], tab[2][1], tab[2][2]);
    printf("     |     |\n\n");

    char turno = 'X';
    int jogadas = 0;

    while (1)
    {
        printf("Turno do %c. Digite a posição para jogar: ", turno);
        int linha, coluna;
        scanf("%d %d", &linha, &coluna);
        tab[linha][coluna] = turno;

        make_move(tab, jogadas);

        printf("     |     |\n");
        printf("  %c  |  %c  |  %c\n", tab[0][0], tab[0][1], tab[0][2]);
        printf("_____|_____|_____\n");
        printf("     |     |\n");
        printf("  %c  |  %c  |  %c\n", tab[1][0], tab[1][1], tab[1][2]);
        printf("_____|_____|_____\n");
        printf("     |     |\n");
        printf("  %c  |  %c  |  %c\n", tab[2][0], tab[2][1], tab[2][2]);
        printf("     |     |\n\n");

        if (checkVictory(tab, turno))
        {
            printf("Vitória do %c!!!", turno);
            break;
        }

        jogadas++;
        if (jogadas == 9)
        {
            printf("Empate.");
            break;
        }
    }

    return 0;
}
