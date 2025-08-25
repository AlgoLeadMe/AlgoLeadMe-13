#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int dp[1001][10];
    int N; cin >> N;
    
    for(int j = 0; j <= 9; ++j)
        dp[1][j] = 1;
    
    for(int i = 2; i <= N; i++) {
        for(int j = 0; j <= 9; j++) {
            dp[i][j] = 0;
            for(int k = 0; k <= j; k++)
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % 10007;
        }
    }
    
    int result = 0;
    for(int j = 0; j <= 9; j++)
        result = (result + dp[N][j]) % 10007;
    
    cout << result << '\n';
    return 0;
}