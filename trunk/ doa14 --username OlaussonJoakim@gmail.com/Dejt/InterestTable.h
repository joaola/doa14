#pragma once
#include <string>
#include <fstream>
#include <ostream>
#include <iostream>
#include <sstream>
#include <vector>
#include "../forward_list_test/forward_list.h"
using namespace std;

class InterestTable
{
private:
	forward_list<string>interests;
public:

	InterestTable()
	{
	}

	InterestTable(string interests)
	{
		this->interests.push_front(interests);
	}

	void addInterest(string s){
		interests.push_front(s);
	}
	
	~InterestTable()
	{
	}
};

