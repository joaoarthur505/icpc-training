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
    _; ll n, x; cin >> n >> x;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    ll sz_low = n/2;
    ll sz_upp = (n+1)/2;

    v64 freq_low;
    v64 upp(1<<sz_upp), low(1<<sz_low);
    upp[0] = 0;
    low[0] = 0;
    freq_low.push_back(0);

    ll bit = 0;
    ll pow = 1;
    forn(mask, 1, 1 << sz_low){
        if(2*pow <= mask){
            pow *=2;
            bit++;
        }
        low[mask] = v[bit] + low[mask^(1<<bit)];
        freq_low.push_back(low[mask]);
    }
    sort(freq_low.begin(), freq_low.end());

    trace(
        for(auto u : freq_low) cout << u << " ";
        cout << ln;
    );


    function<ll (ll)> freq = [&](ll target){
        return upper_bound(freq_low.begin(), freq_low.end(), target) - lower_bound(freq_low.begin(), freq_low.end(), target);
    };

    ll resp = 0;

    resp += freq(x);

    bit = 0;
    pow = 1;
    forn(mask, 1, 1 << sz_upp){
        if(2*pow <= mask){
            pow *=2;
            bit++;
        }
        upp[mask] = v[bit + sz_low] + upp[mask^(1<<bit)];

        debug(upp[mask]);
        debug(freq(x - upp[mask]));
        resp += freq(x - upp[mask]);
    }

    cout << resp << ln;
    return 0;
}
