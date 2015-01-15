#include "ip_search.h"
#include "hr_time.h"
#include "math.h"
#include <iostream>
using namespace std;

namespace U31{

	int fakRek1(int n){ //Fakultetsfunktion
		if (n == 0){
			return 1;
		}
		return n* fakRek1(n - 1);
	}

	float fakRek2(float x, int n){ // Rekursiv funktion
		int i = 0;
		if (n <= i){
			return (x*pow((-x), 2 * n) / (fakRek1(2*n + 1)));
		}
		return (x*pow((-x), 2 * n) / ((fakRek1(2*n + 1)))) + fakRek2(x, n - 1);
	}

	float fakIt(float x, int n){ //Iterativ funktion
			float result = 0;
			for (int i = 0; i <= n; i++){
				result += x*pow((-x), 2 * i) / fakRek1(2*i + 1);
			}
			return result;
	}

	void main_one(){
		float n = 0; 
		int i = 0;
		cout << "Ange n: ";
		cin >> n;
		cout << "Ange i: ";
		cin >> i;
		//Resultat
		cout<<"Rekursiv: "<<fakRek2(n, i)<<endl;
		cout << "Iterativ: "<<fakIt(n, i) << endl;
		//Tid
		volatile int nloop = 10000;
		CStopWatch sw1;
		sw1.startTimer();
		for (int i = 0; i < nloop; i++){
			fakRek2(n,i);
		}
		sw1.stopTimer();
		cout << "Tid för rekursiv funktion: " << (sw1.getElapsedTime() * 10000) / nloop << "ns" << endl << endl;

		CStopWatch sw2;
		sw2.startTimer();
		for (int i = 0; i < nloop; i++){
			fakIt(n, i);
		}
		sw2.stopTimer();
		cout << "Tid för iterativ funktion: " << (sw2.getElapsedTime() * 10000) / nloop << "ns" << endl << endl;

	}
}

namespace U32{
	void main_two(){
		ip_search ip;
		ip.ReadFromFile("ip_three.txt");
		ip.ipSearch("102.128.169.179");

	}
}

namespace U33{
	void main_three(){

		priority_queue<data_pq>ips;
		ip_search ip;

		ip.ReadFromFile("ip_three.txt");
		ip.copyTo(ips);

		for (int i = 0; i < 10; i++)
		{
			cout << ips.top().key << " " << ips.top().antal << endl;
			ips.pop();
		}
	}
}

int main(){
	U31::main_one();
	U32::main_two();
	U33::main_three();
	system("PAUSE");
	return 0;
}