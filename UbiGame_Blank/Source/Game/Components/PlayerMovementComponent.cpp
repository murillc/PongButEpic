#include "PlayerMovementComponent.h"
#include "GameEngine\GameEngineMain.h"

#include <SFML/Window/Keyboard.hpp>
#include <Game/Components/BouncePhysicsComponent.h>

using namespace Game;

PlayerMovementComponent::PlayerMovementComponent()
{
	state = 0;
}


PlayerMovementComponent::~PlayerMovementComponent()
{


}

void PlayerMovementComponent::OnAddToWorld()
{
	__super::OnAddToWorld();
}


void PlayerMovementComponent::Update()
{
	__super::Update();

	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	sf::Vector2f wantedVel = sf::Vector2f(0.f, 0.f);

	float playerVel = 0.1f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		wantedVel.x -= playerVel;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		wantedVel.x += playerVel;
	}

	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);

	BouncePhysicsComponent* bouncePhys = GetEntity()->GetComponent<BouncePhysicsComponent>();
	if (bouncePhys)
	{
		bouncePhys->SetVelocity(wantedVel);
	}
}
