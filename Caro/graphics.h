#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "defs.h"
#include "logic.h"

struct Graphics {
    SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Texture *background;
	SDL_Texture *cellEmpty, *cellX, *cellO, *cellEmptyClick;
	SDL_Texture *win, *lose;
	Mix_Music *gMusic;
	Mix_Chunk *gClickX, *gClickO;
	TTF_Font* font;
	SDL_Color color;
	SDL_Texture* helloText;

	void logErrorAndExit(const char* msg, const char* error);
	void initSDL();
	void init();
	void prepareScene(SDL_Texture *background);
    void presentScene();
    SDL_Texture *loadTexture(const char *filename);
    void renderTexture(SDL_Texture *texture, int x, int y);
    void renderTextureResizeImage(SDL_Texture *texture, SDL_Rect *destRect);
    void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);
    void quit();
    void render(Tictactoe &game);
    Mix_Music* loadMusic(const char* path);
    void play(Mix_Music* gMusic);
    Mix_Chunk* loadSound(const char* path);
    void play(Mix_Chunk* gChunk);
    void playClickMusic (Tictactoe& game);
    SDL_Texture* renderText(const char* text, TTF_Font* font, SDL_Color textColor);
    TTF_Font* loadFont(const char* path, int size);
};

#endif // _GRAPHICS__H
