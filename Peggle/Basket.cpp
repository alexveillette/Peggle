#include "Basket.h"

const float INITIAL_HEIGHT = -275.0f;


Basket::Basket()
	: Sprite(Texture::BASKET)
	, movingLeft(true)
	, movingSlowly(false)
	, speed(200.f)
{
	SetPosition(0, INITIAL_HEIGHT);
	SetPivot(D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0));
	SetRotationDeg(0, 0, 180.f);
}


Basket::~Basket()
{
}


void Basket::Update()
{
	float dt = gTimer->GetDeltaTime();
	currentPos = GetPosition();

	if (movingLeft && currentPos.x <= -250.f && movingSlowly == false)
	{
		speed = 100.f;
		movingSlowly = true;
	}

	if (!movingLeft && currentPos.x > 250.f && movingSlowly == false)
	{
		speed = 100.f;
		movingSlowly = true;
	}

	if (currentPos.x < -300)
	{
		speed = 200.f;
		movingLeft = false;
		movingSlowly = false;
		
	}
	else if (currentPos.x > 300)
	{
		speed = 200.f;
		movingLeft = true;
		movingSlowly = false;
	}

	if (movingLeft)
	{
		dir = D3DXVECTOR3(-1.f, 0.f, 0.f);
		
	}
	else
	{
		dir = D3DXVECTOR3(1.f, 0.f, 0.f);
	}

	currentPos.x += (dir.x) * speed * dt;
	SetPosition(currentPos.x, currentPos.y);
}