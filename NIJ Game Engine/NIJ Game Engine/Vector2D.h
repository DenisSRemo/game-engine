#pragma once

#include <iostream>



class Vector2D
{
public:
	Vector2D(float x=0,float y=0): X(x),Y(y){};
	

	float X, Y;
	inline Vector2D operator+(const Vector2D& v2 )const
	{
		return Vector2D(X + v2.X, Y + v2.Y);
	}

	inline Vector2D operator-(const Vector2D& v2)const
	{
		return Vector2D(X - v2.X, Y - v2.Y);
	}

	inline Vector2D operator*(const float scalar)const
	{
		return Vector2D(X * scalar, Y * scalar);
	}

	inline Vector2D operator/(const float scalar)const
	{
		return Vector2D(X /scalar, Y /scalar);
	}
	
	void Log(std::string mag="")
	{
		std::cout << mag << "(x y)=(" << X << " " << Y << ")" << std::endl;
	}

	
	
};

