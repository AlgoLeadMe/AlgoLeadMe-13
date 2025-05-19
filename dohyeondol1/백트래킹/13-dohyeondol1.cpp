/// N과 M(1)
#include <iostream>
using namespace std;

int N, M;
int arr[9] = {0};
bool visited[9] = {0};

void dfs(int count) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i];
            if(i < M - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            arr[count] = i;
            dfs(count + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    dfs(0);
    return 0;
}

// N과 M(2)
#include <iostream>
using namespace std;

int N, M;
int arr[9] = {0};
bool visited[9] = {0};

void dfs(int num, int count) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i];
            if(i < M - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = num; i <= N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            arr[count] = i;
            dfs(i + 1, count + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    dfs(1, 0);
    return 0;
}

// N과 M(3)
#include <iostream>
using namespace std;

int N, M;
int arr[9] = {0};

void dfs(int count) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i];
            if(i < M - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++) {
        arr[count] = i;
        dfs(count + 1);
    }
}

int main() {
    cin >> N >> M;
    dfs(0);
    return 0;
}

// N과 M(4)
#include <iostream>
using namespace std;

int N, M;
int arr[9] = {0};

void dfs(int num, int count) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i];
            if(i < M - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = num; i <= N; i++) {
        arr[count] = i;
        dfs(i, count + 1);
    }
}

int main() {
    cin >> N >> M;
    dfs(1, 0);
    return 0;
}

// N과 M(5)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
bool visited[10001] = {0};

void dfs(int count, vector<int> &sequence) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i];
            if(i < M - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++) {
        if(!visited[sequence[i]]) {
            visited[sequence[i]] = true;
            arr[count] = sequence[i];
            dfs(count + 1, sequence);
            visited[sequence[i]] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    vector<int> sequence(N);
    for(int i = 0; i < N; i++)
        cin >> sequence[i];

    sort(sequence.begin(), sequence.end());
    dfs(0, sequence);
    return 0;
}

// N과 M(6)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
bool visited[10001] = {0};

void dfs(int num, int count, vector<int> &sequence) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i];
            if(i < M - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = num; i < N; i++) {
        if(!visited[sequence[i]]) {
            visited[sequence[i]] = true;
            arr[count] = sequence[i];
            dfs(i + 1, count + 1, sequence);
            visited[sequence[i]] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    vector<int> sequence(N);
    for(int i = 0; i < N; i++)
        cin >> sequence[i];

    sort(sequence.begin(), sequence.end());
    dfs(0, 0, sequence);
    return 0;
}

// N과 M(7)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];

void dfs(int count, vector<int> &sequence) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i];
            if(i < M - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++) {
        arr[count] = sequence[i];
        dfs(count + 1, sequence);
    }
}

int main() {
    cin >> N >> M;
    vector<int> sequence(N);
    for(int i = 0; i < N; i++)
        cin >> sequence[i];

    sort(sequence.begin(), sequence.end());
    dfs(0, sequence);
    return 0;
}

// N과 M(8)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];

void dfs(int num, int count, vector<int> &sequence) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i];
            if(i < M - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = num; i < N; i++) {
        arr[count] = sequence[i];
        dfs(i, count + 1, sequence);
    }
}

int main() {
    cin >> N >> M;
    vector<int> sequence(N);
    for(int i = 0; i < N; i++)
        cin >> sequence[i];

    sort(sequence.begin(), sequence.end());
    dfs(0, 0, sequence);
    return 0;
}

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
            if(i < M - 1) cout << ' ';
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
    for(int i = 0; i < N; i++) cin >> input[i];

    sort(input.begin(), input.end());
    dfs(0, input);
    return 0;
}

// N과 M(10)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
bool visited[9];

void dfs(int num, int count, vector<int> &sequence) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i];
            if(i < M - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }

    int last = 0;
    for(int i = num; i < N; i++) {
        if(!visited[i] && sequence[i] != last) {
            visited[i] = true;
            arr[count] = sequence[i];
            last = sequence[i];
            dfs(i + 1, count + 1, sequence);
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
    dfs(0, 0, input);
    return 0;
}

// N과 M(11)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];

void dfs(int count, vector<int> &sequence) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i];
            if(i < M - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }

    int last = 0;
    for(int i = 0; i < N; i++) {
        if(sequence[i] != last) {
            arr[count] = sequence[i];
            last = sequence[i];
            dfs(count + 1, sequence);
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

// N과 M(12)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
bool visited[9];

void dfs(int num, int count, vector<int> &sequence) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i];
            if(i < M - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }

    int last = 0;
    for(int i = num; i < N; i++) {
        if(sequence[i] != last) {
            arr[count] = sequence[i];
            last = sequence[i];
            dfs(i, count + 1, sequence);
        }
    }
}

int main() {
    cin >> N >> M;
    vector<int> input(N);
    for(int i = 0; i < N; i++)
        cin >> input[i];

    sort(input.begin(), input.end());
    dfs(0, 0, input);
    return 0;
}