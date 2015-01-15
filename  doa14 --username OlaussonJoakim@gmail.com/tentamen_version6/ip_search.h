#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <array>
#include <deque>
#include <queue>
using namespace std;
struct data_pq{

	string key;
	int antal;
	
	data_pq(){
		key = "";
		antal = 0;
	}

	data_pq(string key, int antal){
		this-> key = key;
		this-> antal = antal;
	}

	friend bool operator <(const data_pq& left, const data_pq& right)
	{
		return left.antal < right.antal;
	}
};
class ip_search
{
private: map <string, map<string, string>> m;
public:

	ip_search()
	{
	}

	void ReadFromFile(std::string fileName){
		std::ifstream fin;
		fin.open(fileName);
		if (!fin.good()){
			std::cout << "Could not open file!" << std::endl;
			return;
		}

		while (!fin.eof())
		{
			std::string ip1, ip2 = "";
			fin >> ip1 >> ip2;

			m[ip1][ip2] = ip1;
			m[ip2][ip1] = ip2;

			//cout << ip1 <<" "<< ip2 << endl;
		}
		std::cout << "Done!" << std::endl;
	}

	void ipSearch(string n){
		/*typedef map<string, map<string, string>>::iterator it_type;
		for (it_type iterator = m.begin(); iterator != m.end(); iterator++){*/
		map<string, string>m2 = m[n];
		for (auto & p: m2){
			cout<<p.first<<endl;
			if (p.second != n){
				cout << p.second << endl;
			}
		}

	}

	void copyTo(priority_queue<data_pq> &ips){
		data_pq d;
		for (auto& x : m) {
			d.antal = x.second.size();
			d.key = x.first;
			ips.push(d);
		}
	}

	~ip_search()
	{
	}
};

