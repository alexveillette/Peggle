#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"
#include "CRectangle.h"

class Wall2 :
	public Sprite
{
public:
	Wall2();
	~Wall2();

	void Update();

	//Rectangle Collider
	CRectangle* collider;

private:
	D3DXVECTOR3 pivot;

};