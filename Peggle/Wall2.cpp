#include "Wall2.h"


Wall2::Wall2()
	: Sprite(Texture::WALL)
{
	//Setting ID and collider.
	this->SetID(Components::Wall);
	CRectangle* wallCollider2 = new CRectangle(this, -(int)gApp->GetParam().BackBufferWidth / 2 - 75, -500.f, 100, 1000);
}


Wall2::~Wall2()
{

}

void Wall2::Update()
{


}
