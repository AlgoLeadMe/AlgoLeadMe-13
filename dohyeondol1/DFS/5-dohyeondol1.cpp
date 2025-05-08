#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<vector<int>> graph;
bool visitedDfs[1001];
bool visitedBfs[1001];
queue<int> q;

void dfs(int current) {
    visitedDfs[current] = true;
    cout << current << " ";

    for(int next : graph[current]) {
        if(!visitedDfs[next]) {
            dfs(next);
        }
    }
}

void bfs(int startNode) {
    q.push(startNode);
    visitedBfs[startNode] = true;
    cout << startNode << " ";
    
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        
        for(int next: graph[current]) {
            if(!visitedBfs[next]) {
                q.push(next);
                visitedBfs[next] = true;
                cout << next << " ";
            }
        }
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> V;
    graph.resize(N + 1);

    for(int i = 0; i < M; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    for(int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    cout << '\n';
    bfs(V);

    return 0;
}
