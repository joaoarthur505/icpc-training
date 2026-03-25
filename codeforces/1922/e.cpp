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

ll val(string s){
    sort(s.begin(), s.end());
    if(s == "JJJ" || s == "AJJ") return 0;
    return 1;
} 

void solve(){
    ll n; cin >> n;
    n = n/3;
    v64 dp1(n,0), dp2(n,0), dp3(n,0);

    string s1, s2; cin >> s1 >> s2;

    dp1[0] = max(val({s1[0], s2[0], s2[1]})+val({s1[1], s1[2], s2[2]}), dp1[0]);
    dp1[0] = max(val({s2[0], s1[0], s1[1]})+val({s2[1], s2[2], s1[2]}), dp1[0]);
    dp1[0] = max(val({s1[0], s1[1], s1[2]})+val({s2[0], s2[1], s2[2]}), dp1[0]);

    dp2[0] = val({s1[0], s2[0], s2[1]});
    dp3[0] = val({s1[0], s2[0], s1[1]});
    
    forn(i, 1, n){
        dp2[i] = max(dp1[i-1] + val({s1[3*i+0], s2[3*i+0], s2[3*i+1]}), dp2[i]);
        dp2[i] = max(dp2[i-1] + val({s1[3*i-2], s1[3*i-1], s1[3*i+0]}) + val({s2[3*i+1], s2[3*i-1], s2[3*i+0]}), dp2[i]);

        dp3[i] = max(dp1[i-1] + val({s2[3*i+0], s1[3*i+0], s1[3*i+1]}), dp3[i]);
        dp3[i] = max(dp3[i-1] + val({s2[3*i-2], s2[3*i-1], s2[3*i+0]}) + val({s1[3*i+1], s1[3*i-1], s1[3*i+0]}), dp3[i]);

        dp1[i] = max(dp1[i-1] + val({s1[0+3*i],s1[1+3*i],s1[2+3*i]})+val({s2[0+3*i],s2[1+3*i],s2[2+3*i]}), dp1[i]);
        dp1[i] = max(dp2[i] + val({s1[3*i+1],s1[3*i+2],s2[3*i+2]}), dp1[i]);
        dp1[i] = max(dp3[i] + val({s2[3*i+1],s1[3*i+2],s2[3*i+2]}), dp1[i]);
    }

    cout << dp1[n-1] << ln;
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}