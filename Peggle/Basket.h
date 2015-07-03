#pragma once
#include "ResourceIDs.h"
#include "Sprite.h"
#include "CRectangle.h"
class Basket :
	public Sprite
{
public:
	Basket();
	~Basket();

	void Update();

private:

	bool movingLeft;
	bool movingSlowly;

	float speed;

	D3DXVECTOR3 dir;
	D3DXVECTOR3 currentPos;

};

