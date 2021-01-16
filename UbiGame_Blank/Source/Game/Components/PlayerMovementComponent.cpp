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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		wantedVel.y -= playerVel;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		wantedVel.y += playerVel;
	}

	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);
}
