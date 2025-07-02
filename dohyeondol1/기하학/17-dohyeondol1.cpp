#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int ccw(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
    long long outer = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
    
    if(outer < 0) return -1;
    else if(outer > 0) return 1;
    else return 0;
}

bool isOverlapping(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c, pair<long long, long long> d) {
    if(a > b) swap(a, b);
    if(c > d) swap(c, d);
    return !(b < c || d < a);
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    pair<long long, long long> a, b, c, d;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;
    
    int abc = ccw(a, b, c);
    int abd = ccw(a, b, d);
    int cda = ccw(c, d, a);
    int cdb = ccw(c, d, b);
    
    if(abc * abd == 0 && cda * cdb == 0) {
        if(isOverlapping(a, b, c, d)) cout << 1;
        else cout << 0;
    }
    else if(abc * abd <= 0 && cda * cdb <= 0) cout << 1;
    else cout << 0;
    cout << '\n';
    
    return 0;
}