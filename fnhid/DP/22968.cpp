#include <iostream>
#include <vector>
using namespace std;

int solve(vector<long long> &dp, int v) {
    int h = 0;
    while (h < dp.size() && dp[h] <= v) h++;
    return h;
}

vector<long long> tabulate() {
    vector<long long> dp;
    dp.push_back(1);
    dp.push_back(2);
    while (true) {
        long long n = 1 + dp[dp.size() - 1] + dp[dp.size() - 2];
        if (n > 1e9) break;
        dp.push_back(n);
    }
    return dp;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t, v;
    vector<long long> dp = tabulate();
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> v;
        cout << solve(dp, v) << endl;
    }
}
