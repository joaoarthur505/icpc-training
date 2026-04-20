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

// Hungarian algorithm — min-cost perfect matching
// a[i][j] = cost of assigning worker i to job j (n workers, m >= n jobs)
// Returns {min cost, assignment}: assignment[i] = j
pair<ll, v64> hungarian(const vector<v64> &a) {
	if (a.empty()) return {0, {}};
	ll n = sz(a) + 1, m = sz(a[0]) + 1;
	v64 u(n), v(m), p(m), ans(n - 1);
	forn(i, 1, n) {
		p[0] = i;
		ll j0 = 0; // "dummy" worker 0
		v64 dist(m, INF), pre(m, -1);
		vector<bool> done(m + 1);
		do { // dijkstra
			done[j0] = true;
			ll i0 = p[j0], j1 = 0, delta = INF;
			forn(j, 1, m) if (!done[j]) {
				auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
				if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
				if (dist[j] < delta) delta = dist[j], j1 = j;
			}
			forn(j, 0, m) {
				if (done[j]) u[p[j]] += delta, v[j] -= delta;
				else dist[j] -= delta;
			}
			j0 = j1;
		} while (p[j0]);
		while (j0) { // update alternating path
			ll j1 = pre[j0];
			p[j0] = p[j1], j0 = j1;
		}
	}
	forn(j, 1, m) if (p[j]) ans[p[j] - 1] = j - 1;
	return {-v[0], ans}; // min cost
}

int main() {
    _; ll n; cin >> n;
    vector<v64> a(n, v64(n));

    forn(i, 0, n)
    forn(j, 0, n){
        cin >> a[i][j];
    }

    auto [cost, match] = hungarian(a);

    cout << cost << ln;
    forn(i, 0, n) cout << i+1 << " " << match[i]+1 << ln;
    return 0;
}
