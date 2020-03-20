#include "Game.h"
#include "TextureManager.h"
#include "Vector2D.h"
#include "Transform.h"
#include "MainCharacter.h"
#include "Input.h"
#include "SDL.h"
#include "Timer.h"

Game* Game::instance = nullptr;
MainCharacter* player = nullptr;
bool Game::Init()
{
	
	if(SDL_Init(SDL_INIT_VIDEO)!=0 &&IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG)!=0)
	{
		SDL_Log("Faliled");
		return false;
	}
	window = SDL_CreateWindow("NIJ ENGINE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if(window==nullptr)
	{
		SDL_Log("failed window");
		return false;
	}
	
		
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		SDL_Log("failed renderer",SDL_GetError());
		return false;
	}
	/////////////////////////////////////////////
	////////////////////////////////////////////
    //  TextureManager::GetInstance()->Load("tree", "..\\Assets\\image.bmp");

	////////////////////////////////////////////////
	////////////////////////////////////////////////


	/*TextureManager::GetInstance()->Load("player", "..\\Assets\\stay.bmp");
	TextureManager::GetInstance()->Load("player_run", "..\\Assets\\running.bmp");
	player = new MainCharacter(new Properties("player", 100, 200, 508, 101));*/     //player animation
	
	  TextureManager::GetInstance()->Load("player", "..\\Assets\\run.bmp");
	  player = new MainCharacter(new Properties("player", 100, 200, 81, 100));
	return  IsRunning = true;
}


void Game::Update()
{
	/*float dt = Timer::GetInstance()->GetDeltaTime();*/
	player->Update(0);   // player animation update
	
}


void Game::Events()
{
	Input::GetInstance()->Listen();
		
}

void Game::Render()
{
	SDL_SetRenderDrawColor(renderer, 124, 218, 254, 255);
	SDL_RenderClear(renderer);
	//TextureManager::GetInstance()->Draw("tree", 100, 100, 500, 500);
	player->Draw();
	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	
}


void Game::Quit()
{
	IsRunning = false;
}



