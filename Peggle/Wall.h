#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"
#include "CRectangle.h"
class Wall :
	public Sprite
{
public:
	Wall();
	~Wall();

	//Circle Collider
	CRectangle* collider;

private:
	D3DXVECTOR3 pivot;
};

