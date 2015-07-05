#include "Ball.h"
#include "PigPeg.h"
#include "LadyPeg.h"
#include "MousePeg.h"


Ball::Ball()
	: Sprite(Texture::CANNONBALL)
	, rot(0)
	, speed(300.0f)
	, isActive(false)
	, gravity(0.981f)
	, numberOfLives(3)
{
	//Circle Collider at (0, 0) with a radius of 8.0;
	this->SetID(Components::Ball);
	D3DXVECTOR3 center(this->GetTextureInfos()->infos.Width / 2, this->GetTextureInfos()->infos.Height / 2, 0.0f);
	collider = new CCircle(this, 0, 0, 8.f);

	//Setting pivot and initial rotation.
	SetPivot(D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0));
	SetRotationDeg(0, 0, 180);


	
}

Ball::Ball(float initialRotDeg)
	: Sprite(Texture::CANNONBALL)
	, rot(initialRotDeg)
	, speed(300.0f)
	, isActive(false)
	, gravity(300.1f)
	, numberOfLives(3)
{
	//Circle Collider at (0, 0) with a radius of 8.0;
	this->SetID(Components::Ball);
	D3DXVECTOR3 center(this->GetTextureInfos()->infos.Width / 2, this->GetTextureInfos()->infos.Height / 2, 0.0f);
	collider = new CCircle(this, 0, 0, 8.f);

	//Setting pivot and initial rotation.
	SetPivot(D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0));
	SetRotationDeg(0, 0, rot);
}

Ball::~Ball()
{
}

void Ball::Update()
{
	//Moving collider to fit ball sprite.
	collider->SetPosition(currentPos.x, currentPos.y);

	currentPos = GetPosition();
	float dt = gTimer->GetDeltaTime();

	if (isActive)
	{
		//Go through each collider collided with though the LookForCollision Function
		for each (Collider* col in collider->LookForCollisions())
		{
			if (col->GetGameObject()->GetID() == Components::PigPeg)
			{
				//Ball bumps into Pig peg.
				mDir = D3DXVECTOR2(GetPosition().x, GetPosition().y) - col->GetPosition();
				D3DXVec2Normalize(&mDir, &mDir);
				AudioSys->play2D(Sounds->Get(Sound::oink));
			}
			else if (col->GetGameObject()->GetID() == Components::MousePeg)
			{
				//Ball bumps into Mouse peg.
				mDir = D3DXVECTOR2(GetPosition().x, GetPosition().y) - col->GetPosition();
				D3DXVec2Normalize(&mDir, &mDir);
				AudioSys->play2D(Sounds->Get(Sound::eek));
			}
			else if (col->GetGameObject()->GetID() == Components::LadyPeg)
			{
				//Ball bumps into Ladybug peg.
				mDir = D3DXVECTOR2(GetPosition().x, GetPosition().y) - col->GetPosition();
				D3DXVec2Normalize(&mDir, &mDir);
				AudioSys->play2D(Sounds->Get(Sound::squish));
			}
			else if (col->GetGameObject()->GetID() == Components::Wall)
			{
				//Ball bumps into WALL.
				if ((GetPosition().y > 0))
				{
					mDir = D3DXVECTOR2((GetPosition().x) * -1 / 20, (GetPosition().y) * -1);
					D3DXVec2Normalize(&mDir, &mDir);
				}
				else 
				{
					mDir = D3DXVECTOR2((GetPosition().x * -1) / 20, (GetPosition().y));
					D3DXVec2Normalize(&mDir, &mDir);
				}
				
			}
			else if (col->GetGameObject()->GetID() == Components::Basket)
			{
				//Gives ball back if falls into basket.
				currentPos.x = 0;
				currentPos.y = gApp->GetParam().BackBufferHeight / 1.75f - 20.f;
				isActive = false;
				AudioSys->play2D(Sounds->Get(Sound::yay));
			}	
		}

		//Moving Sprite.
		mDir.y -= gravity * dt;
		currentPos.x += mDir.x * speed * dt;
		currentPos.y += mDir.y * speed * dt;
		
		SetPosition(currentPos.x, currentPos.y);

		//Reset ball if it falls into the pit + LOSE A LIFE.
		if (currentPos.y < -300)
		{
			isActive = false;
			SetPosition(0, gApp->GetParam().BackBufferHeight / 1.75f - 20.f);
			numberOfLives--;
			AudioSys->play2D(Sounds->Get(Sound::boo));
		}
	}
}

void Ball::Shoot(float cannonRotation)
{
	// If enough lives remain, the ball is shot out of the cannon.
	//It has the cannon's initial rotation and comes out from the mouth.
	if (!isActive && numberOfLives >= 1)
	{
		SetPosition(0, gApp->GetParam().BackBufferHeight / 1.75f - 20.f);
		isActive = true;
		rot = cannonRotation + (90 * PI / 180);
		cannonLength = D3DXVECTOR3(cos(rot), sin(rot), 0.f) * 140.0f;
		isActive = true;
		SetPosition(currentPos.x + cannonLength.x, currentPos.y + cannonLength.y);
		mDir = D3DXVECTOR2(cos(rot), sin(rot));
	}
}

void Ball::RestartGame()
{
	numberOfLives = 3;
}
