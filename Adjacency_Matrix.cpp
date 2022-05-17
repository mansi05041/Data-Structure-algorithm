// Adjacency_Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Creation of Adjacency Matrix

/* Time complexity  
* storage space = o(V^2)
* Adding a vertex = o(V^2)
* Adding an edge = o(1)
* Removing a vertex = o(V^2)
* Removing an edge = o(1)
* Querying = o(1)
*/

#include <iostream>
#define N 10^3
using namespace std;

// global variable
int graph[N][N] = { 0 };

// main function
int main()
{
    int n, m, v1, v2;
    cout << "Enter the number of edges  : ";
    cin >> m;
    cout << "Enter the number of vertices : ";
    cin >> n;
    for (int i = 0; i < m; i++) {
        cout << "Enter the vertices that are connected  for edge " << i + 1 << " : ";
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v1][v2] = 1;
    }
    cout << "Adjacency matrix is given as : " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

