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
    vector<p64> v(n);
    forn(i, 0, n){
        ll a, b; cin >> a >> b;
        v[i] = {-b, a};
    }

    sort(v.begin(), v.end());

    ll t = 0;
    ll counter = 0;
    forn(i, 0, n){
        p64 curr;
        curr.first = v[i].second;
        curr.second = -v[i].first;

        if(curr.first < t) continue;
        counter++;
        t = curr.second;
    }

    cout << counter << ln;

    return 0;
}
