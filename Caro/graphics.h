#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "logic.h"

struct Graphics {
    SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Texture *background;
	SDL_Texture *cellEmpty, *cellX, *cellO;
	SDL_Texture *win, *lose;

	void logErrorAndExit(const char* msg, const char* error);
	void initSDL();
	void init();
	void prepareScene(SDL_Texture * background);
    void presentScene();
    SDL_Texture *loadTexture(const char *filename);
    void renderTexture(SDL_Texture *texture, int x, int y);
    void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);
    void quit();
    void render(Tictactoe &game);
};

#endif // _GRAPHICS__H
