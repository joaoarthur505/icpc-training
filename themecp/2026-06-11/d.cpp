#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

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

string tost(ll n, ll k){
    ll pow = 1;
    forn(i, 0, k) pow *= 2;

    string s(k, '0');
    forn(i, 0, k){
        pow /= 2;
        if(n >= pow){
            s[i] = '1';
            n -= pow;
        }
    }

    return s;
}

pll compare(tuple<string, ll, ll> t1, tuple<string, ll, ll> t2){
    string s1 = get<0>(t1), s2 = get<0>(t2);
    ll v1 = get<2>(t1), v2 = get<2>(t2);

    ll pow = 1, x = 0, k = sz(s1);
    forn(i, 0, k) pow *= 2;

    forn(i, 0, k){
        pow /= 2;
        if(s1[i] == '0' && s2[i] == '0') x+= pow;
    }

    return {(v1^x)&(v2^x), x};
}

void solve(){
    ll n, k; cin >> n >> k;
    vll v(n);
    vector<tuple<string, ll, ll>> to_sort(n);
    forn(i, 0, n){
        cin >> v[i];
        to_sort[i] = {tost(v[i], k), i, v[i]};
    }

    sort(to_sort.begin(), to_sort.end());

    ll best_val = -1, best_i, best_j, best_x;
    forn(i, 0, n-1){
        auto [val, x] = compare(to_sort[i], to_sort[i+1]);

        if(val > best_val){
            best_val = val;
            best_i = get<1>(to_sort[i]);
            best_j = get<1>(to_sort[i+1]);
            best_x = x;
        }
    }

    cout << best_i+1 << " " << best_j+1<< " " << best_x << ln;
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();
    return 0;
}
