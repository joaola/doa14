#include "forward_list.h"
int main(){

	forward_list <int> fli1;
	forward_list <int> fli2;

	fli1.push_front(10);
	fli1.push_front(20);

	fli2.push_front(30);
	fli1.swap(fli2);
	return 0;
}