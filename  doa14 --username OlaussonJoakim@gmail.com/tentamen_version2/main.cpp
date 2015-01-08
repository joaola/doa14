#include "sumCounter.h"
#include "statistics.h"
#include <iostream>
using namespace std;
namespace U31{
	void main_one(){
		sumCounter s1;
		int n = 0;
		int i = 0;
		cout << "n: ";
		cin >> n;
		cout<<"Iterativ: "<<s1.sum_it(n)<<endl;
		cout << "Rekursiv: " << s1.sum_rek(n) << endl;
	}
}

namespace U32{
	void main_two(){
		statistics stat;
		stat.ReadFromFile("salary.txt");
		stat.print();
		stat.clear();
	}
}
int main(){
	U31::main_one();
	U32::main_two();
	system("PAUSE");
	return 0;
}