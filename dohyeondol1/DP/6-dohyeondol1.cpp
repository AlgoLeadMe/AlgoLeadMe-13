#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> W(N+1);
    vector<int> V(N+1);
    for(int i = 1; i <= N; i++)
        cin >> W[i] >> V[i];

    vector<int> dp(K+1, 0);

    for(int i = 1; i <= N; i++)
        for(int j = K; j >= W[i]; j--)
            dp[j] = max(dp[j], dp[j - W[i]] + V[i]);

    cout << dp[K] << '\n';

    return 0;
}
