#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
    long long x, y;
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;
    vector<Point> points(n);
    for(int i = 0; i < n; ++i)
        cin >> points[i].x >> points[i].y;

    long long S2 = 0;
    for(int i = 0; i < n; ++i) {
        long long x1 = points[i].x;
        long long y1 = points[i].y;
        long long x2 = points[(i+1)%n].x;
        long long y2 = points[(i+1)%n].y;

        S2 += (x1*y2 - y1*x2);
    }

    S2 = abs(S2);
    long long B = 0;
    for(int i = 0; i < n; ++i) {
        long long x1 = points[i].x;
        long long y1 = points[i].y;
        long long x2 = points[(i+1)%n].x;
        long long y2 = points[(i+1)%n].y;

        long long dx = abs(x2 - x1);
        long long dy = abs(y2 - y1);

        B += __gcd(dx, dy);
    }

    long long answer = (S2 - B + 2)/2;
    cout << answer << '\n';
    return 0;
}