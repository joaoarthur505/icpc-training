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
#else#define trace (u)
#define _ ios::sync_with_stdio
#endif

// #define debug(u) (trace)

string convert(ll n){
    string s;
    s.push_back('a');
    s.push_back('A');
    s.push_back('4');
    s.push_back('?');
    forn(i, 0, 4){
        ll d = n%93;
        s.push_back((char)(33+d));
        s.push_back((char)(33+d));
        n/=93;
    }

    return s;
}

int main() {
    ll n; cin >> n;
    forn(i, 0, n){
        cout << convert(i) << ln;
    }
}