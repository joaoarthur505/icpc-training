#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n; cin >> n;
    vector<v64> v(2, v64(n));
    vector<vector<p64>> la(2, vector<p64>(n,{n,n})); // last_appearence
    ll best = 0;
    forn(i, 0, 2){
        forn(j, 0, n){
            cin >> v[i][j];
            v[i][j]--;
        }
    }

    for(ll i = n-1; i>=0; i--){
        ll a0 = v[0][i], a1 = v[1][i];

        // cout << i << ln;

        // cout << ln;

        // cout << a0 << ln;
        // cout << la[i%2][a0].first << " " << la[i%2][a0].second << ln;
        // cout << la[(i+1)%2][a0].first << " " << la[(i+1)%2][a0].second << ln;

        // cout << ln;

        // cout << a1 << ln;
        // cout << la[(i+1)%2][a1].first << " " << la[(i+1)%2][a1].second << ln;
        // cout << la[i%2][a1].first << " " << la[i%2][a1].second << ln;

        if(la[i%2][a0].first != n && (la[i%2][a0].first != (i+1) || la[i%2][a0].second != n)){
            best = max(best, i+1);
        }

        if(la[(i+1)%2][a0].first != n){
            best = max(best, i+1);
        }

        if(la[(i+1)%2][a1].first != n && (la[(i+1)%2][a1].first != (i+1) || la[(i+1)%2][a1].second != n)){
            best = max(best, i+1);
        }

        if(la[i%2][a1].first != n){
            best = max(best, i+1);
        }

        if(a0 == a1){
            best = max(best, i+1);
        }

        la[i%2][a0] = {i, la[i%2][a0].first};
        la[(i+1)%2][a1] = {i, la[(i+1)%2][a1].first};
    }

    cout << best << ln;
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}