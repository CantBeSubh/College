// #include<bits/stdc++.h>
// using namespace std;

// int adjArr[20][20];
// map<int, bool> visited;

// void addEdge(vector<int> adj[], int u, int v){
// 	adj[u].push_back(v);
// 	adj[v].push_back(u);
//     adjArr[u][v] = 1;
//     adjArr[v][u] = 1;
// }

// void printMatrix(int v) {
//    int i, j;
//    for(i = 0; i < v; i++) {
//       for(j = 0; j < v; j++) {
//          cout << adjArr[i][j] << " ";
//       }
//       cout << endl;
//    }
// }


// void printList(vector<int> adj[], int V){
// 	for (int v = 0; v < V; ++v){
// 		cout << "\n Adjacency list of vertex "<< v << "\n head ";
// 		for (auto x : adj[v])
// 		    cout << " -> " << x;
// 	}
// }

// void DFS(vector<int> adj[],int v)
// {
//     // Mark the current node as visited and
//     // print it
//     visited[v] = true;
//     cout << v << " ";
  
//     // Recur for all the vertices adjacent
//     // to this vertex
//     list<int>::iterator i;
//     for (i = adj[v].begin(); i != adj[v].end(); ++i)
//         if (!visited[*i])
//             DFS(*i);
// }
// int main(){
// 	int V = 7;
// 	vector<int> adj[V];
//     /*
//     0:A
//     1:B
//     2:C
//     4:D
//     5:W
//     6:R
//     */
// 	addEdge(adj, 0, 1); //A->C
// 	addEdge(adj, 0, 5); //A->W
// 	addEdge(adj, 0, 1);//A->B
// 	addEdge(adj, 2, 6);//C->R
// 	addEdge(adj, 1, 6);//B->R
// 	addEdge(adj, 4, 6);//D->R
// 	addEdge(adj, 6, 5);//R->W
// 	printList(adj, V);
//     cout<<endl;
//     printMatrix(V);
// 	return 0;
// }

// DFS algorithm in C++

#include <iostream>
#include <list>
using namespace std;

int adjArr[20][20];

class Graph {
  int numVertices;
  list<int> *adj;
  bool *visited;

   public:
  Graph(int V);
  void addEdge(int src, int dest);
  void DFS(int vertex);
  void printMatrix(int v);
  void printList(int v);
};

// Initialize graph
Graph::Graph(int vertices) {
  numVertices = vertices;
  adj = new list<int>[vertices];
  visited = new bool[vertices];
}

// Add edges
void Graph::addEdge(int src, int dest) {
  adj[src].push_front(dest);
    adjArr[src][dest] = 1;
    adjArr[dest][src] = 1;
}

void Graph::printMatrix(int v){
    int i, j;
    for(i = 0; i < v; i++) {
        for(j = 0; j < v; j++) {
            cout << adjArr[i][j] << " ";
      }
      cout << endl;
   }

}

void Graph::printList( int V){
	for (int v = 0; v < V; ++v){
		cout << "\n Adjacency list of vertex "<< v << "\n head ";
		for (auto x : adj[v])
		    cout << " -> " << x;
	}
}


// DFS algorithm
void Graph::DFS(int vertex) {
  visited[vertex] = true;
  list<int> adjList = adj[vertex];

  cout << vertex << " ";

  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!visited[*i])
      DFS(*i);
}

int main() {
  Graph a(7);
  	a.addEdge(0, 1); //A->C
	a.addEdge(0, 5); //A->W
	a.addEdge(0, 1);//A->B
	a.addEdge(2, 6);//C->R
	a.addEdge(1, 6);//B->R
	a.addEdge(4, 6);//D->R
	a.addEdge(6, 5);//R->W
    cout<<endl;
    a.printList(7);
    cout<<endl;
    a.printMatrix(7);
    cout<<endl;
    a.DFS(2);

  return 0;
}