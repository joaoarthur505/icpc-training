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
    vector<ll> freq(2*n,0);
    forn(i, 0, 2*n){
        ll a; cin >> a; a--;
        freq[a]++;
    }
    ll best = 0, even4 = 0, even = 0, odd = 0;
    forn(i, 0, 2*n){
        if(freq[i] == 0) continue;
        if(freq[i]%4 == 0) even4 ++;
        else if(freq[i]%4 == 2) even ++;
        else odd++;
    }

    best += odd;
    best += 2*even;
    if(even4%2 == 0) best += 2*even4;
    else{
        best += 2*(even4-1);
        if(odd >= 2) best += 2;
    }

    cout << best << ln;
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}