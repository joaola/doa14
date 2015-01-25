#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>
using namespace std;

#include "Watch.h"
using namespace Course;


//---Power1------------------------------------------------------
double Power1(double base, unsigned int exponent)
{
	double result=1.0;
	int i;

	for (i=0; i<exponent; i++)
	{
		result = result*base;
	}//for

	return result;
}

//---Power2------------------------------------------------------
double Power2(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1.0;
	else if ( (exponent & 0x0001) == 0 ) //Jämn exponent
		return Power2(base*base, exponent/2);
	else //Udda exponent
		return Power2(base*base, exponent/2)*base;
}

//---Power3------------------------------------------------------
double Power3(double base, unsigned int exponent)
{
	if ( base > 0 )
		return exp( exponent*log(base) );
	else if ( (base < 0) && ((exponent & 0x0001) != 0) ) //Udda bas
		return -exp( exponent*log(-base) );
	else if ( (base < 0) && ((exponent & 0x0001) == 0) ) //Jämn bas
		return exp( exponent*log(-base) );
	else
		return 0;
}

#pragma optimize("",off)
void main_execution_time_power()
{
	Watch  w;
	Course::nanoseconds t0,t1,t2,t3;

	double x,y=0.5; 
	long   i,j;
	long   n, nLoop;

	cout << setw(5) << "n";
	cout << setw(15) << "Algoritm 1";
	cout << setw(15) << "Algoritm 2";
	cout << setw(15) << "Algoritm 3\n";
	nLoop=9000000L;
	//nLoop=1000;
	cout.precision(1 );
	cout.setf(ios::fixed);

	//for (n=100000; n<1000000; n=n+100000)
	//for (n=100; n<1000; n=n+100)
	for (n=10; n<300; n=n+10)
	{
		w.restart();
		for (i=0; i<nLoop; i++) { ; }
		t0=w.elapsedNs();
		
		w.restart();
		for (i=0; i<nLoop; i++) { x=Power1(1.0, n);}
		t1=w.elapsedNs();

		w.restart();
		for (i=0; i<nLoop; i++) { x=Power2(1.0, n);}
		t2=w.elapsedNs();

		w.restart();
		for (i=0; i<nLoop; i++) { x=Power3(1.0, n);}
		t3=w.elapsedNs();
	   
		cout << setw(3)  << n << ": " << setw(15) << double(t1.count()-t0.count())/double(nLoop);
		cout << setw(15) << (t2.count()-t0.count())/(double)nLoop;
		cout << setw(15) << (t3.count()-t0.count())/(double)nLoop << "\n";
	}
}
#pragma optimize("",on)
