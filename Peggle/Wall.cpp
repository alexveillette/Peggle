#include "Wall.h"


Wall::Wall()
	: Sprite(Texture::WALL)
{
	this->SetID(Components::Wall);
	D3DXVECTOR3 center(this->GetTextureInfos()->infos.Width / 2, this->GetTextureInfos()->infos.Height / 2, 0.0f);
	this->SetPivot(center);
	this->SetRotationDeg(0, 0, 0);

	collider = new CRectangle(this, 0, 0, 300, 200);
}


Wall::~Wall()
{

}

void Wall::Update()
{


}
