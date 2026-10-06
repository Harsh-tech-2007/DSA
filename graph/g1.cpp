#include <iostream>
#include <vector>
#include <list>
#include<queue>
using namespace std;

class graph {
    int v;
    list<int>* l;

public:
    graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }

    void addedge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printgraph() {
        for (int i = 0; i < v; i++) {
            cout << i << " -> ";

            for (int neighbor : l[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    ~graph() {
        delete[] l;
    }

    void bfs(){
        queue<int> Q;
        vector<bool> vis(v, false);

        Q.push(0);
        vis[0] = true;

        while (Q.size()>0)
        {
            int u = Q.front();
            Q.pop();

            cout << u << " ";

            for (int v:l[u]){
                if(!vis[v]){
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
    }
};

int main() {
    graph g(4);

    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 3);

    g.printgraph();

    return 0;
}