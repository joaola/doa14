#include "interval.h"
#include <iostream>
using namespace std;

int main(){
	interval<double> i1(2,1); 
	interval<double> u1(5, 1);
	interval<double> r1 = u1 / i1;
	interval<double> p1 = u1*i1;

	interval<double> i2(2, 2);
	interval<double>u2(5, 2);
	interval <double> r2 = u2 / i2;
	interval <double> p2 = u2*i2;

	interval<double> i3(2, 4);
	interval<double>u3(5,2);
	interval<double>r3 = u3 / i3;
	interval<double>p3 = u3*i3;

	i1.print_val();
	r1.print_val();
	p1.print_val();

	cout << "" << endl; //radbyte
	i2.print_val();
	r2.print_val();
	p2.print_val();

	cout << "" << endl; //radbyte

	i3.print_val();
	r3.print_val();
	p3.print_val();

	system("PAUSE");
	return 0;
}