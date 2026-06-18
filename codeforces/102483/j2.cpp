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
    _; 
    ll n; cin >> n;
    map<ll,ll> freq;

    ll especial; cin >> especial;
    forn(i, 0, n-1){
        ll a; cin >> a;
        freq[a]++;
    }
    freq[-INF] = 1;

    
    ll resp = 0;
    while (true){
        auto lit = prev(freq.end());
        if(lit->second == 0){
            freq.erase(lit);
            continue;
        }
        auto [k,v] = *prev(freq.end());
        if(k > especial) break;

        ll x = (v+1)/2;
        freq[k] -= x;
        freq[k-1] += x;
        especial--;
        resp++;
    }

    cout << resp-1 << ln;
    return 0;
}
