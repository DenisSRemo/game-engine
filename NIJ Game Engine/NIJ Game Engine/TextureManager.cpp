#include "TextureManager.h"
#include <SDL_image.h>
#include "SDL.h"
#include "Game.h"
#include <stdio.h>
#include <string>

TextureManager* TextureManager::t_instance = nullptr;

TextureManager::TextureManager()
{
	
}


bool TextureManager::Load(std::string id, std::string filename)
{
	SDL_Surface* surface = SDL_LoadBMP(filename.c_str());
	if (surface == nullptr)
	{
		SDL_Log("failed surface");
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::GetInstance()->GetRenderer(), surface);
	
	if(texture==nullptr)
	{
		SDL_Log("failed texture");
		return false;
	}

	TextureMap[id] = texture;
	
	return true;
	
}


void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
	SDL_Rect srcRect = { 0,0,width,height };
	SDL_Rect destRect = { x,y,width,height };
	SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), TextureMap[id], &srcRect, &destRect,0,NULL,flip);
}



void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip)
{
	SDL_Rect srcRect = { width * frame, height * row, width, height };
	SDL_Rect destRect = { x,y,width,height };
	SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), TextureMap[id], &srcRect, &destRect, 0, nullptr, flip);
}


void TextureManager::Drop(std::string id)
{
	SDL_DestroyTexture(TextureMap[id]);
	TextureMap.erase(id);
}


void TextureManager::Clean()
{
	std::map<std::string, SDL_Texture*>::iterator it;
	for (it = TextureMap.begin(); it != TextureMap.end(); it++)
		SDL_DestroyTexture(it->second);
	TextureMap.clear();

	SDL_Log("texture map clean");
}


