#pragma once

//template<class INFO>

#include<iterator>
template <class T>
struct Node{
	T value;
	Node<T>*next;

	Node(){
		next = nullptr;
	}

	Node(const T &t){
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

	bool is_empty(){ return head == nullptr; } //kollar om listan är tom

	forward_list(const forward_list& obj){

	}
	

	T pop_front(){
		if (head->next != nullptr){
			Node<T> *n = head->data;
			temp = n;
			head = head->next;
			delete head;
			return temp;
		}
		else{
			Node<T> *n = head->data;
			head = head->next;
			temp = n;
			return temp;
		}
	}

	void front(){
		if (head->next != nullptr){
			return head;
		}
		else{
			return NULL;
		}
	}

	void push_front(T value){
		Node <T> *n = new Node<T> (value);
		if (head == nullptr)
			head = n;
	}

	void clear(){
		Node<T> *n = new Node<T> (NULL);
		if (head != nullptr)
			head = n;
	}

	void insert_after(){

	}

	void erase(){

	}

	void swap(<T list1, T list2){
		Node <T> *n = head->next;


	}

	virtual ~forward_list(){
	}

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
	public:
		iterator(){return }

		virtual ~iterator(){}

	};



	iterator begin(){ return iterator(head); }
	iterator end(){ return iterator(nullptr); }
};