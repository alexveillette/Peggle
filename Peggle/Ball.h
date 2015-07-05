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

	int GetNumberOfLives(){ return numberOfLives; }

	void RestartGame();
private:
	float rot;
	float speed;
	float gravity;
	bool isActive;

	//This int manages the number of lives the player has.
	int numberOfLives;

	D3DXVECTOR3 cannonLength;
	D3DXVECTOR3 currentPos;
	D3DXVECTOR2 mDir;

	//Circle collider
	CCircle* collider;
};