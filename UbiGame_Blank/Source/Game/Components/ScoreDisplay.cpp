#include "ScoreDisplay.h"
#include "GameEngine\GameEngineMain.h"

#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <string>
#include "Game/Components/ScoreComponent.h"
using namespace Game;

ScoreDisplay::ScoreDisplay()
{
	SetFont("Inter-ExtraBold.ttf");
	SetCharacterSizePixels(15);
}

ScoreDisplay::~ScoreDisplay()
{

}

void ScoreDisplay::OnAddToWorld()
{
	__super::OnAddToWorld();
}


void ScoreDisplay::Update()
{
	
}




