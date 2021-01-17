#include "BouncePhysicsComponent.h"
#include "GameEngine\GameEngineMain.h"

#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <GameEngine/EntitySystem/Components/SoundComponent.h>

#include "GameEngine\Util\CollisionManager.h"
#include "GameEngine\EntitySystem\Entity.h"
#include "Game\Components\ScoreComponent.h"
#include <vector>
#include <math.h>

using namespace Game;



BouncePhysicsComponent::BouncePhysicsComponent()
{
	m_maxSpeed = 500.f;
	m_wantedVelocity = sf::Vector2f(m_maxSpeed, 0.f);
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
	float mult = 4;


	if (dt > 0.f)
	{
		
		m_velocity.x = m_wantedVelocity.x;
		m_velocity.y = m_wantedVelocity.y;

		// V = Dx / Dt => Dx = V * Dt
		sf::Vector2f deltaVelocity = m_velocity * dt * getTimeAcc()  ;
		GetEntity()->SetPos(GetEntity()->GetPos() + deltaVelocity);
		printf("\n%f -- %f", dt, getTimeAcc());
		incrementSpeed(dt);

	}

	//For the time being just a simple intersection check that moves the entity out of all potential intersect boxes
	std::vector<CollidableComponent*>& collidables = GameEngine::CollisionManager::GetInstance()->GetCollidables();

	for (int a = 0; a < collidables.size(); ++a)
	{

		CollidableComponent* colComponent = collidables[a];
		if (colComponent == this)
			continue;

		GameEngine::AABBRect intersection;
		GameEngine::AABBRect myBox = GetWorldAABB();
		GameEngine::AABBRect colideBox = colComponent->GetWorldAABB();
		if (myBox.intersects(colideBox, intersection))
		{
			sf::Vector2f pos = GetEntity()->GetPos();
			if (intersection.width < intersection.height)
			{
				if (myBox.left < colideBox.left)
					pos.x -= intersection.width;
				else
					pos.x += intersection.width;
			}
			else
			{
				if (myBox.top < colideBox.top)
					pos.y -= intersection.height;
				else
					pos.y += intersection.height;
			}

			GetEntity()->SetPos(pos);

			if (colComponent->GetEntity()->GetType() == GameEngine::EntityType::Paddles) {
				// Relative Y Intersect from paddle = Paddle Y pos - Ball Position
				float relativeYIntersect = (colComponent->GetEntity()->GetPos().y) - GetEntity()->GetPos().y;

				// Normalize it
				float normalizedRelYInt = (relativeYIntersect / ((colComponent->GetWorldAABB().height * 1.1) / 2));

				float bounceAngle = normalizedRelYInt * 3.14 / 180.f * 65.f;


				if (GetEntity()->GetPos().x > 400) m_wantedVelocity.x = -m_maxSpeed * cos(bounceAngle);
				else m_wantedVelocity.x = m_maxSpeed * cos(bounceAngle);
				m_wantedVelocity.y = m_maxSpeed * -sin(bounceAngle);

				//printf("%f, %f, %f\n", bounceAngle, cos(bounceAngle), sin(bounceAngle));


				GetEntity()->GetComponent<GameEngine::SoundComponent>()->PlaySound(0);
			}
			else if (colComponent->GetEntity()->GetType() == GameEngine::EntityType::Walls) {
				
				m_wantedVelocity.y = -m_wantedVelocity.y;

			}
			else if (colComponent->GetEntity()->GetType() == GameEngine::EntityType::LeftNet) {
				
				GetEntity()->GetComponent<ScoreComponent>()->increaseScore(0);
				//std::cout << GetEntity()->GetComponent<ScoreComponent>()->getScore();
				//std::cout << "\nLeft Scored";

				GetEntity()->SetPos(sf::Vector2f(400.f, 400.f));
				resetTimeAcc();
			}
			else if (colComponent->GetEntity()->GetType() == GameEngine::EntityType::RightNet) {

				GetEntity()->GetComponent<ScoreComponent>()->increaseScore(1);
				//std::cout << GetEntity()->GetComponent<ScoreComponent>()->getScore();
				//std::cout << "\nRight Scored";
				GetEntity()->SetPos(sf::Vector2f(400.f, 400.f));
				resetTimeAcc();
			}
			

			
		}
	}
}
