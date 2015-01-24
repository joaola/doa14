#pragma once
#include <string>
#include<iostream>
#include <sstream>

#include "../forward_list_test/forward_list.h"
using namespace std;

class Person

{

private:
	string name;
	forward_list<string>interests;

public:

	Person()
	{
		name = "";
	}

	Person(string name)
	{
		this->name = name;
	}

	//Operatoröverlagring ==
	bool operator == (Person& right){
		if (name == right.name){
			return true;
		}
		else
			return false;
	}
	//Operatoröverlagring <<
	/*friend ostream& operator<<(ostream& os, Person& p)
	{
		os << p.name<<p.interests.PrintList();
		return os;
	}*/

	/*void setName(string name)
	{
		this->name = name;
	}*/
	
	/*string getName()
	{
		return name;
	}*/

	void print(){
		cout << this->name<< endl;
		interests.PrintList();
		cout << endl;
	}

	void addInterest(string i)
	{
		interests.push_front(i);
	}

	forward_list<string> getInterest(){
		return this->interests;
	}

	~Person()
	{
	}
};
