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

v64 suffix_array(string s) {
	s += "$";
	ll n = s.size(), N = max(n, 260ll);
	v64 sa(n), ra(n);
	forn(i, 0, n) sa[i] = i, ra[i] = s[i];

	for(ll k = 0; k < n; k ? k *= 2 : k++) {
		v64 nsa(sa), nra(n), cnt(N);

		forn(i, 0, n) nsa[i] = (nsa[i]-k+n)%n, cnt[ra[i]]++;
		forn(i, 1, N) cnt[i] += cnt[i-1];
		for(ll i = n-1; i+1; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];

		for(ll i = 1, r = 0; i < n; i++) nra[sa[i]] = r += ((ra[sa[i]] != ra[sa[i-1]]) || (ra[(sa[i]+k)%n] != ra[(sa[i-1]+k)%n]));
		ra = nra;
		if (ra[sa[n-1]] == n-1) break;
	}
	return v64(sa.begin()+1, sa.end());
}

int main() {
    _;
    string s; cin >> s;
    ll n = sz(s);
    s = s+s;
    v64 sa = suffix_array(s);
    debugv(sa);

    ll ini;
    forn(i, 0, 2*n)
    if(sa[i]<n){
        ini = sa[i];
        break;
    }

    debug(ini);

    forn(i, 0, n) cout << s[i+ini];
    cout << ln;
    return 0;
}
