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
    v64 even, odd, best(2, 0);
    forn(i, 0, n){
        ll a; cin >> a;
        if(a%2 == 0) even.push_back(a);
        if(a%2 == 1) odd.push_back(a);
    }
    sort(even.rbegin(), even.rend());
    sort(odd.rbegin(), odd.rend());

    if(sz(odd) == 0){
        forn(i, 0, n) cout << 0 << " \n"[i == n-1];
        return;
    }

    best[1] += odd[0];
    cout << best[1] << " ";

    ll idx = 0;
    bool zero = false;
    forn(i, 0, n-1){
        if(idx < sz(even)){
            best[1] += even[idx];
            idx++;
            cout << best[1] << " \n"[i == n-2];
            continue;
        }
        if(idx == sz(even) && sz(even)>0){
            best[0] = best[1] - even[sz(even)-1];
            idx++;
        }
        if(i == n-2 && sz(odd)%2 == 0){
            cout << 0 << ln;
            continue;
        }
        cout << best[zero] << " \n"[i == n-2];
        zero = !zero;
    }
}

int main(){
    _; 
    ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}