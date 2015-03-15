#include <iostream>
#include <mutex>
#include <queue>

#include "Player.h"
using namespace std;
#pragma once
namespace Thread{
	mutex mutex_queue;
	vector<char> kb1;
	vector<char> kb2;

	struct pos{
		int posX, posY;
		int old_PosX, old_PosY;
	}posi;
	vector<pos>position;
	class Game
	{
	private:
		char move;

	public:
		Game()
		{
		}
		void gameBoard()
		{
			if (!position.empty())
			{

			}

		~Game()
		{
		}
	};
}
