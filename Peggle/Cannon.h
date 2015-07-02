#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"

class Cannon :
	public Sprite
{
public:
	Cannon();
	~Cannon();

	void Update();

private:
	D3DXVECTOR3 pivot;
	float rotation;
};

