#include "CouplesList.h"
#include "PersonList.h"
#include "InterestTable.h"
#include "Person.h"
#include "../forward_list_test/forward_list.h"

#include "string.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

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
		Person p1 (word);
		while (iss>>word){
			p1.addInterest(word);
		}

		list.push_front(p1);
	}

	fin.close();
}

void mainTest(){
	
}

int main(){
	forward_list<Person>pojkLista;
	forward_list<Person>flickLista;
	forward_list<forward_list<Person>>ListOfPersons;
	//mainTest();
	ReadFromFile("pojkfil.txt", pojkLista);
	ReadFromFile("flickfil.txt", flickLista);

	for (int i = 0; i < pojkLista.length(); i++)
	{
		pojkLista[i].print();
	}

	for (int i = 0; i < flickLista.length(); i++){
		flickLista[i].print();
	}

	system("PAUSE");
	return 0;
}