#include <iostream>
#include <vector>
#include <list>

using namespace std;

void undirectedGraphs();
void matrixRepresentation();
void listRepresentation();

int main() {
    undirectedGraphs();
}

void undirectedGraphs() {
    int num;
    do {
        cout << "\n1: Matrix Representation.\n2: List Representation.\n0: Exit." << endl << endl;
        cout << "Enter the corresponding number: ";
        std::cin >> num;
        system("CLS");
        switch (num) {
        case 1:
            matrixRepresentation();
            break;
        case 2:
            listRepresentation();
            break;
        default:
            break;
        }
        if (!(num <= 1 && num >= 0))
            cout << "\nCorresponding number is incorrect." << endl;
    } while (num != 0);
}

void matrixRepresentation() {
    int n, m;
    cout << "Total Nodes and Edges: ";
    cin >> n >> m;
    int** adjMat = new int* [n];
    for (int i = 0; i < n; i++) {
        adjMat[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMat[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "[S][D] = ";
        cin >> u >> v;
        adjMat[u-1][v-1] = 1;
        adjMat[v-1][u-1] = 1;
    }

    cout << endl << "Adjacency Matrix is given as follows: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] adjMat[i];
        adjMat[i] = NULL;
        adjMat[i] = NULL;
    }
    delete[] adjMat;
    adjMat = NULL;
}

void addEdge (vector<int> adjList[], int u, int v) {
    adjList[u-1].push_back(v);
    adjList[v-1].push_back(u);
}

void printGraph (vector<int> adjList[], int nodes) {
    for (int i = 0; i < nodes; i++) {
        cout << i+1 << "  -> ";
        for (auto x : adjList[i])
            cout << " " << x;
        cout << endl;
    }
}

void BFS(vector<int> adjList[], int nodes, int source) {
    vector<bool> visited;
    visited.resize(nodes, false);
    list<int> queue;
    visited[source] = true;
    queue.push_back(source);
}

void listRepresentation() {
    int nodes = 7;
    vector<int>* adjList = new vector<int>[nodes];
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 2, 5);
    addEdge(adjList, 2, 6);
    addEdge(adjList, 2, 7);
    addEdge(adjList, 7, 3);
    cout << "Adjacency List is given as follows: " << endl;
    printGraph(adjList, nodes);
}