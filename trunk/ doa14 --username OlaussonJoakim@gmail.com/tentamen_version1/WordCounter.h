#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
#pragma once
class WordCounter
{
private: map <string,int> words;
public:

	WordCounter()
	{
	}

	void ReadFromFile(string fileName){
		string str, strRow;
		ifstream fin;
		fin.open("nils_holgersson.txt");
		if (!fin.good()){
			cout << "Could not open file!" << endl;
			return;
		}

		while (!fin.eof())
		{
			string key = "";
			fin >> key;
			words[key]++;
		}

		cout << "Done!" << endl;
	}

	string mostFrequentWord(){
		string word;
		int antal = 0;

		for (auto& x : this->words){
			if (x.second > antal){
				antal = x.second;
				word = x.first;
			}
		}
		return word;
	}

	~WordCounter()
	{
	}
};

