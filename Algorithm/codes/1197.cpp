#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10000 + 1

int vertexParent[MAX];

class Edge {
public:
	int vertexA;
	int vertexB;
	int weight;

	Edge(int _vertexA, int _vertexB, int _weight) {
		this->vertexA = _vertexA;
		this->vertexB = _vertexB;
		this->weight = _weight;
	}

	bool operator<(Edge& edge) {
		return this->weight < edge.weight;
	}
	bool operator<=(Edge& edge) {
		return this->weight <= edge.weight;
	}
};

int getParent(int vertex) {
	if (vertexParent[vertex] == vertex)
		return vertex;
	else
		return getParent(vertexParent[vertex]);
}

int unionEdge(Edge &e) {
	if(e.vertexA < e.vertexB)
		vertexParent[e.vertexB] = e.vertexA;
	else
		vertexParent[e.vertexA] = e.vertexB;
	return e.weight;
}

bool isCycle(int vertexA, int vertexB) {
	if (getParent(vertexA) == getParent(vertexB))
		return true;
	else
		return false;
}

int solution(vector<Edge> &edge, int v) {
	int sum = 0;

	for (int i = 0; i < v; i++)
		vertexParent[i] = i;

	sort(edge.begin(), edge.end());

	for (auto e:edge) {
		if (!isCycle(e.vertexA, e.vertexB))
			sum += unionEdge(e);
	}
	return sum;
}
void input() {
}

int main() {
	int v, e;
	cin >> v >> e;
	vector<Edge> edge;
	for (int i = 0; i < e; i++) {
		int vertexA, vertexB, weight;
		cin >> vertexA >> vertexB >> weight;
		edge.push_back(Edge(vertexA, vertexB, weight));
	}

	cout << solution(edge, v);
}
