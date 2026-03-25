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

map<string,vector<string>> conv = {
    {"12", {"12", "21"}}, 
    {"123", {"123", "132", "213", "231", "312", "321"}}, 
    {"1234", {"1234", "1243", "1324", "1342", "1423", "1432", "2134", "2143", "2314", "2341", "2413", "2431", "3124", "3142", "3214", "3241", "3412", "3421", "4123", "4132", "4213", "4231", "4312", "4321"}}
};


void solve(){
    string s; cin >> s;
    ll n = sz(s);
    ll a, b; cin >> a >> b;
    a--;
    b--;

    string x = conv[s][a], y = conv[s][b];
    ll counter_A = 0, counter_B = 0;
    
    forn(i, 0, n){
        if(x[i] == y[i]) counter_A++;
    }

    counter_B = n - counter_A;

    cout << counter_A << "A" << counter_B << "B" << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i,0,t) {
        solve();
    }
    return 0;
}
