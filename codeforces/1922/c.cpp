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
    ll n, m; cin >> n >> m;
    v64 a(n);
    forn(i, 0, n){
        cin >> a[i];
    }
    string s; cin >> s;
    v64 a_ord;
    ll l = 0, r = n-1;
    forn(i, 0, n){
        if(s[i] == 'L'){
            a_ord.push_back(a[l]);
            l++;
        }
        if(s[i] == 'R'){
            a_ord.push_back(a[r]);
            r--;
        }
    }

    v64 ans;
    ll prod = 1;
    for(ll i = n-1; i>=0; i--){
        prod = (prod*a_ord[i])%m;
        ans.push_back(prod);
    }

    for(ll i = n-1; i>=0; i--) cout << ans[i] << " \n"[i==0];
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}