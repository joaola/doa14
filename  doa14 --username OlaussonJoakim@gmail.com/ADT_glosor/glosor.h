#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class glosor
{
private:
	//vector<string>langVector;
	string lang;
	string inputWord;
	string outputWord;
public:

	glosor()
	{
		this -> lang = inputWord = outputWord =  "";
	}

	glosor(string lang, string inputWord, string outputWord){
		this->lang = lang;

	}

	void Translate(string lang, string inputWord){
		if (lang == "swe"){
			if (inputWord == "hej" || inputWord == "HEJ"){
				this->outputWord = "hello";
			}
			else if (inputWord == "car"){
				this->outputWord = "bil";
			}
			else if (inputWord == "goodbye"){
				this->outputWord = "hej då";
			}
			else if (inputWord == "cat"){
				this->outputWord = "katt";
			}
			else
				cout << "Ordet finns ej i databasen." << endl;
			}

		if (lang == "eng"){
			if (inputWord == "hello" || inputWord == "HELLO"){
				this->outputWord = "hej";
			}

			else if (inputWord == "hej då"){
				this->outputWord = "goodbye";
			}
			else if (inputWord == "bil"){
				this->outputWord = "car";
			}
			else if (inputWord == "katt"){
				this->outputWord = "cat";
			}
			else
				this ->outputWord = "Ordet finns ej i databasen.";
		}
	}

	void PrintWord(){
		cout << this->outputWord << endl;
	}

	~glosor()
	{
	}
};

