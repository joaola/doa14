#include "sumCounter.h"
#include <iostream>
using namespace std;
namespace U31{
	void main_one(){
		sumCounter s1;
		int n;
		cin >> n;
		cout<<s1.sum_it(n);
	}
}
int main(){
	U31::main_one();
	system("PAUSE");
	return 0;
}