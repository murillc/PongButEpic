#pragma once
#include "GameEngine\EntitySystem\Component.h"

namespace Game
{
	class Timer : public GameEngine::Component
	{
	public:
		Timer();
		~Timer();

		virtual void Update() override;
		virtual void OnAddToWorld() override;

		
	private:
		
	};
}