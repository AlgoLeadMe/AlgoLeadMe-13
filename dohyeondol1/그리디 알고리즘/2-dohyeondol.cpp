#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    
    vector<int> sensor(N);
    for(int i = 0; i < N; i++) {
        cin >> sensor[i];
    }
    
    if(K >= N) {
        cout << "0";
        return 0;
    }
    
    sort(sensor.begin(), sensor.end());
    
    vector<int> receivingArea;
    for(int i = 0; i < N-1; i++) {
        receivingArea.push_back(sensor[i+1] - sensor[i]);
    }
    
    sort(receivingArea.begin(), receivingArea.end());
    
    int minTotalReceivingArea = 0;
    for(int i = 0; i < (N-1)-(K-1); i++) {
        minTotalReceivingArea += receivingArea[i];
    }

    cout << minTotalReceivingArea;

    return 0;
}