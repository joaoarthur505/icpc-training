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
    ll n, und; cin >> n >> und;
    v64 v(n);
    ll best = 0, best_ind;
    forn(i, 0, n){
        cin >> v[i];
        if(i==0) v[i] += und;
        if(v[i] > best){
            best = v[i];
            best_ind = i;
        }
    }
 
    ll sum = 0;
    forn(i, 0, n){
        sum += v[i];
        if(i == best_ind){
            cout << 0 << " ";
            continue;
        }
        if(sum >= best) cout << i << " ";
        else cout << i+1 << " ";
    }
    cout << ln;
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}