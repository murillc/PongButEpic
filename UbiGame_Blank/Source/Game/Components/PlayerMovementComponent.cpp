#include "PlayerMovementComponent.h"
#include "GameEngine\GameEngineMain.h"

#include <SFML/Window/Keyboard.hpp>

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
		state = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		state = 2;
	}

	if (state == 1) {
		wantedVel.x -= playerVel;
	}
	else if (state == 2) {
		wantedVel.x += playerVel;
	}
	

	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);
}
