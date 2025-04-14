#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;

    deque<int> dq;
    for(int i = 1; i <= N; i++) 
        dq.push_back(i);
    
    vector<int> target(M);
    for(int i = 0; i < M; i++) 
        cin >> target[i];

    int count = 0;
    for(int i = 0; i < M; i++) {
        int index = find(dq.begin(), dq.end(), target[i]) - dq.begin();

        if(index <= dq.size()/2) {
            while(index--) {
                dq.push_back(dq.front());
                dq.pop_front();
                count++;
            }
        } else{
            int step = dq.size() - index;
            while(step--) {
                dq.push_front(dq.back());
                dq.pop_back();
                count++;
            }
        }
        dq.pop_front();
    }

    cout << count << '\n';
}