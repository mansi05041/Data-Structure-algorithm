// Adjacency list.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Creation of Adjacency list

/* Time Complexity 
* storing Space : O(V+E)
* Adding an Edge : O(1)
* Adding a Vertex : O(1)
* Removing a Vertex : O(V+E)
* Removing an Edge : O(E)
* Querrying : O(V)
*/

#include <iostream>
#include <vector>
using namespace std;
#define N 10^3

// global variables
vector<int> adj[N];

// user -defined function
void AddEdge(int src, int des);
void AdjList(int v);

// main function
int main() {
	int n, m, v1, v2;
	cout << "Enter the number of edges : ";
	cin >> m;
	cout << "Enter the number of vertices : ";
	cin >> n;
	for (int i = 0; i < m; i++) {
		cout << "Enter the Vertices for Edge " << i + 1 << " : ";
		cin >> v1 >> v2;
		AddEdge(v1, v2);
	}
	cout << "\nThe given adjacency list \n";
	AdjList(n);
}

// function to add an edge
void AddEdge(int src, int des) {
	adj[src].push_back(des);
}

// function to print the Adjacency list
void AdjList(int v) {
	for (int i = 0; i < v; i++) {
		cout << "vertex " << i << " : ";
		for (auto x : adj[i]) {
			cout << "->" << x;
		}
		cout << "\n";
	}
}