#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define forn(i,s,e) for(ll i=s;i<e;i++)
#define sz(u) ((ll) u.size())

#ifdef DEBUG
#define trace(u)
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

int main(){
    _;
    ll n, k; cin >> n >> k;
    vll l(n), r(n);
    forn(i,0,n) cin >> l[i];
    forn(i,0,n) cin >> r[i];
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    ll tot = 0;
    forn(i,0,n){
        if(tot + l[i] + r[i] > k){
            cout << i << "\n";
            return 0;
        }
        tot += l[i] + r[i];
    }
    cout << n << "\n";
    return 0;
}


