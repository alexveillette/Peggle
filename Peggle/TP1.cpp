#include "TP1.h"

Peggle::Peggle()
{
	Textures->LoadTexture(Texture::CANNON, "cannon.png");
	Textures->LoadTexture(Texture::CANNONBALL, "cannonball.png");
	Textures->LoadTexture(Texture::PIGPEG, "pigpeg.png");
	Textures->LoadTexture(Texture::MOUSEPEG, "mousepeg.png");
	Textures->LoadTexture(Texture::LADYPEG, "ladypeg.png");
	Textures->LoadTexture(Texture::BASKET, "basket.png");
	Textures->LoadTexture(Texture::SKY, "skyback.jpg");


	Ball* ball = new Ball();
	Cannon* cannon = new Cannon();
	Peg* peg = new Peg();


}

Peggle::~Peggle()
{
}

void Peggle::Start()
{}

void Peggle::Update()
{

}

void Peggle::Draw()
{}

void Peggle::Stop()
{}
