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

struct node {
    ll val = -INF;
    ll idx;
    
    node(){}
    node(ll _val, ll i) : val(_val) , idx(i) {}

    bool operator < (const node p) const {
        if (val != p.val) return val < p.val;
        return idx < p.idx;
    }

    static node comb(const node& a, const node& b) {
        return max(a,b);
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

p64 dnc(ll h, ll l, ll r, segtree<node> &seg){
    if(l == r){ 
        auto q = seg.query(l,r);
        if(q.val < h) return{-1,-1};
        return{q.idx, q.val};
    }

    ll m = (l+r)/2;
    auto q1 = seg.query(l, m);
    if(q1.val >= h) return dnc(h, l, m, seg);

    auto q2 = seg.query(m+1, r);
    if(q2.val >= h) return dnc(h, m+1, r, seg);

    return {-1, -1};
}

int main() {
    _; ll n, m; cin >> n >> m;
    vector<node> v(n);
    forn(i, 0, n){
        ll a; cin >> a;
        v[i] = node(a, i+1);
    }

    segtree<node> seg(n);
    seg.set_leaves(v);

    forn(i, 0, m){
        ll h; cin >> h;
        auto [idx, val] = dnc(h, 0, n-1, seg); 

        if(idx == -1){
            cout << 0 << " \n"[i == m-1];
            continue;
        }

        cout << idx << " \n"[i == m-1];
        seg.update(idx-1, node(val-h,idx));
    }
    return 0;
}
