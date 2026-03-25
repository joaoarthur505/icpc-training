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
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    if(n == 1){
        cout << 0 << ln;
        return;
    }

    ll resp = 0;
    ll curr_max = v[0];
    forn(i, 1, n){
        debug(i);
        debug("peixe");
        while(v[i] < curr_max){
            debug(v[i]);
            assert(v[i]!=0);
            
            resp++;
            v[i]*=2;
        }
        curr_max = v[i];
    }
    
    cout << resp << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}