#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "Game\Components\PlayerMovementComponent.h"
#include "Game\Components\BouncePhysicsComponent.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"
#include "GameEngine\EntitySystem\Components\CollidablePhysicsComponent.h"
#include "GameEngine\EntitySystem\Components\SoundComponent.h"
#include "GameEngine\EntitySystem\Components\TextRenderComponent.h"

#include <iostream>

using namespace Game;

GameBoard::GameBoard()
	: m_player(nullptr), obstacle(nullptr)
{
	CreatePlayer();
	CreateObstacle();
	CreateTitleScreen();
	GameEngine::SoundComponent* soundPlayer = static_cast<GameEngine::SoundComponent*>(m_player->AddComponent<GameEngine::SoundComponent>());
	std::cout << soundPlayer ->LoadSoundFromFile("C:/Users/kurom/OneDrive/Documents/GitHub/PongButEpic/UbiGame_Blank/Resources/sfx/hit.wav");;
	soundPlayer->PlaySound(0);

}


GameBoard::~GameBoard()
{

}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

	m_player->SetPos(sf::Vector2f(50.f, 50.f));
	m_player->SetSize(sf::Vector2f(50.f, 50.f));

	// Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>(m_player->AddComponent<GameEngine::SpriteRenderComponent>());
	
	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Player);

	
	
	
	

	m_player->AddComponent<PlayerMovementComponent>();

	m_player->AddComponent<BouncePhysicsComponent>();
}

void GameBoard::CreateObstacle()
{
	GameEngine::Entity* obstacle = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle);

	obstacle->SetPos(sf::Vector2f(150.f, 350.f));
	obstacle->SetSize(sf::Vector2f(300.f, 100.f));

	// Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>(obstacle->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Obstacle);

	obstacle->AddComponent<GameEngine::CollidableComponent>();
}

void GameBoard::Update()
{

	
}

void GameBoard::CreateTitleScreen()
{
	GameEngine::Entity* title = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(title);

	GameEngine::TextRenderComponent* titleRender = static_cast<GameEngine::TextRenderComponent*>(title->AddComponent<GameEngine::TextRenderComponent>());
	
	float centerX = GameEngine::GameEngineMain::GetInstance()->getWidth();
	float centerY = GameEngine::GameEngineMain::GetInstance()->getHeight();
	
	title->SetPos(sf::Vector2f(centerX/2 - 100.f, 30.f));


	titleRender->SetFont("Inter-ExtraBold.ttf");
	titleRender->SetString("Pong But Epic");

}


