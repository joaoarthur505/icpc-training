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

ll ask(ll st, set<ll> &vert){
    cout << '? ' << st << " " << sz(vert) << " ";
    for(auto v : vert) cout << v << " ";
    cout << endl;

    ll resp; cin >> resp;
    return resp;
}

void solve(){
    ll n; cin >> n;

    set<ll> vert;
    forn(i, 0, n) vert.insert(i+1);
    
    ll best = 0;
    ll best_start;
    forn(i, 0, n){
        ll curr = ask(i+1, vert);
        if(curr > best){
            best = curr;
            best_start = i;
        }
    }
}

int main() {
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}
