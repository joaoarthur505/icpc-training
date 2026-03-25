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

// Segment Tree (Range Query + Point Update)
//
//supports point updates and range queries.
//
// complexity: O(log N) per op, O(N)

struct node {
    ll val = 0;
    
    node() {}
    node(ll _val) : val(_val) {}
    static node comb(const node& a, const node& b) {
        return {a.val + b.val};
    }
};

template<typename T> struct segtree {
  ll n;
  T neutral;
  vector<T> tree;

  segtree(ll _n, T _neutral = T()) {
    n = _n, neutral = _neutral;
    tree.resize(2*n+1, neutral);
  }

  void set_leaves(vector<T> &leaves) {
    copy(leaves.begin(), leaves.end(), tree.begin() + n);

    for (ll i = n - 1; i > 0; i--) tree[i] = T::comb(tree[2 * i], tree[2 * i + 1]);
  }

  void update(ll i, T v) {
    i += n;
    tree[i] = v;
    while (i > 1) {
      i /= 2;
      tree[i] = T::comb(tree[2 * i], tree[2 * i + 1]);
    }
  }

  T query(ll i, ll j) {
    T rl = neutral, rr = neutral;
    for(i += n, j += n; i <= j; i /= 2, j /= 2){
      if((i&1) == 1) rl = T::comb(rl, tree[i++]);
      if((j&1) == 0) rr = T::comb(tree[j--], rr);
    }
    return T::comb(rl, rr);
  }
};

struct event{
    vector<ll> add;
    vector<p64> query; // query[i] = {idx, +-1}; 
};

int main() {
    _; ll n, q; cin >> n >> q;
    v64 v(n), compr;
    forn(i, 0, n){
        cin >> v[i];
        compr.push_back(v[i]);
        // sweep[a].add.push_back(i);
    }
    
    v64 resp(q);
    vector<p64> range(q);
    vector<p64> vrange(q);
    
    forn(i, 0, q){
        ll a, b, c, d; cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        range[i] = {a,b};
        vrange[i] = {c,d};
        compr.push_back(c);
        compr.push_back(d);
        // sweep[d].query.push_back({i, 1});
        // sweep[c].query.push_back({i, -1});
    }
    
    sort(compr.begin(), compr.end());
    compr.erase(unique(compr.begin(), compr.end()), compr.end());

    function<ll (ll)> trad = [&](ll x){
        return lower_bound(compr.begin(), compr.end(), x) - compr.begin();
    };

    vector<event> sweep(n+2*q + 10);
    forn(i, 0, n) sweep[trad(v[i])].add.push_back(i);
    forn(i, 0, q){
        auto [c, d] = vrange[i];
        sweep[trad(d)].query.push_back({i, 1});
        sweep[trad(c)].query.push_back({i, -1});
    }

    segtree<node> seg(n);
    
    for(auto ev : sweep){
        for(auto i : ev.add) seg.update(i, 1);
        for(auto [idx, mult] : ev.query){
            auto [a,b] = range[idx];
            auto qu = seg.query(a,b);
            resp[idx] += (qu.val)*mult;
        }
    }

    forn(i, 0, q) cout << resp[i] << ln;

    return 0;
}
