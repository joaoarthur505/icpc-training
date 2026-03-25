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
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    if(n == 1){
        cout << "NO" << ln;
        return;
    }

    vector<bool> dp(n+1, false);

    dp[n] = true;

    for(ll i = n; i >= 0; i--){
        if((i<n) && (i + v[i] + 1 <= n) && dp[i + v[i] + 1]){
            dp[i] = true;
        }

        if(dp[i] && (i>0) && ((i - v[i-1] - 1) >= 0)){
            dp[i - v[i-1] - 1] = true;
        }
    }

    // forn(i, 0, n){
    //     cout << dp[i] << " ";
    // }
    // cout << ln;

    if(dp[0]){
        cout << "YES" << ln;
    }
    else{
        cout << "NO" << ln;
    }
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}