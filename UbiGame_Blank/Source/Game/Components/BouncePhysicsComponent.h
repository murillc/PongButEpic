#pragma once
#include "GameEngine\EntitySystem\Components\CollidablePhysicsComponent.h"


namespace Game
{
	class BouncePhysicsComponent : public GameEngine::CollidablePhysicsComponent
	{
	public:
		BouncePhysicsComponent();
		~BouncePhysicsComponent();

		virtual void OnAddToWorld() override;
		virtual void Update() override;

		void SetVelocity(sf::Vector2f vel) { m_wantedVelocity = vel; }
	private:
		sf::Vector2f m_wantedVelocity;
		sf::Vector2f m_velocity;
		sf::Vector2f m_lastPos;
		int		     m_maxSpeed;
	};
}