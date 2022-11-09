#include <bits/stdc++.h>
using namespace std;

const int max_size = 7;

int G[max_size][max_size];
char C[max_size];
int par[max_size];

void DFS(int node) {
    cout << node << "->\n";

    for (int i = 0; i < max_size; ++i) {
        cout << "Parent[" << i << "] = " << par[i] << "\n";
        cout << "Color[" << i << "] = " << C[i] << "\n";
        cout << "\n";
    }
    cout << "---------------------------------------------------\n";

    C[node] = 'g';
    for (int i = 0; i < max_size; ++i) {
        int adj = i;
        if (G[node][adj] == 1 and C[adj] == 'w') {
            par[adj] = node;
            DFS(adj); //DFS(4)
        }
    }
    C[node] = 'b';
}

int main()
{
    int edgeCount;
    cin >> edgeCount;

    for (int i = 0; i < edgeCount; ++i) {
        int u, v;
        cin >> u >> v;

        G[u][v] = 1;
    }

    for (int i = 0; i < max_size; ++i) {
        C[i] = 'w';
        par[i] = -1;
    }

    int sourceNode;
    cin >> sourceNode;

    DFS(sourceNode); //DFS(1)
    par[sourceNode] = -1;

    cout << "Final:\n";
    for (int i = 0; i < max_size; ++i) {
        cout << "Parent[" << i << "] = " << par[i] << "\n";
        cout << "Color[" << i << "] = " << C[i] << "\n";
        cout << "\n";
    }

    return 0;
}

/*
8
1 6
1 4
4 3
3 5
3 2
2 1
5 2
3 1
1
*/

