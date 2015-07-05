#pragma once

#include "ResourceIDs.h"
#include "Sprite.h"


class StartScreen :
	public Sprite
{
public:
	StartScreen();
	~StartScreen();

	void Update();
};

