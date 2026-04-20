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

    map<ll,ll> freq;
    set<p64> mode;

    forn(i, 0, k-1) freq[v[i]]++;
    for(auto [val, f] : freq) mode.insert({f, -val});

    forn(i, k-1, n){
        mode.erase({freq[v[i]], -v[i]});
        freq[v[i]]++;
        mode.insert({freq[v[i]], -v[i]});

        auto it = mode.rbegin();
        cout << -(it->second) << " ";

        mode.erase({freq[v[i - (k-1)]], -v[i - (k-1)]});
        freq[v[i - (k-1)]]--;
        mode.insert({freq[v[i - (k-1)]], -v[i - (k-1)]});
    }

    cout << ln;
    return 0;
}
