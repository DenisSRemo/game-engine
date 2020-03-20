#include "Game.h"
#include "Timer.h"


int main(int argc, char* argv[])
{



	Game::GetInstance()->Init();
	while(Game::GetInstance()->isRunning())
	{
		Game::GetInstance()->Events();
		Game::GetInstance()->Update();
		Game::GetInstance()->Render();
		
	}


	Game::GetInstance()->Clean();







	
	return 0;
}