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
    ll best = 0;
    forn(i, 0, n){
        forn(j, 0, n){
            ll curr = i + j*n + 1;
            if(i > 0) curr += (i-1) + j*n + 1;
            if(i < n-1) curr += (i+1) + j*n + 1;
            if(j > 0) curr += i + (j-1)*n + 1;
            if(j < n-1) curr += i + (j+1)*n + 1;

            best = max(best, curr);
        }
    }

    cout << best << ln;
}

int main(){
    _;ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}