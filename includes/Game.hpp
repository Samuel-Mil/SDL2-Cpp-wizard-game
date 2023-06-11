#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Game {
private:
    int cnt = 0;
    bool isRunning;
    SDL_Window *window;
public:
    Game();
    ~Game();
    void init(const char* title, int w, int h, bool fullscreen);

    static SDL_Renderer *renderer;

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; };
};
