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
const ll MAXN = 10;
const ll MAXM = 10;
const ll peso = 1000;

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

void random_perm(ll m){
    vector<pll> v(m);
    forn(i, 0, m) v[i] = {uniform(1, peso), i+1};

    sort(v.begin(), v.end());

    forn(i, 0, m) cout << v[i].second << " ";
    cout << ln;
}

int main() {
    _;
    cout << 1 << ln;
    ll n = uniform(1, MAXN);
    ll m = uniform(1, MAXM);

    cout << n << " " << m << ln;

    forn(i, 0, n){
        random_perm(m);
    }
    return 0;
}
