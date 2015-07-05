#include "PigPeg.h"


PigPeg::PigPeg()
	: Sprite(Texture::PIGPEG)
{
	//Setting ID, initial position, pivot, collider and rotate it so the sprite is not upside down.
	this->SetID(Components::PigPeg);
	float radius = 8;
	collider = new CCircle(this, 0, 0, radius);
	SetPivot(D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0));
	SetRotationDeg(0, 0, 180.f);
}

PigPeg::~PigPeg()
{
}

void PigPeg::Update()
{
	//Setting collider.
	D3DXVECTOR3 currentPos = GetPosition();
	collider->SetPosition(currentPos.x, currentPos.y);
}



