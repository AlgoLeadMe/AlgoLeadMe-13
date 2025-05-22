#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;
int map[501][501];
int visited[501][501];
int xCheck[501];
int answer[501];
int area = 0;

void dfs(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 1 || ny < 1 || nx > N || ny > M) continue;
        if(visited[nx][ny] || map[nx][ny] == 0) continue;

        visited[nx][ny] = 1;
        if(!xCheck[ny]) xCheck[ny] = 1;
        area++;

        dfs(nx, ny);
    }
}

int solution(vector<vector<int>> land) {
    N = land.size();
    M = land[0].size();

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            map[i][j] = land[i-1][j-1];

    for(int x = 1; x <= M; x++) {
        for(int y = 1; y <= N; y++) {
            if(map[y][x] == 0 || visited[y][x]) continue;

            visited[y][x] = 1;
            xCheck[x] = 1;
            area = 1;

            dfs(y, x);

            for(int i = 1; i <= M; i++) {
                if(xCheck[i]) {
                    answer[i] += area;
                    xCheck[i] = 0;
                }
            }

            area = 0;
        }
    }

    int maxOil = 0;
    for(int i = 1; i <= M; i++)
        maxOil = max(maxOil, answer[i]);

    return maxOil;
}