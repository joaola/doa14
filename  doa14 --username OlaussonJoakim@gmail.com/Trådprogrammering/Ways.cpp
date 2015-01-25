
#include <iostream>
#include <iomanip>
#include <utility>
#include <memory>
#include <vector>
#include <tuple>
#include "../Course/Console.h"
using namespace std;

namespace CourseRecursive
{
	using namespace Course;

	int ways(int x, int y)
	{
		int n=0;

		if ( (x==0) && (y==0) )
		{
			n = 1;
		}
		else
		{
			if ( x>0 )
				n += ways(x-1,y);
			
			if ( y>0 )
				n += ways(x,y-1);
		}
		return n;
	}

	void ways_print(int x, int y, int &i, int &n)
	{
		Console::gotoxy(i*4, Console::wherey());
		cout << x << ":" <<  y << " ";
		if ( (x==0) && (y==0) )
		{
			n++; //One way
			cout << endl;
		}
		else
		{
			i++;
			if ( x>0 )
			{
				ways_print(x-1,y,i,n);
			}

			if ( y>0 )
			{
				ways_print(x,y-1,i,n);
			}
			i--;
		}
	}

	struct x_y
	{
		int x;
		int y;
	};

	void ways_matrix(int x, int y, int &i, int &n, tuple<int,int> **m)
	{
		m[n][i]=tuple<int,int>(x,y);
		if ( (x==0) && (y==0) )
		{
			n++;
		}
		else
		{
			i++;
			if ( x>0 )
			{
				ways_matrix(x-1,y,i,n,m);
			}

			if ( y>0 )
			{
				ways_matrix(x,y-1,i,n,m);
			}
			i--;
		}
	}
	


}

using namespace CourseRecursive;

void main_recursive_ways()
{
	cout << "Ways to (0,1): " << ways(0,1) << endl ;
	cout << "Ways to (0,2): " << ways(0,2) << endl ;
	cout << "Ways to (0,3): " << ways(0,3) << endl ;
	cout << "Ways to (1,1): " << ways(1,1) << endl ;
	cout << "Ways to (1,2): " << ways(1,2) << endl ;
	cout << "Ways to (1,3): " << ways(1,3) << endl ;
	cout << "Ways to (2,2): " << ways(2,2) << endl ;
	cout << "Ways to (2,3): " << ways(2,3) << endl ;
	cout << "Ways to (3,3): " << ways(3,3) << endl ;
	cout << "Ways to (4,4): " << ways(4,4) << endl ;
	
	//===Utskrift av en form av ett rekursionsträd===
	cout << endl;
	int i=0, n=0;
	ways_print(2,3,i, n);

	//===Genererering av matris innehållande alla vägar===
	cout << endl;
	int rows = ways(2,3);
	int cols = 2+3+1;
	tuple<int,int> **m;
	m = new tuple<int,int> *[rows];

	for (int k=0; k<rows; k++) 
	{
		m[k]=new tuple<int,int>[cols];
		for(int j=0; j<cols; j++)
		{
			m[k][j]=tuple<int,int>(0,0);
		}
	}

	i=n=0;
	ways_matrix(2,3,i, n,m);

	for (int k=0; k<rows; k++) 
	{
		for(int j=0; j<cols; j++)
		{
			cout << get<0>(m[k][j]) << ":" << get<1>(m[k][j]) << " ";
		}
		cout << endl;
	}

	for (int k=0; k<rows; k++) 
	{
		delete m[k];
	}
	delete m;
}
