#include "graph.h"

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
	graph.add_edge(4, 2, 1);
	graph.add_edge(5, 0, 4);
	graph.add_edge(5, 1, 5);
	graph.add_edge(5, 2, 3);
	graph.add_edge(5, 3, 6);
	graph.add_edge(5, 4, 1);
	graph.add_edge(5, 9, 9);
	graph.add_edge(6, 7, 1);

	graph.print();

	cout << graph.order() << endl;
	cout << graph.has_vertex(9) << endl;
	cout << graph.remove_vertex(9) << endl << endl;
	graph.print();
	cout << graph.order() << endl;
	cout << graph.has_vertex(9) << endl;

	auto vertices = graph.vertices();
	for (auto& v : vertices)
	{
		cout << v << " ";
	}
	cout << endl << endl;

	cout << graph.has_edge(1, 2) << endl << graph.has_edge(Graph<int, int>::Edge(5, 3, 6)) << endl << graph.has_edge(Graph<int, int>::Edge(5, 3, 2)) << endl << endl;
	cout << graph.remove_edge(Graph<int, int>::Edge(5, 3, 6)) << endl << graph.has_edge(5, 3) << endl << endl;

	cout << graph.degree(0) << endl;
	auto edges = graph.edges(0);
	for (auto& v : edges)
	{
		cout << "[" << v.from << ", " << v.to << "]=" << v.d << "; ";
	}
	cout << endl << endl;

	auto walk = graph.walk(0);
	for (auto& v : walk)
	{
		cout << v << " ";
	}
	cout << endl << endl;

	auto path = graph.shortest_path(0, 7);
	if (path.empty()) cout << "Shortest way is not exist";
	else {
		for (auto& v : path) {
			cout << "[" << v.from << ", " << v.to << "] =" << v.d << " -> ";
		}
		cout << graph.count_shortest_path(0, 7);
	}

	cout << endl << endl << find_warehouse(graph);
}