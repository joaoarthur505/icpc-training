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
    
    node() {};
    node(ll _val) : val(_val) {};

    static node comb(const node& a, const node& b) {
        return max(a.val, b.val);
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

  void print(){
    forn(i, 0, n) cout << tree[i+n].val << " \n"[i == n-1];
  }
};

struct Query{
    ll type, a, b;
    Query(ll _type, ll _a, ll _b) : type(_type), a(_a), b(_b) {}
};

int main() {
    _; ll n, q; cin >> n >> q;
    v64 v(n);
    v64 comp;
    forn(i, 0, n){
        cin >> v[i];
        comp.push_back(v[i]);
    }

    vector<Query> query;
    forn(i, 0, q){
        ll t, a, b; cin >> t >> a >> b;
        query.emplace_back(t, a, b);
        if(t == 1) comp.push_back(b);
    }

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    function<ll (ll)> trad = [&](ll x){ return lower_bound(comp.begin(), comp.end(), x) - comp.begin(); };
    
    forn(i, 0, n) v[i] = trad(v[i]);
    forn(i, 0, q) if(query[i].type == 1) query[i].b = trad(query[i].b);

    vector<set<ll>> fake_map(sz(comp));
    forn(i, 0, sz(comp)) fake_map[i].insert(-1);
    vector<node> last_eq(n);

    forn(i, 0, n){
        last_eq[i] = *fake_map[v[i]].rbegin();
        fake_map[v[i]].insert(i);
    }

    segtree<node> seg(n);
    seg.set_leaves(last_eq);

    trace( seg.print(); );

    forn(i, 0, q){
        auto [type, a, b] = query[i];
        if(type == 1){
            a--;
            auto it = fake_map[v[a]].lower_bound(a);
            if(next(it) != fake_map[v[a]].end()){
                seg.update(*next(it), *prev(it));
            }
            fake_map[v[a]].erase(a);

            v[a] = b;

            fake_map[v[a]].insert(a);
            auto it2 = fake_map[b].lower_bound(a);
            seg.update(a, *prev(it2));

            if(next(it2) != fake_map[v[a]].end()){
                seg.update(*next(it2), a);
            }
            

           trace( seg.print(); );
        } else {
            a--;
            b--;
            auto qu = seg.query(a, b);
            if(qu.val < a) cout << "YES" << ln;
            else cout << "NO" << ln;
        }
    }

    return 0;
}
