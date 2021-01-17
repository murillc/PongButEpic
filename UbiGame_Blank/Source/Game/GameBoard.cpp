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
	: m_player1(nullptr), m_player2(nullptr), obstacle(nullptr), wallNorth(nullptr)
{
	CreatePlayers();
	CreateObstacle();
	CreateWalls();
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
	m_player1->SetSize(sf::Vector2f(25.f, 100.f));
	m_player1->SetType(GameEngine::EntityType::Paddles);


	// Render
	GameEngine::SpriteRenderComponent* spriteRender1 = static_cast<GameEngine::SpriteRenderComponent*>(m_player1->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender1->SetFillColor(sf::Color::Transparent);
	spriteRender1->SetTexture(GameEngine::eTexture::Player);

	// Player Movement Component
	PlayerMovementComponent* playerMove1 = static_cast<PlayerMovementComponent*>(m_player1->AddComponent<PlayerMovementComponent>());
	playerMove1->setPlayer(1);

	m_player1->AddComponent<GameEngine::CollidablePhysicsComponent>();

	///////////////////////////////////////////////////////////////////////////////////

	// Player 2
	m_player2 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player2);

	m_player2->SetPos(sf::Vector2f(GameEngine::GameEngineMain::GetInstance()->getWidth() - 50.f, GameEngine::GameEngineMain::GetInstance()->getHeight() / 2));
	m_player2->SetSize(sf::Vector2f(25.f, 100.f));
	m_player2->SetType(GameEngine::EntityType::Paddles);

	// Render
	GameEngine::SpriteRenderComponent* spriteRender2 = static_cast<GameEngine::SpriteRenderComponent*>(m_player2->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender2->SetFillColor(sf::Color::Transparent);
	spriteRender2->SetTexture(GameEngine::eTexture::Player);

	// Player Movement Component
	PlayerMovementComponent* playerMove2 = static_cast<PlayerMovementComponent*>(m_player2->AddComponent<PlayerMovementComponent>());
	playerMove2->setPlayer(2);

	m_player2->AddComponent<GameEngine::CollidablePhysicsComponent>();
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

void Game::GameBoard::CreateWalls()
{
	GameEngine::Entity* wallNorth = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(wallNorth);

	wallNorth->SetPos(sf::Vector2f(0.f, 0.f));
	wallNorth->SetSize(sf::Vector2f(2000.f, 50.f));
	wallNorth->SetType(GameEngine::EntityType::Walls);

	// Render
	GameEngine::RenderComponent* renderN = static_cast<GameEngine::RenderComponent*>(wallNorth->AddComponent<GameEngine::RenderComponent>());

	renderN->SetFillColor(sf::Color::Green);

	wallNorth->AddComponent<GameEngine::CollidableComponent>();




	GameEngine::Entity* wallSouth = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(wallSouth);

	wallSouth->SetPos(sf::Vector2f(0.f, 600.f));
	wallSouth->SetSize(sf::Vector2f(2000.f, 50.f));
	wallSouth->SetType(GameEngine::EntityType::Walls);

	// Render
	GameEngine::RenderComponent* renderS = static_cast<GameEngine::RenderComponent*>(wallSouth->AddComponent<GameEngine::RenderComponent>());

	renderS->SetFillColor(sf::Color::Green);

	wallSouth->AddComponent<GameEngine::CollidableComponent>();
}

void GameBoard::Update()
{	
	
}