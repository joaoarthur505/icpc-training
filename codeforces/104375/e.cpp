#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define forn(i,s,e) for(ll i = (s); i<(e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

# ifdef DEBUG
#define trace(u) u
#define _
const ll MAXITS = 5;
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
const ll MAXITS = 17;
#endif

#define debug(u) trace(cout << #u << " = " << u << ln)
#define debugv(v) trace(cout << #v << ": "; for(auto xx : v) cout << xx << " "; cout << ln;)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct Node{
    ll sum = 0, cnt = 1;
    Node operator*(const Node &o) const { return {sum+o.sum,cnt+o.cnt}; }
};

struct Update{
    ll add=0;

    Node operator()(const Node &n) const {
        return {n.sum +add * n.cnt, n.cnt};
    }

    Update operator+(const Update &o) const {
        Update res = *this;
        res.add += o.add;
        return res;
    }
};

template<typename T, typename U> struct segtree {
    ll s,h;

    T id;
    vector<T> val;

    U noop;
    vector<bool> dirty;
    vector<U> prop;

    segtree(ll ts, T tid = T(), U tnoop = U()) {
        id = tid, noop = tnoop;
        for (s = 1, h = 1; s< ts; ) s*=2, h++;

        val.assign(2*s, id);
        dirty.assign(2*s, false);
        prop.assign(2*s, noop);
    }

    void set_leaves(vector<T> &lvs) {
        copy(lvs.begin(), lvs.end(), val.begin()+s);

        for (ll i = s - 1; i > 0; i--) val[i] = val[2 * i] * val[2 * i + 1];
        dirty.assign(2*s, false);
        prop.assign(2*s, noop);
    }

    void apply(ll i, U &upd) {
        val[i] = upd(val[i]);
        if(i<s) {
            prop[i] = prop[i] + upd;
            dirty[i] = true;
        }
    }

    void pull(ll i) {
        for(ll l = i/2; l; l/=2) {
            T comb = val[2*l]*val[2*l+1];
            val[l] = prop[l](comb);
        }
    }

    void push(ll i) {
        for(ll th = h; th > 0; th--) {
            ll l = i >> th;

            if(dirty[l]) {
                apply(2*l, prop[l]);
                apply(2*l+1, prop[l]);

                prop[l] = noop;
                dirty[l] = false;
            }
        }
    }

    void update(ll i, ll j, U upd) {
        i +=s, j+= s;
        push(i),push(j);

        for (ll l = i, r = j; l<=r; l/=2, r/=2) {
            if((l&1) == 1) apply(l++, upd);
            if((r&1) == 0) apply(r--, upd);
        }

        pull(i), pull(j);
    }

    T query(ll i, ll j){
        i += s, j += s;
        push(i), push(j);

        T rl = id, rr = id;
        for(; i<=j; i/=2, j/=2){
            if((i&1) == 1) rl = rl * val[i++];
            if((j&1) == 0) rr = val[j--] * rr;
        }
        return rl * rr; 
    }
};

vector<vll> euler_tour (vector<vll> &tree, ll n){
    vll in_deg(n, 0);
    forn(u, 0, n)
    for(auto v : tree[u]) in_deg[v]++;

    vll in(n), out(n), w(n, 0);
    ll time = 0;

    function<void (ll)> dfs = [&](ll curr){
        in[curr] = time++;
        w[curr]++;

        for(auto next : tree[curr]){
            dfs(next);
            w[curr] += w[next];
        }

        out[curr] = time++;
    };

    forn(i, 0, n) if(in_deg[i] == 0) dfs(i);
    return {in, out, w};
}

int main(){
    _;
    ll n, q; cin >> n >> q;
    vll target(n);
    forn(i, 0, n) cin >> target[i];
    vector<vll> tree(n);
    forn(i, 0, n-1){
        ll a, b; cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
    }

    auto aux = euler_tour(tree, n);
    vll in = aux[0], out = aux[1], w = aux[2];

    vll receiver(q), bonus(q);
    forn(i, 0, q){
        cin >> receiver[i] >> bonus[i];
        receiver[i]--;
    }

    vll l(n, 0), r(n, q-1), ans(n, -2);
    
    forn(ii, 0, MAXITS){
        vector<vll> m(q);
        debugv(l);
        debugv(r);
        ll cnt = 0;
        forn(i, 0, n){
            ll mid = (l[i] + r[i])/2;
            if(l[i] <= r[i]){
                m[mid].push_back(i);
                cnt++;
            }
        }
        if(cnt == 0){
            break;
        }
        segtree<Node, Update> seg(2*n);

        forn(t, 0, q){
            ll gen_bonus = bonus[t]/w[receiver[t]];
            ll ind_bonus = bonus[t]%w[receiver[t]];

            seg.update(in[receiver[t]], out[receiver[t]], {gen_bonus});
            seg.update(in[receiver[t]], in[receiver[t]], {ind_bonus});

            debug(t);
            for(auto v : m[t]){
                auto auxx = seg.query(in[v],in[v]);
                ll curr_money = auxx.sum;

                debug(v);
                debug(curr_money);

                if(curr_money >= target[v]){
                    ans[v] = t;
                    r[v] = t-1;
                } else {
                    l[v] = t+1;
                    ll mid = (l[v] + r[v])/2;
                    if(mid > t){
                        m[mid].push_back(v);
                    }
                }
            }
        }
    }

    forn(i, 0, n) cout << ans[i]+1 << ln;
    return 0;
} 