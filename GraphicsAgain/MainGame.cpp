#include "MainGame.h"
#include <iostream>
#include "Errors.h"





MainGame::MainGame()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHeight = 768;
	_gameState = GameState::PLAY;
}


MainGame::~MainGame()
{
}


void MainGame::run()
{
	initSystems();
	_sprite.init(-1.0f, -1.0f, 1.0f, 1.0f);
	gameLoop();
}


void MainGame::initSystems()
{
	//Init SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
	if (_window == nullptr){
	fatalError("SDL Window failed to create!");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr){
	fatalError("SDL_GL context could not be created!");
	}

	GLenum error = glewInit();
	if (error != GLEW_OK){
	fatalError("Could not initialize glew!");
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}


void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
	processInput();
	drawGame();
	}

}


void MainGame::processInput()
{
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt) == 1){
	switch (evnt.type){
	case SDL_QUIT:
	_gameState = GameState::EXIT;
	break;
	case SDL_MOUSEMOTION:
	std::cout << "X: "<< evnt.motion.x << " " << "Y: " << evnt.motion.y << std::endl;
	break;
	}
	}
}


void MainGame::drawGame()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_sprite.draw();


	SDL_GL_SwapWindow(_window);

}