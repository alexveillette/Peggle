#include "MousePeg.h"


MousePeg::MousePeg()
	: Sprite(Texture::MOUSEPEG)
{
	this->SetID(Components::Peg);
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
	D3DXVECTOR3 currentPos = GetPosition();
	collider->SetPosition(currentPos.x, currentPos.y);
}