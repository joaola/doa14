#include <iostream>
#include <clocale>
#include <string>
#include "forward_list.h"
using namespace std;
int main(){

	forward_list <int> fli1;
	forward_list <int> fli2;

	//****************
	fli1.push_front(10);
	fli1.push_front(20);

	fli2.push_front(30);
	fli1.swap(fli2);
	cout << "Swapped? " << "fli1:" << fli1.PrintList()<<endl;
	cout << "Swapped?" << "fli2: " << fli2.PrintList()<<endl;

	fli2.pop_front();
	fli2.pop_front();

	cout << "Empty?" << fli2.is_empty() << endl;

	fli2.push_front(10);
	fli2.push_front(20);
	fli2.push_front(30);

	fli2.insert_after(1, 25);

	cout << "Insert after: " << fli2.PrintList() << endl;

	cout << "Front: " << fli2.front() << endl;

	cout << "Empty? " << fli2.is_empty() << endl;

	fli2.clear();

	cout << "Empty? " << fli2.is_empty() << endl;

	

	system("PAUSE");
	
	return 0;
}