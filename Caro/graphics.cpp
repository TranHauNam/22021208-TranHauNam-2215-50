#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "graphics.h"

void Graphics::logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}

void Graphics::initSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logErrorAndExit("SDL_Init", SDL_GetError());

    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //full screen
    //window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
            logErrorAndExit( "SDL_image error:", IMG_GetError());

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        logErrorAndExit( "SDL_mixer could not initialize! SDL_mixer Error: %s\n",Mix_GetError() );
    }

}

void Graphics::init() {
    initSDL();

    background = loadTexture("images//background.jpg");

    cellEmpty  = loadTexture("images//cell_empty.png");
    cellX  = loadTexture("images//cell_x.png");
    cellO  = loadTexture("images//cell_o.png");
    cellEmptyClick = loadTexture("images//cell_empty_click.png");

    win = loadTexture("images//win.png");
    lose = loadTexture("images//lose.png");

    gMusic = loadMusic("assets\\game_music.mp3");

    gClickX = loadSound("assets\\click_x.mp3");
    gClickO = loadSound("assets\\click_o.mp3");
}

void Graphics::prepareScene(SDL_Texture * background)
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy( renderer, background, NULL, NULL);
}

void Graphics::presentScene()
{
    SDL_RenderPresent(renderer);
}

SDL_Texture* Graphics::loadTexture(const char *filename)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

    SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
    if (texture == NULL)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

    return texture;
}

void Graphics::renderTexture(SDL_Texture *texture, int x, int y)
{
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void Graphics::renderTextureResizeImage(SDL_Texture *texture, SDL_Rect *destRect) {
    SDL_RenderCopy(renderer, texture, nullptr, destRect);
}

void Graphics::blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y)
{
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    dest.w = src->w;
    dest.h = src->h;

    SDL_RenderCopy(renderer, texture, src, &dest);
}

void Graphics::quit()
{
    Mix_Quit();
    SDL_DestroyTexture(cellEmpty);
    cellEmpty = nullptr;
    SDL_DestroyTexture(cellX);
    cellX = nullptr;
    SDL_DestroyTexture(cellO);
    cellO = nullptr;
    cellEmptyClick = nullptr;
    SDL_DestroyTexture(win);
    win = nullptr;
    SDL_DestroyTexture(lose);
    lose = nullptr;

    IMG_Quit();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Graphics::render(Tictactoe& game) {
    prepareScene(background);
    SDL_Rect destRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    //renderTextureResizeImage(background, &destRect);
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int x = BOARD_X + j * CELL_SIZE;
            int y = BOARD_Y + i * CELL_SIZE;
            SDL_Rect cellRect = {x, y, CELL_SIZE, CELL_SIZE};
            switch (game.board[i][j]) {
                case EMPTY_CELL: renderTextureResizeImage(cellEmpty, &cellRect);
                break;
                case X_CELL: renderTextureResizeImage(cellX, &cellRect);
                break;
                case O_CELL: renderTextureResizeImage(cellO, &cellRect);
                break;
                case EMPTY_CELL_CLICK: renderTextureResizeImage(cellEmptyClick, &cellRect);
            };

        };
    }

    if (game.checkWin(game.board)) {
        SDL_RenderClear(renderer);
        renderTextureResizeImage(win, &destRect);
    }
    //else {
    //    renderTextureResizeImage(lose, &destRect);
    //}

    presentScene();
}

Mix_Music* Graphics::loadMusic(const char* path)
{
	Mix_Music* gMusic = Mix_LoadMUS(path);
	if (gMusic == nullptr) {
		SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
			SDL_LOG_PRIORITY_ERROR,
			"Could not load music! SDL_mixer Error: %s", Mix_GetError());
	}
	return gMusic;
}

void Graphics::play(Mix_Music* gMusic)
{
	if (gMusic == nullptr) return;

	if (Mix_PlayingMusic() == 0) {
		Mix_PlayMusic(gMusic, -1);
	}
	else if (Mix_PausedMusic() == 1) {
		Mix_ResumeMusic();
	}
}

Mix_Chunk* Graphics::loadSound(const char* path) {
    Mix_Chunk* gChunk = Mix_LoadWAV(path);
    if (gChunk == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
            SDL_LOG_PRIORITY_ERROR,
            "Could not load sound! SDL_mixer Error: %s", Mix_GetError());
    }
}
void Graphics::play(Mix_Chunk* gChunk) {
    if (gChunk != nullptr) {
        Mix_PlayChannel(-1, gChunk, 0);
    }
}

void Graphics::playClickMusic (Tictactoe& game) {
    if (game.nextMove == X_CELL) play(gClickX);
    if (game.nextMove == O_CELL) play(gClickO);
}


