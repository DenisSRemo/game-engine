#pragma once


#include "IObject.h"

#include  "Transform.h"
#include <SDL.h>



struct Properties
{
public:
	Properties(std::string textureID,float x, float y, int width, int height,SDL_RendererFlip flip=SDL_FLIP_NONE)
	{
		X = x;
		Y = y;
		Width = width;
		Height = height;
		Flip = flip;
		TextureID = textureID;
	}



	
public:
	float X, Y;
	int Width, Height;
	std::string TextureID;
	SDL_RendererFlip Flip;
};




class GameObject: public IObject
{
public:
	GameObject(Properties* prop)
	{
		m_TextureID = prop->TextureID;
		m_width = prop->Width;
		m_height = prop->Height;
		m_Flip = prop->Flip;
		m_transform = new Transform(prop->X, prop->Y);
	}



	

	virtual void Draw() = 0;
	virtual  void Clean() = 0;
	virtual void Update(float dt) = 0;

protected:
	Transform* m_transform;
	int m_width, m_height;
	std::string m_TextureID;
	SDL_RendererFlip m_Flip;






	
};

