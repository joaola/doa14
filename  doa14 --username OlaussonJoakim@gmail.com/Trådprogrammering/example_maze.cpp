#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

namespace Course
{
	namespace Maze
	{
		struct pos
		{
			pos() { r = -1; c = -1; }
			pos(int rr, int cc) { r = rr; c = cc; }
			int r;
			int c;
		};

		struct node
		{
			node() { p = pos(); is_visited = false; c = ' '; }
			char c;
			pos p; //Previous position
			bool is_visited;
		};

		const array<array<char, 5>, 5> MazeOne =
		{ { //array
			{ ' ', ' ', ' ', ' ', ' ' },
			{ 'X', ' ', ' ', 'X', ' ' },
			{ 'X', ' ', ' ', 'X', 'G' },
			{ 'X', 'X', ' ', 'X', 'X' },
			{ 'S', ' ', ' ', ' ', 'X' }
		} };


		const array<array<char, 5>, 5> MazeTwo =
		{ { //array
			{ ' ', ' ', ' ', ' ', ' ' },
			{ 'X', 'X', ' ', 'X', ' ' },
			{ ' ', ' ', ' ', 'X', 'G' },
			{ 'X', ' ', 'X', ' ', ' ' },
			{ 'S', ' ', 'X', ' ', 'X' }
		} };


		class maze
		{
		private:
			pos start, goal;
			vector<vector<node>> matrix;
			queue<pos> q;
			stack<pos> s;

			bool search_start()
			{
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
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
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
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
				matrix = vector<vector<node>>(5);
				for (int i = 0; i < 5; i++)
				{
					matrix[i] = vector<node>(5);
					for (int j = 0; j < 5; j++)
					{
						matrix[i][j] = node();
						matrix[i][j].c = MazeTwo[i][j];
					}
				}
				search_start();
				matrix[start.r][start.c].is_visited = true;
				search_goal();
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

					if (((r + 1) < 5) && (matrix[r + 1][c].c == ' ') && !matrix[r + 1][c].is_visited) //Below
					{
						if (goal_test(r + 1, c, r, c)) break;
						q.push(pos(r + 1, c));
					}

					if (((c - 1) >= 0) && (matrix[r][c - 1].c == ' ') && !matrix[r][c - 1].is_visited) //Left
					{
						if (goal_test(r, c - 1, r, c)) break;
						q.push(pos(r, c - 1));
					}
					if (((c + 1) < 5) && (matrix[r][c + 1].c == ' ') && !matrix[r][c + 1].is_visited) //Right
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
						matrix[r][c].c = '?';
						pos p = matrix[r][c].p;
						r = p.r;
						c = p.c;
					}
				}
			}

			void depth()
			{
				s.push(start);
				while (!s.empty())
				{
					//print_maze();
					int r = s.top().r;
					int c = s.top().c;
					s.pop();
					//cout << "(" << r << "," << c << ")" << endl;

					if (((r - 1) >= 0) && (matrix[r - 1][c].c == ' ') && !matrix[r - 1][c].is_visited) //Above
					{
						if (goal_test(r - 1, c, r, c)) break;
						s.push(pos(r - 1, c));
					}

					if (((r + 1) < 5) && (matrix[r + 1][c].c == ' ') && !matrix[r + 1][c].is_visited) //Below
					{
						if (goal_test(r + 1, c, r, c)) break;
						s.push(pos(r + 1, c));
					}

					if (((c - 1) >= 0) && (matrix[r][c - 1].c == ' ') && !matrix[r][c - 1].is_visited) //Left
					{
						if (goal_test(r, c - 1, r, c)) break;
						s.push(pos(r, c - 1));
					}

					if (((c + 1) < 5) && (matrix[r][c + 1].c == ' ') && !matrix[r][c + 1].is_visited) //Right
					{
						if (goal_test(r, c + 1, r, c)) break;
						s.push(pos(r, c + 1));
					}
				}

				if (matrix[goal.r][goal.c].is_visited)
				{
					int r = goal.r;
					int c = goal.c;
					while (!((r == start.r) && (c == start.c)))
					{
						matrix[r][c].c = '?';
						pos p = matrix[r][c].p;
						r = p.r;
						c = p.c;
					}
				}
			}

			void print_maze()
			{
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						cout << matrix[i][j].c;
					}
					cout << endl;
				}
				cout << endl << endl;
			}

			~maze(){}
		};
	}
}


void main_maze()
{

	using namespace Course::Maze;

	maze m1, m2;

	m1.print_maze();
	m1.breadth();
	m1.print_maze();

	m2.print_maze();
	m2.depth();
	m2.print_maze();
}
