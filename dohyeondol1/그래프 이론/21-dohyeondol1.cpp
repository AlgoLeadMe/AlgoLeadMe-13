#include <iostream>
#include <vector>
using namespace std;

int height, width;
int visited[320001];
char grid[201][201];
vector<int> graph[320001];

void dfs(int u) {
    if(visited[u]) 
        return;
    visited[u] = true;
    
    for(int v : graph[u])
        dfs(v);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> height >> width;
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            int base = (i * width + j) * 8;
            char ch;
            cin >> ch;

            int mask = 0;
            if(ch == 'H') mask = 1;
            else if(ch == 'I') mask = 2;
            else if(ch == 'O') mask = 4;

            for(int k = 0; k < 8; ++k)
                graph[base + k].push_back(base + (k ^ mask));
        }
    }

    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width - 1; ++j) {
            int u = (i * width + j) * 8;
            int v = (i * width + (j + 1)) * 8;

            graph[u+1].push_back(v);
            graph[v].push_back(u + 1);

            graph[u+3].push_back(v+2);
            graph[v+2].push_back(u+3);

            graph[u+5].push_back(v+4);
            graph[v+4].push_back(u+5);

            graph[u+7].push_back(v+6);
            graph[v+6].push_back(u+7);
        }
    }

    for(int i = 0; i < height - 1; ++i) {
        for(int j = 0; j < width; ++j) {
            int u = (i * width + j) * 8;
            int v = ((i + 1) * width + j) * 8;

            graph[u+2].push_back(v);
            graph[v].push_back(u+2);

            graph[u+3].push_back(v+1);
            graph[v+1].push_back(u+3);

            graph[u+6].push_back(v+4);
            graph[v+4].push_back(u+6);

            graph[u+7].push_back(v+5);
            graph[v+5].push_back(u+7);
        }
    }

    int cnt = 0;
    for(int i = 0; i < height * width * 8; ++i) {
        if(visited[i]) continue;
        dfs(i);
        cnt++;
    }

    cout << cnt << '\n';
    return 0;
}