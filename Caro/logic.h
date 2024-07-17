#ifndef _LOGIC__H
#define _LOGIC__H

#define BOARD_SIZE 15
#define EMPTY_CELL ' '
#define X_CELL 'x'
#define O_CELL 'o'



struct Tictactoe {
    //bool win = false;
    char board[BOARD_SIZE][BOARD_SIZE];
    bool filled[BOARD_SIZE][BOARD_SIZE];
    char nextMove = O_CELL;
    void init ();
    void move (int row, int col);
    bool checkWin (char board[][BOARD_SIZE]);
};

#endif // _LOGIC__H
