#include "Ball.h"

Ball::Ball()
	: Sprite(Texture::CANNONBALL)
	, rot(0)
	, speed(1000.0f)
{
	SetPivot(D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0));
	SetRotationDeg(0, 0, 180);
}

Ball::Ball(float initialRotDeg)
	: Sprite(Texture::CANNONBALL)
	, rot(initialRotDeg)
	, speed(1000.0f)
{
	SetPivot(D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0));
	SetRotationDeg(0, 0, rot);
}


Ball::~Ball()
{
}

void Ball::Update()
{
	D3DXVECTOR3 currentPos = GetPosition();
	D3DXVECTOR3 dir = D3DXVECTOR3(cos(rot), sin(rot), 0.f);
	float dt = gTimer->GetDeltaTime();

	currentPos.x += dir.x * speed * dt;
	currentPos.y += dir.y * speed * dt;

	SetPosition(currentPos.x, currentPos.y);
}