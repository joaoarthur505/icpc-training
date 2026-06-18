#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

map<char, ll> dic = {{'E', 0}, {'C', 1}, {'D', 2}};

int main() {
    _; ll n; cin >> n;
    string s; cin >> s;
    vll v(n);
    forn(i, 0, n) v[i] = dic[s[i]];
    
    vector<vll> dp(3, vll(n, 0));

    forn(i,0, n){
        forn(j, 0, 3){
            if(i != 0) dp[j][i] = max( dp[j][i-1], max(dp[min(2ll, j+1)][i-1], dp[max(0ll,j-1)][i-1]));
            dp[j][i] += (v[i] == j);
        }
    }

    cout << max(dp[0][n-1], max(dp[1][n-1], dp[2][n-1])) << ln;

    return 0;
}
