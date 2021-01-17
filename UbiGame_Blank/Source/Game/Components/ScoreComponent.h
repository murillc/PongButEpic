#pragma once
#include "GameEngine\EntitySystem\Component.h"
#include "GameEngine\EntitySystem\Components\TextRenderComponent.h"
namespace Game
{
	class ScoreComponent : public GameEngine::Component
	{
	public:
		ScoreComponent();
		~ScoreComponent();
	
		virtual void Update() override;
		virtual void OnAddToWorld() override;

		int getScore() { 

			return scores[this->m_player];
		}

		int getScore(int playerNum) {
			return scores[playerNum];
		}
		
		
		void increaseScore() 
		{ 
			scores[this->m_player] ++;
			printf("\n%d: %d", this->m_player, scores[this->m_player]);
			m_score++; 
		}

		void increaseScore(int playerNum)
		{
			//m_score++;
			scores[playerNum]++;
			printf("\n%d: %d", playerNum, scores[playerNum]);
		}
		//void resetScore() { m_score = 0; }
		
		void setPlayer(int player)  { m_player = player; }
	private:
		int  m_score;
		int	 m_player;
		int	 scores[2];
	};
}