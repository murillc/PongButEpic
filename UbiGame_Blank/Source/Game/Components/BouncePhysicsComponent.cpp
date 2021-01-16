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

	// This is our A

	if (dt > 0.f)
	{
		m_velocity.x = m_wantedVelocity.x;

		// V = Dx / Dt => Dx = V * Dt
		sf::Vector2f deltaVelocity = dt * m_velocity;
		GetEntity()->SetPos(GetEntity()->GetPos() + deltaVelocity);

	}

	__super::Update();


}
