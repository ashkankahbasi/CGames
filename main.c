#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    /* Tic-Tac-Toe */
    /* Show the game board */
    /* The one with 3 in a row wins */


    /* setting the scores of each players to zero */
    int player1[3][3], player2[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            player1[i][j] = 0;
            player2[i][j] = 0;
        }
    }

    /* Setting the elements of the game board to 0
    and printing the board on the screen */
    char game[300] = "";
    int rows, cols, height, blank, btmedge, n = 3;

    for (rows = 1; rows < n; rows++) {
        for (height = 1; height < 3; height++) {
            if (height == 2) {
                for (cols = 0; cols < n; cols++) {
                    if (cols == (n-1))
                        strcat(game, "   N   ");
                    else
                        strcat(game, "   N   |");
                }
                strcat(game, "       \n");
            } else {
                for (blank = 1; blank < n; blank++) {
                    strcat(game, "       |");
                }
                strcat(game, "       \n");
            }
        }
        for (btmedge = 1; btmedge < n; btmedge++) {
            strcat(game, "_______|");
        }
        strcat(game, "_______\n");
    }
    for (height = 0; height < 3; height++) {
        for (cols = 0; cols < n; cols++) {
            if (cols == (n-1)) {
                if (height == 1)
                    strcat(game, "   N   ");
                else
                    strcat(game, "       ");
            } else {
                if (height == 1)
                    strcat(game, "   N   |");
                else
                    strcat(game, "       |");
            }

        }
        strcat(game, "       \n");
    }
    int board[3][3], cnt = 0;
    char numsymbol, num;
    numsymbol = 'N';
    num = '1';
    for (int i = 0;game[i] != '\0'; i++){
        if (game[i] == 'N') {
            game[i] = num++;
        }
    }
    printf("%s", game);

/*
    int board[3][3], cnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 0;
            cnt++;
            printf("%d\t", board[i][j]);
            if (cnt%3==0) {
                printf("%\n");
            }
        }
    } */

    /* Taking input */
    int input, k, i, j, turn = 1;
    k = 0;
    while (k < 9) {

        /* Winning conditions for player1 */
        /* horizontal */
        if (player1[0][1] != 0 && player1[0][2] != 0 && player1[0][3] != 0) {
            printf("player1 Won the game!\n");
            return 0;
        }
        if (player1[1][1] != 0 && player1[1][2] != 0 && player1[1][3] != 0) {
            printf("player1 Won the game!\n");
            return 0;
        }
        if (player1[2][1] != 0 && player1[2][2] != 0 && player1[2][3] != 0) {
            printf("player1 Won the game!\n");
            return 0;
        }
        /* cross */
        if (player1[0][1] != 0 && player1[1][2] != 0 && player1[2][3] != 0) {
            printf("player1 Won the game!\n");
            return 0;
        }
        if (player1[2][1] != 0 && player1[1][2] != 0 && player1[0][3] != 0) {
            printf("player1 Won the game!\n");
            return 0;
        }
        /* vertical */
        if (player1[0][1] != 0 && player1[1][1] != 0 && player1[2][1] != 0) {
            printf("player1 Won the game!\n");
            return 0;
        }
        if (player1[0][2] != 0 && player1[1][2] != 0 && player1[2][2] != 0) {
            printf("player1 Won the game!\n");
            return 0;
        }
        if (player1[0][3] != 0 && player1[1][3] != 0 && player1[2][3] != 0) {
            printf("player1 Won the game!\n");
            return 0;
        }
        /* Winning conditions for player2 */
        /* horizontal */
        if (player2[0][1] != 0 && player2[0][2] != 0 && player2[0][3] != 0) {
            printf("player2 Won the game!\n");
            return 0;
        }
        if (player2[1][1] != 0 && player2[1][2] != 0 && player2[1][3] != 0) {
            printf("player2 Won the game!\n");
            return 0;
        }
        if (player2[2][1] != 0 && player2[2][2] != 0 && player2[2][3] != 0) {
            printf("player2 Won the game!\n");
            return 0;
        }
        /* cross */
        if (player2[0][1] != 0 && player2[1][2] != 0 && player2[2][3] != 0) {
            printf("player2 Won the game!\n");
            return 0;
        }
        if (player2[2][1] != 0 && player2[1][2] != 0 && player2[0][3] != 0) {
            printf("player2 Won the game!\n");
            return 0;
        }
        /* vertical */
        if (player2[0][1] != 0 && player2[1][1] != 0 && player2[2][1] != 0) {
            printf("player2 Won the game!\n");
            return 0;
        }
        if (player2[0][2] != 0 && player2[1][2] != 0 && player2[2][2] != 0) {
            printf("player2 Won the game!\n");
            return 0;
        }
        if (player2[0][3] != 0 && player2[1][3] != 0 && player2[2][3] != 0) {
            printf("player2 Won the game!\n");
            return 0;
        }

        /* Taking the input */
        scanf("%d", &input);

        for (int i = 0;game[i] != '\0'; i++){
            if (turn == 1) {
                if (isdigit(game[i]) && game[i] == (input + '0')) {
                    game[i] = 'X';
                }
            }
            if (turn == 2) {
                if (isdigit(game[i]) && game[i] == (input + '0')) {
                    game[i] = 'O';
                }
            }
        }


        /* Taking input and storing the data */
        if (input < 1 || input > 9) {
            printf("Invalid input!\n");
        } else {
            /* sending the input to its right position
            in the board */
            i = input / 3;
            j = input % 3;
            board[i][j] = input;
            /* sending the input to its right position
            in each player's log */
            switch (turn) {
            case 1:
                player1[i][j] = input;
                turn++;
                break;
            case 2:
                player2[i][j] = input;
                turn--;
                break;
            }
            system("cls");
            printf("%s", game);
        }
        k++;
    }
}
