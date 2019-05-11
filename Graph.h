
#include<iostream>
#include<map>
#include<vector>
#include<set>

using namespace std;

class Edge {

public:
	int u;
	int v;
	double w;

	Edge(int _u, int _v, double _w=0.0) {
		u = _u;
		v = _v;
		w = _w;
	};

};

// template <typename S, typename T>
class Digraph {

private:
	int num;
    map<int, vector<Edge*>*> adj;

public:
    Digraph(int n) {
        num = n;
        for (int i = 0; i < num; i++) {
        	adj.insert({i, new std::vector<Edge*>()});
        }
    }

    int size() {
    	return num;
    }

    void add_edge(int from, int to, double weight=0.0) {
    	Edge* e = new Edge(from, to, weight);
    	adj[from]->push_back(e);
    }

    void print() {
    	// cout << "\n";
    	for (int i = 0; i < num; i++) {

    		cout << "[" << i << "] ";

        	vector<Edge*>* adjacency = adj[i];
        	for (Edge* e : *adjacency) {
        		cout << e->v << " ";
        	}

        	cout << "\n";
        }
    }

    set<int> out_neighbors(int u) {
    	set<int> neighbors;
    	vector<Edge*>* adjacency = adj[u];
    	for (Edge* e : *adjacency) {
    		neighbors.insert(e->v);
    	}
    	return neighbors;
    }

};
