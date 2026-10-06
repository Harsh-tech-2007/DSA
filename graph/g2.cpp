#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class Graph {
    map<int, list<int>> adjList;

public:
    void add_edge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void print() {
        cout << "Adjacency list for the Graph:\n";

        for (auto i : adjList) {
            cout << i.first << " -> ";

            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    // BFS: O(V + E)
    void bfs(int src) {
        queue<int> Q;
        map<int, bool> vis;

        Q.push(src);
        vis[src] = true;

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();

            cout << u << " ";

            for (int v : adjList[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
    }

    // DFS: O(V + E)
    void dfs(int src) {
        map<int, bool> vis;
        dfshelper(src, vis);
    }

    void dfshelper(int u, map<int, bool>& vis) {
        cout << u << " ";
        vis[u] = true;

        for (int v : adjList[u]) {
            if (!vis[v]) {
                dfshelper(v, vis);
            }
        }
    }
};

int main() {
    Graph g;

    g.add_edge(1, 0);
    g.add_edge(2, 0);
    g.add_edge(1, 2);

    cout << "DFS: ";
    g.dfs(0);

    cout << "\nBFS: ";
    g.bfs(0);

    return 0;
}