#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "logic.h"
using namespace std;

void Tictactoe::init() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_CELL;
            filled[i][j] = false;
        }
    }

}

void Tictactoe::move(int row, int column) {
    if (row >= 0 && row < BOARD_SIZE && column >= 0 && column < BOARD_SIZE) {
        if (filled[row][column] == false) {
            board[row][column] = nextMove;
            nextMove = (nextMove == O_CELL) ? X_CELL : O_CELL;
            filled[row][column] = true;
        }
    }
}

bool Tictactoe::checkWin(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board [i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY_CELL) return true;
    }
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == board [1][j] && board[1][j] == board[2][j] && board[0][j] != EMPTY_CELL) return true;
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2])
        || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
            if (board[1][1] != EMPTY_CELL) return true;
        }
    return false;
}
