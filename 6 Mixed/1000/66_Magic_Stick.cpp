// https://codeforces.com/problemset/problem/1257/B

#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define debug(...) 47
#else
#include "debug.h"
#endif
#define int long long
#define float long double
#define mod 1000000007ll
#define endl '\n'
#define inf LLONG_MAX >> 1
#define all(x) (x).begin(), (x).end()
#define cinv(v, n) do { (v).resize(n); for (int i = 0; i < (n); ++i) cin >> (v)[i]; } while (0)
#define coutv(v) do { for (const auto& elem : (v)) cout << elem << " "; cout << endl; } while (0)
#define cin2d(v, rows, cols) do { (v).resize(rows, vector<int>(cols)); for (int i = 0; i < (rows); ++i) for (int j = 0; j < (cols); ++j) cin >> (v)[i][j]; } while (0)
#define cinvp(v, n) do { (v).resize(n); for (int i = 0; i < (n); ++i) cin >> (v)[i].first >> (v)[i].second; } while (0)
#define coutvp(v) do { for (const auto& p : (v)) cout << p.first << " " << p.second << " "; cout << endl; } while (0)
#define cout2d(v) do { for (const auto& row : (v)) { for (const auto& elem : row) cout << elem << " "; cout << endl; } } while (0)
#define coutb(CONDITION) cout << (CONDITION ? "YES" : "NO") << endl;
constexpr int pctr(int x) { return __builtin_popcountll(x); }



inline void solve()
{
    int n, n1;
    cin>>n>>n1;
    set<int> a;
    for(;a.find(n)==a.end();){
        if(n>=n1){
            cout<<"YES"<<endl;
            return;
        }
        a.insert(n);
        if(n&1){
            n--;
        }
        else{
            n=3*n/2;
        }
    }
    cout<<"NO"<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}