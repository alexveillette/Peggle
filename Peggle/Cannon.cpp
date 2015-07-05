#include "Cannon.h"

Cannon::Cannon()
	: Sprite(Texture::CANNON)
	, pivot(GetTextureInfos()->infos.Width / 2, 0, 0)
	, rotation(180)
	, rotationRad(0)
	, gameOver(false)
{
	//Setting ID, initial position, pivot, collider and rotate it so the sprite is not upside down.
	SetPivot(pivot);
	SetRotationDeg(0, 0, rotation);
	SetPosition(0, gApp->GetParam().BackBufferHeight / 1.75f - 20.f);
	b = new Ball();
	b->SetPosition(0, gApp->GetParam().BackBufferHeight / 1.75f);


	//Creating sprites for lives, lives font and game over screen, placing them, making them invisible.
	livesFont = new Sprite(Texture::LIVESFONT);
	livesFont->SetPosition(-400.f, 200.f);
	livesFont->SetVisible(true);

	livesNumber1 = new Sprite(Texture::LIVESNUMBER1);
	livesNumber1->SetPosition(-285.f, 248.f);
	livesNumber1->SetVisible(false);

	livesNumber2 = new Sprite(Texture::LIVESNUMBER2);
	livesNumber2->SetVisible(false);
	livesNumber2->SetPosition(-285.f, 248.f);

	livesNumber3 = new Sprite(Texture::LIVESNUMBER3);
	livesNumber3->SetPosition(-285.f, 248.f);
	livesNumber3->SetVisible(true);

	StartScreen* startScreen2 = new StartScreen();
	startScreen2->SetVisible(false);

	gameOverScreen = new Sprite(Texture::GAMEOVER);
	gameOverScreen->SetPosition(-512.f, -512.f);
	gameOverScreen->SetVisible(false);
}


Cannon::~Cannon()
{
}

void Cannon::Update()
{
	if (!gameOver)
	{
		//Rotating cannon to the right.
		if (gDInput->keyDown(DIK_RIGHT))
		{
			rotation += 100.0f * gTimer->GetDeltaTime();
			if (rotation > 240.0f)
			{
				rotation = 240.0f;
			}
		}
		//Rotating cannon to the left.
		if (gDInput->keyDown(DIK_LEFT))
		{
			rotation -= 100.0f * gTimer->GetDeltaTime();
			if (rotation < 120.0f)
			{
				rotation = 120.0f;
			}
		}
		//Shooting ball, calls function in ball class.
		if (gDInput->keyPressed(DIK_SPACE))
		{
			rotationRad = rotation * PI / 180;
			b->Shoot(rotationRad);
		}

		SetRotationDeg(0, 0, rotation);

		if (b->GetNumberOfLives() == 3)
		{
			livesNumber3->SetVisible(true);
			livesNumber2->SetVisible(false);
			livesNumber1->SetVisible(false);
		}
		else if (b->GetNumberOfLives() == 2)
		{
			livesNumber3->SetVisible(false);
			livesNumber2->SetVisible(true);
			livesNumber1->SetVisible(false);
		}
		else if (b->GetNumberOfLives() == 1)
		{
			livesNumber3->SetVisible(false);
			livesNumber2->SetVisible(false);
			livesNumber1->SetVisible(true);
		}
		else if (b->GetNumberOfLives() == 0)
		{
			livesNumber3->SetVisible(false);
			livesNumber2->SetVisible(false);
			livesNumber1->SetVisible(false);
			gameOverScreen->SetVisible(true);
			gameOver = true;
			AudioSys->stopAllSounds();
			AudioSys->play2D(Sounds->Get(Sound::boo));
			AudioSys->play2D(Sounds->Get(Sound::gameOver));
		}
	}
	else
	{
		if (gDInput->keyPressed(DIK_SPACE))
		{
			gameOverScreen->SetVisible(false);
			gameOver = false;
			b->RestartGame();
			AudioSys->stopAllSounds();
			AudioSys->play2D(Sounds->Get(Sound::stage));
		}
	}
	

}