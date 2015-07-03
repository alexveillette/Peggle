#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"
#include "Ball.h"
#include "CRectangle.h"
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
	float rotationRad;
	Ball* b;
};

