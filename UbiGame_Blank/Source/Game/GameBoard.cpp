#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "Game\Components\PlayerMovementComponent.h"
#include "Game\Components\BouncePhysicsComponent.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"
#include "GameEngine\EntitySystem\Components\CollidablePhysicsComponent.h"
#include "Game\Components\ScoreComponent.h"

#include <GameEngine/EntitySystem/Components/SoundComponent.h>

#include <iostream>
#include<string>
using namespace Game;

GameBoard::GameBoard()
	: m_player1(nullptr), m_player2(nullptr), obstacle(nullptr)
{
	CreatePlayers();
	CreateObstacle();
	CreateText();

}


GameBoard::~GameBoard()
{

}

void GameBoard::CreatePlayers()
{
	// Player 1
	m_player1 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player1);

	m_player1->SetPos(sf::Vector2f(50.f, GameEngine::GameEngineMain::GetInstance()->getHeight()/2));
	m_player1->SetSize(sf::Vector2f(50.f, 200.f));

	// Render
	GameEngine::SpriteRenderComponent* spriteRender1 = static_cast<GameEngine::SpriteRenderComponent*>(m_player1->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender1->SetFillColor(sf::Color::Transparent);
	spriteRender1->SetTexture(GameEngine::eTexture::Player);

	// Player Movement Component
	PlayerMovementComponent* playerMove1 = static_cast<PlayerMovementComponent*>(m_player1->AddComponent<PlayerMovementComponent>());
	playerMove1->setPlayer(1);

	m_player1->AddComponent<GameEngine::CollidableComponent>();
	m_player1->AddComponent<ScoreComponent>();
	//m_player2->AddComponent<GameEngine::TextRenderComponent>();
	

	///////////////////////////////////////////////////////////////////////////////////

	// Player 2
	m_player2 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player2);

	m_player2->SetPos(sf::Vector2f((GameEngine::GameEngineMain::GetInstance()->getWidth())-50.f, GameEngine::GameEngineMain::GetInstance()->getHeight() / 2));
	m_player2->SetSize(sf::Vector2f(50.f, 200.f));


	// Render
	GameEngine::SpriteRenderComponent* spriteRender2 = static_cast<GameEngine::SpriteRenderComponent*>(m_player2->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender2->SetFillColor(sf::Color::Transparent);
	spriteRender2->SetTexture(GameEngine::eTexture::Player);

	// Player Movement Component
	PlayerMovementComponent* playerMove2 = static_cast<PlayerMovementComponent*>(m_player2->AddComponent<PlayerMovementComponent>());
	playerMove2->setPlayer(2);

	m_player2->AddComponent<GameEngine::CollidableComponent>();
	m_player2->AddComponent<ScoreComponent>();

	//m_player2->AddComponent<GameEngine::TextRenderComponent>();
}

void GameBoard::CreateObstacle()
{
	GameEngine::Entity* obstacle = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle);

	obstacle->SetPos(sf::Vector2f(200.f, 250.f));
	obstacle->SetSize(sf::Vector2f(50.f, 50.f));

	// Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>(obstacle->AddComponent<GameEngine::SpriteRenderComponent>());
	
	
	GameEngine::TextRenderComponent* p1Text = static_cast<GameEngine::TextRenderComponent*>(obstacle->AddComponent<GameEngine::TextRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Obstacle);

	obstacle->AddComponent<BouncePhysicsComponent>();
	obstacle->AddComponent<ScoreComponent>();

	
	p1Text->SetFont("Inter-ExtraBold.ttf");


	GameEngine::SoundComponent* soundPlayer = static_cast<GameEngine::SoundComponent*>(obstacle->AddComponent<GameEngine::SoundComponent>());
	std::cout << soundPlayer->LoadSoundFromFile("C:/Users/kurom/OneDrive/Documents/GitHub/PongButEpic/UbiGame_Blank/Resources/sfx/hit.wav");
}

void GameBoard::CreateText()
{
	GameEngine::Entity* title = new GameEngine::Entity();
	GameEngine::Entity* p1Score = new GameEngine::Entity();
	GameEngine::Entity* p2Score = new GameEngine::Entity();
	
	GameEngine::GameEngineMain::GetInstance()->AddEntity(title);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(p1Score);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(p2Score);


	// Title
	GameEngine::TextRenderComponent* titleRender = static_cast<GameEngine::TextRenderComponent*>(title->AddComponent<GameEngine::TextRenderComponent>());
	titleRender->SetFont("Inter-ExtraBold.ttf");
	titleRender->SetString("Pong But Epic");

	//

	p1Score->AddComponent<ScoreComponent>();
	p1Score->GetComponent<ScoreComponent>()->SetFont("Inter-ExtraBold.ttf");
	p1Score->GetComponent<ScoreComponent>()->SetString("Test");
	/*
	Game::ScoreComponent* p1Score = static_cast<Game::ScoreComponent*>(title->AddComponent<Game::ScoreComponent>());

	float centerX = GameEngine::GameEngineMain::GetInstance()->getWidth();
	float centerY = GameEngine::GameEngineMain::GetInstance()->getHeight();

	title->SetPos(sf::Vector2f(centerX / 2 - 100.f, 30.f));

	p1Score->SetFont("Inter-ExtraBold.ttf");
	p1Score->SetString(std::to_string(p1Score->getScore()));
	*/
	
}

void GameBoard::Update()
{	

}