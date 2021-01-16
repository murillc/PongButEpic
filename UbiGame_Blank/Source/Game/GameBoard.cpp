#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "Game\Components\PlayerMovementComponent.h"
#include "Game\Components\BouncePhysicsComponent.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"
#include "GameEngine\EntitySystem\Components\CollidablePhysicsComponent.h"
#include <GameEngine/EntitySystem/Components/SoundComponent.h>
#include <iostream>

using namespace Game;

GameBoard::GameBoard()
	: m_player1(nullptr), m_player2(nullptr), obstacle(nullptr)
{
	CreatePlayers();
	CreateObstacle();
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

	///////////////////////////////////////////////////////////////////////////////////

	// Player 2
	m_player2 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player2);

	m_player2->SetPos(sf::Vector2f(500.f, GameEngine::GameEngineMain::GetInstance()->getHeight() / 2));
	m_player2->SetSize(sf::Vector2f(50.f, 200.f));

	// Render
	GameEngine::SpriteRenderComponent* spriteRender2 = static_cast<GameEngine::SpriteRenderComponent*>(m_player2->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender2->SetFillColor(sf::Color::Transparent);
	spriteRender2->SetTexture(GameEngine::eTexture::Player);

	// Player Movement Component
	PlayerMovementComponent* playerMove2 = static_cast<PlayerMovementComponent*>(m_player2->AddComponent<PlayerMovementComponent>());
	playerMove2->setPlayer(2);

	m_player2->AddComponent<GameEngine::CollidableComponent>();
}

void GameBoard::CreateObstacle()
{
	GameEngine::Entity* obstacle = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle);

	obstacle->SetPos(sf::Vector2f(200.f, 250.f));
	obstacle->SetSize(sf::Vector2f(50.f, 50.f));

	// Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>(obstacle->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Obstacle);

	obstacle->AddComponent<BouncePhysicsComponent>();

	GameEngine::SoundComponent* soundPlayer = static_cast<GameEngine::SoundComponent*>(obstacle->AddComponent<GameEngine::SoundComponent>());
	std::cout << soundPlayer->LoadSoundFromFile("C:/Users/crmur/source/repos/HackersNest/UbiGame_Blank/Resources/sfx/hit.wav");
}

void GameBoard::Update()
{	
	
}