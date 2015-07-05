#pragma once
#include "Sprite.h"
#include "ResourceIDs.h"
#include "Ball.h"
#include "CRectangle.h"
#include "StartScreen.h"
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

	bool gameOver;


	//Creating sprite pointers so we can reference them in whole class.
	StartScreen* startScreen;
	StartScreen* startScreen2;
	Sprite* gameOverScreen;
	Sprite* livesFont;
	Sprite* livesNumber1;
	Sprite* livesNumber2;
	Sprite* livesNumber3;

};

