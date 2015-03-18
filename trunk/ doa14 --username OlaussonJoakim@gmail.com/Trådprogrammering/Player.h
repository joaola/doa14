#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <mutex>
#include <thread>
#include <chrono>
#include "Console.h"
#include "Game.h"
using namespace std;
using namespace Course;
#pragma once
namespace Thread
{
	class Player
	{
	private:
		char playerSign, c;
		int posx, posy;
		vector<char>*vPointer;

	public:

		Player()
		{
		}

		Player(char playerSign, int posx, int posy, vector<char> *vPointer)
		{
			this->playerSign = playerSign;
			this->posx = posx;
			this->posy = posy;
			this->vPointer = vPointer;

		}

		char getPlayerSign()
		{
			return this->playerSign;
		}

		void operator()()
		{
			SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
			SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
			while (true)
			{
				mutex_pos.lock();
				pos pos2;
				pos2.playerSign = this->playerSign;
				pos2.old_Posx = this->posx;
				pos2.old_Posy = this->posy;
				if (!(vPointer->empty()))
				{
					if (vPointer->back() == 'w' || vPointer->back() == 'i')
					{


						if (posy > 0)
						{
							posy--;
						}
						else
							;

					}
					else if (vPointer->back() == 'a' || vPointer->back() == 'j')
					{
						if (posx > 0)
						{
							posx--;
						}
						else
							;
					}
					else if (vPointer->back() == 's' || vPointer->back() == 'k')
					{
						if (posy < 10)
						{
							posy++;
						}
						else
							;
					}

					else if (vPointer->back() == 'd' || vPointer->back() == 'l')
					{
						if (posx < 10)
						{
							posx++;
						}
						else
							;
					}
					Console::gotoxy(pos2.old_Posx, pos2.old_Posy);
					cout << " ";
					vPointer->pop_back();
				}

				pos2.posx = this->posx;
				pos2.posy = this->posy;
				thePosition.push_back(pos2);
				mutex_pos.unlock();
				this_thread::sleep_for(chrono::milliseconds(200));
			}
			
		}

		~Player()
		{
		}
	};
}

