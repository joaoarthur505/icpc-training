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

void print(ll n){
    if(n < 10){
        cout << 0 << n;
        return;
    }
    cout << n;
}

int main() {
    _;
    string fim; cin >> fim;
    string ini; cin >> ini;
    ll hi = stoi(ini.substr(0,2));
    ll hf = stoi(fim.substr(0,2));
    ll mi = stoi(ini.substr(3,5));
    ll mf = stoi(fim.substr(3,5));
    // cout << hi << " " << mi << ln;
    if(mi > mf){
        mf += 60;
        hf -= 1;
    }
    print(hf - hi); 
    cout << ":";
    print(mf-mi);
    cout << ln;
    return 0;
}
