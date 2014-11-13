#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class interval
{
private:
	T lower;
	T upper;
public:
	interval(){
		lower = upper = 0;
	}
#pragma region Operatoröverlagringar
	
	interval(T mean, double procent){
		lower = (T)(mean - mean * procent / 100.0);
		upper = (T)(mean + mean * procent / 100.0);
	}
	friend interval <T> operator + (const interval<T> &lop, const interval<T> &rop){ //addition
		interval<T> m;
		m.upper = lop.upper + rop.upper;
		m.lower = lop.lower + rop.lower;
		return m;
			}
	friend interval <T> operator * (const interval<T> &lop, const interval<T> &rop){ //multiplikation
		interval<T> m;
		m.upper = lop.upper * rop.upper;
		m.lower = lop.lower * rop.lower;
		return m;
	}

	friend interval <T> operator - (const interval<T> &lop, const interval<T> &rop){ //subtraktion
		interval<T> m;
		m.upper = lop.upper - rop.upper;
		m.lower = lop.lower - rop.lower;
		return m;
	}

	friend interval <T> operator / (const interval<T> &lop, const interval<T> &rop){ //division
		interval<T> m;
		m.upper = lop.upper / rop.upper;
		m.lower = lop.lower / rop.lower;
		return m;
	}

#pragma endregion

	double realative_error(){
		return (upper - lower) / 2.0 / mean();
		}
	double relative_error_procent(){
		return 100*(upper - lower) / 2.0 / mean();
	}
	double absolut_error(){
		return(upper - lower) / 2.0 ;
	}
	T mean(){
		return (upper + lower) / 2.0; //mellanvärde
		}
	void print_val(){
		cout << "Upper: " << upper <<endl;
		cout << "Lower: " << lower << endl;
		cout << "Relative error: "<< "+- " << relative_error_procent() <<"%"<< endl;
		cout << "" << endl;
		}


	~interval()
	{
	}
};

