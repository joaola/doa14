#pragma once
#include <string>
#include<iostream>
#include <sstream>

#include "InterestTable.h"
#include "Couple.h"
#include "CouplesList.h"
#include "../forward_list_test/forward_list.h"
using namespace std;
class Person
{
private:
	string name;
	//string gender;
	forward_list<string>interests;

public:

	Person()
	{
		name = "";
		//gender = "";
	}

	Person(string name)
	{
		this->name = name;
	}

	bool operator == (Person& right){
		if (name == right.name){
			return true;
		}
		else
			return false;
	}

	void setName(string name)
	{
		this->name = name;
	}

	/*void setGender(string gender){
		this->gender = gender;
	}*/
	
	string getName()
	{
		return name;
	}

	void print(){
		cout << this->name<< endl;
		cout<<this->interests.PrintList()<<endl;
	}

	/*string getGender(){
		return gender;
	}*/

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

