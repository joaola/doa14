#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <mutex>
#include <thread>
#include <chrono>
#include "Console.h"
using namespace std;
using namespace Course;
#pragma once
class Player
{
	struct position
	{
	int posx, posy;
	int oldPosX, oldPosY;
	}pos;
private:
	int x, y;
	char c;
	vector<char>controls;

public:
	mutex mutex_pos1, mutex_pos2;

	Player(char c = '1', int x = 0, int y = 0, char up = 'w', char down = 's', char left = 'a', char right = 'd')
	{
		this->c = c;
		this->x = x;
		this->y = y;
		this->controls.push_back(up);
		this->controls.push_back(down);
		this->controls.push_back(left);
		this->controls.push_back(right);

	}

	Operator()()
	{
		
	}

	void MovePlayer(char c)
	{
		mutex_pos1.lock();

		mutex_pos1.unlock();
	}

	~Player()
	{
	}
};

