#include <bits/stdc++.h>
#define ll long long
#define MAX 50001

using namespace std;

ll mu[MAX] = {0, 1}; 
unordered_map<int, ll> mp;

ll sum_mu(int x) {
   int j;
   if (x<MAX) return mu[x];
   if (mp.find(x) != mp.end()) return mp[x];
   ll ret = 1;
   for (int i=2; i<=x; i=j+1) {
      j = x/(x/i);
      ret -= (j-i+1) * sum_mu(x/i);
   }
   return mp[x] = ret;
}

void init_mu(){
    for (int i=1; i<MAX; i++) {
      for (int j=2; j*i<MAX; j++) mu[j*i] -= mu[i];
      mu[i] += mu[i-1];
   }
}

ll count_coprime_pairs(int a, int b){
    ll result=0;
    ll q_a, q_b, r, mu_sum;
    ll i = 1, n = min(a,b);
    while (i<=n){
        q_a = a/i;
        q_b = b/i;
        r = min(a/q_a, b/q_b);
        mu_sum = sum_mu(r) - sum_mu(i-1);
        result += (q_a * q_b) * mu_sum;
        i=r+1;
    }
    return result;
}

void solve(int a, int b, int d){
    cout << count_coprime_pairs(a/d, b/d) << "\n";
}

int main()
{
   //freopen("./input.txt", "r", stdin);
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   init_mu();
   int a,b,d,n;
   cin >> n;
   for (int i=0;i<n;i++){
       cin >> a >> b >> d;
       solve(a,b,d);
   }
   
   return 0;
}
