#pragma once

#include "Vector2D.h"

#define  UNIT_MASS 1.0f
#define GRAVITY 10.0f
#define  FORWARD 1
#define  BACKWORD -1

class Rigidbody
{
public:
	Rigidbody()
	{
		Mass = UNIT_MASS;
		Gravity = GRAVITY;
	}
	

	inline void SetMass(float mass) { Mass = mass; }
	inline void SetGravity(float gravity) { Gravity = gravity; }

	inline void ApplyForce(Vector2D F) { Force = F; }
	inline void ApplyForceX(float Fx) { Force.X = Fx; }
	inline void ApplyForceY(float Fy) { Force.Y = Fy; }
	inline void UnSetForce() { Force = Vector2D(0, 0); }

	inline void ApplyFriction(Vector2D Fr) { Friction = Fr; }
	inline void UnSetFriction() { Friction = Vector2D(0, 0); }

	inline float GetMass() { return Mass; }
	inline Vector2D Position() { return  m_Position; }
	inline Vector2D Velocity() { return m_Velocity; }


	

	void Update(float dt)
	{
		m_Acceleration.X = (Force.X + Friction.X) / Mass;
		m_Acceleration.Y = Gravity + Force.Y / Mass;
		m_Velocity = m_Acceleration * dt;
		m_Position = m_Velocity * dt;
	}

private:
	float Mass;
	float Gravity;

	Vector2D Force;
	Vector2D Friction;

	Vector2D m_Position;
	Vector2D m_Velocity;
	Vector2D m_Acceleration;
};

