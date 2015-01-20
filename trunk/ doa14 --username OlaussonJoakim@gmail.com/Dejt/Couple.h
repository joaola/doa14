#pragma once

#include "../forward_list_test/forward_list.h"

#include "Person.h"
using namespace std;
class Couple
{
private:
public: forward_list<Person> couples;
		Person p;

		Couple()
		{
		}

		int compareInterests(Person girl, Person boy){
			int sameInterests = 0;
			for (int i = 0; i < girl.getInterest().length(); i++){
				for (int j = 0; j < boy.getInterest().length(); j++){
					if (girl.getInterest()[i] == boy.getInterest()[i]){
						sameInterests++;
					}

				}
			}
			return sameInterests;
		}

		void createCouple(forward_list<Person>&girlList, forward_list<Person>&boyList, forward_list<forward_list<Person>>&coupleList){
			Person girl;
			Person boy;

			for (int i = 0; i < girlList.length(); i++){ // fortsätt med denna funktion senare
				girl = girlList[i];

				for (int j = 0; j < boyList.length(); j++){
					if (compareInterests(boyList[j], girlList[i]) >= 4){
						boy = boyList[j];
					}
				}
				couples.push_front(boy);
				coupleList.push_front(couples);
				//Ska ta bort matchande pojke och flicka från vardera lista
			}

		}
		~Couple()
		{
		}
};


