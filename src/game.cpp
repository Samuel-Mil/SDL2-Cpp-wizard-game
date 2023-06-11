#include "../includes/Game.hpp"
#include "../includes/TextureManager.hpp"
#include "../includes/GameObject.hpp"
#include "../includes/Map.hpp"

GameObject* player;
GameObject* enemy;
Map* map;

Game::Game(){}

Game::~Game(){}

SDL_Renderer* Game::renderer = nullptr;

void Game::init(const char* title, int w, int h, bool fullscreen){
    int flags = 0;

    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Subsystems initialised!..." << std::endl;
        
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);
        if(window){
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        isRunning = true;
    }else{
        isRunning = false;
    }

    player = new GameObject("res/player.png", 0, 0);
    enemy = new GameObject("res/enemy.png", 70, 0);
    map = new Map();
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type){
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }
}

void Game::update(){
    player->Update();
    enemy->Update();
}

void Game::render(){
    SDL_RenderClear(renderer);
    map->DrawMap();
    player->Render();
    enemy->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!..." << std::endl;
}