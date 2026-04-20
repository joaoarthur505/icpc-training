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

bool disjoint(p64 i1, p64 i2){
    return (i1.second < i2.first);
}

ll calc(p64 i1, p64 i2){
    return (i2.first-i1.second + i2.second - i1.first) - (i1.second - i1.first + i2.second - i2.first);
}

void solve(){
    ll n, k; cin >> n >> k;
    vector<p64> inter(n);
    forn(i, 0, n) cin >> inter[i].first;
    forn(i, 0, n) cin >> inter[i].second;

    ll sum = 0;
    forn(i, 0, n){
        if(inter[i].first > inter[i].second) inter[i] = {inter[i].second, inter[i].first};
        sum += inter[i].second - inter[i].first;
    }
    sort(inter.begin(), inter.end());

    ll best = INF;
    forn(i, 0, n-1){
        p64 curr = inter[i], next = inter[i+1];
        if(!disjoint(curr, next)){
            cout << sum << ln;
            return;
        }

        best = min(best, calc(curr, next));
    }

    cout << sum + best<< ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
