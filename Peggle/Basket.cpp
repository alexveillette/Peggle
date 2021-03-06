#include "Basket.h"

const float INITIAL_HEIGHT = -275.0f;


Basket::Basket()
	: Sprite(Texture::BASKET)
	, movingLeft(true)
	, movingSlowly(false)
	, speed(200.f)
{
	//Setting ID, initial position, pivot, collider and rotate it so the sprite is not upside down.
	this->SetID(Components::Basket);
	SetPosition(0, INITIAL_HEIGHT);
	SetPivot(D3DXVECTOR3(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0));
	basketCollider = new CRectangle(this, 0, INITIAL_HEIGHT, 64.f, 20.f);

	SetRotationDeg(0, 0, 180.f);
}


Basket::~Basket()
{
}


void Basket::Update()
{

	// Basket slows down when it gets near the wall and then accelerates when going back

	float dt = gTimer->GetDeltaTime();
	currentPos = GetPosition();

	if (movingLeft && currentPos.x <= -250.f && movingSlowly == false)
	{
		speed = 100.f;
		movingSlowly = true;
	}

	if (!movingLeft && currentPos.x > 250.f && movingSlowly == false)
	{
		speed = 100.f;
		movingSlowly = true;
	}

	if (currentPos.x < -300)
	{
		speed = 200.f;
		movingLeft = false;
		movingSlowly = false;
		
	}
	else if (currentPos.x > 300)
	{
		speed = 200.f;
		movingLeft = true;
		movingSlowly = false;
	}

	if (movingLeft)
	{
		dir = D3DXVECTOR3(-1.f, 0.f, 0.f);
		
	}
	else
	{
		dir = D3DXVECTOR3(1.f, 0.f, 0.f);
	}

	// Basket moves according to the direction vector
	currentPos.x += (dir.x) * speed * dt;
	SetPosition(currentPos.x, currentPos.y);

	// The collider's position matches the position of the sprite
	basketCollider->SetPosition(currentPos.x - 32.f, INITIAL_HEIGHT + 20.f);


}