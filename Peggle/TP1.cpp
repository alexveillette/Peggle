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
	Textures->LoadTexture(Texture::WALL, "woodwall.png");

	screenWidth = (int)gApp->GetParam().BackBufferWidth / 2;
	screenHeight = (int)gApp->GetParam().BackBufferHeight / 2;

	InitBoard();
}

Peggle::~Peggle()
{
}

void Peggle::Start()
{
}

void Peggle::Update()
{

}

void Peggle::Draw()
{
}

void Peggle::Stop()
{
}

void Peggle::InitBoard()
{

	Sprite* skyBack = new Sprite(Texture::SKY);
	skyBack->SetPosition(-900, -500);

	// Init PEGS

	//PigPeg1
	PigPeg* pigPeg = new PigPeg();
	pigPeg->SetPosition(0, screenHeight / 3);

	//MousePeg1+2
	for (int i = -50; i <= 50; i += 100)
	{
		MousePeg* mousePeg = new MousePeg();
		mousePeg->SetPosition(i, 50);
	}

	//PigPeg2+3+4
	for (int i = -100; i <= 100; i += 100)
	{
		PigPeg* pigPeg = new PigPeg();
		pigPeg->SetPosition(i, 0);
	}

	//MousePeg3+4+5+6
	for (int i = -150; i <= 150; i += 100)
	{
		MousePeg* mousePeg = new MousePeg();
		mousePeg->SetPosition(i, -50);
	}

	//PigPeg5+6+7+8
	for (int i = -200; i <= 200; i += 100)
	{
		PigPeg* pigPeg = new PigPeg();
		pigPeg->SetPosition(i, -100);
	}
	
	//MousePeg7+8+9+10+11
	for (int i = -250; i <= 250; i += 100)
	{
		MousePeg* mousePeg = new MousePeg();
		mousePeg->SetPosition(i, -150);
	}

	//LadyPeg1+2
	for (int i = -250; i <= 250; i += 500)
	{
		LadyPeg* ladyPeg = new LadyPeg();
		ladyPeg->SetPosition(i, 75);
	}

	//LadyPeg3+4
	for (int i = -300; i <= 300; i += 600)
	{
		LadyPeg* ladyPeg = new LadyPeg();
		ladyPeg->SetPosition(i, -50);
	}

	// Init WALLS

	Wall* wall1 = new Wall();
	wall1->SetPosition(screenWidth + 50, 0.f);
	Wall* wall2 = new Wall();
	wall2->SetPosition(-screenWidth - 25, 0.f);
	Wall* wall3 = new Wall();
	wall3->SetPosition(0.f, screenHeight + 25.f);
	wall3->SetRotationDeg(0, 0, 90.f);

	//Init CANNON + BASKET
	Cannon* cannon = new Cannon();
	Basket* basket = new Basket();
}