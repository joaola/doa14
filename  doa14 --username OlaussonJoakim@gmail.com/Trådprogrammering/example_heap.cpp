#include <iostream>
#include <iomanip>
#include <utility>
#include <memory>
#include <vector>
using namespace std;

namespace Course
{
	namespace Example
	{
		namespace Heap
		{
			template<class T>
			class data
			{
			public:
				T info;
				friend bool operator<(data<T>& left , data<T>& right) { return left.info < right.info; }
				data() { }
				data(T t) { info=t; }
				~data(){ /*cout << info << endl;*/ }
			};

			template<class T>
			class heap
			{
			private:
				int n; //Actual numbers of elements used.
				int maxSize;
				unique_ptr<T[]> v;

			public:
				heap(int maxSize=1024)
				{
					this->maxSize = maxSize;
					v = unique_ptr<T[]>(new T[maxSize]);
					n=0;
				}

				~heap() { /*cout << "~heap" << endl;*/ }

				int getMaxSize() { return maxSize; }

				void set(int index, T value) { v[index].info=value.info;} 
				void set(int index, int value) { v[index].info=value;} //Specialized version if T is int

				bool add(T value)
				{
					if (this->n >= this->maxSize )    // If we have reached our maximum capacity
						return false;
					v[ n] = value;
					shift_up(n++);
					return true;
				}

				void shift_up(int k)
				{
					int  current = k;
					int parent  = (k-1)/2;
					T item = v[current];
					while (current > 0)  // While !root
					{
						if (v[parent] < item)
						{
							v[current] = v[parent];
							current = parent;
							parent = (current-1)/2;
						}
						else
							break;
					}
					v[current] = item;
				}

				T remove(void)
				{
					T temp = v[0];
					v[0] = v[--this->n]; 
					shift_down(0);
					return temp;
				}

				void shift_down(int k)
				{
					int current = k;
					int child   = 2*current+1;
					T item = v[current];    // Used to compare values

					while (child < this->n)
					{
						if (child < (this->n - 1))
							if (v[child] < v[child+1])  // Set Child to largest Child node
								++child;

						if (item < v[child])
						{    
							v[current] = v[child];
							current = child;
							child   = 2*current+1;
						}
						else
							break;
					}
					v[current] = item;
				}


				vector<T>  sort()
				{
					vector<T> sv(this->n);

					for (int i = n-1; i >=0; --i)
					{
						sv[i] = remove(); 
					}
					return sv;
				}

				void print()
				{
					cout << endl << endl << endl;
					print(0,0);
				}

			private:
				void print(int k, int level)
				{
					if (k >= this->n )
						return;

					print(2*k+2, level+1);
					cout << setw(level*4) << v[k].info << endl;
					print(2*k+1, level+1);
				}
			};
		}
	}
}

using namespace Course::Example::Heap;

void main_example_heap_one()   
{
	{
		heap<data<int>> h;

		cout << "Init" << endl;
		for (int i = 0; i < h.getMaxSize(); i++)
		{
			h.set(i , i);
		}

		h.add(10);
		h.add(20);
		h.add(30);
		h.add(40);

		h.print();

		h.add(1);
		h.add(2);
		h.add(3);
		h.add(4);
		h.add(5);

		h.print();

		h.add(51);
		h.add(52);
		h.add(53);
		h.add(54);
		h.add(55);

		h.print();

		vector<data<int>> sv = h.sort();
		for(auto item=sv.begin(); item!=sv.end(); item++)
		{
			//cout << *item << " , ";
		}
		cout << endl;

		h.print();

		cout << "Destruction" << endl;
	}
}
