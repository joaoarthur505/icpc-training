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
const ll MAX = (2*1e5)+10, UPD = (2*1e5)+10, LOG = 19;
const ll MAXS = 2*MAX+UPD*LOG;

namespace perseg {
	ll seg[MAXS];
	ll rt[UPD], L[MAXS], R[MAXS], cnt, t;
	ll n, *v;

	ll build(ll p, ll l, ll r) {
		if (l == r) return seg[p] = v[l];
		L[p] = cnt++, R[p] = cnt++;
		ll m = (l+r)/2;
		return seg[p] = build(L[p], l, m) + build(R[p], m+1, r);
	}
	void build(ll n2, ll* v2) {
		n = n2, v = v2;
		rt[0] = cnt++;
		build(0, 0, n-1);
	}
	ll query(ll a, ll b, ll p, ll l, ll r) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		ll m = (l+r)/2;
		return query(a, b, L[p], l, m) + query(a, b, R[p], m+1, r);
	}
	ll query(ll a, ll b, ll tt) {
		return query(a, b, rt[tt], 0, n-1);
	}
	ll update(ll a, ll x, ll lp, ll p, ll l, ll r) {
		if (l == r) return seg[p] = seg[lp]+x;
		ll m = (l+r)/2;
		if (a <= m)
			return seg[p] = update(a, x, L[lp], L[p]=cnt++, l, m) + seg[R[p]=R[lp]];
		return seg[p] = seg[L[p]=L[lp]] + update(a, x, R[lp], R[p]=cnt++, m+1, r);
	}
	ll update(ll a, ll x, ll tt=t) {
		update(a, x, rt[tt], rt[++t]=cnt++, 0, n-1);
		return t;
	}
};

int main() {
    _; ll n, q; cin >> n >> q;
	vector<p64> v(n);
	vector<p64> time_to_jump;
	ll zero[n];

	forn(i, 0, n){
		ll a; cin >> a;
		v[i] = {a, i};
		zero[i] = 0;
	}

	sort(v.begin(), v.end());

	perseg::build(n, zero);

	ll last = 0;
	ll time = 0;
	forn(j, 0, n){
		auto [val, idx] = v[j];
		if(val != last) time_to_jump.push_back({last, time});
		time = perseg::update(idx, val, time);
		last = val;
	}
	time_to_jump.push_back({last, time});


	function<ll (ll, ll, ll)> sum_leq = [&](ll a, ll b, ll x){
		auto it = upper_bound(time_to_jump.begin(), time_to_jump.end(), p64(x, INF));
		it = prev(it);

		ll resp = perseg::query(a, b, it->second);
		return resp;
	};

	forn(i, 0, q){
		ll a, b; cin >> a >> b;
		a--;
		b--;
 
		ll reach = 0;
		ll nreach = sum_leq(a, b, reach+1);
		while(reach < nreach){
			debug(reach);
			reach = nreach;
			nreach = sum_leq(a, b, reach+1);
		}
		debug(reach);

		cout << reach + 1 << ln;
	}

    return 0;
}
