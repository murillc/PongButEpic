#include "BouncePhysicsComponent.h"
#include "GameEngine\GameEngineMain.h"

#include <SFML/Window/Keyboard.hpp>
#include <iostream>

using namespace Game;

BouncePhysicsComponent::BouncePhysicsComponent()
{
	m_wantedVelocity = sf::Vector2f(-100.f, 0.0f);
}


BouncePhysicsComponent::~BouncePhysicsComponent()
{


}

void BouncePhysicsComponent::OnAddToWorld()
{
	__super::OnAddToWorld();
}


void BouncePhysicsComponent::Update()
{
	// Get delta time from the previous frame
	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	if (dt > 0.f)
	{
		m_velocity.x = m_wantedVelocity.x;

		// V = Dx / Dt => Dx = V * Dt
		sf::Vector2f deltaVelocity = m_velocity * dt;
		GetEntity()->SetPos(GetEntity()->GetPos() + deltaVelocity);

	}

	__super::Update();

	if (getCollide()) {
		m_wantedVelocity.x = -m_wantedVelocity.x;
	}
}
