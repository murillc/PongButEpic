#pragma once
#include "GameEngine\EntitySystem\Component.h"
#include "GameEngine\EntitySystem\Components\TextRenderComponent.h"
namespace Game
{
	class ScoreComponent : public GameEngine::TextRenderComponent
	{
	public:
		ScoreComponent();
		~ScoreComponent();

		virtual void Update() override;
		virtual void OnAddToWorld() override;

		int getScore() { return m_score; }
		
		void increaseScore() { m_score++; }
		void resetScore() { m_score = 0; }

	private:
		int  m_score;
	};
}