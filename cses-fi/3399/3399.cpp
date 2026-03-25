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
    ll n, a, b; cin >> n >> a >> b;
    ll extra = n-a-b;
    if(extra < 0){
        cout << "NO" << ln;
        return;
    }
    vector<p64> resp;
    forn(i, 0, extra)resp.emplace_back(n-i, n-i);
    n = a+b;

    if(n == 0){
        cout << "YES" << ln;

        for(auto p : resp) cout << p.first << " ";
        cout << ln;
        for(auto p : resp) cout << p.second << " ";
        cout << ln;

        return;
    }

    if(a == 0 || b == 0){
        cout << "NO" << ln;
        return;
    }

    forn(i,0, n){
        resp.emplace_back(i+1, (i+a)%n + 1);
    }

    cout << "YES" << ln;

    for(auto p : resp) cout << p.first << " ";
    cout << ln;
    for(auto p : resp) cout << p.second << " ";
    cout << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
