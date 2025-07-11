#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int prim(int V, const vector<vector<pair<int, int>>>& adj) {
    vector<bool> visited(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    int totalWeight = 0;
    pq.push({0, 0});

    while(!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if(visited[u]) continue;
        visited[u] = true;
        totalWeight += weight;

        for(auto& [w, v] : adj[u]) {
            if(!visited[v]) {
                pq.push({w, v});
            }
        }
    }

    return totalWeight;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> adj(V);

    for(int i = 0; i < E; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        
        A--; B--;
        adj[A].push_back({C, B});
        adj[B].push_back({C, A});
    }

    int mstWeight = prim(V, adj);
    cout << mstWeight << '\n';
    return 0;
}