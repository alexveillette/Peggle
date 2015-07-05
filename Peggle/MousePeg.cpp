#include "MousePeg.h"


MousePeg::MousePeg()
	: Sprite(Texture::MOUSEPEG)
{
	//Setting ID, initial position, pivot, collider and rotate it so the sprite is not upside down.
	this->SetID(Components::MousePeg);
	float radius = 8;
	collider = new CCircle(this, 0, 0, radius);
	SetPivot(D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0));
	SetRotationDeg(0, 0, 180.f);
}


MousePeg::~MousePeg()
{
}


void MousePeg::Update()
{
	// Setting collider.
	D3DXVECTOR3 currentPos = GetPosition();
	collider->SetPosition(currentPos.x, currentPos.y);
}