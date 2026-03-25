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

// Sparse Table (Idempotent Range Query)
//
// Preprocesses static array to answer idempotent range queries (e.g., min/max) in O(1) after O(N log N) build.
//
// complexity: O(N log N) build, O(1) query; O(N log N) space

struct sparse {
    vector<vector<p64>> m;
    
    p64 comb(p64 p, p64 q){
        if(p.first != q.first){
            if(p.first > q.first) return p;
            return q;
        }
        if(p.second < q.second) return p;
        return q;
    }

    sparse(v64& v) {
        ll n = sz(v);
        ll logn = 64 - __builtin_clzll(n - 1);
        m.resize(n+1, vector<p64>(logn+1));

        forn(i, 0, n) m[i][0] = {v[i], i};

        for (ll j = 1; (1 << j) <= n; j++)
        for (ll i = 0; i + (1 << j) <= n; i++)
            // m[i][j] = min(m[i][j-1], m[i + (1 << (j-1))][j-1]);    
            m[i][j] = comb(m[i][j-1], m[i + (1 << (j-1))][j-1]);    
    }
    
    p64 query(ll a, ll b) { 
        ll j = __builtin_clzll(1) - __builtin_clzll(b - a + 1);
        return comb(m[a][j], m[b - (1 << j) + 1][j]);
    }
};

int main() {
    _; ll n, q; cin >> n >> q;
    v64 v(n+1);
    forn(i, 1, n+1) cin >> v[i];

    sparse table(v);

    v64 last_big(n+1), obfuscate(n+1);
    forn(i, 1, n+1){
        ll at = i-1;
        while(at > 0 && v[at] < v[i]) at = last_big[at];
        last_big[i] = at;
        obfuscate[at]++;
    }

    v64 acc_back(n+1);
    acc_back[n] = obfuscate[n];
    for(ll i = n-1; i>=0; i--){
        acc_back[i] = obfuscate[i] + acc_back[i+1];
    }

    trace(
        forn(i, 0, n) cout << obfuscate[i] << " \n"[i==n-1]; 
        forn(i, 0, n) cout << acc_back[i] << " \n"[i==n-1]; 
    );

    forn(i, 0, q){
        ll a, b; cin >> a >> b;
        auto [m, idx] = table.query(a,b);
        b = idx;

        cout << (b-a+1) + acc_back[b] - acc_back[a] << ln;
    }
    return 0;
}
