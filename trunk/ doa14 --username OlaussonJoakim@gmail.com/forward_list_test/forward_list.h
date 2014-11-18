#pragma once
template<class INFO>
struct Node{
	Node<INFO>(){ this->next = nullptr; }
	Node<INFO>(INFO info){ this->info = info; this->next = nullptr; }
	INFO info;
	NODE<INDO> *next;
	~Node<INFO>()
};
class forward_list
{
private:
	Node <T> *head;
public:
	forward_list(){

	}
	forward_list(const forward_list& obj){

	}
	virtual ~forward_list();
};

