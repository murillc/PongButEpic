#include "Timer.h"
#include "GameEngine\GameEngineMain.h"
#include "GameEngine/EntitySystem//Components/TextRenderComponent.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <string>
#include <math.h>
using namespace Game;

Timer::Timer()
{
	//GetEntity()->SetPos(sf::Vector2f(350.f, 350.f));
	int m_score = 0;

}

Timer::~Timer()
{

}

void Timer::OnAddToWorld()
{
	__super::OnAddToWorld();
}


void Timer::Update()
{
	float time = GameEngine::GameEngineMain::GetGameTime();
	float nearest = roundf(time * 100.0) / 100.0;
	GetEntity()->GetComponent<GameEngine::TextRenderComponent>()->SetString(std::to_string(time)+" s");

}




