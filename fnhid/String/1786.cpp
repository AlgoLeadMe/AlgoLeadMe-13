#include <vector>
#include <iostream>

using namespace std;

vector<int> getPi(string &pattern) {
    int m = pattern.size();
    vector<int> pi(m, 0);
    int j = 0;


    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) j = pi[j - 1];
        if (pattern[i] == pattern[j]) {
            j++;
            pi[i] = j;
        }
    }
    return pi;
}

vector<int> kmp(string &pattern, string &text) {
    vector<int> res;
    vector<int> pi = getPi(pattern);
    int j = 0;
    int n = text.size(), m = pattern.size();
    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) j = pi[j - 1];
        if (text[i] == pattern[j]) {
            if (j == m - 1) {
                // success
                res.push_back(i - m + 1);
                j = pi[j];
            } else {
                j++;
            }
        }
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string P, T;
    getline(cin, T);
    getline(cin, P);
    vector<int> res = kmp(P, T);
    cout << res.size() << "\n";
    for (int i: res) {
        cout << i + 1 << " ";
    }


    return 0;
}
