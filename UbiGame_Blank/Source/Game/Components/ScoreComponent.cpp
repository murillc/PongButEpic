#include "ScoreComponent.h"
#include "GameEngine\GameEngineMain.h"

#include <SFML/Window/Keyboard.hpp>
#include <iostream>


using namespace Game;

ScoreComponent::ScoreComponent()
{	

	
	int m_score = 0;


}


ScoreComponent::~ScoreComponent()
{
	
}

void ScoreComponent::OnAddToWorld()
{
	__super::OnAddToWorld();
}


void ScoreComponent::Update()
{
	
	
	GetEntity()->GetComponent<GameEngine::TextRenderComponent>()->SetString(std::to_string(this->getScore()));
}
