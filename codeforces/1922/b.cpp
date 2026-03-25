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
    vector<ll> freq(n+1,0);
    forn(i, 0, n){
        ll a; cin >> a;
        freq[a]++;
    }

    ll sum = 0;
    ll ans = 0;
    forn(i, 0, n+1){
        ans += (freq[i]*(freq[i]-1)*(freq[i]-2))/6;
        ans += (freq[i]*(freq[i]-1)/2)*sum;
        sum += freq[i];
    }

    cout << ans << ln;
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}