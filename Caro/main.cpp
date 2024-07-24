#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"

using namespace std;

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

void processClick(int x, int y, Tictactoe& game) {
    // chuyển tọa độ màn hình x, y thành tọa độ hàng cột của game
    int clickedCol = (x - BOARD_X) / CELL_SIZE;
    int clickedRow = (y - BOARD_Y) / CELL_SIZE;
    game.move(clickedRow, clickedCol);
}


int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();

    graphics.play(graphics.gMusic);

    Tictactoe game;
    game.init();
    graphics.render(game);

    int x, y;
    SDL_Event event;
    bool quit = false;
    while (! quit) {
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                 quit = true;
                 break;
            case SDL_MOUSEBUTTONDOWN:
                 SDL_GetMouseState(&x, &y);
                 processClick(x, y, game);
                 graphics.playClickMusic(game);
                 //if (game.nextMove == X_CELL) graphics.play(graphics.gClickX);
                 //if (game.nextMove == O_CELL) graphics.play(gClickO);
                 graphics.render(game);
                 break;
        }
        //SDL_Delay(100);
    }

    if (graphics.gMusic != nullptr) Mix_FreeMusic(graphics.gMusic);
    if (graphics.gClickX != nullptr) Mix_FreeChunk(graphics.gClickX);
    if (graphics.gClickO != nullptr) Mix_FreeChunk(graphics.gClickO);
    graphics.quit();
    return 0;
}

