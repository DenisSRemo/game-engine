#pragma once



#include "Character.h"
#include "Animation.h"
#include "Rigidbody.h"

class MainCharacter: public Character
{
public:
	
	MainCharacter(Properties* props);
	
	

	virtual void Draw();
	virtual  void Clean() ;
	virtual  void Update(float dt) ;

private:
	////int m_Row, m_Frame, m_FrameCount;
	////int m_AnimationSpeed;
	Animation* m_animation;









	
	/*Rigidbody* m_rigidbody;*/
	
};

