#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool visited[1001][1001];
int days[1001][1001];

int bfs(vector<vector<int>>& graph, int N, int M) {
    queue<pair<int, int>> q;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(graph[i][j] == 1) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    int max_day = 0;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny >= 0 && ny < N && nx >= 0 && nx < M) {
                if(!visited[ny][nx] && graph[ny][nx] == 0) {
                    visited[ny][nx] = true;
                    graph[ny][nx] = 1;
                    days[ny][nx] = days[y][x] + 1;
                    max_day = max(max_day, days[ny][nx]);
                    q.push({ny, nx});
                }
            }
        }
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(graph[i][j] == 0) return -1;

    return max_day;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int M, N;
    cin >> M >> N;

    vector<vector<int>> storage(N, vector<int>(M));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> storage[i][j];

    cout << bfs(storage, N, M) << '\n';
    return 0;
}
