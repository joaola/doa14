#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>
using namespace std;

#include "Watch.h"
using namespace Course;

int RFib(int n)
{
	if ( n <= 1 )
		return 1;
	else
	{
		return RFib(n-1) + RFib(n-2);
	}
}

int IFib(int n)
{
	if ( n <= 1)
		return 1;
	else
	{
		int a0=1;
		int a1=1;
		int a2=1;
		int t;

		for ( int i=2; i<=n; i++)
		{
			a2 = a1+a0;
			a0=a1;
			a1=a2;
		}
		return a2;
	}
}


void main_recursive_fibonacci() {
    Watch w;
    Course::microseconds t0, t1, t2, t3;
    long nLoop = 1000000L;
    int x,y;
    
    cout << setw(5) << "n";
    cout << setw(15) << "RFib (ns)";
    cout << setw(15) << "value";
    cout << setw(15) << "Ifib (ns)";
    cout << setw(15) << "value"  << endl;
    nLoop=10000L;
    cout.precision(2);
    cout.setf(ios::fixed);
    
    for (int n = 1; n < 25; n++) {
        w.restart();
        for (int i = 0; i < nLoop; i++) {
            ;
        }
        t0 = w.elapsedUs();

        w.restart();
        for (int i = 0; i < nLoop; i++) {
            x = RFib(n);
        }
        t1 = w.elapsedUs();

        w.restart();
        for (int i = 0; i < nLoop; i++) {
            y = IFib(n);
        }
        t2 = w.elapsedUs();
        
        cout << setw(3)  << n << ": " << setw(15) << 1e3*double(t1.count()-t0.count())/nLoop << setw(15) << x;
        cout << setw(15) << 1e3*(t2.count()-t0.count())/ (double)nLoop << setw(15) << y <<  endl;
        
    }

}