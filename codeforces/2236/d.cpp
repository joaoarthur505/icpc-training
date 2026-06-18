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

void solve(){
    ll n, k; cin >> n >> k;
    map<ll,ll> freq;

    forn(i, 0, n){
        ll a; cin >> a;
        freq[-a]++;
    }

    bool yes = false;
    while(!freq.empty() && !yes){
        auto it = freq.begin();
        auto [v, f] = *it;

        if(f%2 == 0) yes = true;
        freq.erase(v);
        if(!freq.empty() && !yes){
            auto it2 = freq.begin();
            auto [v2, f2] = *it2;

            if(v2 - v <= k) yes = true;
        }
    }

    if(yes) cout << "YES" << ln;
    else cout << "NO" << ln;
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();
    return 0;
}
