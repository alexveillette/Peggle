#include "Ball.h"


Ball::Ball()
	: Sprite(Texture::CANNONBALL)
	, pivot(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0)
{
	SetPivot(pivot);
	SetRotationDeg(0, 0, 180);
}


Ball::~Ball()
{
}

void Ball::Update()
{
	
	
}