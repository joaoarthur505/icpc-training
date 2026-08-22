#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define forn(i,s,e) for(ll i=s;i<e;i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

// #ifdef DEBUG
// #define trace (u)
// #define _
// #else #define trace (u)
// #define _ ios::sync_with_stdio
// #endif

// #define debug(u) (trace)

int main(){
    ll n; cin >> n;
    ll resp = 0;
    resp = max(resp, min(n-6*60, 30ll));
    resp = max(resp, min(n-9*60, 45ll));
    resp = max(resp, n-10*60);
    cout << resp << ln;
}