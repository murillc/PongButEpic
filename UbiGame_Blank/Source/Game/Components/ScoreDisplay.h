#pragma once
#include "GameEngine\EntitySystem\Component.h"
#include "GameEngine\EntitySystem\Components\TextRenderComponent.h"
namespace Game
{
	class ScoreDisplay : public GameEngine::TextRenderComponent
	{
	public:
		ScoreDisplay();
		~ScoreDisplay();

		virtual void Update() override;
		virtual void OnAddToWorld() override;

		
	private:
		
	};
}