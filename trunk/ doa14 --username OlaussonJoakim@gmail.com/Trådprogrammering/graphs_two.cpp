#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <vector>
using namespace std;

#include <boost\config.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost\graph\adjacency_list.hpp>
#include <boost\graph\dijkstra_shortest_paths.hpp>

namespace Course
{
	namespace ExampleGraphsTwo
	{
		typedef boost::adjacency_list<                  //Template class adjaceny_list
			boost::listS,                               //Use std::list for edges
			boost::vecS,                                //Use std::vector for vertexes
			boost::directedS,                           //Edges with direction
			boost::no_property,
			boost::property<boost::edge_weight_t, int>  //Weights
		> Graph;                                        //New type with the name Graph

		typedef Graph::vertex_descriptor                                      VertexID;
		typedef boost::graph_traits<Graph>::vertex_iterator                   VertexIterator;
		typedef boost::property_map<Graph, boost::vertex_index_t>::type       VertexIndexMap;
		typedef boost::graph_traits <Graph>::vertex_descriptor                VertexDescriptor;
		typedef Graph::edge_descriptor                                        EdgeID;
		typedef boost::graph_traits<Graph>::edge_iterator                     EdgeIterator;
		typedef boost::graph_traits<Graph>::in_edge_iterator                  EdgeInIterator;
		typedef boost::graph_traits<Graph>::out_edge_iterator                 EdgeOutIterator;
		typedef boost::property_map<Graph,boost::edge_weight_t>::type         WeightMap;

		//Vertexes
		enum class Nodes {A, B, C, D, E, F, G, H, I, NumberOfVertices };
		const string NodeNames = "ABCDEFGHIJKLMNOPQRSTUVXYZ";


		//Edges
		typedef std::pair<int,int> Edge;
		//array<Edge,NumberOfEdges> edges = 
		Edge edges[] = 
		{ 
			Edge((int) Nodes::A, (int) Nodes::B), Edge((int) Nodes::A, (int) Nodes::C), Edge((int) Nodes::A, (int) Nodes::D),
			Edge((int) Nodes::B, (int) Nodes::H), 
			Edge((int) Nodes::C, (int) Nodes::D), Edge((int) Nodes::C, (int) Nodes::F),
			Edge((int) Nodes::D, (int) Nodes::E), Edge((int) Nodes::D, (int) Nodes::I),
			Edge((int) Nodes::E, (int) Nodes::F), Edge((int) Nodes::E, (int) Nodes::G), Edge((int) Nodes::E, (int) Nodes::I),
			Edge((int) Nodes::F, (int) Nodes::H), 
			Edge((int) Nodes::G, (int) Nodes::H), Edge((int) Nodes::G, (int) Nodes::I), 
			Edge((int) Nodes::I, (int) Nodes::H)
		};
		const int NumberOfEdges = sizeof(edges)/sizeof(Edge);

		//Vikter
		int weights[] = { 15, 13, 5, 11,  18, 6, 4, 99, 1, 9, 14, 17, 7, 10 , 12};
	}
}

using namespace Course::ExampleGraphsTwo;

void main_graphs_two()
{
	//Build the graph using edge- and weight data
	Graph g(edges, edges+NumberOfEdges, weights, NumberOfEdges);

	//Access of allnodes/vertexes
	cout << "Nodes in the graph: ";
	VertexIndexMap vim = boost::get(boost::vertex_index, g);

	for ( std::pair<VertexIterator,VertexIterator> vp=boost::vertices(g); vp.first != vp.second; ++vp.first )
	{
		char n = NodeNames[vim[*vp.first]];
		cout << " " << n;
	}
	cout << endl;

	//Access of all edges
	WeightMap wm = boost::get(boost::edge_weight, g);
	cout << "Edges in the graph: ";
	EdgeIterator ei, ei_end;

	for ( boost::tie(ei , ei_end)=boost::edges(g); ei != ei_end; ++ei)
	{
		char s = NodeNames[vim[boost::source(*ei,g)]];
		char t = NodeNames[vim[boost::target(*ei,g)]];
		int w = boost::get(wm, *ei);
		cout << endl << " (" << s << "," << t << "," << w <<")" ;
	}

	//Shortest path
	vector<VertexDescriptor> p(num_vertices(g));
	std::vector<int> d(num_vertices(g));
	VertexDescriptor s = vertex((int) Nodes::A, g);

	boost::dijkstra_shortest_paths(g, s, boost::predecessor_map(&p[0]).distance_map(&d[0]));

	cout  << endl << "Distances and parents:" << endl;
	VertexIterator vi, vend;
	for (boost::tie(vi, vend) = vertices(g); vi != vend; ++vi) 
	{
		cout << "distance(" << NodeNames[vim[*vi]] << ") = " << setw(13) << d[*vi] << ", ";
		cout << "parent(" << NodeNames[vim[*vi]] << ") = " << NodeNames[vim[p[*vi]]] << endl;
	}
	cout << endl;

}