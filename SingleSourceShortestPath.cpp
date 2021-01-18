#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
// #define V 9

//Belmen Ford
class Edge {
public:
	int src;
	int dest;
	int weight;
	Edge() {}
	Edge(int s, int d, int w) {
		src = s;
		dest = d;
		weight = w;
	}
};

class Graph {
public:
	int V, E;
	Edge* edges;
	Graph(int v, int e) {
		V = v;
		E = e;
		edges = new Edge[e];
	}
};
void BellmanFord(Graph *graph, int s) {
	int dist[graph->V];
	for (int i = 0; i < graph->V; ++i) {
		dist[i] = INF;
	}
	dist[s] = 0;
	for (int i = 0; i < graph->V; ++i) {
		for (int j = 0; j < graph->E; ++j) {
			Edge e = graph->edges[j];
			if (dist[e.src] != INF && dist[e.dest] > dist[e.src] + e.weight) {
				dist[e.dest] = dist[e.src] + e.weight;
			}
		}
	}
	for (int j = 0; j < graph->E; ++j) {
		Edge e = graph->edges[j];
		if (dist[e.src] != INF && dist[e.dest] > dist[e.src] + e.weight) {
			printf("Graph contains negative weight cycle");
			return; // If negative cycle is detected, simply return
		}
	}
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < graph->V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}
int main() {
	int V = 5;
	int E = 8;
	Graph* graph = new Graph(V, E);

	// // add edge 0-1 (or A-B in above figure)
	graph->edges[0] = *(new Edge(0, 1, -1));
	graph->edges[1] = *(new Edge(0, 2, 4));
	graph->edges[2] = *(new Edge(1, 2, 3));
	graph->edges[3] = *(new Edge(1, 3, 2));
	graph->edges[4] = *(new Edge(1, 4, 2));
	graph->edges[5] = *(new Edge(3, 2, 5));
	graph->edges[6] = *(new Edge(3, 1, 1));
	graph->edges[7] = *(new Edge(4, 3, -3));

	BellmanFord(graph, 0);
}
//Greddy Approach-Dijkstra Complexity-O(V^2+E)
// int minDistance(int dist[], bool sptSet[])
// {
// 	int min = INT_MAX, min_index;

// 	for (int v = 0; v < V; v++)
// 		if (sptSet[v] == false && dist[v] <= min)
// 			min = dist[v], min_index = v;

// 	return min_index;
// }
// void dijkstra(int graph[V][V], int s) {
// 	int dist[V];
// 	bool splSet[V];

// 	for (int i = 0; i < V; ++i) {
// 		dist[i] = INF;
// 		splSet[i] = false;
// 	}

// 	dist[s] = 0;

// 	for (int count = 0; count < V; ++count) {
// 		int m = minDistance(dist, splSet);
// 		splSet[m] = true;
// 		for (int v = 0; v < V; ++v) {
// 			if (graph[m][v] != 0 && dist[m] != INT_MAX && splSet[v] == false && graph[m][v] + dist[m] < dist[v]) {
// 				dist[v] = graph[m][v] + dist[m];
// 			}
// 		}
// 	}
// 	cout << "Vertex \t\t Distance from Source\n";
// 	for (int i = 0; i < V; i++)
// 		cout << i << '\t' << '\t' << dist[i] << endl;
// }
// int main() {
// 	int graph[V][V] =
// 	{	{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
// 		{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
// 		{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
// 		{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
// 		{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
// 		{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
// 		{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
// 		{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
// 		{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
// 	};
// 	dijkstra(graph, 0);
// }
//Directed Acyclic Graph O(V+E)
// class AdjListNode
// {
// 	int v;
// 	int weight;
// public:
// 	AdjListNode(int _v, int _w)  { v = _v;  weight = _w;}
// 	int getV()       {  return v;  }
// 	int getWeight()  {  return weight; }
// };

// class Graph
// {
// 	int V;
// 	list<AdjListNode> *adj;
// 	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
// public:
// 	Graph(int V);
// 	void addEdge(int u, int v, int weight);
// 	void shortestPath(int s);
// };
// void Graph::shortestPath(int s) {
// 	bool visited[V];
// 	for (int i = 0; i < V; ++i) {
// 		visited[i] = false;
// 	}
// 	std::stack<int> st;
// 	topologicalSortUtil(s, visited, st);
// 	int dist[V];
// 	for (int i = 0; i < V; i++)
// 		dist[i] = INF;
// 	dist[s] = 0;
// 	while (!st.empty()) {
// 		int x = st.top();
// 		if (dist[x] != INF) {
// 			for (auto it = adj[x].begin(); it != adj[x].end(); ++it) {
// 				if (it->getWeight() + dist[x] < dist[it->getV()]) {
// 					dist[it->getV()] = it->getWeight() + dist[x];
// 				}
// 			}
// 		}
// 		st.pop();
// 	}
// 	for (int i = 0; i < V; i++)
// 		(dist[i] == INF) ? cout << "INF " : cout << dist[i] << " ";
// }
// void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &stack) {
// 	visited[v] = true;
// 	for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
// 		if (!visited[it->getV()]) {
// 			topologicalSortUtil(it->getV(), visited, stack);
// 		}
// 	}
// 	stack.push(v);
// }
// Graph::Graph(int V) {
// 	this->V = V;
// 	adj = new list<AdjListNode>[V];
// }
// void Graph::addEdge(int u, int v, int weight) {
// 	AdjListNode* newNode = new AdjListNode(v, weight);
// 	adj[u].push_back(*newNode);
// }
// int main() {
// 	Graph g(6);
// 	g.addEdge(0, 1, 5);
// 	g.addEdge(0, 2, 3);
// 	g.addEdge(1, 3, 6);
// 	g.addEdge(1, 2, 2);
// 	g.addEdge(2, 4, 4);
// 	g.addEdge(2, 5, 2);
// 	g.addEdge(2, 3, 7);
// 	g.addEdge(3, 4, -1);
// 	g.addEdge(4, 5, -2);

// 	int s = 1;
// 	cout << "Following are shortest distances from source " << s << " n";
// 	g.shortestPath(s);

// 	return 0;
// }