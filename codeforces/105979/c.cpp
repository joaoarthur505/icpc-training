#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define forn(i,s,e) for(ll i=s;i<e;i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u)
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

const ll MOD = 998244353;


int main(){
    _;
    ll n; cin >> n;
    vll h(n), dp(n), sdp(100'005);
    forn(i,0,n) cin >> h[i];

    // forn(j,0,10) cout << j << " \n"[j==9];

    sdp[h[0]] = 1;
    forn(i,0,n){
        ll ans = sdp[h[i]];
        dp[i] = ans;
        if(i + 1 < n) sdp[h[i+1]] = (sdp[h[i+1]] + ans)%MOD;
        // forn(j,0,10) cout << sdp[j] << " \n"[j==9];
    }

    // forn(i,0,n) cout << dp[i] << " \n"[i==n-1];
    cout << dp[n-1] << ln;
}


