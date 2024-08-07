#ifndef _LOGIC__H
#define _LOGIC__H

#include "defs.h"
#include <bits/stdc++.h>
using namespace std;

struct Tictactoe {
    char board[BOARD_SIZE][BOARD_SIZE];
    Status fill[BOARD_SIZE][BOARD_SIZE];
    pair<int, int> oldClicked;
    bool clickExists = false;
    bool clickMusic = true;
    char nextMove = selectNextMove();
    void init ();
    void move (int row, int col);
    char selectNextMove ();
    bool checkWin (char board[][BOARD_SIZE]);
    bool checkWinRow (char board[][BOARD_SIZE], int i, int j);
    bool checkWinColumn (char board[][BOARD_SIZE], int i, int j);
    bool checkWinCross (char board[][BOARD_SIZE], int i, int j);
    int count = 0;
};

#endif // _LOGIC__H
