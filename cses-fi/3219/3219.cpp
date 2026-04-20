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

int main() {
    _; ll n, k; cin >> n >> k;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    set<ll> candidates;
    forn(i, 0, k+1) candidates.insert(i);

    map<ll,ll> freq;

    forn(i, 0, k-1){
        freq[v[i]]++;
        candidates.erase(v[i]);
    }

    forn(i, k-1, n){
        freq[v[i]]++;
        candidates.erase(v[i]);

        cout << *candidates.begin() << " ";

        freq[v[i-(k-1)]]--;
        if(freq[v[i-(k-1)]] == 0) candidates.insert(v[i-(k-1)]);
    }

    cout << ln;

    return 0;
}
