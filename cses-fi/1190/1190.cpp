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
    ll l = INF;
    ll sum = 0;
    ll vall = -INF;
    ll valr = -INF;
    ll valt = -INF;
    
    node() {};
    node(ll val, ll idx){
        l = idx;
        sum = val;
        valt = vall = valr = max(0ll, val);
    }

    static node comb_ord(const node& a, const node& b) {
        node n;
        n.l = a.l;
        n.sum = a.sum + b.sum;
        n.vall = max(a.vall, a.sum+b.vall);
        n.valr = max(a.valr + b.sum, b.valr);
        n.valt = max(a.valr + b.vall, max(a.valt, b.valt));

        // debug(a.l);

        return n;
    }

    static node comb(const node& a, const node& b) {
        if(a.l < b.l) return comb_ord(a,b);
        return comb_ord(b,a);
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

int main() {
    _; ll n, q; cin >> n >> q;

    vector<node> v;
    forn(i, 0, n){
        ll a; cin >> a;
        // auto x = node(a,i);
        // debug(x.l);
        v.push_back(node(a, i));
    }

    segtree<node> seg(n);
    seg.set_leaves(v);

    trace(
        forn(i, 0, n)
        forn(j, i, n){
            auto qu = seg.query(i, j);
            debug(i);
            debug(j);
            debug(qu.valt);
            debug(qu.vall);
            debug(qu.valr);
            debug(qu.sum);
            debug(qu.l);
        }
    );

    forn(qq, 0, q){
        ll i, x; cin >> i >> x;
        i--;
        seg.update(i, node(x,i));

        auto qu = seg.query(0, n-1);
        cout << qu.valt << ln;
    }

    return 0;
}
