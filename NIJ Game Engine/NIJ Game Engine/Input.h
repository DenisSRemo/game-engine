#pragma once
#include<unordered_map>
#include "Vector2D.h"
#include<SDL.h>
class Input
{
public:
	
//	void update();
//
//	void pressKey(unsigned int keyID);
//	void releaseKey(unsigned int keyID);
//
//	void setMouseCoords(float x, float y);
//
//	/// Returns true if the key is held down
//	bool isKeyDown(unsigned int keyID);
//
//	/// Returns true if the key was just pressed
//	bool isKeyPressed(unsigned int keyID);
//
//	//getters
//	Vector2D getMouseCoords() const { return mouseCoords; }
//private:
//	/// Returns true if the key is held down
//	bool wasKeyDown(unsigned int keyID);
//
//	std::unordered_map<unsigned int, bool> _keyMap;
//	std::unordered_map<unsigned int, bool> _previousKeyMap;
//	Vector2D mouseCoords;
//
//



	static Input* GetInstance()
	{
		return s_Instance = ( s_Instance != nullptr )? s_Instance : new Input();
	}

	void Listen();
	bool GetKeyDown(SDL_Scancode key);
	~Input();

private:
	
	Input();
	void KeyUp();
	void KeyDown();
	const Uint8* m_KeyStates;
	static Input* s_Instance;

	
};

