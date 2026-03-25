#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

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

int main() {
    _; ll n; cin >> n;

    set<ll> s;
    s.insert(n-1);

    v64 bigl(n, -1), bigr(n, n), dp(n, 1);

    vector<p64> v(n);
    v64 height(n);
    forn(i, 0, n){
        ll a; cin >> a;
        height[i] = a;
        v[i] = {-a, i};
    }

    sort(v.begin(), v.end());

    forn(k, 0, n){
        auto [h, i] = v[k];
        h = -h;

        debug(i);
        
        auto it = s.lower_bound(i);
        ll rep = *it;

        debug(rep);

        ll bl = bigl[rep], br = bigr[rep];

        debug(bl);
        debug(br);

        if(bl != -1){
            if(height[bl] == h) bl = bigl[bl];
            if(bl == -1) continue;
            dp[i] = max(dp[i], 1 + dp[bl]);
        }

        if(br != n){
            if(height[br] == h) br = bigr[br];
            if(br == n) continue;
            dp[i] = max(dp[i], 1 + dp[br]);
        }

        bigl[i] = bl; 
        bigr[i] = br;

        debug(bigl[i]);
        debug(bigr[i]);

        if(rep != i){
            bigl[rep] = i;
        }

        if(i != 0 && !s.count(i-1)){
            debug("oi");
            bigr[i-1] = i;
            debug(i-1);
            debug( bigr[i-1]);
        }

        s.insert(i);
        s.insert(i-1);
    }

    ll maximo = 0;
    forn(i, 0, n){
        maximo = max(maximo, dp[i]);
    }

    cout << maximo << ln;

    return 0;
}
