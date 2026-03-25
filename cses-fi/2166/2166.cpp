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

// Segment Tree (Range Query + Range Update)
//
// Tree for range queries with a customizable combine; supports range updates and range queries.
//
// complexity: O(log N) per op, O(N) to build

struct Node {
    ll sum = -INF, cnt = 1;

    Node(){}
    Node(ll _sum) : sum(_sum) {}
    Node(ll _sum, ll _cnt) : sum(_sum), cnt(_cnt) {}

    Node operator*(const Node &o) const { return {max(sum, o.sum), cnt + o.cnt}; }
};

struct Update {
    ll add = 0;
    optional<ll> set;

    Node operator()(const Node &n) const {
        ll res = set.has_value() ? *set * n.cnt : n.sum;
        // return {res + add * n.cnt, n.cnt};
        return {res + add, n.cnt};
    }

    Update operator+(const Update &o) const {
        Update res = *this;
        if (o.set.has_value()) {
            res.set = o.set;
            res.add = 0;
        }
        if (o.add != 0) {
            if (res.set.has_value()) *res.set += o.add;
            else res.add += o.add;
        }
        return res;
    }
};

template<typename T, typename U> struct segtree {
  ll s, h;

  T id;
  vector<T> val;

  U noop;
  vector<bool> dirty;
  vector<U> prop;

  segtree(ll ts, T tid = T(), U tnoop = U()) {
    id = tid, noop = tnoop;
    for (s = 1, h = 1; s < ts; ) s *= 2, h++;

    val.assign(2*s, id);
    dirty.assign(2*s, false);
    prop.assign(2*s, noop);
  }

  void set_leaves(vector<T> &lvs) {
    copy(lvs.begin(), lvs.end(), val.begin() + s);

    for (ll i = s - 1; i > 0; i--) val[i] = val[2 * i] * val[2 * i + 1];
    dirty.assign(2*s, false);
    prop.assign(2*s, noop);
  }

  void apply(ll i, U &upd) {
    val[i] = upd(val[i]);
    if(i < s) {
      prop[i] = prop[i] + upd;
      dirty[i] = true;
    }
  }

  void pull(ll i) {
    for (ll l = i/2; l; l /= 2) {
      T comb = val[2*l] * val[2*l+1];
      val[l] = prop[l](comb);
    }
  }

  void push(ll i) {
    for (ll th = h; th > 0; th--) {
      ll l = i >> th;

      if (dirty[l]) {
        apply(2*l, prop[l]);
        apply(2*l+1, prop[l]);

        prop[l] = noop;
        dirty[l] = false;
      }
    }
  }

  void update(ll i, ll j, U upd) {
    i += s, j += s;
    push(i), push(j);

    for (ll l = i, r = j; l <= r; l /= 2, r /= 2) {
      if((l&1) == 1) apply(l++, upd);
      if((r&1) == 0) apply(r--, upd);
    }

    pull(i), pull(j);
  }

  T query(ll i, ll j){
    i += s, j += s;
    push(i), push(j);

    T rl = id, rr = id;
    for(; i <= j; i /= 2, j /= 2){
      if((i&1) == 1) rl = rl * val[i++];
      if((j&1) == 0) rr = val[j--] * rr;
    }
    return rl * rr;
  }
};

int main() {
    _; ll n, q; cin >> n >> q;
    v64 v(n);
    vector<Node> acc(n+1);

    acc[0] = Node(0);
    forn(i, 0, n){
        cin >> v[i];
        acc[i+1] = v[i] + acc[i].sum;
    }

    segtree<Node, Update> seg(n+1);
    seg.set_leaves(acc);

    forn(i, 0, q){
        ll c; cin >> c;
        if(c == 2){
            ll a, b; cin >> a >> b;
            auto qu = seg.query(a-1,b), qu2 = seg.query(a-1,a-1);
            debug(qu.sum);
            debug(qu2.sum);
            cout<< qu.sum - qu2.sum << ln;
            continue;
        } 

        ll k, u; cin >> k >> u;

        ll delta = u - v[k-1];
        debug(delta);
        Update upd;
        upd.add = delta;
        seg.update(k, n, upd);
        debug(seg.query(k,k).sum);
        v[k-1] = u;
    }

    return 0;
}
