#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> dp(N+1, vector<int> (K+1, 0));
    for(int i = 0; i <= N; i++) {
        dp[i][0] = 1;
        dp[i][1] = 1;
    }
    
    for(int i = 0; i <= K; i++) 
        dp[0][i] = 1;

    for(int i = 1; i <= N; i++)
        for(int j = 2; j <= K; j++)
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000000000;
    
    cout << dp[N][K] << '\n';
    
    return 0;
}