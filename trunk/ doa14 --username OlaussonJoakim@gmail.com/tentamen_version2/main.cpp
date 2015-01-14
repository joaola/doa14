#include "wordCounter.h"
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
		//stat.print();
		stat.clear();
		cout << "Mean: " << stat.calculate_mean() << endl;
	}
}

namespace U33{
	void main_three(){
		priority_queue <data_pq>wordList;
		wordCounter w;
		w.ReadFromFile("nils_holgersson.txt");
		w.copyTo(wordList);
		for (int i = 0; i < 20; i++)
		{
			cout << wordList.top().ord << " " << wordList.top().antal << endl;
			wordList.pop();
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