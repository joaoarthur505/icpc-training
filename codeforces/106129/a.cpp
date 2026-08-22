#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define forn(i,s,e) for(ll i=s;i<e;i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace (u)
#define _
#else
#define trace (u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for(auto xx : v) cout << v << " "; cout << ln)
#define debugm(v) trace(cout << #v ": "; for(auto xx : v) cout << xx.first << ":" << xx.second << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    _; ll l, r; cin >> l >> r;
    ll n = l+r;
    ll k = n-r+1;

    if(2*(k-1) == n) cout << 2*n - n/2 << ln;
    else if(2*(k-2) == n) cout << 2*n - n/2 << ln;
    else if(2*(k) - 3 == n) cout << n << ln;
    else cout << 2*n << ln;
    
    return 0;
}