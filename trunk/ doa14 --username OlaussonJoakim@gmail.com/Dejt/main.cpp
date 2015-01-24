#include "Person.h"

#include "string.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
namespace date{
	//Printa dubbellistan via två for-loopar
	void printCouples(forward_list<forward_list<Person>> coupleList)
	{
		for (int i = 0; i < coupleList.length(); i++)
		{
			for (int j = 0; j < coupleList[i].length(); j++)
			{
				coupleList[i][j].print();
			}
			cout << endl;
		}
	}

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
			int maxMutualInterest = 0;
			int matchValue = 0;
			girl = girlList[i];
			for (int j = 0; j < boyList.length(); j++){
				//Få fram match
				matchValue = compareInterests(boyList[j], girlList[i]);
				if (matchValue >= maxMutualInterest){
					maxMutualInterest = matchValue;
					boy = boyList[j];
				}
			}
			if(maxMutualInterest>=3){
				boyList.remove(boy);
				girlList.remove(girl);
				couples.push_front(boy);
				couples.push_front(girl);
				coupleList.push_front(couples);
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
}

int main(){
	//forward lists
	forward_list<Person>pojkLista;
	forward_list<Person>flickLista;
	forward_list<Person>personList;

	//Forward_list i en forward_list
	forward_list<forward_list<Person>> parLista;

	//Cleara listorna innan användning
	pojkLista.clear();
	flickLista.clear();
	personList.clear();
	parLista.clear();

	//Läs filer
	date::ReadFromFile("pojkfil.txt", pojkLista);
	date::ReadFromFile("flickfil.txt", flickLista);

	//Lägg till info från flick- och pojklistan till personlistan
	date::addToPeopleList(flickLista, pojkLista, personList);
	
	//Skapa par
	date::createCouple(flickLista, pojkLista, parLista);

	//Printa pojkar
	cout << endl << "POJKAR: " << endl;
	for (int i = 0; i < pojkLista.length(); i++){
		pojkLista[i].print();
	}

	//Printa flickor
	cout << endl << "FLICKOR: " << endl;
	for (int i = 0; i < flickLista.length(); i++){
		flickLista[i].print();
	}

	//Printa personlistan
	cout << endl <<"PERSONLISTA: " << endl;
	for (int i = 0; i < personList.length(); i++){
		personList[i].print();
	}

	//Printa par
	cout <<endl<< "PARLISTA: " << endl;
	date::printCouples(parLista);
	system("PAUSE");
	return 0;
}