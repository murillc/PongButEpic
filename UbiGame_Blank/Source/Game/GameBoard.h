#pragma once
#include "GameEngine/EntitySystem/Entity.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application	
	class PlayerEntity;	

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();

		void Update();		
		bool IsGameOver() { return false; }

	private:
		void CreatePlayers();
		void CreateObstacle();
		void CreateWalls();
		void CreateText();
		GameEngine::Entity* m_player1_1;
		GameEngine::Entity* m_player1_2;

		GameEngine::Entity* m_player2_1;
		GameEngine::Entity* m_player2_2;

		GameEngine::Entity* wallNorth;
		GameEngine::Entity* wallSouth;
		GameEngine::Entity* wallWest;
		GameEngine::Entity* wallEast;

		GameEngine::Entity* obstacle;
	};

}

