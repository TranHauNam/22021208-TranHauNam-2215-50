#include <iostream>
#include "defs.h"
#include "graphics.h"

using namespace std;

void processClick(int x, int y, Tictactoe& game) {
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

