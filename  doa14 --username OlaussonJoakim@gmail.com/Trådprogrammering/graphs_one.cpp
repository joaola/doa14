#include <iostream>
#include <string>
#include <array>
using namespace std;

#include <boost\graph\adjacency_list.hpp>

namespace Course
{
	namespace ExampleGraphsOne
	{
		typedef boost::adjacency_list<  //Mallklassen adjaceny_list
			boost::listS,               //Anv�nd std::list f�r b�gar (kanter, edges)
			boost::vecS,                //Anv�nd std::vector f�r noder (h�rn, vertex)
			boost::bidirectionalS       //B�gar (kanter, edges) med riktning
		> Graph;                        //Min nya grafdatatyp

		typedef Graph::vertex_descriptor                                      VertexID;
		typedef boost::graph_traits<Graph>::vertex_iterator                   VertexIterator;
		typedef boost::property_map<Graph, boost::vertex_index_t>::type       VertexIndexMap;
		typedef Graph::edge_descriptor                                        EdgeID;
		typedef boost::graph_traits<Graph>::edge_iterator                     EdgeIterator;

		//Noder
		enum class Nodes {A, B, C, D, E, F, G, H , NumberOfVertices};
		const string NodeNames = "ABCDEFGH";


		//B�gar
		typedef std::pair<int,int> Edge;
		const int NumberOfEdges = 7;
		array<Edge,NumberOfEdges> edges = 
			//Edge edges[] = 
		{ 
			Edge((int) Nodes::A, (int) Nodes::B), Edge((int) Nodes::A, (int) Nodes::D),
			Edge((int) Nodes::C, (int) Nodes::A), Edge((int) Nodes::D, (int) Nodes::C),
			Edge((int) Nodes::C, (int) Nodes::E), Edge((int) Nodes::B, (int) Nodes::D),
			Edge((int) Nodes::D, (int) Nodes::E)
		};

		//Vikter
		array<int,NumberOfEdges> weights = { 1, 2, 1, 2, 7, 3, 1 };
	}
}

using namespace Course::ExampleGraphsOne;

void main_graphs_one()
{
	//Bygg grafen med r�tt antal noder fr�n b�rjan
	Graph g((int) Nodes::NumberOfVertices); 

	//S�tt in b�gar i grafen
	for (auto e : edges)
	{
		boost::add_edge(e.first , e.second, g);
	}

	//Access av alla noder
	cout << "Nodes in the graph: ";
	VertexIndexMap vim = boost::get(boost::vertex_index, g);

	for ( std::pair<VertexIterator,VertexIterator> vp=boost::vertices(g); vp.first != vp.second; ++vp.first )
	{
		cout << " " << vim[*vp.first];
	}
	cout << endl;

	//Access av alla b�gar
	cout << "Edges in the graph: ";
	EdgeIterator ei, ei_end;

	for ( boost::tie(ei , ei_end)=boost::edges(g); ei != ei_end; ++ei)
	{
		cout << " (" << vim[boost::source(*ei,g)] << "," << vim[boost::target(*ei,g)] << ")" ;
	}
	cout << endl;

}