#pragma once

#include "ResourceIDs.h"
#include "Sprite.h"
#include "CCircle.h"

class PigPeg :
	public Sprite
{
public:
	PigPeg();
	~PigPeg();

	void Update();

	//Circle collider
	CCircle* collider;


};

