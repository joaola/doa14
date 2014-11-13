#include "hr_time.h"
#include <iostream>
using namespace std;

int fak(int n)
{
	int r;
	if (n == 1){
		r = 1;
	}
	else{
		r = n*fak(n - 1);
	}
		return r;
}

int fak_it(int n){ 
	int r=n;
	for (int i = n-1; i > 0; i--)
	{
		r *= i;
	}
	return r;
}

int main(){
	CStopWatch s;
	s.startTimer();
	for (int t = 0; t < 1000000; t++)
	{
		fak_it(4);
	}
	s.stopTimer();
	cout << "Time1=" << s.getElapsedTime() * 1000000000/1000000 << "ns" << endl << endl;
	cout << fak(3)<<endl;
	cout << fak_it(3) << endl;
	system("PAUSE");
	return 0;
}