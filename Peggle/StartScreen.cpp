#include "StartScreen.h"


StartScreen::StartScreen()
	: Sprite(Texture::STARTSCREEN)
{
	SetPivot(D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0));
	SetRotationDeg(0, 0, 180.f);
}

StartScreen::~StartScreen()
{
}

void StartScreen::Update()
{

}
