#include "ip_search.h"

#include <math.h>
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
		//unordered_map<string, int> i;
		//ReadFromFile("ip_two.txt");
		
	}
}


int main(){
	U31::main_one();
	system("PAUSE");
	return 0;
}