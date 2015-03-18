#pragma once
#include <iostream>
#include <mutex>
#include <queue>
#include "Console.h"
#include <conio.h>
#include <thread>
#include <Windows.h>
namespace Thread{
	mutex mutex_q;
	mutex mutex_pos;
	mutex mutex_board;
	vector<char> kb1, kb2;

	struct pos{
		int posx, posy;
		int old_Posx, old_Posy;
		char playerSign;
	};
	vector<pos>thePosition;
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
			if (!(thePosition.empty()))
			{
				pos pos3 = thePosition.back();
				Course::Console::gotoxy(pos3.old_Posx, pos3.old_Posy);
				cout << " ";
				Course::Console::gotoxy(pos3.posx, pos3.posy);
				cout << pos3.playerSign;
				thePosition.pop_back();
			}
		}

		void operator()(){
			SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
			SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
			while (true)
			{
				if (_kbhit())
				{
					move = _getch();

					mutex_q.lock();
					if (move == 'w' || move == 'a' || move == 's' || move == 'd')
					{
						kb1.push_back(move);
					}
					
					if (move == 'i' || move == 'j' || move == 'k' || move == 'l')
					{
						kb2.push_back(move);
					}

					mutex_q.unlock();

					
				}
				mutex_board.lock();
				gameBoard();
				mutex_board.unlock();
				this_thread::sleep_for(chrono::milliseconds(50));
		}
	}

		~Game()
		{
		}
	};
}
