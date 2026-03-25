#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;


struct dsu {
	v64 id, len;

	dsu(ll n) : id(n), len(n, 1) { iota(id.begin(), id.end(), 0); }

	ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void uni(ll a, ll b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (len[a] < len[b]) swap(a, b);
		len[a] += len[b], id[b] = a;
	}
};

void solve(){
    ll n; cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    if(n==1){
        cout << 0 << ln;
        return;
    }

    dsu sdu(n);
    forn(i, 0, n){
        ll last = -INF;
        ll next = INF;
        if(i != 0) last = v[i-1];
        if(i != (n-1)) next = v[i+1];

        if(v[i] - last <= next - v[i]) sdu.uni(i, i-1);
        if(v[i] - last >= next - v[i]) sdu.uni(i, i+1);
    }

    set<ll> heads;
    forn(i, 0, n) heads.insert(sdu.find(i));

    cout << n - sz(heads) << ln;
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}