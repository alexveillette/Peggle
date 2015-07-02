#pragma once

#include "ResourceIDs.h"
#include "Sprite.h"

class Ball :
	public Sprite
{
public:
	Ball();
	Ball(float initialRotDeg);
	~Ball();

	void Update();

private:
	float rot;
	float speed;

};

