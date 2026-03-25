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
    ll n, m; cin >> n >> m;

    map<ll, ll> a;
    map<ll, ll> b;
    forn(i, 0, n){
        ll c; cin >> c;
        a[-c]++;
    }
    forn(i, 0, m){
        ll c; cin >> c;
        b[-c]++;
    }

    bool deu_ruim = false;
    for(auto [val, freq] : a){
        a[val]-=2*b[2*val];

        if(b.count(2*val)){
            a[val]-=2*b[2*val];
            b[2*val] = 0;
        }

        if(b.count(2*val + 1)){
            if(!a.count(val+1)) deu_ruim = true;
            else{
                a[val] -= b[2*val + 1];
                a[val+1] -= b[2*val + 1];
            }
        }

        a[val] -= b[2*val + 1];
        a[val+1] -= b[2*val + 1];

        b[val] -= a[val];
        a[val] = 0;

        if(b[val] < 0) deu_ruim = true;
        if(a[val] < 0) deu_ruim = true;
        if(a[val+1] < 0) deu_ruim = true;
    }

    for(auto [val, freq] : a) if(freq > 0) deu_ruim = true;
    for(auto [val, freq] : b) if(freq > 0) deu_ruim = true;
    if(deu_ruim){
        cout << "NO" << ln;
        return;
    }
    cout << "YES" << ln;

}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
