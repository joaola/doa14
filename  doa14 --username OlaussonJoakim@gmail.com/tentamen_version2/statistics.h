#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#pragma once
using namespace std;
struct data{
	long long sum; //Totalsumma som de n personerna har haft i inkomst
	int n; //Antal personer i detta 1000-Kronorsintervall
	data(long long sum, int n){
		this->sum = sum;
		this->n = n;
	}

	data(){
		this->sum = 0;
		this->n = 0;
	}
};

class statistics
{
private:
	vector<data>salary;
public:

	statistics()
	{
		for (int i = 0; i < 1000; i++){


			data dat;
			this->salary.push_back(dat);
		}
	}

	void clear(){
		for (int i = 0; i < 1000; i++){
			this->salary[i].sum = 0;
			this->salary[i].n = 0;
		}
	}

	void print(){
		for (int i = 0; i < 1000; i++){
			cout << "Totalsumman: " << this->salary[i].sum << endl;
			cout << "Antal personer: " << this->salary[i].n << endl;
		}
	}

	void ReadFromFile(string fileName){
		ifstream fin;
		string str, strRow;

		fin.open(fileName);
		if (!fin.good()){
			cout<<"Kunde ej öppna filen!"<<endl;
			return;
		}

		while (getline(fin, strRow)){
			istringstream iss(strRow);
			long long salary = 0;
			//int index = 0;
			iss >> salary;
			cout << salary;
			if (salary <= 1000000 && salary >= 0){ //Läs in lönen som är mellan 0-1000000
				long long index = ((long long)(salary / 1000));
				this->salary[index].sum+=salary; //Lön
				this->salary[index].n++; //Antal personer

				
			}
		}

		cout << "Läst färdigt!" << endl;


	}

	float calculate_mean(){

		return 0;
	}

	int percentile(int procent){
		return 0;
	}

	~statistics()
	{
	}
};

