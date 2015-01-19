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

void mainTest(){
	
}

int main(){
	forward_list<Person>pojkLista;
	forward_list<Person>flickLista;
	forward_list<Person>personLista;
	
	//mainTest();
	PersonList pl;
	pl.ReadFromFile("pojkfil.txt", pojkLista);
	pl.ReadFromFile("flickfil.txt", flickLista);

	pl.addToPeopleList(pojkLista, flickLista, personLista);


	for (int i = 0; i < pojkLista.length(); i++) //Printa pojklista
	{
		pojkLista[i].print();
	}

	for (int i = 0; i < flickLista.length(); i++){ //Printa flicklista
		flickLista[i].print();
	}

	system("PAUSE");
	return 0;
}