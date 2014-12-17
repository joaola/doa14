#include "statistics.h"
#include "WordCounter.h"

#include <iostream>
#include <deque>
#include "string.h"
#include <fstream>
#include <sstream>
using namespace std;
namespace U31
{
	bool palindrome(string s){
		deque<char> palindrome;
		/*for (int i = 0; i < int(s.length()); i++){
			if (s[i] != ' ')
				palindrome.push_back(s[i]);
		}*/

		while (!palindrome.empty()){
			if (palindrome.back() != palindrome.front()){
				return false;
			}
			if (!palindrome.empty())
				palindrome.pop_back();
			if (!palindrome.empty())
				palindrome.pop_front();

		}
		return true;

	
	}

	bool palindrome_recursive(string str, int s, int e){
		if (s >= e)
			return true;
		if (str[s] == str[e] && palindrome_recursive(str, s + 1, e - 1))
			return true;
		else
			return false;
	}

	void main_one(){
		string s = "ana";
		cout << palindrome(s) << endl;
		cout << palindrome_recursive(s, 0, s.length() - 1) << endl;
	}
}
namespace U32{
	void main_two(){
		statistics s1;
		s1.clear();
		s1.ReadFromFile("salary.txt");
		cout << s1.calculate_mean() << endl;
		cout << s1.calculate_median() << endl;

	}
}
namespace U33{

	void main_three(){
		WordCounter w1;
		w1.ReadFromFile("nils_holgersson.txt");
		cout << w1.mostFrequentWord()<<endl;
	}
}

int main(){
	U31::main_one();
	U32::main_two();
	U33::main_three();
	cout << endl;
	system("PAUSE");

	return 0;
}