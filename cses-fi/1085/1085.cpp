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

bool test(ll m, v64 &v, ll k){ 
    debug(m);
    ll sum = 0, n = sz(v);
    ll counter = 1;
    forn(i, 0, n){
        if(sum+v[i] > m){
            counter++;
            sum = 0;
        }
        sum += v[i];
        debug(i);
        debug(sum);
    }

    return counter <= k;
}

int main() {
    _; ll n, k; cin >> n >> k;
    v64 v(n);
    ll sum = 0, maximo = 0;
    forn(i, 0, n){
        cin >> v[i];
        sum += v[i];
        maximo = max(maximo, v[i]);
    }

    ll l = max(sum/k, maximo), r = sum, ans;
    while(l<=r){
        ll m = (l+r)/2;
        bool t = test(m, v, k);

        if(t){
            ans = m;
            r = m-1;
        } else {
            l = m+1;
        }
        
    }

    cout << ans << ln;

    return 0;
}
