#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <array>
/*template <class Key,
	class T, 
		class Hash = hash<Key>,
			class Pred = equal_to<Key>,
				class Alloc = allocator <pair<const key, T>>>*/

class Data{
	string ipNr;
	int antal_IP;
	int antal_Uppkopplingar;
	
	public Data(){
		this->ipNr = "";
		this->antal_IP = 0;
		int antal_Uppkopplingar = 0;
	}
	public Data(string ipNr, int antal_IP, int antal_Uppkopplingar){
		string ipNr = ipNr;
		this->antal_IP = antal_IP;
		this->antal_Uppkopplingar = antal_Uppkopplingar;

	}

	inline operator Data=(Data a){
		this->ipNr = a.IpNr;
		this->antal_IP = a.antal_IP;
		this->antal_Uppkopplingar = a.antal_Uppkopplingar;
		return a;
	}

	public override bool Equals(object obj)
	{
		return v == ((Data)obj).ipNr;
	}

	public override int GetHashCode()
	{
		return ipNr.GetHashCode();
	}

	public override string ToString()
	{
		return "" + ipNr;
	}
};
template <unordered_map>
class ip_search
{
private:
	Data dat;
	vector<string>key;
	vector<int>value;
	unordered_map<string, int>ipList;
public:

	ip_search()
	{

	}

	void ReadFromFile(string fileName){
		string str, strRow;
		ifstream fin;
		fin.open(fileName);
		if (!fin.good()){
			cout << "Could not open file!" << endl;
			return;
		}

		while (!fin.eof())
		{
			string ip = "";
			fin >> ip;
			if (ipList(ip)){
				this->ipList[key]++
			}
		}

		cout << "Done!" << endl;
	}

	~ip_search()
	{
	}
};

