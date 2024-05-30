#include "graph.h"

using namespace std;

int main() {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	graph.add_vertex(5);
	graph.add_vertex(6);
	graph.add_vertex(7);
	graph.add_vertex(8);
	graph.add_vertex(9);
	graph.add_edge(0, 1, 6);
	graph.add_edge(0, 2, 3);
	graph.add_edge(0, 3, 4);
	graph.add_edge(0, 4, 5);
	graph.add_edge(0, 5, 2);
	graph.add_edge(0, 9, 10);
	graph.add_edge(1, 2, 6);
	graph.add_edge(1, 6, 10);
	graph.add_edge(2, 3, 4);
	graph.add_edge(2, 8, 3);
	graph.add_edge(3, 4, 2);
	graph.add_edge(5, 0, 4);
	graph.add_edge(5, 1, 5);
	graph.add_edge(5, 2, 3);
	graph.add_edge(5, 3, 6);
	graph.add_edge(5, 4, 1);
	graph.add_edge(5, 9, 9);
	graph.add_edge(6, 7, 1);
	cout << "Now graph looks like: \n\n";
	graph.print();
	cout << "Graph size is : " << graph.order() << endl << endl;
	cout <<"Contains vertex: " << graph.has_vertex(9) << endl << endl;

	cout <<"Removing vertex: "<< graph.remove_vertex(9) << endl;
	cout << "Now graph looks like: \n\n";
	graph.print();
	cout << "All graph vertexes: " << endl;
	auto vertices = graph.vertices();
	for (auto& v : vertices)
	{
		cout << v << " ";
	}
	cout << endl << endl;

	cout << "Contains edge: " << graph.has_edge(1, 2) << endl << endl;
	cout << "Remove edge: " << graph.remove_edge(5, 3) << endl;
	cout << "Contains removed edge: " << graph.has_edge(5, 3) << endl << endl;
	cout << "Degree of vertex: " << graph.degree(0) << endl << endl;
	cout << "All graph edges and there distance: " << endl;
	auto edges = graph.edges(0);
	for (auto& v : edges)
	{
		cout << "(" << v.from << ", " << v.to << ")=" << v.d << "; ";
	}
	cout << endl << endl;

	cout << "Depth First Search" << endl << endl;
	auto dfs = graph.dfs_algorithm(0);
	for (auto& v : dfs)
	{
		cout << v << " ";
	}
	cout << endl << endl;

	cout << "Shortest path using dijkstra algorithm" << endl << endl;
	auto path = graph.dijkstra_algorithm(5, 3);
	for (auto& v : path) {
		cout << "(" << v.from << ", " << v.to << ")=" << v.d << " -> ";
	}

	cout <<endl << endl << "Task" << endl;
	cout << endl << graph.optimal_point();
}