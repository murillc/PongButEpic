#include "ScoreComponent.h"
#include "GameEngine\GameEngineMain.h"

#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <string>

using namespace Game;

ScoreComponent::ScoreComponent()
{	
	//GetEntity()->SetPos(sf::Vector2f(350.f, 350.f));
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
	//GetEntity()->GetComponent<GameEngine::TextRenderComponent>()->SetString("1");
}




