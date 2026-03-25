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

v64 get_z(string s) {
	ll n = sz(s);
	v64 z(n, 0);

	ll l = 0, r = 0;
	forn(i, 1, n){
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}

	return z;
}

int main() {
    _; string s; cin >> s;
    ll n = sz(s);
    v64 z = get_z(s);
    debugv(z);
    set<ll> targ;
    v64 freq(n+1,0);
    for(ll i = n-1; i>=0; i--){
        freq[z[i]]++;
        if(z[i] + i == n) targ.insert(z[i]);
    }

    v64 freq_acc(n+1,0);
    freq_acc[n] = 1;
    for(ll i = n-1; i>=0; i--) freq_acc[i] = freq[i] + freq_acc[i+1];

    cout << sz(targ) << ln;
    for(auto a : targ) cout << a << " " << freq_acc[a] << ln;
    
    return 0;
}
