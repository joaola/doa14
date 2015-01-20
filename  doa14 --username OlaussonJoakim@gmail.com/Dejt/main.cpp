//#include "Couple.h"
//#include "PersonList.h"
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
		Person p1(word);
		while (iss >> word){
			p1.addInterest(word);
		}

		list.push_front(p1);
	}

	fin.close();
}

void addToPeopleList(forward_list<Person> girlList, forward_list<Person>boyList, forward_list<Person>& peopleList){
for (int i = 0; i < girlList.length(); i++){
peopleList.push_front(girlList[i]);
}

for (int i = 0; i < boyList.length(); i++){
peopleList.push_front(boyList[i]);
}
}

void mainTest(){
	
}

int main(){
	forward_list<Person>pojkLista;
	forward_list<Person>flickLista;
	forward_list<Person>personList;
	forward_list<forward_list<Person>> parLista;
	ReadFromFile("pojkfil.txt", pojkLista);
	ReadFromFile("flickfil.txt", flickLista);

	addToPeopleList(flickLista, pojkLista, personList);

	//pl.addToPeopleList(pojkLista, flickLista, personList);


	for (int i = 0; i < personList.length(); i++) //Printa pojklistan
	{
		personList[i].print();
	}

	//for (int i = 0; i < flickLista.length(); i++){ //Printa flicklistan
	//	flickLista[i].print();
	//}

	//c.createCouple(pojkLista,flickLista, parLista);
	//parLista.PrintList();
	/*for (int i = 0; i < flickLista.length(); i++){ //Printa parlistan
		parLista[i].print();
	}*/

	system("PAUSE");
	return 0;
}