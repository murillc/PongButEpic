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

		static void resetTimer() {
			time = 0.f;
		}
		void incrementTimer(float dt) {
			time += dt;
		}

		float getTime() {
			return time;
		}
	private:
		static float time;
	};
}