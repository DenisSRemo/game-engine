#include "Input.h"
#include "Game.h"


Input* Input::s_Instance = nullptr;

Input::Input()
{
	/*mouseCoords.X = 0;
	mouseCoords.Y = 0;*/
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}


Input::~Input()
{
}






bool Input::GetKeyDown(SDL_Scancode key)
{
	if (m_KeyStates[key] == 1)
	{
		return true;
	}
	return false;
}
void Input::KeyDown()
{
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}

void Input::KeyUp()
{
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}

void Input::Listen()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:Game::GetInstance()->Quit();break;
		case SDL_KEYDOWN:KeyDown(); break;
		case SDL_KEYUP:KeyUp();break;
		}
	}
}























//
//
//void Input::update() {
//	// Loop through _keyMap using a for each loop, and copy it over to _previousKeyMap
//	for (auto& it : _keyMap) {
//		_previousKeyMap[it.first] = it.second;
//	}
//}
//
//void Input::pressKey(unsigned int keyID) {
//	// Here we are treating _keyMap as an associative array.
//	// if keyID doesn't already exist in _keyMap, it will get added
//	_keyMap[keyID] = true;
//}
//
//void Input::releaseKey(unsigned int keyID) {
//	_keyMap[keyID] = false;
//}
//
//void Input::setMouseCoords(float x, float y) {
//	mouseCoords.X = x;
//	mouseCoords.Y = y;
//}
//
//bool Input::isKeyDown(unsigned int keyID) {
//	// We dont want to use the associative array approach here
//	// because we don't want to create a key if it doesnt exist.
//	// So we do it manually
//	auto it = _keyMap.find(keyID);
//	if (it != _keyMap.end()) {
//		// Found the key
//		return it->second;
//	}
//	else {
//		// Didn't find the key
//		return false;
//	}
//}
//
//bool Input::isKeyPressed(unsigned int keyID) {
//	// Check if it is pressed this frame, and wasn't pressed last frame
//	if (isKeyDown(keyID) == true && wasKeyDown(keyID) == false) {
//		return true;
//	}
//	return false;
//}
//
//bool Input::wasKeyDown(unsigned int keyID) {
//	// We dont want to use the associative array approach here
//	// because we don't want to create a key if it doesnt exist.
//	// So we do it manually
//	auto it = _previousKeyMap.find(keyID);
//	if (it != _previousKeyMap.end()) {
//		// Found the key
//		return it->second;
//	}
//	else {
//		// Didn't find the key
//		return false;
//	}
//}
