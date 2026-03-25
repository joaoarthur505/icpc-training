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
    
    static node comb(const node& a, const node& b) {
        node res;
        res.val = a.val+b.val;
        return res;
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
    tree[i] = T::comb(tree[i], v);
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
 
struct interval{
    ll x, y, idx;
    interval(ll _x, ll _y, ll _idx) : x(_x) , y(_y), idx(_idx) {};
};
 
bool cmp1(interval i1, interval i2){
    if(i1.x != i2.x) return i1.x < i2.x;
    return i1.y > i2.y;
}
 
bool cmp2(interval i1, interval i2){
    if(i1.x != i2.x) return i1.x > i2.x;
    return i1.y < i2.y;
}
 
int main() {
    _; ll n; cin >> n;
    vector<p64> inter_old(n);
    vector<ll> comp;
    forn(i, 0, n){
        cin >> inter_old[i].first >> inter_old[i].second;
        comp.push_back(inter_old[i].first);
        comp.push_back(inter_old[i].second);
    }

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
 
    vector<interval> inter;
    forn(i, 0, n){
        ll x = lower_bound(comp.begin(), comp.end(), inter_old[i].first) - comp.begin();
        ll y = lower_bound(comp.begin(), comp.end(), inter_old[i].second) - comp.begin();
        inter.emplace_back(x, y, i);

    }
    ll cnt = sz(comp);
 
    v64 in_resp(n,0), out_resp(n, 0);
    node neutral, update;
    update.val = 1;
 
    sort(inter.begin(), inter.end(), cmp2);
    // responde in
 
    segtree<node> tree(cnt, neutral);
    for(auto i : inter){
        auto q = tree.query(i.x, i.y);
        in_resp[i.idx] = q.val;
 
        tree.update(i.y, update);
    }
 
    forn(i, 0, n) cout << (in_resp[i] != 0ll) << " \n"[i == n-1];
 
 
    // responde out
 
    segtree<node> seg(cnt, neutral);
    // for(auto i : inter){
    for(ll j = n-1; j>=0; j--){
        auto i = inter[j];
        auto q = seg.query(i.y, cnt);
        out_resp[i.idx] = q.val;
 
        seg.update(i.y, update);
    }
 
    forn(i, 0, n) cout << (out_resp[i] != 0ll) << " \n"[i == n-1];
 
 
    return 0;
}