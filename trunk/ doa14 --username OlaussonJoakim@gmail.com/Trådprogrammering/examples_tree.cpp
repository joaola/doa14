#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <memory>
using namespace std;

namespace Course
{
	namespace BinaryTree
	{
		namespace ExampleOne
		{
			struct Node
			{
				Node(char c) {key=c;} 
				~Node() { cout << key ; } 
				char key;
				std::unique_ptr<Node> l;
				std::unique_ptr<Node> r;
			};

			void build_tree_one(unique_ptr<Node> &root)
			{
				root = unique_ptr<Node>(new Node('A'));
				root->l = unique_ptr<Node>(new Node('B'));
				root->l->l = unique_ptr<Node>(new Node('D'));
				root->l->l->l = unique_ptr<Node>(new Node('H'));
				root->l->l->r = unique_ptr<Node>(new Node('I'));
				root->l->r = unique_ptr<Node>(new Node('E'));

				root->r = unique_ptr<Node>(new Node('C'));
				root->r->l = unique_ptr<Node>(new Node('F'));
				root->r->r = unique_ptr<Node>(new Node('G'));
			}

			void print_lnr(unique_ptr<Node> &root)
			{
				if ( root == nullptr ) return;
				print_lnr(root->l);
				cout << setw(2) << root->key;
				print_lnr(root->r);
			}
		}
	}
}

void main_example_binary_tree_one()
{
	{
		using namespace Course::BinaryTree::ExampleOne;
		unique_ptr<Node> root(new Node('A'));
		cout << "main_example_binary_tree_one: start" << endl;
		build_tree_one(root);
		print_lnr(root);
		cout << endl;
		cout << "main_example_binary_tree_one: end" << endl;
	} //Här anropas destruktorerna för alla nodobjekt 
}

namespace Course
{
	namespace BinaryTree
	{
		namespace ExampleTwo
		{
			template<class T>
			struct node
			{
				node() { l=nullptr; r=nullptr; }
				node(T v) { l=nullptr; r=nullptr; info=v;}
				~node() { cout << info << " ";}
				T info;
				unique_ptr<node> l;
				unique_ptr<node> r;
			};

			typedef unique_ptr<node<int>> sptr;
			typedef vector<int> vint;

			template<class T>
			class binary_tree
			{
			private:
				unique_ptr<node<T>> root;	

				void add(unique_ptr<node<T>> &r, unique_ptr<node<T>> n)
				{
					if ( r == nullptr ) r=std::move(n);
					else
					{
						if ( n->info < r->info )
							add(r->l,std::move(n));
						else 
							add(r->r,std::move(n));
					}
				}

				void print(unique_ptr<node<T>> &p, int level)
				{
					if (p == nullptr)
						return;

					print(p->r, level+1);
					cout << setw(level*4) << p->info << endl;
					print(p->l, level+1);
				}

				int count_nodes(unique_ptr<node<T>> &p)
				{
					if ( p == nullptr )
						return 0;
					else
					{
						return 1+count_nodes(p->l) + count_nodes(p->r);
					}
				}


				int count_depth(unique_ptr<node<T>> &p)
				{
					if ( p == nullptr )
						return 0;
					else
					{
						int dl=1 + count_depth(p->l);
						int dr=1 + count_depth(p->r);

						return (dl > dr) ? dl : dr;
					}
				}

				void tree2vector(unique_ptr<node<T>>  r, vector<int> &v)
				{
					if ( r == nullptr )
					{
						return;
					}
					v.push_back(r->info);

					tree2vector(std::move(r->l), v);
					tree2vector(std::move(r->r), v);
				}

				void vector2tree(unique_ptr<node<T>>  &r, vector<T> &v, int s, int e)
				{
					if ( e < s ) return;

					int m = (e-s) / 2;

					r = unique_ptr<node<T>>(new node<T>(v[s+m]));

					vector2tree(r->l, v, s, s+m-1);
					vector2tree(r->r, v, s+m+1, e);
				}

			public:
				binary_tree(){ root = nullptr;}
				~binary_tree() { cout  << "destructor binary_tree \n"; }

				void add(unique_ptr<node<T>> n)  { add(root, std::move(n)); }
				void print() { cout << endl; this->print(root,0); cout << endl;}
				int count_nodes() { return count_nodes(this->root); }
				int count_depth() { return count_depth(this->root); }

				void balance_tree()
				{
					std::vector<int> v;
					tree2vector(std::move(root),v);
					this->root=nullptr;
					std::sort(v.begin(),v.end());
					vector2tree(root,v,0,v.size()-1);
				}
			};
		}
	}
}

void main_example_binary_tree_two()
{
	{
		using namespace Course::BinaryTree::ExampleTwo;
		cout << "main_example_binary_tree_two: start" << endl;
		array<int,10> v  = { 18, 4 , 6, 60, 2 , 5, 9 , 10, 99, 20};

		shared_ptr<binary_tree<int>> bt(new binary_tree<int>());

		for(int i=0; i<v.size(); i++)
			bt->add(unique_ptr<node<int>>(new node<int>(v[i])));

		bt->print();

		cout << endl ;
		cout << "Antal noder: " << bt->count_nodes() << endl;
		cout << "       Djup: " << bt->count_depth() << endl;


		cout << "balansering" << endl;
		bt->balance_tree();

		bt->print();

		cout << "main_example_binary_tree_two: end" << endl;
	} //Här anropas destruktorerna för alla nodobjekt 
}

namespace Course
{
	namespace BinaryTree
	{
		namespace ExampleThree
		{
			template<class T>
			struct node
			{
				node() { info=-1; used=false; }
				node(T v) { info=v; used=false;}
				~node() { }
				T info;
				bool used;
			};

			template<class T>
			class bt
			{
			private:
				vector<node<T>> v; 

				void add(int k, T info) 
				{
					if (!v[k].used )
					{
						v[k].info=info;
						v[k].used=true;
						return;
					}
					else if (v[k].info < info )
						add(2*k+1,info);
					else
						add(2*k+2, info);
				}

				void print(int k, int level)
				{
					if (v[k].used == false)
						return;

					print(2*k+2, level+1);
					cout << setw(level*4) << v[k].info << endl;
					print(2*k+1, level+1);
				}
			public:
				bt() { }
				bt(int size) { v.resize(size, node<T>() ); }
				void add(T info) { add(0,info); }
				void print() {  cout << endl; print(0,0);  cout << endl;}
			};   
		}

	}

}


void main_example_binary_tree_three()
{
	{
		using namespace Course::BinaryTree::ExampleThree;

		cout << "main_example_binary_tree_three: start" << endl;
		array<int,10> v  = { 18, 4 , 6, 60, 2 , 5, 9 , 10, 99, 20};
		bt<int>  b(100);
		for(int i=0; i<v.size(); i++)
			b.add(v[i]);
		b.print();

		cout << "main_example_binary_tree_three: end" << endl;
	} //Här anropas destruktorerna för alla nodobjekt 

}