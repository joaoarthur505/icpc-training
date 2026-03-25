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
    v64 v(n), inv_v(n);
    forn(i, 0, n){
        cin >> v[i];
        v[i]--;
        inv_v[v[i]] = i;
    }

    ll l = 0, r = n-1, target_up = n-1, target_down = 0;
    while(l < r){
        if(inv_v[target_up] == l){
            target_up--;
            l++;
            continue;
        }
        if(inv_v[target_up] == r) {
            target_up--;
            r--;
            continue;
        }
        if(inv_v[target_down] == l){
            target_down++;
            l++;
            continue;
        }
        if(inv_v[target_down] == r){
            target_down++;
            r--;
            continue;
        }

        break;
    }

    if(l == r){
        cout << -1 << ln;
        return;
    }
    cout << l+1 << " " << r+1 << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
