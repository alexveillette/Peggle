#include "TP1.h"

Peggle::Peggle()
{
	//Creating textures.
	Textures->LoadTexture(Texture::CANNON, "cannon.png");
	Textures->LoadTexture(Texture::CANNONBALL, "cannonball.png");
	Textures->LoadTexture(Texture::PIGPEG, "pigpeg.png");
	Textures->LoadTexture(Texture::MOUSEPEG, "mousepeg.png");
	Textures->LoadTexture(Texture::LADYPEG, "ladypeg.png");
	Textures->LoadTexture(Texture::BASKET, "basket.png");
	Textures->LoadTexture(Texture::SKY, "skyback.jpg");
	Textures->LoadTexture(Texture::WALL, "woodwall.png");
	Textures->LoadTexture(Texture::STARTSCREEN, "startscreen.jpg");
	Textures->LoadTexture(Texture::GAMEOVER, "gameoverscreen.png");
	Textures->LoadTexture(Texture::LIVESFONT, "livesfont.png");
	Textures->LoadTexture(Texture::LIVESNUMBER1, "lives1.png");
	Textures->LoadTexture(Texture::LIVESNUMBER2, "lives2.png");
	Textures->LoadTexture(Texture::LIVESNUMBER3, "lives3.png");

	//Loading sounds.
	Sounds->LoadSound(Sound::intro, "intro.mp3");
	Sounds->LoadSound(Sound::stage, "stage.mp3");
	Sounds->LoadSound(Sound::gameOver, "gameover.mp3");
	Sounds->LoadSound(Sound::yay, "crowdyay.mp3");
	Sounds->LoadSound(Sound::boo, "crowdboo.mp3");
	Sounds->LoadSound(Sound::eek, "eek.wav");
	Sounds->LoadSound(Sound::oink, "oink.wav");
	Sounds->LoadSound(Sound::squish, "squish.wav");

	//Defining screen width and height.
	screenWidth = (int)gApp->GetParam().BackBufferWidth / 2;
	screenHeight = (int)gApp->GetParam().BackBufferHeight / 2;

	//Creating Start screen.
	startScreen = new StartScreen();
	AudioSys->play2D(Sounds->Get(Sound::intro));

}

Peggle::~Peggle()
{
}

void Peggle::Start()
{
}

void Peggle::Update()
{
	if (gDInput->keyPressed(DIK_SPACE))
	{
		if (!gameStarted)
		{
			InitBoard();
			gameStarted = true;
			startScreen->SetVisible(false);
			AudioSys->stopAllSounds();
			AudioSys->play2D(Sounds->Get(Sound::stage));
		}
	}
	
}

void Peggle::Draw()
{
}

void Peggle::Stop()
{
}

void Peggle::InitBoard()
{
	//Setting sky sprite background.
	Sprite* skyBack = new Sprite(Texture::SKY);
	skyBack->SetPosition(-900, -500);

	// Init PEGS

	//PigPeg1.
	PigPeg* pigPeg = new PigPeg();
	pigPeg->SetPosition(0, screenHeight / 3);

	//MousePeg1+2.
	for (int i = -50; i <= 50; i += 100)
	{
		MousePeg* mousePeg = new MousePeg();
		mousePeg->SetPosition(i, 50);
	}

	//PigPeg2+3+4.
	for (int i = -100; i <= 100; i += 100)
	{
		PigPeg* pigPeg = new PigPeg();
		pigPeg->SetPosition(i, 0);
	}

	//MousePeg3+4+5+6.
	for (int i = -150; i <= 150; i += 100)
	{
		MousePeg* mousePeg = new MousePeg();
		mousePeg->SetPosition(i, -50);
	}

	//PigPeg5+6+7+8.
	for (int i = -200; i <= 200; i += 100)
	{
		PigPeg* pigPeg = new PigPeg();
		pigPeg->SetPosition(i, -100);
	}
	
	//MousePeg7+8+9+10+11.
	for (int i = -250; i <= 250; i += 100)
	{
		MousePeg* mousePeg = new MousePeg();
		mousePeg->SetPosition(i, -150);
	}

	//LadyPeg1+2.
	for (int i = -250; i <= 250; i += 500)
	{
		LadyPeg* ladyPeg = new LadyPeg();
		ladyPeg->SetPosition(i, 75);
	}

	//LadyPeg3+4.
	for (int i = -300; i <= 300; i += 600)
	{
		LadyPeg* ladyPeg = new LadyPeg();
		ladyPeg->SetPosition(i, -50);
	}


	// Init WALLS

	//Wall1+collider.
	Wall1* wall1 = new Wall1();
	wall1->SetPosition(screenWidth - 30, -500.f);
	
	
	//Wall2+collider.
	Wall2* wall2 = new Wall2();
	wall2->SetPosition(-screenWidth - 100, -500.f);

	
	////Wall3+collider.
	Wall3* wall3 = new Wall3();
	wall3->SetPosition(500.f, screenHeight - 20.f);
	wall3->SetRotationDeg(0, 0, 90.f);

	//Init CANNON + BASKET.
	Cannon* cannon = new Cannon();
	Basket* basket = new Basket();
	
}