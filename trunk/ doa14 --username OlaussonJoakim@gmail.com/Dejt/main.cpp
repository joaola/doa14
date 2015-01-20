#include "Couple.h"
#include "PersonList.h"
#include "InterestTable.h"
#include "Person.h"
#include "../forward_list_test/forward_list.h"

#include "string.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void mainTest(){
	
}

int main(){
	forward_list<Person>pojkLista;
	forward_list<Person>flickLista;
	forward_list<Person>personList;
	forward_list<forward_list<Person>> parLista;
	
	//mainTest();
	PersonList pl;
	Couple c;
	pl.ReadFromFile("pojkfil.txt", pojkLista);
	pl.ReadFromFile("flickfil.txt", flickLista);

	pl.addToPeopleList(pojkLista, flickLista, personList);


	//for (int i = 0; i < pojkLista.length(); i++) //Printa pojklistan
	//{
	//	pojkLista[i].print();
	//}

	//for (int i = 0; i < flickLista.length(); i++){ //Printa flicklistan
	//	flickLista[i].print();
	//}

	c.createCouple(pojkLista,flickLista, parLista);
	parLista.PrintList();
	/*for (int i = 0; i < flickLista.length(); i++){ //Printa parlistan
		parLista[i].print();
	}*/

	system("PAUSE");
	return 0;
}