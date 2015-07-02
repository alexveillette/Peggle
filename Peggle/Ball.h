#pragma once

#include "ResourceIDs.h"
#include "Sprite.h"

class Ball :
	public Sprite
{
public:
	Ball();
	~Ball();

	void Update();

private:
	D3DXVECTOR3 pivot;

};

