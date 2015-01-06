#pragma once
#include "Person.h"
#include "../forward_list_test/forward_list.h"
class PersonList
{
public:
	forward_list<string>pojkLista;
	forward_list<string>flickLista;

	PersonList()
	{
	}

	void Clear(){
		pojkLista.clear();
		flickLista.clear();
	}



	

	~PersonList()
	{
	}
};