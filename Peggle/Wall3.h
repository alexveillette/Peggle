#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"
#include "CRectangle.h"

class Wall3 :
	public Sprite
{
public:
	Wall3();
	~Wall3();

	void Update();

	//Rectangle Collider
	CRectangle* collider;

private:
	D3DXVECTOR3 pivot;

};