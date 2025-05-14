// N과 M(9)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
bool visited[9];

void dfs(int count, vector<int> &sequence) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i];
            if(i < M-1) cout << ' ';
        }
        cout << '\n';
        return;
    }

    int last = 0;
    for(int i = 0; i < N; i++) {
        if(!visited[i] && sequence[i] != last) {
            visited[i] = true;
            arr[count] = sequence[i];
            last = sequence[i];
            dfs(count + 1, sequence);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    vector<int> input(N);
    for(int i = 0; i < N; i++)
        cin >> input[i];

    sort(input.begin(), input.end());
    dfs(0, input);

    return 0;
}