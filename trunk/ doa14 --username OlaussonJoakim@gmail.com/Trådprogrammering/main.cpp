#include <iostream>	
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

#include "../Course/Console.h"
using namespace Course;

enum class Example
{
	algorithms_time_measurement,
	algorithms_exercise_complexity,
	recursive_faculty,
	recursive_reverse_string,
	recursive_fibonacci,
	recursive_array,
	recursive_ways,
    template_iterator,
	binary_tree_one,
	binary_tree_two,
	binary_tree_three,
	queue_stack_maze,
	priority_queue_one,
	priority_queue_astar,
	heap,
	graphs_one,
	graphs_two,
	graphs_three,
	threads,
	quit,
	test
};


Example menu()
{	
	Console::clrscr();
	Console::set_color(true,true,true,true,false,false,false,false);
	Console::set_console_window_size(800,600);
	int x = 10;
	int y = 3;
	Console::gotoxy(x, y++); 
	cout << setw(2) << (int) Example::algorithms_time_measurement << ": "        << "    ALGORITMER: Tidmätning med <chrono>";
	Console::gotoxy(x, y++); 
	cout << setw(2) << (int) Example::algorithms_exercise_complexity << ": "     << "    ALGORITMER: Övning i komplexitetsteori";
	Console::gotoxy(x, y++); 
	cout << setw(2) << (int) Example::recursive_faculty << ": "                  << "     REKURSION: Fakultet";
	Console::gotoxy(x, y++); 
	cout << setw(2) << (int) Example::recursive_reverse_string << ": "           << "     REKURSION: Reversera en sträng";
	Console::gotoxy(x, y++); 
	cout << setw(2) << (int) Example::recursive_fibonacci << ": "                << "     REKURSION: Fibonacci";
	Console::gotoxy(x, y++); 
	cout << setw(2) << (int) Example::recursive_array << ": "                    << "     REKURSION: Arrayberäkningar";
	Console::gotoxy(x, y++); 
	cout << setw(2) << (int) Example::recursive_ways << ": "                     << "     REKURSION: Olika vägar";
	Console::gotoxy(x, y++); 
	cout << setw(2) << (int) Example::template_iterator << ": "                  << "      TEMPLATE: Mallklassen stack<T>, iterator och undantag,";
	Console::gotoxy(x, y++); 
	cout << setw(2) << (int) Example::binary_tree_one << ": "                    << "          TREE: Skriv ut ett binärt alfabetiskt träd.";
	Console::gotoxy(x, y++); 
	cout << setw(2) << (int) Example::binary_tree_two << ": "                    << "          TREE: Binärt heltalsträd - Dynamisk minnesallokering.";
	Console::gotoxy(x, y++); 
	cout << setw(2) << (int) Example::binary_tree_three << ": "                  << "          TREE: Binärt heltalsträd - Arrayimplementering.";
	Console::gotoxy(x, y++); 
	cout << setw(2) << (int) Example::queue_stack_maze << ": "                   << " STACK & QUEUE: Maze";
	Console::gotoxy(x, y++); 
	cout << setw(2) << (int)Example::priority_queue_one << ": "                  << "PRIORITY QUEUE: Patientkö";
	Console::gotoxy(x, y++);
	cout << setw(2) << (int)Example::priority_queue_astar << ": "                << "PRIORITY QUEUE: A*";
	Console::gotoxy(x, y++);
	cout << setw(2) << (int)Example::heap << ": "                                << "          HEAP: Heap.";
	Console::gotoxy(x, y++); 
	cout << setw(2) << (int) Example::graphs_one << ": "                         << "        GRAPHS: Uppbyggnad av en graf";
	Console::gotoxy(x, y++);  
	cout << setw(2) << (int) Example::graphs_two << ": "                         << "        GRAPHS: Viktad graf";
	Console::gotoxy(x, y++); 
	cout << setw(2) << (int) Example::graphs_three << ": "                       << "        GRAPHS: Dijkstras algoritm";
	Console::gotoxy(x, y++); 
	cout << setw(2) << (int) Example::threads << ": "                            << "        THREAD: Trådprogrammering i C++11.";
	Console::gotoxy(x, y++); 
	cout << setw(2) << (int) Example::quit << ": "                               << "      Avsluta";

	Console::gotoxy(x, y=y+3);
	cout << setw(2) << "Val: ";
	string s;
	std::getline(cin , s);
	istringstream iss(s);
	int val=-1;
	iss >> val;
	Console::clrscr();
	return (Example) val;
}


int main()
{
	//===Algorithms - Execution Time==============================================
	void main_execution_time_power();
	//main_execution_time_power();

	setlocale(LC_ALL , "swedish");
    

	while (true)
	try
	{
		Example ex = menu();
		Course::Console::clrscr();
		string str;
		
		switch ( ex )
		{
		case Example::algorithms_time_measurement:			void main_execution_time_power(); main_execution_time_power(); break;
		case Example::algorithms_exercise_complexity:		void main_exercise_complexity(); main_exercise_complexity(); break;
		case Example::recursive_faculty:					void main_recursive_faculty(); main_recursive_faculty(); break;
		case Example::recursive_reverse_string:				void main_recursive_reverse_string(); main_recursive_reverse_string(); break;
		case Example::recursive_fibonacci:					void main_recursive_fibonacci(); main_recursive_fibonacci(); break;
		case Example::recursive_array: 					    void main_recursive_array(); main_recursive_array(); break;
		case Example::template_iterator: 	    		    void main_template_iterator(); main_template_iterator(); break;
		case Example::recursive_ways:						void main_recursive_ways(); main_recursive_ways(); break;
		case Example::binary_tree_one:						void main_example_binary_tree_one(); main_example_binary_tree_one(); break;
		case Example::binary_tree_two:						void main_example_binary_tree_two(); main_example_binary_tree_two(); break;
		case Example::binary_tree_three:					void main_example_binary_tree_three(); main_example_binary_tree_three(); break;
		case Example::queue_stack_maze:						void main_maze(); main_maze(); break;
		case Example::priority_queue_one:					void main_example_priority_queue_one(); main_example_priority_queue_one(); break;
		case Example::priority_queue_astar:					void main_pqueue_maze(); main_pqueue_maze(); break;
		case Example::heap:									void main_example_heap_one(); main_example_heap_one(); break;
		case Example::graphs_one:							void main_graphs_one(); main_graphs_one(); break;
		case Example::graphs_two:							void main_graphs_two(); main_graphs_two(); break;
		case Example::graphs_three:							void main_graphs_three(); main_graphs_three(); break;
		case Example::threads:								void main_threads(); main_threads(); break;
		case Example::quit:									return 0;
		case Example::test:									void main_pqueue_maze(); main_pqueue_maze();
		default:
			break;
		}


		std::getline(cin, str); //Finns i <string>
	}
	catch (exception e)
	{
		cout << setw(2) << e.what() << endl;
	}

}