#include <iostream>
#include <queue>
using namespace std;

int N;
int map[64][64];
bool visited[64][64];

bool bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        int jump = map[x][y];
        if(jump == -1) return true;
        
        if(x + jump < N && !visited[x + jump][y]) {
            q.push({x + jump, y});
            visited[x + jump][y] = true;
        }
        if(y + jump < N && !visited[x][y + jump]) {
            q.push({x, y + jump});
            visited[x][y + jump] = true;
        }
    }
    
    return false;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> map[i][j];

    if(bfs()) cout << "HaruHaru";
    else cout << "Hing";

    return 0;
}