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

struct Node {
    ll sum, cnt, l;
    Node () {};
    Node (ll val, ll _l) : sum(val), cnt(1), l(_l) {}
    Node (ll _sum, ll _cnt, ll _l) : sum(_sum), cnt(_cnt), l(_l) {}
    Node operator*(const Node &o) const { return {sum + o.sum, cnt + o.cnt, min(l, o.l)}; }
};

struct Update {
    ll ini = 0;
    ll razao = 0;
    optional<ll> set;

    Node operator()(const Node &n) const {
        ll res = set.has_value() ? *set * n.cnt : n.sum;
        debug(n.l);
        debug(n.cnt);
        debug(ini);
        debug(razao);
        debug((ini+razao*n.l)*n.cnt + (razao*n.cnt*(n.cnt-1)/2));
        return {res + (ini+razao*n.l)*n.cnt + (razao*n.cnt*(n.cnt-1)/2), n.cnt, n.l};
    }

    Update operator+(const Update &o) const {
        Update res = *this;
        if (o.set.has_value()) {
            res.set = o.set;
            res.ini = 0;
            res.razao = 0;
        }
        if (o.razao != 0) {
            res.ini += o.ini;
            res.razao += o.razao;
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
    vector<Node> lvs(n);
 
    forn(i, 0, n){
        ll a; cin >> a;
        lvs[i] = Node(a, i);
    }
 
    segtree<Node, Update> seg(n);
    seg.set_leaves(lvs);
 
    forn(i, 0, q){
        ll c; cin >> c;
 
        if(c == 1){
            ll a, b; cin >> a >> b;
            a--;
            b--;
 
            Update upd;
            upd.ini = 1 - a;
            upd.razao = 1;
 
            seg.update(a, b, upd);
        } 
        if(c == 2){
            ll a, b; cin >> a >> b;
            a--;
            b--;
 
            auto qu = seg.query(a, b);
            cout << qu.sum << ln;
        }
    }
 
    return 0;
}