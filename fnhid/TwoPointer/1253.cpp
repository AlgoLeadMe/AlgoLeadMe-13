#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  cin.sync_with_stdio(false);
  cin.tie(NULL);
  int n, cnt=0, target, l, r, sum;

  cin >> n;

  vector<int> v(n,0);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());


  for (int i = 0; i < n; i++) {
    l=0;r=n-1;
    target = v[i];
    while (l < r){
      if (l==i) {l++;continue;}
      if (r==i) {r--;continue;}
      sum=v[r]+v[l];
      if (sum==target) {
        cnt++;
        break;
      } else if (sum < target) {
        l++;
      } else {
        r--;
      }

    }
  }

  cout << cnt << endl;
  return 0;
}
