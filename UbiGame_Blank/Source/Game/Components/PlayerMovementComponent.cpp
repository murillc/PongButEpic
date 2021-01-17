#include "PlayerMovementComponent.h"
#include "GameEngine\GameEngineMain.h"

#include <SFML/Window/Keyboard.hpp>
#include <Game/Components/BouncePhysicsComponent.h>
#include <cstdio>

using namespace Game;

PlayerMovementComponent::PlayerMovementComponent()
{
	m_player = 1;
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

	float playerVel = 0.25f;

	if (m_player == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			wantedVel.y -= playerVel;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			wantedVel.y += playerVel;
		}
	}
	else if (m_player == 2) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			wantedVel.y -= playerVel;
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			wantedVel.y += playerVel;
		}
	}
	

	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);

	if (GetEntity()->GetPos().y < 0.f - GetEntity()->GetSize().y / 2) {
		GetEntity()->SetPos(sf::Vector2f(GetEntity()->GetPos().x, 800.f + GetEntity()->GetSize().y / 2));
	}
	else if (GetEntity()->GetPos().y > 600.f + GetEntity()->GetSize().y / 2) {
		GetEntity()->SetPos(sf::Vector2f(GetEntity()->GetPos().x, 0.f - GetEntity()->GetSize().y / 2));
	}

	
}
