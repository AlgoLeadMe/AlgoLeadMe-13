#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

struct Lecture
{
    long long start, end;
};

int max(int a, int b)
{
    return a > b ? a : b;
}

using namespace std;

int main()
{
    int n, id, start, end, answer=0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;


    cin >> n;
    vector<Lecture> v(n);
    for (int i=0;i<n;i++)
    {
        cin >> id >> start >> end;
        v.push_back({start, end});
    }

    sort(v.begin(), v.end(), [](const Lecture& a, const Lecture& b)
    {
        return a.start < b.start;
    });

    for (Lecture& l : v)
    {

        while (!pq.empty() && pq.top() <= l.start)
            pq.pop();
        pq.push(l.end);
        answer = max(answer, (int)pq.size());
    }


    cout << answer;

}