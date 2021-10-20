#include <stdio.h>
#include <string.h>

char set_ttt(void) {
    extern char game[];
    char cells, width, height;

    cells = 9;
    width = 7;
    height = 3;

    for (int loaded_height = 0; loaded_height < height; loaded_height++){
        for (int loaded_cells = 0; loaded_cells < cells; loaded_cells++) {
            for (int loaded_width = 0; loaded_width <= width; loaded_width++)
                strcat(game, (loaded_width < width)? " " : "|");
        }
        strcat(game, "\n");
    }
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
