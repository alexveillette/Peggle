#include "Wall1.h"


Wall1::Wall1()
	: Sprite(Texture::WALL)
{
	//Setting ID and collider.
	this->SetID(Components::Wall);
	CRectangle* wallCollider = new CRectangle(this, (int)gApp->GetParam().BackBufferWidth / 2 -28, -500.f, 100, 1000);
}


Wall1::~Wall1()
{

}

void Wall1::Update()
{


}
