#include "MainCharacter.h"
#include "TextureManager.h"
#include "Input.h"
#include "SDL.h"




MainCharacter::MainCharacter(Properties* props):Character(props)
{
	////m_Row = 0;
	////m_FrameCount = 6;
	////m_AnimationSpeed = 100;
	m_animation = new Animation;
	m_animation->SetProps(m_TextureID, 0, 6, 100);











	
	/*m_rigidbody = new Rigidbody();*/
}



void MainCharacter::Draw()
{
	////TextureManager::GetInstance()->DrawFrame(m_TextureID, m_transform->X, m_transform->Y, m_width, m_height, m_Row, m_Frame);
	m_animation->Draw(m_transform->X,m_transform->Y,m_width,m_height);







	
}

void MainCharacter::Clean()
{
	TextureManager::GetInstance()->Clean();
}


void MainCharacter::Update(float dt)
{
	////m_Frame = (SDL_GetTicks() / m_AnimationSpeed) % m_FrameCount;
	m_animation->Update();






	




	
	/*m_animation->SetProps("player", 1, 1, 100);*/
	/*m_rigidbody->UnSetForce();
	if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A))
	{
		m_rigidbody->ApplyForceX(5*BACKWORD);
		m_animation->SetProps("player_run", 1, 6, 100,SDL_FLIP_HORIZONTAL);
	}


	if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D))
	{
		m_rigidbody->ApplyForceX(5*FORWARD);
		m_animation->SetProps("player_run", 1, 6, 100);
	}*/
	
	
	
	/*m_rigidbody->Update(dt);*/
	/*m_transform->TranslateX(m_rigidbody->Position().X);
	m_transform->TranslateY(m_rigidbody->Position().Y);*/
	
	
}

