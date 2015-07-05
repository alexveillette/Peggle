#include "Wall3.h"


Wall3::Wall3()
	: Sprite(Texture::WALL)
{
	//Setting ID and collider.
	this->SetID(Components::Wall);
	CRectangle* wallCollider3 = new CRectangle(this, -500.f, gApp->GetParam().BackBufferHeight / 1.75f + 10.f, 1000, 10);
}


Wall3::~Wall3()
{

}

void Wall3::Update()
{


}
