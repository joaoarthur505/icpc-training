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
const ll LOG = 19;

int main() {
    _; ll n, q; cin >> n >> q;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    v64 acc(n+1);
    acc[0] = 0;
    forn(i, 1, n+1){
        acc[i] = v[i-1]+acc[i-1];
    }

    function<ll (ll, ll)> query = [&](ll l , ll r){ return acc[r+1] - acc[l]; };

    vector<vector<p64>> step(19, vector<p64> (n+1, {0,0}));
    step[0][n] = {n,0};
    for(ll i = n-1; i >= 0; i--){
        ll aux = i+1;
        while(aux < n && v[i] >= v[aux]) aux = step[0][aux].first;

        debug(v[i]);
        debug((aux-i));
        debug(query(aux-1, i));
        step[0][i] = {aux, v[i]*(aux-i) - query(i, aux-1)};
    }

    forn(log, 1, LOG){
        forn(i, 0, n+1){
            step[log][i] = {step[log-1][step[log-1][i].first].first, step[log-1][i].second + step[log-1][step[log-1][i].first].second};
        }
    }

    trace(
        forn(log, 0, LOG){
            forn(i, 0, n){
                    cout << "(" << step[log][i].first << ", " << step[log][i].second << "), ";
            }
            cout << ln;
        }
    );

    forn(i, 0, q){
        ll a, b; cin >> a >> b;
        a--;
        b--;

        ll curr = a;
        ll sum = 0;
        for(ll log = LOG-1; log>=0; log--){
            if(step[log][curr].first > b) continue;
            sum += step[log][curr].second;
            curr = step[log][curr].first;
        }

        sum += v[curr]*(b+1-curr) - query(curr, b);
        cout << sum << ln;
    }

    return 0;
}
