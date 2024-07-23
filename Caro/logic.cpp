#include <iostream>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>
#include "logic.h"
using namespace std;

void Tictactoe::init() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_CELL;
            fill[i][j] = NOTFILLED;
        }
    }

}

void Tictactoe::move(int row, int column) {
    if (row >= 0 && row < BOARD_SIZE && column >= 0 && column < BOARD_SIZE) {
        if (fill[row][column] == NOTFILLED) {
            if (clickExists == false) {
                board[row][column] = EMPTY_CELL_CLICK;
                fill[row][column] = CLICKED;
                oldClicked = {row, column};
                clickExists = true;
            } else {
                board[oldClicked.first][oldClicked.second] = EMPTY_CELL;
                fill[oldClicked.first][oldClicked.second] = NOTFILLED;
                board[row][column] = EMPTY_CELL_CLICK;
                fill[row][column] = CLICKED;
                oldClicked = {row, column};
            }
        } else if (fill[row][column] == CLICKED) {
            board[row][column] = nextMove;
            nextMove = (nextMove == O_CELL) ? X_CELL : O_CELL;
            fill[row][column] = FILLED;
            clickExists = false;
        }
    }
}

char Tictactoe::selectNextMove () {
    srand(time(NULL));
    int random = rand() % 2;
    nextMove = (random == 0) ? 'O' : 'X';
    return nextMove;
}

bool Tictactoe::checkWinRow (char board[][BOARD_SIZE], int i, int j) {
    char cell = board[i][j];
    if (cell != EMPTY_CELL && cell != EMPTY_CELL_CLICK && j <= BOARD_SIZE - 5) {
        for (int position = j; position <= j + 3; position++) {
            if (board[i][position] != board[i][position + 1]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Tictactoe::checkWinColumn (char board[][BOARD_SIZE], int i, int j) {
    char cell = board[i][j];
    if (cell != EMPTY_CELL && cell != EMPTY_CELL_CLICK && i <= BOARD_SIZE - 5) {
        for (int position = i; position <= i + 3; position++) {
            if (board[position][j] != board[position + 1][j]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Tictactoe::checkWinCross (char board[][BOARD_SIZE], int i, int j) {
    char cell = board[i][j];
    if (cell != EMPTY_CELL && cell != EMPTY_CELL_CLICK && i <= BOARD_SIZE - 5) {
        if (j - 4 >= 0) {
            for (int add = 0; add <= 3; add++) {
                if (board[i + add][j - add] != board[i + add + 1][j - add -1]) return false;
            }
            return true;
        }
        if (j + 4 < BOARD_SIZE) {
            for (int add = 0; add <= 3; add++) {
                if (board[i + add][j + add] != board[i + add + 1][j + add +1]) return false;
            }
            return true;
        }
    }
    return false;
}

bool Tictactoe::checkWin(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (checkWinRow(board, i ,j) || checkWinColumn (board, i, j) || checkWinCross(board, i, j)) return true;
        }
    }
    return false;

}
