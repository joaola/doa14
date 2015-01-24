#pragma once

//template<class INFO>

#include<iterator>
#include <exception>
#include <string>
#include<sstream>
#include <iostream>
using namespace std;
template <class T>
struct Node{
	T value;
	Node<T>*next;

	Node(){
		next = nullptr;
	}

	Node(T t){
		value = t;
		next = nullptr;
	}

	/*Node<INFO>(){ this->next = nullptr; }
	Node<INFO>(INFO info){ this->info = info; this->next = nullptr; }
	INFO info;
	NODE<INDO> *next;
	~Node<INFO>()*/
};
template <class T>
class forward_list
{
private:
	Node <T> *head;
public:
	forward_list(){
		head = nullptr;
	}

	bool is_empty(){ return head == nullptr; } //Kollar om listan är tom

	void pop_front(){ //Tag bort det första elementet i listan.
		if (head != nullptr){
			Node<T> *temp = head;
			head = head->next;
			delete temp;
		}
	}

	T& front(){
		if (head != nullptr){
			return head->value;
		}
		else{
			throw exception("Tom lista");
		}
	}

	void push_front(T value){ //Insättning av ett element i början av listan
		Node <T> *n = new Node<T>(value);
		if (head == nullptr){
			head = n;
		}
		else{
			n->next = head;
			head = n;
		}


	}

	void clear(){ //Töm hela listan
		//Node<T> *n = new Node<T>(NULL);
		while (!is_empty()){
			pop_front();
		}


	}

	void PrintList(){ //Skriv ut listan

		Node <T> *ptr = head;
		while (ptr != nullptr)
		{
			if (ptr == head){
				cout << "{";
			}
			cout << ptr->value;
			if (ptr->next == nullptr)
			{
				cout << "}";
			}
			else
				cout << ",";
			ptr = ptr->next;
		}
	
		/*ostringstream oss;
		Node<T> *n = head;
		if (n == nullptr)
			return "";
		while (n != nullptr){
			oss << n->value << endl;
		}
		return oss.str();*/
		}

	void insert_after(int index, T value){ //Sätt in ett element efter
		Node<T> *ptr = head;
		int i = 0;

		while (i != index){
			ptr = ptr->next;
			i++;
		}
		Node<T> *n = new Node <T>(value);
		n->next = ptr->next;
		ptr->next = n;
	}

	void erase_after(int index){ //Tag bort ett element efter
		Node<T> *ptr = head;
		Node<T> *temp;
		int i = 0;
		while (i != index){
			ptr = ptr->next;
			i++;
		}
		temp = ptr->next;
		ptr->next = temp->next;
		delete temp;
	}

	T before(T val){ //Returnerar index
		Node<T>*ptr = head;
		//int sum = 0;
		while (!(ptr->next->value == val) || ptr != NULL){
			ptr->next;
			//sum++;
		}
		return ptr;//sum;
	}

	void remove(T value)
	{
		Node<T> *prePtr = nullptr;
		Node<T> *ptr = head;
		while (ptr != nullptr)
		{
			if (ptr->value == value)
			{
				if (prePtr == nullptr)
					head = head->next;
				else
					prePtr->next = ptr->next;

				delete ptr;
				return;
			}
			prePtr = ptr;
			ptr = ptr->next;
		}
	}

	//void remove(T val){
	//	if (!is_empty())
	//	{
	//		Node <T>*ptr = head;

	//		if (val == head->value){
	//			pop_front();
	//		}
	//			//int i = before(value);
	//			//erase_after(i);
	//			//before(value);
	//			while (!(ptr->value == val)){
	//				ptr->next;
	//				if (head -> value == val){
	//					delete head;
	//				}
	//		}
	//	}
	//	
	//}

	void swap(forward_list &fl1){ //Byt plats på innehållet
		Node<T>*n = head;
		auto temp = head;
		head = fl1.head;
		fl1.head = temp;
	}

	T& operator[](int index){
		Node <T> *tempptr = this->head;
		for (int i = 0; i < index; i++)
		{
			tempptr = tempptr->next;
		}
		return tempptr->value;
	}

	int length(){
		int sum = 0;
		Node <T> *tempptr = this->head;
		while (tempptr!= nullptr){
			tempptr = tempptr->next;
			sum++;
		}
		return sum;
	}


	forward_list& operator = (forward_list& right_object) //Copy-konstruktor

		{
			this->clear();
			Node<T> *n = right_object.head;
			Node<T> *n2 = nullptr;
			while (n != nullptr)
			{
				if (head == nullptr)
				{
					head = new Node<T>(n->value);
					n2 = head;
				}
				else
				{
					n2->next = new Node<T>(n->value);
					n2 = n2->next;
				}
				n = n->next;
			}
			return *this;

	}

	virtual ~forward_list(){}

	class iterator {
	public:
		typedef iterator self_type;
		typedef Node<T> value_type;
		typedef Node<T>& reference;
		typedef Node<T>* pointer;
		typedef std::forward_iterator_tag iterator_category;
		typedef int difference_type;

		iterator(pointer ptr) : ptr_(ptr){}
		self_type operator++(){
			self_type i = *this;
			ptr_ = ptr_->next;
			return i;
		}
		self_type operator++(int junk){ ptr_ = ptr_->next; return *this; }
		reference operator*(){ return *ptr_; }
		pointer operator->(){ return ptr_; }

		bool operator == (const self_type& rhs){ return ptr_ == rhs.ptr_; }
		bool operator!=(const self_type& rhs){ return ptr_ != rhs.ptr_; }
	private:
		pointer ptr_;
	};
	iterator begin(){ return iterator(head); }
	iterator end(){ return iterator(nullptr); }
};