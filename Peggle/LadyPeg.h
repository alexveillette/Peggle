#pragma once
#include "ResourceIDs.h"
#include "Sprite.h"
#include "CCircle.h"

class LadyPeg :
	public Sprite
{
public:
	LadyPeg();
	~LadyPeg();

	void Update();

	//Circle collider
	CCircle* collider;
};