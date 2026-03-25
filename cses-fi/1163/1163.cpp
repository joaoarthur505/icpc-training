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
    _; ll x, n; cin >> x >> n;

    map<ll, ll> freq;
    set<ll> light;
    light.insert(0);
    light.insert(x);
    freq[x]++;
    forn(i, 0, n){
        ll a; cin >> a;
        // auto it = lower_bound(light.begin(), light.end(), a);
        auto it = light.lower_bound(a);
        auto it2 = prev(it);
        ll ant = *it2;
        ll prx = *it;

        freq[prx-ant]--;
        if(freq[prx-ant] == 0) freq.erase(prx-ant);
        freq[prx-a]++;
        freq[a-ant]++;

        light.insert(a);

        trace(
            for(auto p :inter) cout << p.first << ": "<< p.second << " ";
            cout << ln;
        );

        cout << (freq.rbegin()->first) << " \n"[i == n-1];
    }
    return 0;
}
