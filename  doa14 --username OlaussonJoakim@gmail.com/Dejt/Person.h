#pragma once
#include <string>
#include<iostream>
#include <sstream>

#include "InterestTable.h"
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
	friend ostream& operator<<(ostream& os, Person& p)
	{
		os << p.name<<p.interests.PrintList();
		return os;
	}	

	void setName(string name)
	{
		this->name = name;
	}
	
	string getName()
	{
		return name;
	}

	void print(){
		cout << this->name<< endl;
		cout<<this->interests.PrintList()<<endl;
	}

	void addInterest(string i)
	{
		this->interests.push_front(i);
	}

	forward_list<string> getInterest(){
		return interests;
	}

	~Person()
	{
	}
};
