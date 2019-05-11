using namespace std;

#include<iostream>
#include "Graph.h"
#include "GraphAlgorithms.h"

void bfs_test() {

	Digraph g = Digraph(10);

	g.add_edge(0,1);
	g.add_edge(1,2);
	g.add_edge(1,8);
	g.add_edge(2,3);
	g.add_edge(2,4);
	g.add_edge(2,7);
	g.add_edge(3,5);
	g.add_edge(4,3);
	g.add_edge(5,6);
	g.add_edge(6,7);
	g.add_edge(7,8);
	g.add_edge(8,9);

	BFS(g, 1);

}

void random_test() {

	Digraph g = Digraph(10);

	g.add_edge(1, 2);
	g.add_edge(1, 3);
	g.add_edge(1, 9);
	g.add_edge(2, 4);
	g.add_edge(3, 5);
	g.add_edge(7, 1);

	g.print();

	BFS(g, 1);

}

int main()
{
    bfs_test();
}


