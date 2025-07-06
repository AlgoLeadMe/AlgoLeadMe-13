#include <bits/stdc++.h>
using namespace std;

enum WORDS {
    VOID,
    APPLE,
    BODY
};

#define X first
#define Y second

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int solve(int n, vector<pair<int, char> > &cmd, vector<vector<int> > &board) {
    int time = 0, length = 1, dir_idx = 0, cmd_idx = 0;


    pair<int, int> head = {0, 0}, tail;
    queue<pair<int, int> > q;

    q.push({0, 0});
    board[0][0] = BODY;

    while (true) {
        time++;
        //move
        head.X += dx[dir_idx];
        head.Y += dy[dir_idx];

        // crash check
        if (head.X < 0 || head.Y < 0 || head.X >= n || head.Y >= n ||
            board[head.X][head.Y] == BODY)
            break;

        if (board[head.X][head.Y] != APPLE) {
            tail = q.front();
            q.pop();
            board[tail.first][tail.second] = VOID;
        }
        q.push(head);
        board[head.X][head.Y] = BODY;


        // dir change for next time
        if (cmd_idx < cmd.size() && cmd[cmd_idx].first == time) {
            if (cmd[cmd_idx].second == 'D') {
                dir_idx = (dir_idx + 1) % 4;
            } else {
                // 'L'
                dir_idx = (dir_idx + 3) % 4; // 3 mod 4 == -1 mod 4
            }
            cmd_idx++;
        }
    }
    return time;
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    vector<vector<int> > board(n, vector<int>(n, 0)); // 1: apple, 2: body
    board[0][0] = BODY;

    pair<int, int> apl; // first: row, second: column


    for (int i = 0; i < k; i++) {
        cin >> apl.first >> apl.second;

        apl.first--;
        apl.second--;
        board[apl.first][apl.second] = APPLE;
    }

    int l;
    cin >> l;

    vector<pair<int, char> > cmd(l, {0, 0}); // first: time, second: dir idx
    for (int i = 0; i < l; i++) {
        cin >> cmd[i].first >> cmd[i].second;
    }

    cout << solve(n, cmd, board);
    return 0;
}

