#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

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
const ll MAX = 1'000'005;

void print(ll n){
    ll x = n/100;
    if(x < 10) cout << 0 << x << '.';
    else cout << x << '.';
    ll y = n%100;
    if(y < 10) cout << 0 << y;
    else cout << y;   
}

int main() {
    _;
    ll n; cin >> n;
    vll compras(MAX);
    vll vendas(MAX);
    
    ll numcom = 0;
    ll numven = 0;
    forn(i,0,n){
        string s; cin >> s;
        string ss; 
        forn(j,0,sz(s)) if(s[j] != '.') ss.push_back(s[j]);
        ll x = stoi(ss);
        ll c, v; cin >> c >> v;
        compras[x] = c;
        numcom += c;
        vendas[x] = v;
    }

    ll best = 0;
    ll bval = 0;
    forn(x,0,MAX){
        numven += vendas[x];
        // trace(cout << x << " " << numven << " " << numcom << ln);
        if(min(numven, numcom)*x >= best){
            best = x*min(numven, numcom);
            bval = x;
        }
        numcom -= compras[x];
    }
    if(best == 0){
        cout << "impossible" << ln;
        return 0;
    }
    
    print(bval);
    cout << " ";
    print(best);
    cout << ln;
    return 0;
}
