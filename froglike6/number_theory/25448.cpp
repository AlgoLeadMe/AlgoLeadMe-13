#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u128 = __uint128_t;

u64 pow_mod(u64 x, u64 y, u64 m){
    u64 r = 1 % m;
    x %= m;
    while(y){
        if(y & 1) r = (u128)r * x % m;
        x = (u128)x * x % m;
        y >>= 1;
    }
    return r;
}

bool mr_wit(u64 n, u64 a){
    u64 d = n - 1, s = 0;
    while(!(d & 1)){ d >>= 1; ++s; }
    u64 x = pow_mod(a, d, n);
    if(x == 1 || x == n - 1) return false;
    for(u64 i = 1; i < s; ++i){
        x = (u128)x * x % n;
        if(x == n - 1) return false;
    }
    return true;
}

bool is_prime(u64 n){
    if(n < 2) return false;
    int small[]{2,3,5,7,11,13,17,19,23,29,31,37};
    for(int p: small) if(n % p == 0) return n == (u64)p;
    u64 bases[]{2,325,9375,28178,450775,9780504,1795265022};
    for(u64 a: bases) if(a % n && mr_wit(n, a % n)) return false;
    return true;
}

i64 find_t(i64 p, const vector<char>& T, i64 d, i64 u, i64 v, i64 inv){
    i64 lo = (u128(u) * inv) % p;
    i64 hi = p + (u128(v) * inv) % p;
    while(lo + 1 != hi){
        i64 mid = (lo + hi) >> 1;
        if(T[(u128(mid) * d) % p]) lo = mid;
        else hi = mid;
    }
    return (u128(hi) * d) % p;
}

vector<char> egz_prime(i64 p, const vector<i64>& a){
    i64 m = 2 * p - 1;
    vector<int> mods(m);
    for(i64 i = 0; i < m; ++i) mods[i] = a[i] % p;
    vector<int> k(m); iota(k.begin(), k.end(), 0);
    sort(k.begin(), k.end(), [&](int x,int y){ return mods[x] < mods[y]; });
    vector<char> L(m,0);
    for(i64 i = 0; i < p - 1; ++i){
        if(mods[k[1+i]] == mods[k[p+i]]){
            for(i64 j = 1+i; j <= p+i; ++j) L[k[j]] = 1;
            return L;
        }
    }
    i64 s = 0; for(i64 i = 0; i < p; ++i) s += mods[k[i]];
    s %= p;
    vector<char> T(p,0); vector<i64> P(p,-1); T[s] = 1;
    unordered_map<i64,i64> inv_cache;
    for(i64 i = 1; i < p && !T[0]; ++i){
        i64 d = mods[k[p+i-1]] - mods[k[i]];
        if(d < 0) d += p;
        i64 inv = inv_cache.count(d) ? inv_cache[d] : (inv_cache[d] = pow_mod(d, p-2, p));
        i64 t = find_t(p,T,d,s,0,inv);
        T[t]=1; P[t]=i;
    }
    i64 c = 0;
    for(i64 i = 0; i < p; ++i) L[k[i]] = 1;
    while(s != c){
        int idx1 = k[p + P[c] - 1];
        int idx2 = k[P[c]];
        L[idx1] = 1; L[idx2] = 0;
        c = (c - (mods[idx1] - mods[idx2])) % p;
        if(c < 0) c += p;
    }
    return L;
}

vector<char> EGZ(i64, const vector<i64>&);

vector<char> egz_comp(i64 p, i64 q, const vector<i64>& a){
    vector<i64> sums;
    vector<int> win;
    for(i64 i=0;i<p-1;++i) win.push_back(i);
    for(i64 i=0;i<2*q-1;++i){
        for(i64 j=(i+1)*p-1;j<(i+2)*p-1;++j) win.push_back(j);
        vector<i64> sub; sub.reserve(win.size());
        for(int id:win) sub.push_back(a[id]);
        auto flags = egz_prime(p,sub);
        i64 s=0; vector<int> nxt; nxt.reserve(win.size());
        for(size_t j=0;j<flags.size();++j)
            if(flags[j]) s += a[win[j]];
            else nxt.push_back(win[j]);
        sums.push_back(s/p);
        win.swap(nxt);
    }
    auto sel = EGZ(q,sums);
    vector<char> L(2*p*q-1,0);
    win.clear();
    for(i64 i=0;i<p-1;++i) win.push_back(i);
    for(i64 i=0;i<2*q-1;++i){
        for(i64 j=(i+1)*p-1;j<(i+2)*p-1;++j) win.push_back(j);
        vector<i64> sub; sub.reserve(win.size());
        for(int id:win) sub.push_back(a[id]);
        auto flags = egz_prime(p,sub);
        if(sel[i])
            for(size_t j=0;j<flags.size();++j) if(flags[j]) L[win[j]]=1;
        vector<int> nxt; nxt.reserve(win.size());
        for(size_t j=0;j<flags.size();++j) if(!flags[j]) nxt.push_back(win[j]);
        win.swap(nxt);
    }
    return L;
}

vector<char> EGZ(i64 n, const vector<i64>& a){
    if(n==1) return {1};
    if(is_prime(n)) return egz_prime(n,a);
    for(i64 d=2; d*d<=n; ++d)
        if(n%d==0) return egz_comp(d,n/d,a);
    return {};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 N; if(!(cin>>N)) return 0;
    vector<i64> A(2*N-1);
    for(auto& x:A) cin>>x;
    auto mask = EGZ(N,A);
    bool first=true;
    for(i64 i=0;i<2*N-1;++i)
        if(mask[i]){
            if(!first) cout<<' ';
            cout<<A[i]; first=false;
        }
    cout<<'\n';
    return 0;
}