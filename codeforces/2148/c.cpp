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
    if(n == 1){
        cout << 0 << ln;
        cout << 1 << ln;
        return;
    }
    if(n == 2){
        cout << 2 << ln;
        cout << 1 << " " << 2 << ln;
        return;
    }
    if(n == 3){
        cout << 2 << ln;
        cout << 1 << " " << 2 << " " << 3 << ln;
        return;
    }
    if(n == 4){
        cout << 6 << ln;
        cout << 1 << " " << 2 << " " << 3 << " " << 4 << ln;
        return;
    }

    if(n%2 == 1){
        set<ll> s;
        forn(i, 2, n-1){
            if(i == 3) continue;
            s.insert(i);
        }
        cout << n << ln;
        for(auto x : s) cout << x << " ";
        cout << 3 << " " << 1 << " " << n-1 << " " << n << ln;
        return;
    }
    
    ll pot = 1;
    while(2*pot <= n) pot *= 2;

    if(pot != n){
        set<ll> s;
        forn(i, 1, n){
            if(i == pot || i == pot-1) continue;
            s.insert(i);
        }
        cout << 2*pot-1 << ln;
        for(auto x : s) cout << x << " ";
        cout << pot << " " << n << " " << pot-1 << ln;
        return;
    }

    set<ll> s;
    forn(i, 2, n-2){
        if(i == 3) continue;
        s.insert(i);
    }
    cout << 2*pot-1 << ln;
    for(auto x : s) cout << x << " ";
    cout << 3 << " " << 1 << " " << n-2 << " " << n-1 << " " << n << ln;
    return;
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}