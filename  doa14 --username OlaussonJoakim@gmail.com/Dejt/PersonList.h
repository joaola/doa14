#pragma once
#include "Person.h"
#include "../forward_list_test/forward_list.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class PersonList
{
public:
	//forward_list<forward_list<Person>>ListOfPersons; //Lista med alla personer
	forward_list<string>pojkLista;
	forward_list<string>flickLista;

	PersonList()
	{
	}

	void addToPeopleList(forward_list<Person> girlList, forward_list<Person>boyList, forward_list<Person> peopleList){
		for (int i = 0; i < girlList.length(); i++){
			peopleList.push_front(girlList[i]);
		}

		for (int i = 0; i < boyList.length(); i++){
			peopleList.push_front(boyList[i]);
		}
	}

	void ReadFromFile(string fileName, forward_list<Person>& list){
		string str, strRow;
		ifstream fin;
		fin.open(fileName);
		if (!fin.good()){
			cout << "Gick ej att öppna" << endl;
			return;
		}
		while (getline(fin, strRow)){
			istringstream iss(strRow);
			string word;
			iss >> word;
			Person p1(word);
			while (iss >> word){
				p1.addInterest(word);
			}

			list.push_front(p1);
		}

		fin.close();
	}

	void Clear(){
		pojkLista.clear();
		flickLista.clear();
	}

	~PersonList()
	{
	}
};