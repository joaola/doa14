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
#include<queue>
using namespace std;
struct data_pq{
	string ip;
	int antal;
	data_pq(string ip, int antal){
		this->ip = ip;
		this->antal = antal;
	}

	friend bool operator <(const data_pq& left, const data_pq& right)
	{
		return left.antal < right.antal;
	}

	/*inline data_pq operator=(data_pq a) {
		this->ip = a.ip;
		this->n = a.n;
		return a;
	}*/
};
class ip_search
{
private:
	//std::string a;
	std::unordered_map <std::string, int> ipList;
public:

	ip_search()
	{

	}

	int Antal(std::string a){
		return ipList[a];
	}

	void ReadFromFile(std::string fileName){
		//std::string str, strRow;
		std::ifstream fin;
		fin.open(fileName);
		if (!fin.good()){
			std::cout << "Could not open file!" << std::endl;
			return;
		}

		while (!fin.eof())
		{
			//std::istringstream iss(str);
			std::string ip1,ip2 = "";
			fin >> ip1>>ip2;
			ipList[ip2]++;
			//cout << ip1 <<" "<< ip2 << endl;
			//system("PAUSE");
		}
		std::cout << "Done!" << std::endl;
	}

	void copyTo(priority_queue<data_pq> &ips){

		for (auto& x : ipList) {
			data_pq a(x.first, x.second);

			//std::cout << x.first << ": " << x.second << std::endl;
			ips.push(a);
		}
		
	}
	~ip_search()
	{
	}
};


