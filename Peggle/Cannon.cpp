#include "Cannon.h"

Cannon::Cannon()
	: Sprite(Texture::CANNON)
	, pivot(GetTextureInfos()->infos.Width / 2, 0, 0)
	, rotation(180)
{
	SetPivot(pivot);
	SetRotationDeg(0, 0, rotation);
	SetPosition(0, gApp->GetParam().BackBufferWidth / 4);
}


Cannon::~Cannon()
{
}

void Cannon::Update()
{
	if (gDInput->keyDown(DIK_RIGHT))
	{
		rotation += 30.0f * gTimer->GetDeltaTime();
	}

	if (gDInput->keyDown(DIK_LEFT))
	{
		rotation -= 30.0f * gTimer->GetDeltaTime();
	}

	if (gDInput->keyPressed(DIK_SPACE))
	{
		Ball* b = new Ball(rotation);
		b->SetPosition(GetPosition().x, GetPosition().y);
	}

	SetRotationDeg(0, 0, rotation);

	std::cout << rotation << std::endl;
}