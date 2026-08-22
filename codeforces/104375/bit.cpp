#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define forn(i,s,e) for(ll i = (s); i<(e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

# ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u << " = " <<  u << ln)
#define debugv(v) trace(cout << #v << ": "; for(auto xx : v) cout << xx << " "; cout << ln;)

const ll INF = 0x3f3f3f3f3f3f3f3fll;


struct Bit {
    ll n; 
    vll bit;
    Bit(ll _n = 0) : n(_n), bit(n+1) {};

    void update(ll i, ll x){
        for(i++; i <= n; i += i & -i) bit[i] += x;
    }

    ll pref(ll i){
        ll ret = 0;
        for(i++; i; i -= i&-i) ret += bit[i];
        return ret;
    }
    ll query(ll l, ll r){
        return pref(r) - pref(l-1);
    }
};

int main(){
    _;
    return 0;
}