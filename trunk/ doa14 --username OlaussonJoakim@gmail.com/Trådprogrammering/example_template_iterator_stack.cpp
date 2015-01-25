#include <iostream>
#include <array>
#include <exception>
using namespace std;

namespace Course
{
	namespace Example
	{
		namespace TemplateIterator
		{
			template <class T>
			class stack
			{
			public:
				class stack_full_exception : public exception
				{
				public:
					stack_full_exception() { cerr << "\nStack full error\n";}
				};

				class stack_empty_exception : public exception
				{
					stack_empty_exception() { cerr << "\nStack empty error\n";}
				};

				typedef int size_type;
				class iterator
				{
				public:
					typedef iterator self_type;
					typedef T value_type;
					typedef T& reference;
					typedef T* pointer;
					typedef std::forward_iterator_tag iterator_category;
					typedef int difference_type;

					iterator(pointer ptr) : ptr_(ptr) { }
					self_type operator++() { self_type i = *this; ptr_++; return i; }
					self_type operator++(int junk) { ptr_++; return *this; }
					reference operator*() { return *ptr_; }
					pointer operator->() { return ptr_; }
					bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
					bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
				private:
					pointer ptr_;
				};

			private: 
				enum class Constants { EMPTY=-1, FULL=99 };
				int count;
				std::array<T,100> items;
			public:
				stack(void) {  count= (int)Constants::EMPTY; }

				void push(const T &n) 
				{ 
                    if ( is_full() )
                        throw stack_full_exception();
					items[++count]=n;  
				}

				T pop() 
				{ 
                    if ( is_empty() )
                        throw stack_empty_exception();
					return items[count--]; 
				}
				bool is_empty() { return count <= (int) Constants::EMPTY; }
				bool is_full() { return count >= (int) Constants::FULL; }

				iterator begin()
				{
					return iterator(&items[0]);
				}

				iterator end()
				{
					return iterator(&items[count+1]);
				}

				virtual ~stack(void) {}
			};



		}
	}
}

using namespace Course::Example::TemplateIterator;

void main_template_iterator()
{
	stack<int> si;

	try
	{
		si.push(10);
		si.push(20);
		si.push(30);
		si.push(40);
	}
	catch (stack<int>::stack_full_exception sfe)
	{ 
	}

	for (auto it=si.begin(); it != si.end(); it++)
	{
		cout << *it << " ,";
	}
	cout << endl;

}
