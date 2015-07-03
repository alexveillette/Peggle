#include "Cannon.h"

Cannon::Cannon()
	: Sprite(Texture::CANNON)
	, pivot(GetTextureInfos()->infos.Width / 2, 0, 0)
	, rotation(180)
	, rotationRad(0)
{
	SetPivot(pivot);
	SetRotationDeg(0, 0, rotation);
	SetPosition(0, gApp->GetParam().BackBufferHeight / 1.75f - 20.f) ;
	b = new Ball();
	b->SetPosition(0, gApp->GetParam().BackBufferHeight / 1.75f);
}


Cannon::~Cannon()
{
}

void Cannon::Update()
{
	if (gDInput->keyDown(DIK_RIGHT))
	{
		rotation += 100.0f * gTimer->GetDeltaTime();
		if (rotation > 240.0f)
		{
			rotation = 240.0f;
		}
	}

	if (gDInput->keyDown(DIK_LEFT))
	{
		rotation -= 100.0f * gTimer->GetDeltaTime();
		if (rotation < 120.0f)
		{
			rotation = 120.0f;
		}
	}

	if (gDInput->keyPressed(DIK_SPACE))
	{
		rotationRad = rotation * PI / 180;
		b->SetPosition(GetPosition().x, GetPosition().y);
		b->Shoot(rotationRad);
	}
	SetRotationDeg(0, 0, rotation);

}