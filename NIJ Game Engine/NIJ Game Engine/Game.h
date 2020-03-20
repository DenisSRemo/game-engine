


#ifndef GAME_H
#define GAME_H


#include "SDL.h"
#include "SDL_image.h"

#include <iostream>
#include "Input.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


class Game
{
public:
	static Game* GetInstance()
	{
		return instance = (instance != nullptr)? instance : new Game();
	}
	bool Init();
	void Clean();
	void Quit();


	void Update();
	void Render();
	void Events();

	inline bool isRunning() { return IsRunning; }
	inline SDL_Renderer* GetRenderer() { return renderer; }
	

private:
	Game(){}
	bool IsRunning;
	
	static Game* instance;
	SDL_Window* window;

	SDL_Renderer* renderer;
	
};
#endif
