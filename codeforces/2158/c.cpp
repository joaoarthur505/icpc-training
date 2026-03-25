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
    ll n, k; cin >> n >> k;
    v64 perm(n);
    ll up = 1, down = n;
    forn(i, 0, k){
        for(ll j = i; j < n; j+=k){
            if(i%2 == 0){
                perm[j] = up;
                up++;
            }
            else{
                perm[j] = down;
                down--;
            }
        }
    }

    forn(i, 0, n) cout << perm[i] << " \n"[i==n-1];
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}