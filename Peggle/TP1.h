#pragma once
#include "Component.h"
#include "Engine.h"
#include "Sprite.h"
#include "ResourceIDs.h"
#include "Ball.h"
#include "Peg.h"
#include "Cannon.h"

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
};