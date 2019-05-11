using namespace std;

#include<iostream>
#include<set>
#include<queue>
#include "Graph.h"

void BFS (Digraph& graph, int s) {
	int n = graph.size();			// number of nodes
	bool* disc = new bool[n];		// discovery list: did we traverse this node yet?
	int* parent = new int[n];		// parent pointer
	int* level = new int[n];		// the level of each vertex (equal to its parent + 1)
	int max_level = 0;

	// Initialize data structures
	for (int i = 0; i < n; i++) {
		disc[i] = false;
		parent[i] = -1;
		level[i] = -1;
	}

	queue<int> qu;
	qu.push(s);
	disc[s] = true;
	parent[s] = -1;
	level[s] = 0;

	while (qu.size() > 0) {
		int u = qu.front();
		qu.pop();
		set<int> neighbors = graph.out_neighbors(u);

		for (int v : neighbors) {
			if (!disc[v]) {
				qu.push(v);
				disc[v] = true;
				parent[v] = u;
				level[v] = level[u] + 1;
				max_level = (level[v] > max_level ? level[v] : max_level);
			}
		}
	}

	cout << "{{{ BFS }}}" << endl;

	for (int l = 0; l <= max_level; l++) {
		cout << "[" << l << "] ";

		for (int i = 0; i < n; i++) {
			if (level[i] == l) {
				cout << i << " ";
			}
		}

		cout << endl;
	}

	delete(disc);
	delete(parent);
	delete(level);
}