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

bool valid(map<ll,ll> &freq, ll k){
    if(sz(freq) != k) return false;
    if(k == 1) return true;
    auto it1 = freq.begin();
    auto it2 = freq.rbegin();

    ll v1 = (*it1).first;
    ll v2 = (*it2).first;

    return (v2-v1 == k-1);
}

void solve(){
    ll n; cin >> n;
    vll v(n); 
    forn(i, 0, n){
        cin >> v[i];
        v[i]--;
    }

    vector<vector<bool>> good(n+1, vector<bool>(n, false));

    forn(i, 0, n){
        vll freq(n);
        ll diff = 0;
        ll maximo = -INF;
        ll minimo = INF;

        forn(j, i, n){
            if(freq[v[j]] == 0) diff++;
            freq[v[j]]++;

            maximo = max(maximo, v[j]);
            minimo = min(minimo, v[j]);

            if((maximo - minimo == (j-i)) && diff == j-i+1) good[j-i+1][minimo] = true;

            debug(i);
            debug(j);
            debug(diff);
            debug(maximo);
            debug(minimo);
        }
    }

    ll best_k = 0;
    for(ll k = n; k>=0; k--){
        if(best_k != 0) break;
        forn(i, 0, n-k){
            if(good[k][i] && good[k][i+k]) best_k = k;
        }
    }

    assert(best_k <= n/2);
    cout << best_k << ln;
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();
    return 0;
}
