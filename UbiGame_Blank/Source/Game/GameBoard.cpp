#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "Game\Components\PlayerMovementComponent.h"
#include "Game\Components\BouncePhysicsComponent.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"
#include "GameEngine\EntitySystem\Components\CollidablePhysicsComponent.h"
#include <GameEngine/EntitySystem/Components/SoundComponent.h>
#include <GameEngine/EntitySystem/Components/TextRenderComponent.h>
#include <Game\Components\ScoreComponent.h>
#include <Game\Components\ScoreDisplay.h>
#include <Game\Components\Timer.h>
#include <iostream>

using namespace Game;

GameBoard::GameBoard()
	: m_player1(nullptr), m_player2(nullptr), obstacle(nullptr), wallNorth(nullptr)
{
	
	CreatePlayers();
	CreateObstacle();
	CreateWalls();
	CreateText();
	CreateBg();
	CreateTimer();
	CreateScoreDisplay();
}


GameBoard::~GameBoard()
{

}

void GameBoard::CreatePlayers()
{	

	float h = GameEngine::GameEngineMain::GetInstance()->getHeight();
	float w = GameEngine::GameEngineMain::GetInstance()->getWidth();
	const float paddleHeight = h - 300.f;
	// Player 1
	m_player1 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player1);

	m_player1->SetPos(sf::Vector2f(50.f, GameEngine::GameEngineMain::GetInstance()->getHeight()/2));
	m_player1->SetSize(sf::Vector2f(25.f, paddleHeight));
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
	m_player2->SetSize(sf::Vector2f(25.f, paddleHeight));
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
	float h = GameEngine::GameEngineMain::GetInstance()->getHeight();
	float w = GameEngine::GameEngineMain::GetInstance()->getWidth();
	GameEngine::Entity* obstacle = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle);

	obstacle->SetPos(sf::Vector2f(200.f, 250.f));
	obstacle->SetSize(sf::Vector2f(50.f, 50.f));
	
	// Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>(obstacle->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Obstacle);

	obstacle->AddComponent<BouncePhysicsComponent>();
	obstacle->AddComponent<ScoreComponent>();



	GameEngine::SoundComponent* soundPlayer = static_cast<GameEngine::SoundComponent*>(obstacle->AddComponent<GameEngine::SoundComponent>());
	std::cout << soundPlayer->LoadSoundFromFile("Resources/sfx/hit.wav");
}

void Game::GameBoard::CreateWalls()
{
	float width = GameEngine::GameEngineMain::GetInstance()->getWidth();
	float height = GameEngine::GameEngineMain::GetInstance()->getHeight();

	GameEngine::Entity* wallNorth = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(wallNorth);

	wallNorth->SetPos(sf::Vector2f(0.f, 0.f));
	wallNorth->SetSize(sf::Vector2f(2000.f, 50.f));
	wallNorth->SetType(GameEngine::EntityType::Walls);

	// Render
	GameEngine::RenderComponent* renderN = static_cast<GameEngine::RenderComponent*>(wallNorth->AddComponent<GameEngine::RenderComponent>());

	renderN->SetFillColor(sf::Color::White);
	wallNorth->AddComponent<GameEngine::CollidableComponent>();

	/////////////////////////

	GameEngine::Entity* wallSouth = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(wallSouth);

	wallSouth->SetPos(sf::Vector2f(0.f, 600.f));
	wallSouth->SetSize(sf::Vector2f(2000.f, 50.f));
	wallSouth->SetType(GameEngine::EntityType::Walls);

	// Render
	GameEngine::RenderComponent* renderS = static_cast<GameEngine::RenderComponent*>(wallSouth->AddComponent<GameEngine::RenderComponent>());

	renderS->SetFillColor(sf::Color::White);

	wallSouth->AddComponent<GameEngine::CollidableComponent>();


	/////////////////////////

	GameEngine::Entity* netEast = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(netEast);

	netEast->SetPos(sf::Vector2f(width, 0.f));
	netEast->SetSize(sf::Vector2f(50.f, 2000.f));
	netEast->SetType(GameEngine::EntityType::RightNet);

	// Render
	GameEngine::RenderComponent* renderE = static_cast<GameEngine::RenderComponent*>(netEast->AddComponent<GameEngine::RenderComponent>());
	ScoreComponent* score1 = static_cast<ScoreComponent*>(netEast->AddComponent<ScoreComponent>());

	renderE->SetFillColor(sf::Color::Transparent);

	netEast->AddComponent<GameEngine::CollidableComponent>();
	score1->setPlayer(0);




	/////////////////////////

	GameEngine::Entity* netWest = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(netWest);

	netWest->SetPos(sf::Vector2f(0.f, 0.f));
	netWest->SetSize(sf::Vector2f(50.f, 2000.f));
	netWest->SetType(GameEngine::EntityType::LeftNet);

	// Render
	GameEngine::RenderComponent* renderW = static_cast<GameEngine::RenderComponent*>(netWest->AddComponent<GameEngine::RenderComponent>());
	ScoreComponent* score2 = static_cast<ScoreComponent*>(netWest->AddComponent<ScoreComponent>());
	
	renderW->SetFillColor(sf::Color::Transparent);

	netWest->AddComponent<GameEngine::CollidableComponent>();
	score2->setPlayer(1);
	
	
}


void GameBoard::CreateText()
{
	GameEngine::Entity* title = new GameEngine::Entity();
	GameEngine::Entity* scoreCounter = new GameEngine::Entity();
	GameEngine::Entity* p2Score = new GameEngine::Entity();

	GameEngine::GameEngineMain::GetInstance()->AddEntity(title);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(scoreCounter);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(p2Score);


	// TITLE
	GameEngine::TextRenderComponent* titleRender = static_cast<GameEngine::TextRenderComponent*>(title->AddComponent<GameEngine::TextRenderComponent>());
	titleRender->SetFont("Inter-ExtraBold.ttf");
	titleRender->SetString("Pong But Epic");
	titleRender->SetColor(sf::Color::Black);
	titleRender->SetCharacterSizePixels(20);
	title->SetPos(sf::Vector2f(330.f, 0.f));

	// PLAYER 1 SCORE DISPLAY
	GameEngine::TextRenderComponent* scoreRender = static_cast<GameEngine::TextRenderComponent*>(scoreCounter->AddComponent<GameEngine::TextRenderComponent>());
	scoreCounter->AddComponent<ScoreComponent>();

	scoreCounter->SetPos(sf::Vector2f(400.f, 400.f));
	scoreRender->SetFont("Inter-ExtraBold.ttf");
	
	//p1ScoreRender->SetString("Pepega");
	// PLAYER 2 SCORE DISPLAY

}

void GameBoard::CreateBg()
{
	float h = GameEngine::GameEngineMain::GetInstance()->getHeight();
	float w = GameEngine::GameEngineMain::GetInstance()->getWidth();
	GameEngine::Entity* bg = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bg);

	bg->SetPos(sf::Vector2f(w/2, h/2));
	bg->SetSize(sf::Vector2f(800.f, 600.f));

	GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>(bg->AddComponent<GameEngine::SpriteRenderComponent>());

	render->SetTexture(GameEngine::eTexture::Background);
	render->SetFillColor(sf::Color::Transparent);
	render->SetZLevel(-1);
			
}

void GameBoard::CreateTimer()
{
	float h = GameEngine::GameEngineMain::GetInstance()->getHeight();
	float w = GameEngine::GameEngineMain::GetInstance()->getWidth();
	GameEngine::Entity* timer = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(timer);
	GameEngine::TextRenderComponent* timerRender = static_cast<GameEngine::TextRenderComponent*>(timer->AddComponent<GameEngine::TextRenderComponent>());
	
	timer->AddComponent<Timer>();
	timer->SetPos(sf::Vector2f(w/2-50.f, 550.f));
	timerRender->SetFont("Inter-ExtraBold.ttf");
	timerRender->SetCharacterSizePixels(15);
	
}

void GameBoard::CreateScoreDisplay()
{
	float h = GameEngine::GameEngineMain::GetInstance()->getHeight();
	float w = GameEngine::GameEngineMain::GetInstance()->getWidth();
	GameEngine::Entity* scoreCounter = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(scoreCounter);
	
	//GameEngine::TextRenderComponent* timerRender = static_cast<GameEngine::TextRenderComponent*>(scoreCounter->AddComponent<GameEngine::TextRenderComponent>());
	scoreCounter->AddComponent<ScoreComponent>();
	scoreCounter->AddComponent<ScoreDisplay>();
	
	scoreCounter->SetPos(sf::Vector2f(w / 2 - 50.f, 300.f));
	
}

void GameBoard::Update()
{	
	
}