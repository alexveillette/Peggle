#pragma once

#include "ResourceIDs.h"
#include "Sprite.h"
#include "CCircle.h"

class Ball :
	public Sprite
{
public:
	Ball();
	Ball(float initialRotDeg);
	~Ball();

	void Update();
	void Shoot(float cannonRotation);
	void Bounce();

private:
	float rot;
	float speed;
	float gravity;

	bool isActive;
	D3DXVECTOR3 cannonLength;
	D3DXVECTOR3 currentPos;
	D3DXVECTOR2 mDir;

	CCircle* collider;
};