#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* replaces the propers numbers in the grid */
void placenumbers(char game[]);
void set_game(int n);
void replace_XO(char c);
int game_on(void);
int switchturn(void);
void restart(void);

int turn = 1;

void tictactoe(void) {

    extern char game[];
    char c;
    set_game(3);
    replacenum();
    printf("%s", game);
    while (1) {
        while (game_on()) {
            if (isdigit(c = getchar())) {
                replace_XO(c);
            }
        }
        restart();
    }
}

/* take a number for example 3, 4 or 5 and makes a grid accordingly */
void set_game(int n) {

    /* declarations */
    extern char game[];
    int rows, cols, height, blank, btmedge;

    /* implementations */
    if (n) {
        /* the number of rows */
        for (rows = 1; rows < n; rows++) {
            /* the height of every portion */
            for (height = 1; height < 3; height++) {
                /* number of columns */
                if (height == 2) { /* the number in the portions */
                    for (cols = 0; cols < n; cols++) {
                        if (cols == (n-1))
                            strcat(game, "   N   ");
                        else
                            strcat(game, "   N   |");
                    }
                    strcat(game, "       \n");
                } else {    /* the empty spaces around the numbers */
                    for (blank = 1; blank < n; blank++) {
                        strcat(game, "       |");
                    }
                    strcat(game, "       \n");
                }
            }
            /* The bottom edge of every row */
            for (btmedge = 1; btmedge < n; btmedge++) {
                strcat(game, "_______|");
            }
            /* The bottom edge of the last column */
            strcat(game, "_______\n");
        }


        /* the last row */
        /* the height of the last row */
        for (height = 0; height < 3; height++) {
            /* number of columns of the last row*/
            for (cols = 0; cols < n; cols++) {
                if (cols == (n-1)) { /* the edges of the last row and column */
                    if (height == 1)
                        strcat(game, "   N   ");
                    else
                        strcat(game, "       ");
                } else { /* the edges of the last row */
                    if (height == 1)
                        strcat(game, "   N   |");
                    else
                        strcat(game, "       |");
                }

            }
            strcat(game, "       \n");
        }
    }
    strcat(game, "\n\n\n");
    strcat(game, "Statement           \n");
    strcat(game, "============================\n");
    strcat(game, "(Player name): (Points)     \n");
    strcat(game, "(Player name): (Points)     \n");
    strcat(game, "============================\n");
    strcat(game, "[R]Restart      [X]Exit     \n");
    strcat(game, "[L]Records                  \n");
}

void replacenum(void)
{
    extern char game[];
    char numsymbol, num;

    numsymbol = 'N';
    num = '1';
    for (int i = 0;game[i] != '\0'; i++){
        if (game[i] == 'N') {
            game[i] = num++;
        }
    }
}

void replace_XO(char c)
{
    extern char game[];

    for (int i = 0;game[i] != '='; i++){
        if (game[i] == c) {
            game[i] = (switchturn()) ? 'X' : 'O';
            system("cls");
            printf("%s", game);
        }
    }
}

int switchturn(void)
{
    extern int turn;

    if (turn == 1) {
        --turn;
        return 1;
    } else {
        ++turn;
        return 0;
    }
}

int game_on(void)
{
    extern char game[];
    char status = 0;

    for (int i = 0; game[i] != '='; i++){
        if (isdigit(game[i])) {
            status += 1;
        }
    }
    return status;
}

void restart(void)
{
    extern char game[];
    char num, c;
    num = '1';
    for (int i = 0; game[i] != '='; i++){
        if (game[i] == 'X') {
            game[i] = num++;
        } else if (game[i] == 'O') {
            game[i] = num++;
        }
    }
    system("cls");
    printf("%s", game);
}

/*
********Questions before starting the game*********
Single player or multi player?
------------------------------------------------------------
Single player             Multi player
-----------------------   ----------------------------------
Please Enter your name:   Player X, please Enter your names:
X or O?                   Player O, please Enter your names:
------------------------------------------------------------



********The interface*********
           |       |
       1   |   2   |   3
    _______|_______|_______
           |       |
       4   |   5   |   6
    _______|_______|_______
           |       |
       7   |   8   |   9
           |       |


           Statement
================================
    (Player name): (Points)
    (Player name): (Points)
================================
    [R]Restart      [X]Exit
    [L]Records

            - By hitting numbers 1 to 9 They should be replaced by X or O
            - The player who gets these numbers, wins:
            123 - 456 - 789 - 741 - 852 -963 -753 - 951
            - After winning, 1 point adds up to the right player name
            - The statement part changes to these sentences:
            It's (Player name)'s turn - (Player name) won - draw
            - By changing the screens, the game screen save the last state
            so you can come back to it.

********Questions after hitting "R" or "X"*********
Are you sure? [Y/N]



********The records page*********
========================================
Name          Points        Date
------------  ------------  ------------
Reza Kahba..  65 (Highest)  10/19/2021
Ashkan        16 (Lowest)   10/19/2021
========================================
Name          Points        Date
------------  ------------  ------------
Ashkan        16            10/19/2021
Iman          22            10/19/2021
Reza Kahba..  65            10/19/2021
----------------------------------------
                [B]Back

*/
