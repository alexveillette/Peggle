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
{
	//Circle Collider at (0, 0) with a radius of 8.0;
	this->SetID(Components::Ball);
	D3DXVECTOR3 center(this->GetTextureInfos()->infos.Width / 2, this->GetTextureInfos()->infos.Height / 2, 0.0f);
	collider = new CCircle(this, 0, 0, 8.f);

	SetPivot(D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0));
	SetRotationDeg(0, 0, 180);
	
}

Ball::Ball(float initialRotDeg)
	: Sprite(Texture::CANNONBALL)
	, rot(initialRotDeg)
	, speed(300.0f)
	, isActive(false)
	, gravity(300.1f)
{
	//Circle Collider at (0, 0) with a radius of 8.0;
	this->SetID(Components::Ball);
	D3DXVECTOR3 center(this->GetTextureInfos()->infos.Width / 2, this->GetTextureInfos()->infos.Height / 2, 0.0f);
	collider = new CCircle(this, 0, 0, 8.f);

	SetPivot(D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0));
	SetRotationDeg(0, 0, rot);
}

Ball::~Ball()
{
}

void Ball::Update()
{
	
	currentPos = GetPosition();

	//MOVING COLLIDER
	collider->SetPosition(currentPos.x, currentPos.y);
	
	float dt = gTimer->GetDeltaTime();

	if (isActive)
	{
		//Go through each collider collided with though the LookForCollision Function
		for each (Collider* col in collider->LookForCollisions())
		{
			mDir = D3DXVECTOR2(GetPosition().x, GetPosition().y) - col->GetPosition();
			D3DXVec2Normalize(&mDir, &mDir);
			//If one of the collider is a peg
			if (col->GetGameObject()->GetID() == Components::Peg)
			{
			}
		}
		mDir.y -= gravity * dt;
		currentPos.x += mDir.x * speed * dt;
		currentPos.y += mDir.y * speed * dt;
		
		SetPosition(currentPos.x, currentPos.y);
	}
}

void Ball::Shoot(float cannonRotation)
{
	if (isActive)
	{
		rot = cannonRotation + (90 * PI/180) ;
		isActive = false;
	}
	else
	{
		rot = cannonRotation + (90 * PI / 180);
		cannonLength = D3DXVECTOR3(cos(rot), sin(rot), 0.f) * 140.0f;
		isActive = true;
		SetPosition(currentPos.x + cannonLength.x, currentPos.y + cannonLength.y);
		mDir = D3DXVECTOR2(cos(rot), sin(rot));
	}
}

void Ball::Bounce()
{

}