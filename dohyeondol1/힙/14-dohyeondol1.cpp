#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto &sco : scoville)
        pq.push(sco);

    while (pq.top() < K) {
        answer++;
        int notHot1 = pq.top();
        pq.pop();
        if (pq.empty()) return -1;
        int notHot2 = pq.top();
        pq.pop();

        int newOne = notHot1 + notHot2 * 2;
        pq.push(newOne);
    }

    return answer;
}