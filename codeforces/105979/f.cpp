#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define forn(i,s,e) for(ll i=s;i<e;i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u)
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

int main(){
    _;
    ll n; cin >> n;
    vector<pll> vec(n);
    ll best_a = 0;
    ll sx = 0;
    ll sy = 0;

    forn(i,0,n){
        cin >> vec[i].first >> vec[i].second;
        sx += vec[i].first;
        sy += vec[i].second;

        best_a = max(best_a, vec[i].first + vec[i].second);
    }
    
    ll resp = 0;

    resp += max(sx,sy) - min(sx,sy);
    resp += 2*max(best_a - max(sx,sy), 0ll);

    cout << resp << ln;
}


