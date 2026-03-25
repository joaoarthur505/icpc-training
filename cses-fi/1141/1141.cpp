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
    v64 song(n);
    forn(i, 0, n) cin >> song[i];

    ll best = 0;
    ll l = 0, r = 1;
    set<ll> active;
    active.insert(song[0]);
    while(r < n){
        debug(l);
        debug(r);
        if(active.count(song[r])){
            best = max(best, r-l);
            active.erase(song[l]);
            l++;
        }
        else{
            active.insert(song[r]);
            r++;
        }
    }

    best = max(best, r-l);

    cout << best << ln;
    return 0;
}
