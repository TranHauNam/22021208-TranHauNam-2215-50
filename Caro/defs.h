#ifndef _DEFS__H
#define _DEFS__H

const int SCREEN_WIDTH = 780;
const int SCREEN_HEIGHT = 780;
#define WINDOW_TITLE "Tictactoe"
#define BOARD_X 40
#define BOARD_Y 40
#define CELL_SIZE 35
#define BOARD_SIZE 20
#define EMPTY_CELL ' '
#define EMPTY_CELL_CLICK 'C'
#define X_CELL 'X'
#define O_CELL 'O'
enum Status {
    NOTFILLED,
    CLICKED,
    FILLED
};

#endif
