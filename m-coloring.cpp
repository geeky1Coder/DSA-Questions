#include <bits/stdc++.h>
using namespace std;

bool isSafe(bool graph[101][101], int v, int color, int index, int vertices[]) {
	//Check all adjacent verticies not in same colour
	bool flag = true;
	for (int i = 0; i < v; ++i) {
		if (index != i && graph[index][i] == 1) {
			if (vertices[i] == color) {
				flag = false;
				break;
			}
		}
	}
	return flag;
}
bool graphColoring_util(bool graph[101][101], int m, int v, int index, int vertices[]) {
	if (index > v ) {
		return true;
	}
	//Trying all colours
	for (int i = 1; i <= m; ++i) {
		if (isSafe(graph, v, i, index, vertices)) {
			vertices[index] = i;
			if (graphColoring_util(graph, m, v, index + 1, vertices)) {
				return true;
			}
			//BackTrack
			vertices[index] == 0;
		}
	}
	return false;
}
void printSoluion(int vertices[], int v);
bool graphColoring(bool graph[101][101], int m, int V) {
	int vertices[V];
	for (int i = 0; i < V + 1; ++i) {
		vertices[i] = 0;
	}
	int index = 0;
	bool f = graphColoring_util(graph, m, V, index, vertices);
	printSoluion(vertices, V);
	return f;
}
void printSoluion(int vertices[], int v) {
	cout << "Assigned colours : ";
	for (int i = 0; i < v; ++i) {
		cout << vertices[i] << " ";
	}
	cout << endl;
}
int main() {
	bool graph[101][101] = {
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 },
	};
	int m = 3; // Number of colors
	int v = 4;
	cout << graphColoring(graph, m, v);
	return 0;
}