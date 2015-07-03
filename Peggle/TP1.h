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
#include "Wall.h"

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
};