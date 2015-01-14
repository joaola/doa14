#include "math.h"
#include <iostream>
#include "observatory.h"
using namespace std;

namespace U31{

	float RekFak(float x, int n){ //3.1 a)
		if (x == 0){
			return 0;
		}
		else if (n == 0){
			return 1;
		}
		else if (n > 0){
			return(x*pow(x, n-1));
		}
		else{
			return ((1 / x)*pow(x, n + 1));
		}
	}

	float ItFak(float x, int n){ //3.1 b)
		float result = 1.0;
		while (n--){
			result *= x;
		}
		return result;
	}

	void main_one(){
		float x;
		int n;
		cout << "Ange X: ";
		cin >> x;
		cout << "Ange N: ";
		cin >> n;
		cout << "Rekursiv: " << RekFak(x, n) << endl;
		cout << "Iterativ: " << ItFak(x, n) << endl;
	}
}

namespace U32{
	void main_two(){ // 3.2
		observatory o;
		o.ReadFromFile("testfil-10.txt");
		o.Print();
	}
}

int main(){
	U31::main_one();
	U32::main_two();
	system("PAUSE");
	return 0;
}