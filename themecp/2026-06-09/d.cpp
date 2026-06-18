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

pair<string, string> read(ll m){
    string a, a_inv;
    vll v(m), v_inv(m);

    forn(i, 0, m){
        cin >> v[i];
        v[i]--;
        v_inv[v[i]] = i;
    }

    forn(i, 0, m){
        a.push_back(v[i]+'0');
        a_inv.push_back(v_inv[i]+'0');
    }

    return {a, a_inv};
}

void solve(){
    ll n, m; cin >> n >> m;
    vector<string> v(n), v_inv(n);
    forn(i, 0, n){
        auto [a, a_inv] = read(m);
        v[i] = a;
        v_inv[i] = a_inv;
    }

    sort(v_inv.begin(), v_inv.end());

    debugv(v);
    debugv(v_inv);

    forn(i, 0, n){
        ll j = lower_bound(v_inv.begin(), v_inv.end(), v[i]) - v_inv.begin();

        debug(i);
        debug(j);

        ll best_beauty = 0;
        if(j < n){ 
            ll beauty = 0;
            while(beauty < m && (v[i][beauty] == v_inv[j][beauty])) beauty++;
            best_beauty = max(best_beauty, beauty);
        }
        if(j > 0){
            j--;

            ll beauty = 0;
            while(beauty < m && (v[i][beauty] == v_inv[j][beauty])) beauty++;
            best_beauty = max(best_beauty, beauty);
        }

        cout << best_beauty << " \n"[i == n-1];
    }
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();
    return 0;
}
