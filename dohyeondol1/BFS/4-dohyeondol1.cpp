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
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        int jump = map[y][x];
        if(jump == -1) return true;
        
        if(y + jump < N && !visited[y + jump][x]) {
            q.push({y + jump, x});
            visited[y + jump][x] = true;
        }
        if(x + jump < N && !visited[y][x + jump]) {
            q.push({y, x + jump});
            visited[y][x + jump] = true;
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