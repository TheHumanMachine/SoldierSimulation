#pragma once
#include "Sprite.h"
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <string>
#include <iostream>
#include "Errors.h"

enum class GameState{ PLAY, EXIT };


class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();



private:
	void initSystems();
	void gameLoop();
	void processInput();
	void drawGame();
	int _screenWidth;
	int _screenHeight;
	SDL_Window* _window;
	GameState _gameState;
	Sprite _sprite;

};
