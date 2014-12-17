#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#pragma once
using namespace std;
class statistics
{
private: int* salary;
public:
	statistics(){
		this->salary = new int[1000001];
	}
	void ReadFromFile(string fileName){
		string str, strRow;
		ifstream fin;
		fin.open("salary.txt");
		if (!fin.good()){
			cout << "Could not open file!" << endl;
			return;
		}

		while (getline(fin, strRow)){
			istringstream iss(strRow);
			int index;
			iss >> index;
			if (index >= 20000 && index <= 1000000)
				this->salary[index]++;
		}

		cout << "Done!" << endl;
	}
	void clear(){
		for (int i = 0; i <= 1000000; i++){
			this->salary[i] = 0;
		}
		cout << "Cleared!" << endl;
	}

	int calculate_mean(){
		long long sum = 0;
		int divider = 0;
		for (int i = 0; i <= 1000000; i++){
			sum += (i*this->salary[i]);
			divider += this->salary[i];
		}
		return((int)((sum / divider)));;
	}

	int calculate_median(){
		int people = 0;
		int middleman = 0;
		for (int i = 0; i <= 1000000; i++){
			people += this->salary[i];
		}
		middleman = people / 2;
		people = 0;
		for (int i = 0; i <= 1000000; i++){
			people += this->salary[i];
			if (people >= middleman){
				return i;
			}
			
		}
		return 0;
	}

	~statistics(){
		delete[] salary;
	}
};

