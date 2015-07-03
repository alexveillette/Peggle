#pragma once

#include "ResourceIDs.h"
#include "Sprite.h"
#include "CCircle.h"

class MousePeg :
	public Sprite
{
public:
	MousePeg();
	~MousePeg();

	void Update();

	//Circle collider
	CCircle* collider;

};

