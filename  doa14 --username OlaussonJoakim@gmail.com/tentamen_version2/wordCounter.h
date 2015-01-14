#pragma once
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
#include <deque>
using namespace std;

struct data_pq{
	string ord;
	int antal;
	data_pq(string ord, int antal){
		this->ord = ord;
		this->antal = antal;
	}

	friend bool operator <(const data_pq& left, const data_pq& right)
	{
		return left.antal < right.antal;
	}
};

class wordCounter
{
private: map <string, int> word;

public:

	wordCounter()
	{
	}

	void ReadFromFile(string fileName){
		string str, strRow;
		ifstream fin;
		fin.open(fileName);
		if (!fin.good()){
			cout << "Kan ej öppna filen" << endl;
		}
		while (!fin.eof()){
			fin >> str;
			word[str]++;
		}
	}

	/*void MostFrequent(){
		string word;
		int antal = 0;

		for (auto& x : this->word){
			if (x.second>antal){
				antal = x.second;
				word = x.first;

			}
		}

	}*/

	void copyTo(priority_queue<data_pq> &freqWord){

		for (auto& x : word) {
			data_pq a(x.first, x.second);
			//std::cout << x.first << ": " << x.second << std::endl;
			freqWord.push(a);
		}

	}

	~wordCounter()
	{
	}
};

