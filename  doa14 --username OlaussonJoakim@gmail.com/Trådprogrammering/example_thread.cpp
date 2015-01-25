#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <atomic>
#include <mutex>
#include <random>
using namespace std;

#include <iso646.h>

#include "..\Course\Console.h"
using namespace Course;

namespace CourseThreads
{
	std::atomic<bool> atomicFlagQuit = false;

	class say_hello
	{
	private:
		string str;
		int x,y;
		mutable default_random_engine g;
		mutable uniform_int_distribution<int> d;
	public:
		say_hello(string s="hello world", int x=10, int y=0) 
		{ 
			str=s; 
			this->x=x; 
			this->y=y; 
			d = uniform_int_distribution<int>(1,7);
		}

		void operator()() 
		{
			for (int i=0; i<10; i++)
			{
				this->random_color();
				Console::gotoxy(x,y);
				cout << str << endl;
				this_thread::sleep_for(chrono::milliseconds(1000));
			}
		}

		void random_color() const
		{
			int r = d(g);
			bool red = false;
			bool green = false;
			bool blue = false;

			if ( r bitand 0x04) { red=true; }
			if ( r bitand 0x02) { green=true; }
			if ( r bitand 0x01) { blue=true; }

			Console::set_color(red,green,blue,true,false,false,false,false);
		}
	};

	mutex mutex_cout;

	class say_hello2
	{
	private:
		string str;
		int x,y;
		static default_random_engine g;
		static uniform_int_distribution<int> d;
	public:
		say_hello2(string s="HELLO WORLD", int x=10, int y=0) 
		{ 
			str=s; 
			this->x=x; 
			this->y=y; 
		}

		void operator()() 
		{
			for (int i=0; i<10; i++)
			{
				//this->random_color(); //case 1: Color selection not protected
				mutex_cout.lock();
				this->random_color();   //case 2: Color selection protected
				Console::gotoxy(x,y);
				cout << str << endl;
				mutex_cout.unlock();
				this_thread::sleep_for(chrono::milliseconds(1000));
			}
		}

		void random_color() const
		{
			int r = d(g);
			bool red = false;
			bool green = false;
			bool blue = false;

			if ( r bitand 0x04) { red=true; }
			if ( r bitand 0x02) { green=true; }
			if ( r bitand 0x01) { blue=true; }

			Console::set_color(red,green,blue,true,false,false,false,false);
		}
	};

	default_random_engine say_hello2::g;
	uniform_int_distribution<int> say_hello2::d = uniform_int_distribution<int>(1,7);


}


using namespace CourseThreads;

void main_threads()
{
	{	
		Console::gotoxy(0,40);
		cout << "Three threads sharing the common resource the ostream object cout." << endl;
		cout << "Problem:	The resource is not shareable. " << endl;
		cout << "When using it the oeration must be completed before anyone else can use it." << endl;
		say_hello  world, sweden("Heja Sverige", 10, 10), usa("Hello United States of America", 10,20);

		thread t1(world), t2(sweden), t3(usa);

		t1.join();
		t2.join();
		t3.join();
	}

	Console::clrscr();

	{	Console::gotoxy(0,40);
		cout << "Three threads sharing the common resource the ostream object cout." << endl;
		cout << "Problem:	The resource is not shareable. " << endl;
		cout << "Solution: use of a mutex as a global object." << endl;
		say_hello2  world, sweden("HEJA SVERIGE", 10, 10), usa("HELLO USA", 10,20);

		thread t1(world), t2(sweden), t3(usa);

		t1.join();
		t2.join();
		t3.join();
	}
}