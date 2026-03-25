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
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << setw(3) << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

v64 get_z(v64 s) {
	ll n = sz(s);
	v64 z(n, 0);

	ll l = 0, r = 0;
	forn(i, 1, n) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}

	return z;
}

v64 convert(string& s){
	ll n = sz(s);
	v64 conv(n+1);

	forn(i, 0, n) conv[i] = (ll)s[i];
	conv[n] = 127;

	return conv;
}

v64 concat(v64& a, v64& b){
	ll n = sz(a), m = sz(b);
	v64 con(n+m);
	forn(i, 0, n) con[i] = a[i];
	forn(i, 0, m) con[i+n] = b[i];

	return con;
}

int main() {
    _;
    string s1, s2, rev_s1;
	getline(cin, s1);
	getline(cin, s2);

	if(sz(s1) != sz(s2)){
		cout << -1 << " " << -1 << ln;
		return 0;
	}

	ll n = sz(s1);

	rev_s1 = s1;
	reverse(rev_s1.begin(), rev_s1.end());

	v64 v1 = convert(s1), v2 = convert(s2), rev_v1 = convert(rev_s1);

	v64 z1 = get_z(concat(v2, v1)), z2 = get_z(concat(rev_v1, v2));

	
	v64 v(n);
	forn(i, 0, n) v[i] = z2[n+1+i] + i;

	v64 first_appear(2*n, INF);
	forn(i, 0, n) if(first_appear[v[i]] == INF) first_appear[v[i]] = i;
	
	v64 acc_min(2*n, INF);
	acc_min[2*n-1] = first_appear[2*n-1];
	for(ll i = 2*n-2; i>=0; i--){
		acc_min[i] = min(acc_min[i+1], first_appear[i]);
	}

	ll best_i = -1, best_j = -1;
	forn(i, 0, n-1){
		debug(i);
		if(s1[i] != s2[n-1-i]) break;
 
		ll target = z1[n+2+i];
		ll val = acc_min[n-i-1];

		if(val <= target){
			best_i = i;
			best_j = val+i+1;
		}
	}

	cout << best_i << " " << best_j << ln;

    return 0;
}
