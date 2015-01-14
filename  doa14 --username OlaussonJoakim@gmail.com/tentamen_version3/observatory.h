#pragma once
#include <unordered_map>
#include <map>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

struct data{
	list <int>observatory; //Lista med observatorier(STL-klassen)
	//string time;
	int x;
	int y;

	data(){
		//string time = "";
		int x = 0;
		int y = 0;
	}

	data(string time, int x, int y){
		//this->time = time;
		this->x = x;
		this->y = y;
	}

	void addObservatory(int o){
		observatory.push_front(o);
	}
};

class observatory
{
private: unordered_map<string, data>m;

public:

	observatory()
	{

	}

	void ReadFromFile(string fileName){
		std::string str, strRow;
		std::ifstream fin;
		fin.open(fileName);
		if (!fin.good()){
			std::cout << "Could not open file!" << std::endl;
			return;
		}

		while (!fin.eof())
		{
			int obs, x, y = 0;
			string time = "";
			fin >> obs >> time >> x >> y;
			data d (time, x, y);
			d.addObservatory(obs);
			this->m[time] = d;
			
			//cout << obs << time << x << y << endl;

		}
		std::cout << "Done!" << std::endl;
	}

	void Print(){
		for (auto& x : this->m){

			for (list<int>::const_iterator iterator = x.second.observatory.begin(); iterator != x.second.observatory.end();++iterator){
				cout << "Observatory: " << *iterator <<" Time: "<< x.first << " Riktning: " <<x.second.x << x.second.y << endl;
			}
		}
	}

	~observatory()
	{
	}
};

