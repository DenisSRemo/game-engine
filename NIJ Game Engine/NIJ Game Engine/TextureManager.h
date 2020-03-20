#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "SDL.h"
#include <string>
#include <map>

class TextureManager
{
public:
	
	

	static TextureManager* GetInstance()
	{
		return t_instance = (t_instance != nullptr) ? t_instance : new TextureManager();
    }

	bool Load(std::string id, std::string filename);
	void Drop(std::string id);
	void Clean();

	void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	static TextureManager* t_instance;
	TextureManager();
	std::map<std::string, SDL_Texture*>TextureMap;
	
};

#endif
