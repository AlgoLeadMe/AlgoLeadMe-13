#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using Graph = vector<vector<int> >;

void dfs(Graph &graph, vector<bool> &visited) {
    stack<int> s;
    s.push(1);
    visited[1] = true;
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        for (int neigh: graph[v]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                s.push(neigh);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    Graph G(n + 1);
    vector<bool> visited(n + 1, false);
    for (int i = 0; i < n - 2; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    } // set graph

    dfs(G, visited);

    int iso = -1;
    for (int i = 2; i < n + 1; i++) {
        if (!visited[i]) {
            iso = i;
            break;
        }
    }

    cout << 1 << " " << iso;
    return 0;
}
