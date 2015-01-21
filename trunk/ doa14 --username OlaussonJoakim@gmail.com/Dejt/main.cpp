#include "InterestTable.h"
#include "Person.h"
//#include "Couple.h"

#include "string.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int compareInterests(Person girl, Person boy){
	int sameInterests = 0;
	for (int i = 0; i < girl.getInterest().length(); i++){
		for (int j = 0; j < boy.getInterest().length(); j++){
			if (girl.getInterest()[i] == boy.getInterest()[j]){
				sameInterests++;
			}

		}
	}
	return sameInterests;
}

void createCouple(forward_list<Person>&girlList, forward_list<Person>&boyList, forward_list<forward_list<Person>>&coupleList){
	Person girl;
	Person boy;
	forward_list<Person> couples;

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
		girlList.remove(girl);
		boyList.remove(boy);
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
	//4st forward lists
	forward_list<Person>pojkLista;
	forward_list<Person>flickLista;
	forward_list<Person>personList;
	forward_list<forward_list<Person>> parLista;

	//Läs filer
	ReadFromFile("pojkfil.txt", pojkLista);
	ReadFromFile("flickfil.txt", flickLista);

	//Lägg till info från flick- och pojklistan till personlistan
	addToPeopleList(flickLista, pojkLista, personList);
	
	//Skapa par
	//Couple c;
	createCouple(flickLista, pojkLista, parLista);
	//Printa personlistan
	for (int i = 0; i < parLista.length(); i++){
		parLista[i].PrintList();
	}
	//parLista.PrintList();

	/*for (int i = 0; i < personList.length(); i++)
	{
		personList[i].print();
	}*/

	system("PAUSE");
	return 0;
}