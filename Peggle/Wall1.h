#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"
#include "CRectangle.h"

class Wall1 :
	public Sprite
{
public:
	Wall1();
	~Wall1();

	void Update();

	//Rectangle Collider
	CRectangle* collider;

private:
	D3DXVECTOR3 pivot;

};

