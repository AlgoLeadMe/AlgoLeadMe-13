#include <iostream>

using namespace std;

int main() {
    int t, x1, y1, r1, x2, y2, r2;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int rsum = (r1 + r2) * (r1 + r2);
        int rdiff = (r1 - r2) * (r1 - r2);
        if (d == 0) {
            if (r1 == r2) {
                cout << -1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (d > rsum || d < rdiff) {
            cout << 0 << "\n";
        } else if (d == rsum || d == rdiff) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
    return 0;
}
