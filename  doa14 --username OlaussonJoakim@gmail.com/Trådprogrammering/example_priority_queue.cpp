#include <iostream>
#include <string>
#include <queue>

using namespace std;

namespace Course
{
	namespace PriorityQueue
	{
		namespace ExampleOne
		{
			class Patient 
			{
			private:
				int id;
				string name;
				bool emergencyCase;

			public:
				Patient() 
				{
					*this= Patient(0,"",false);
				}

				Patient(int id, string name, bool emergencyCase) 
				{
					this->id = id;
					this->name = name;
					this->emergencyCase = emergencyCase;
				}

				int getId() const { return id; }
				void setId(int id) { this->id = id; }
				string getName() const { return name; }

				friend ostream& operator<<(ostream &out, const Patient &p)
				{
					out << "("<< p.getId() << "," << p.getName() << ")";
					return out;
				}

				friend bool operator<(const Patient &left, const Patient &right)
				{
					if ( left.emergencyCase < right.emergencyCase )
						return true;
					else if  ( left.emergencyCase > right.emergencyCase )
						return false;
					else
						return left.id > right.id;
				}
			};
		}
	}
}

void main_example_priority_queue_one()
{
	using namespace Course::PriorityQueue::ExampleOne;

	priority_queue<Patient>	pq;

	pq.push(Patient(1, "P1", false));
	pq.push(Patient(2, "P2", false));
	pq.push(Patient(3, "P3", true));
	pq.push(Patient(4, "P4", false));
	pq.push(Patient(5, "P5", true));
	pq.push(Patient(6, "P6", false));
	pq.push(Patient(7, "P7", false));

	while ( !pq.empty() )
	{
		cout << pq.top() << " <-- ";
		pq.pop();
	}



}