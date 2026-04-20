#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

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

bool solve_aux(vector<ll> &v, ll mask){
    ll angle = 0;
    forn(i,0,sz(v)){
        if(mask & (1ll << i)){
            angle += v[i];
        }
        else{
            angle -= v[i];
        }
    }
    return !(angle % 360);
}

int main() {
    _;
    ll n;
    cin >> n;
    vector<ll> v(n);
    forn(i,0,n){
        cin >> v[i];
    }
    forn(i, 0, 1ll << n){
        if(solve_aux(v,i)){
            cout << "YES\n";
            return 0;
        }
    }
    
    cout << "NO\n";
    return 0;
}
