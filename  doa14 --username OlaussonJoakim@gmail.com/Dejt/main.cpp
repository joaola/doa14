#include "InterestTable.h"
#include "Person.h"

#include "string.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

//Jämför flickors intressen med pojkars intressen
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

//Skapar par
void createCouple(forward_list<Person>&girlList, forward_list<Person>&boyList, forward_list<forward_list<Person>>&coupleList){
	Person girl;
	Person boy;
	forward_list<Person> couples;

	//Loopa flicklistan och pojklistan för att kunna jämföra intressen
	for (int i = 0; i < girlList.length(); i++){
		girl = girlList[i];
		for (int j = 0; j < boyList.length(); j++){
			boy = boyList[j];
			//Få fram match
			int minMutualInterest = 4;
			int matchValue = compareInterests(boy, girl);
			if (matchValue >= minMutualInterest){ 
				couples.push_front(boy);
				couples.push_front(girl);
				coupleList.push_front(couples);
				girlList.remove(girl);
				boyList.remove(boy);

			}
		}
	}
}

//Läser in filerna i en forward_list
void ReadFromFile(string fileName, forward_list<Person>& list){
	string str;
	ifstream fin;
	fin.open(fileName);
	if (!fin.good()){
		cout << "Gick ej att öppna" << endl;
		return;
	}
	while (getline(fin, str)){
		istringstream iss(str);
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

//Lägger till personer till personlistan
void addToPeopleList(forward_list<Person> girlList, forward_list<Person>boyList, forward_list<Person>& peopleList){
for (int i = 0; i < girlList.length(); i++){
peopleList.push_front(girlList[i]);
}

for (int i = 0; i < boyList.length(); i++){
peopleList.push_front(boyList[i]);
}
}

//Test main-funktion
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
	createCouple(flickLista, pojkLista, parLista);
	//Printa personlistan
	/*for (int i = 0; i < parLista.length(); i++){
		parLista[i].PrintList();
	}*/

	/*for (int i = 0; i < personList.length(); i++)
	{
		personList[i].print();
	}*/

	system("PAUSE");
	return 0;
}