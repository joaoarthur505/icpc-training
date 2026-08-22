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
// #else#define trace (u)
// #define _ ios::sync_with_stdio
// #endif

// #define debug(u) (trace)

int main(){
    ll n, a, b; cin >> n >> a >> b;
    if(a+b > n+1 || a+b==2){
        cout << "no" << ln;
        return 0;
    }   

    vll vec(n);

    if(b == 1){
        vec[n-1] = n;
        vec[a-2] = n-1;
        forn(i,0,a-2) vec[i] = i+1;
        forn(i,a-1,n-1) vec[i] = i;
        cout << "yes" << ln;
        forn(i,0,n) cout << vec[i] << " \n"[i==n-1];
        return 0;
    }

    forn(i,1,a) vec[i-1] = i;
    vec[a-1] = n;

    forn(i,n-b+1, n) vec[i] = 2*n-b-i;
    
    forn(i,a,n-b+1) vec[i] = i;

    cout << "yes" << ln;
    forn(i,0,n) cout << vec[i] << " \n"[i==n-1];
}