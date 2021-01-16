#include "BouncePhysicsComponent.h"
#include "GameEngine\GameEngineMain.h"

#include <SFML/Window/Keyboard.hpp>

using namespace Game;

BouncePhysicsComponent::BouncePhysicsComponent()
{
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
		// Set the wanted velocity as current
		m_velocity = m_wantedVelocity;

		// V = Dx / Dt => Dx = V * Dt
		sf::Vector2f deltaVelocity = dt * m_velocity;
		GetEntity()->SetPos(GetEntity()->GetPos() + deltaVelocity);
	}

	__super::Update();
}
