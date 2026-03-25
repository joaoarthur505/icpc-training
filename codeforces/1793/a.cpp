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
    ll n; cin >> n;
    map<ll,v64> mp;
    vector<p64> v;
    forn(i, 0, n){
        ll a; cin >> a;
        v.push_back({a+i+1, i});
    }

    sort(v.begin(), v.end());

    set<ll> possib;
    possib.insert(n+1);

    forn(i, 0, n){
        if(possib.count(v[i].first)) possib.insert(v[i].first + v[i].second); 
    }

    cout << *possib.rbegin() - 1 << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
