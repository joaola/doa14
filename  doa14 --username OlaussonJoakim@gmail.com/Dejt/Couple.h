#pragma once
#include "Person.h"
using namespace std;
class Couple //: public Person
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

	void createCouple(forward_list<Person>&girlList, forward_list<Person>&boyList, forward_list<forward_list<Person>>&coupleList){
		Person girl;
		Person boy;
		Person couples;

		for (int i = 0; i < girlList.length(); i++){ // forts�tt med denna funktion senare
			girl = girlList[i];

			for (int j = 0; j < boyList.length(); j++){
				boy = boyList[j];
			}

		}
	}

	~Couple()
	{
	}
};

