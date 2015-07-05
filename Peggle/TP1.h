#pragma once
#include "Component.h"
#include "Engine.h"
#include "Sprite.h"
#include "ResourceIDs.h"
#include "Ball.h"
#include "PigPeg.h"
#include "Cannon.h"
#include "Basket.h"
#include "MousePeg.h"
#include "LadyPeg.h"
#include "Wall1.h"
#include "Wall2.h"
#include "Wall3.h"
#include "CRectangle.h"
#include "StartScreen.h"

class Peggle :
	public Component
{
public:
	Peggle();
	~Peggle();

	void Start();
	void Update();
	void Draw();
	void Stop();

	void InitBoard();
	float screenWidth;
	float screenHeight;

	bool gameStarted = false;

private:
	StartScreen* startScreen;
};