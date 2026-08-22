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

int main() {
    _; string s, resp = ""; cin >> s;
    ll n = sz(s);
    forn(i, 0, n){
        if(s.substr(i, 6) == "mesero"){
            resp.push_back('t');
            resp.push_back('a');
            resp.push_back('q');
            resp.push_back('u');
            resp.push_back('e');
            resp.push_back('r');
            resp.push_back('o');
            i+=5;
            continue;
        }
        else resp.push_back(s[i]);
    }

    cout << resp << ln;
    return 0;
}
