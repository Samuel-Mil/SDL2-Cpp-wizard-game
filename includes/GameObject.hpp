#pragma once
#include "Game.hpp"

class GameObject{
private:
	int xpos;
	int ypos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
public:
	GameObject(const char* textureSheet, int x, int y);
	~GameObject();
	void Update();
	void Render();
};