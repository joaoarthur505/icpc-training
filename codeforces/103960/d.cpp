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

ll fexp(ll n){
    ll a=1,b=2;
    while(n>0){
        if(n & 1)a*=b;
        b*=b;
        n=n>>1;
    }
    return a;
}

int main() {
    _;
    ll n,x,y; cin >> n >> x >> y;
    ll m=fexp(n);

    vll dp(m);
    ll j=m/2,cnt=0;
    while(j>0){
        for(ll i=j;i<m;i+=2*j) dp[i]=cnt;
        j/=2; cnt++;
    }

    cout << max(dp[x],dp[y]) << endl;

}

