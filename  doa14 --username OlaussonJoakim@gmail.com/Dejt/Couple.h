#pragma once
#include "Person.h"
using namespace std;
class Couple//: public Person
{
private:
public:

	Couple()
	{
	}

	int compareInterests(Person girl, Person boy){
		int sameInterests = 0;
		for (int i = 0; i < girl.getInterest().length(); i++){
			for (int j = 0; j < boy.getInterest().length(); j++){
				if(girl.getInterest()[i] == boy.getInterest()[i]){
					sameInterests++;
				}

			}
		}
		return sameInterests;
	}

	void createCouple(forward_list<Person>&girlList, forward_list<Person>&boyList, forward_list<forward_list<Person>>&coupleList, int limInt){
		Person girl;
		Person boy;

		for (int i = 0; i < girlList.length(); i++){ // fortsätt med denna funktion senare
			girl = girlList[i];

		}
	}

	~Couple()
	{
	}
};

