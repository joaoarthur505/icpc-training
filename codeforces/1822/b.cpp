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
    ll n, c; cin >> n >> c;

    ll number_1;
    cin >> number_1;

    vector<p64> v(n-1);
    forn(i, 0, n-1){
        ll a; cin >> a;
        v[i] = {a - c*(i+2), a};
    }

    sort(v.begin(), v.end());
    ll fim = n-1;
    
    while(fim > 0){
        auto it = lower_bound(v.begin(), v.begin()+fim, p64(-number_1, -1));
        ll temp = it - v.begin();

        if(temp == fim){
            cout << "No" << ln;
            return;
        }

        forn(i, temp, fim) number_1 += v[i].second;
        fim = temp;
    }

    cout << "Yes" << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
