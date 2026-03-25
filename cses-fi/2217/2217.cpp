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
    _; ll n, k; cin >> n >> k;
    v64 a(n), b(n);
    forn(i, 0, n){
        ll c; cin >> c;
        c--;
        a[i] = c;
        b[c] = i;
    }

    function<bool (ll)> check = [&](ll i){
        return b[i] > b[i+1]; 
    };

    ll curr = 1;
    forn(i, 0, n-1) curr += check(i);

    forn(i, 0, k){
        debug(i);
        ll xa, ya; cin >> xa >> ya;
        xa--;
        ya--;
        ll xb = a[xa];
        ll yb = a[ya];

        debug(xa);
        debug(ya);
        debug(xb);
        debug(yb);

        set<ll> off;
        if(xb < n-1) off.insert(xb);
        if(xb > 0) off.insert(xb-1);
        if(yb < n-1) off.insert(yb);
        if(yb > 0) off.insert(yb-1);

        for(auto z : off) curr -= check(z); 

        trace(
            forn(i, 0, n) cout << a[i] << " \n"[i==n-1];
            cout << ln;
            forn(i, 0, n) cout << b[i] << " \n"[i==n-1];
            cout << ln;
        );

        b[xb] = ya;
        b[yb] = xa; 
        a[xa] = yb;
        a[ya] = xb;

        trace(
            forn(i, 0, n) cout << a[i] << " \n"[i==n-1];
            cout << ln;
            forn(i, 0, n) cout << b[i] << " \n"[i==n-1];
            cout << ln;
        );

        if(xb < n-1) off.insert(xb);
        if(xb > 0) off.insert(xb-1);
        if(yb < n-1)off.insert(yb);
        if(yb > 0) off.insert(yb-1);

        for(auto z : off) curr += check(z);

        cout << curr << ln;
    }

    return 0;
}
