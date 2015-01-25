#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

#include "..\Course\Console.h"
using namespace Course;

namespace Course
{
	namespace Astar
	{
		const int SIZE = 10;

		struct pos
		{
			static int rgoal;
			static int cgoal;
			pos() { r = -1; c = -1; }
			pos(int rr, int cc) { r = rr; c = cc; }

			friend bool operator<(pos lop, pos rop)
			{
				int distLop = (int)sqrt((lop.r - rgoal)*(lop.r - rgoal) + (lop.c - cgoal)*(lop.c - cgoal));
				int distRop = (int)sqrt((rop.r - rgoal)*(rop.r - rgoal) + (rop.c - cgoal)*(rop.c - cgoal));
				return distLop > distRop; //Min- eller Max-heap? Max-heap-default, användning av > ger oss en min-heap
			}
			int r;
			int c;
		};

		int pos::rgoal = 0; //Här skapas den statiska variabeln som ingår i pos
		int pos::cgoal = 0;

		struct node
		{
			node() { p = pos(); is_visited = false; c = ' '; }
			char c;
			pos p; //Previous position
			bool is_visited;
		};

		const array<array<char, SIZE>, SIZE> MazeOne =
		{ { //array
			{ ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' },
			{ ' ', 'S', ' ', 'X', ' ', 'X', ' ', ' ', ' ', ' ' },
			{ ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', ' ', ' ' },
			{ ' ', 'X', ' ', 'X', ' ', 'X', ' ', ' ', ' ', ' ' },
			{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
			{ ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ' },
			{ ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', 'G', ' ' },
			{ ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ' },
			{ ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' ' },
			{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X' }

		} };

		class maze
		{
		private:
			pos start, goal;
			vector<vector<node>> matrix;
			priority_queue<pos> pq;
			queue<pos> q;

			bool search_start()
			{
				for (int i = 0; i < SIZE; i++)
				{
					for (int j = 0; j < SIZE; j++)
					{
						if (matrix[i][j].c == 'S')
						{
							start.r = i;
							start.c = j;
							matrix[i][j].c = ' ';
							return true;
						}
					}
				}
				return false;
			}

			bool search_goal()
			{
				for (int i = 0; i < SIZE; i++)
				{
					for (int j = 0; j < SIZE; j++)
					{
						if (matrix[i][j].c == 'G')
						{
							goal.r = i;
							goal.c = j;
							matrix[i][j].c = ' ';
							return true;
						}
					}
				}
				return false;
			}

		public:
			maze()
			{
				matrix = vector<vector<node>>(SIZE);
				for (int i = 0; i < SIZE; i++)
				{
					matrix[i] = vector<node>(SIZE);
					for (int j = 0; j < SIZE; j++)
					{
						matrix[i][j] = node();
						matrix[i][j].c = MazeOne[i][j];
					}
				}
				search_start();
				matrix[start.r][start.c].is_visited = true;
				search_goal();
				pos::rgoal = this->goal.r;
				pos::cgoal = this->goal.c;

			}

			bool goal_test(int r, int c, int rb, int cb)
			{
				bool b = ((r == goal.r) && (c == goal.c));

				matrix[r][c].is_visited = true;
				matrix[r][c].p.r = rb;
				matrix[r][c].p.c = cb;
				matrix[r][c].c = 'v';
				return b;
			}

			void astar()
			{
				pq.push(start);
				while (!pq.empty())
				{
					//print_maze();
					int r = pq.top().r;
					int c = pq.top().c;
					pq.pop();
					//cout << "(" << r << "," << c << ")" << endl;

					if (((r - 1) >= 0) && (matrix[r - 1][c].c == ' ') && !matrix[r - 1][c].is_visited) //Above
					{
						if (goal_test(r - 1, c, r, c)) break;
						pq.push(pos(r - 1, c));
					}

					if (((r + 1) < SIZE) && (matrix[r + 1][c].c == ' ') && !matrix[r + 1][c].is_visited) //Below
					{
						if (goal_test(r + 1, c, r, c)) break;
						pq.push(pos(r + 1, c));
					}

					if (((c - 1) >= 0) && (matrix[r][c - 1].c == ' ') && !matrix[r][c - 1].is_visited) //Left
					{
						if (goal_test(r, c - 1, r, c)) break;
						pq.push(pos(r, c - 1));
					}
					if (((c + 1) < SIZE) && (matrix[r][c + 1].c == ' ') && !matrix[r][c + 1].is_visited) //Right
					{
						if (goal_test(r, c + 1, r, c)) break;
						pq.push(pos(r, c + 1));
					}
				}

				if (matrix[goal.r][goal.c].is_visited)
				{
					int r = goal.r;
					int c = goal.c;
					while (!((r == start.r) && (c == start.c)))
					{
						pos p = matrix[r][c].p;
						r = p.r;
						c = p.c;
						matrix[r][c].c = '?';
					}
				}
			}

			void breadth()
			{
				q.push(start);
				while (!q.empty())
				{
					//print_maze();
					int r = q.front().r;
					int c = q.front().c;
					q.pop();
					//cout << "(" << r << "," << c << ")" << endl;

					if (((r - 1) >= 0) && (matrix[r - 1][c].c == ' ') && !matrix[r - 1][c].is_visited) //Above
					{
						if (goal_test(r - 1, c, r, c)) break;
						q.push(pos(r - 1, c));
					}

					if (((r + 1) < SIZE) && (matrix[r + 1][c].c == ' ') && !matrix[r + 1][c].is_visited) //Below
					{
						if (goal_test(r + 1, c, r, c)) break;
						q.push(pos(r + 1, c));
					}

					if (((c - 1) >= 0) && (matrix[r][c - 1].c == ' ') && !matrix[r][c - 1].is_visited) //Left
					{
						if (goal_test(r, c - 1, r, c)) break;
						q.push(pos(r, c - 1));
					}
					if (((c + 1) < SIZE) && (matrix[r][c + 1].c == ' ') && !matrix[r][c + 1].is_visited) //Right
					{
						if (goal_test(r, c + 1, r, c)) break;
						q.push(pos(r, c + 1));
					}
				}

				if (matrix[goal.r][goal.c].is_visited)
				{
					int r = goal.r;
					int c = goal.c;
					while (!((r == start.r) && (c == start.c)))
					{
						pos p = matrix[r][c].p;
						r = p.r;
						c = p.c;
						matrix[r][c].c = '?';
					}
				}
			}
			void print_maze()
			{
				for (int i = 0; i < SIZE; i++)
				{
					for (int j = 0; j < SIZE; j++)
					{
						if (i == this->goal.r && j == this->goal.c)
						{
							
							cout << "G ";
						}
						if (i == this->start.r && j == this->start.c)
							cout << "S ";
						else
							cout << matrix[i][j].c << " ";
					}
					cout << endl;
				}
				cout << endl << endl;
			}

			void print_way()
			{
				if (matrix[goal.r][goal.c].is_visited)
				{
					int r = goal.r;
					int c = goal.c;
					cout << "[" << r << "," << c << "],";
					while (!((r == start.r) && (c == start.c)))
					{
						pos p = matrix[r][c].p;
						r = p.r;
						c = p.c;
						cout << "[" << r << "," << c << "],";
					}
					cout << endl;
				}
				else
					cout << "Ingen väg funnen" << endl;
			}

			~maze(){}
		};
	}
}


void main_pqueue_maze()
{
	using namespace Course::Astar;
	
	maze m,m2;

	m.print_maze();

	cout << "A*-ALGORITMEN" << endl;
	m.astar();
	m.print_maze();
	m.print_way();

	cout << "BF-ALGORITMEN" << endl;
	m2.breadth();
	m2.print_maze();
	m2.print_way();
}
