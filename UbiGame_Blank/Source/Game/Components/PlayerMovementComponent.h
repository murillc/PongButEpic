#pragma once
#include "GameEngine\EntitySystem\Component.h"

namespace Game
{
	class PlayerMovementComponent : public GameEngine::Component
	{
	public:
		PlayerMovementComponent();
		~PlayerMovementComponent();
		
		virtual void Update() override;
		virtual void OnAddToWorld() override;

		virtual void setPlayer(int player) { m_player = player; }
	private:
		int m_player;
	};
}