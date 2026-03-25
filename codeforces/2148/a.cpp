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

v64 topo_sort(vector<v64>& g) {
	v64 indeg(g.size()), q;
	for (auto& li : g) for (int x : li) indeg[x]++;
	forn(i, 0, g.size()) if (indeg[i] == 0) q.push_back(i);
	forn(j, 0, q.size()) for(int x : g[q[j]]) if(--indeg[x] == 0) q.push_back(x);
	return q;
}

void solve(){
    ll n, k; cin >> n >> k;
    vector<v64> g(n);
    forn(i,0,k){
        ll a, last; cin >> a;
        forn(j, 0, n-1){
            cin >> a;
            if(j > 0){
                g[last-1].push_back(a-1);
            }
            last = a;
        }
    }

    v64 q = topo_sort(g);

    if(q.size() == n){
        cout << "YES" << ln;
    }
    else{
        cout << "NO" << ln;
    }
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}