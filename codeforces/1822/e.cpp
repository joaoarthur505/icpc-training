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

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    string s;

    if(k<max(abs(n-m),1ll)){
        cout << -1 << ln;
        return;
    }
    if(k>max(n, m)){
        cout << -1 << ln;
        return;
    }

    bool first = 1;
    if(n > m){
        swap(n, m);
        first = 0;
    }

    forn(i, 0, k)s.push_back("01"[first]);

    forn(i, 0, m-k){
        s.push_back("01"[first^1]);
        s.push_back("01"[first]);
    }

    forn(i, 0, n+k-m) s.push_back("01"[first^1]);

    cout << s << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
