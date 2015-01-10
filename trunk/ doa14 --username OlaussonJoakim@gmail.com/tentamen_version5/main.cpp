#include "ip_search.h"

#include <math.h>
#include <iostream>
#include <deque>
#include <queue>
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
			return (pow(-x, 2*n) / 2*fakRek1(n));
		}
		return (pow(-x, 2*n) / 2*fakRek1(n)) + fakRek2(x, n-1);

	}

	float fakIt(float x, int n){ //Iterativ funktion
		float result = 0;
		for (int i = 0; i <= n; i++){
			result += pow(-x,2*i) / 2*fakRek1(i);
			}
		return result;
		}
	void main_one(){
		cout << "Rekursiv: " << fakRek2(3.0, 3) << endl;
		cout << "Iterativ: " <<fakIt(3.0,3)<<endl;
	}
}
namespace U32{
	void main_two(){
		ip_search ip;
		ip.ReadFromFile("ip_two.txt");
		cout << ip.Antal("119.128.105.153") << endl;


	}

}

namespace U33{
	void main_three(){
		priority_queue<data_pq>ips;

		ip_search ip;
		ip.ReadFromFile("ip_two.txt");
		//cout << ip.Antal("119.128.105.153") << endl;
		ip.copyTo(ips);
		
		for (int i= 0; i < 10; i++)
		{
			cout << ips.top().ip << " " <<ips.top().antal<< endl;
			ips.pop();
		}
		
	}
}

int main(){
	//U31::main_one();
	//U32::main_two();
	U33::main_three();
	system("PAUSE");
	return 0;
}