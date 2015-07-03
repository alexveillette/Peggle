#include "Wall.h"


Wall::Wall()
	: Sprite(Texture::WALL)
{
	SetPivot(D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0));
	SetRotationDeg(0, 0, 180);
}


Wall::~Wall()
{
}
