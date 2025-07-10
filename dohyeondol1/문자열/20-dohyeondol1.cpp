#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string arr[50];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr+N);
    
    int count = N;
    for(int i = 0; i < N-1; i++) {
        string prefix = arr[i+1].substr(0, arr[i].size());
        if(prefix == arr[i])
            count--;
    }

    cout << count << '\n';
    return 0;
}