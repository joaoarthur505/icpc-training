#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define forn(i,s,e) for(ll i = (s); i<(e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

# ifdef DEBUG
#define trace(u) u
const ll MAX = 15;
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
const ll MAX = 3'000'005;
#endif

#define debug(u) trace(cout << __LINE__ << ": " <<  #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln;)
#define debugm(v) trace(cout << #v ": "; for (auto xx : v) cout << xx.first << ":" << xx.second << " "; cout << ln;)

// const ll INF = 0x3f3f3f3f3f3f3f3fll;


struct Node{
    ll sum = 0, cnt = 1;
    Node operator*(const Node &o) const { return {sum+o.sum,cnt+o.cnt}; }
};

struct Update{
    ll add=0;

    Node operator()(const Node &n) const {
        return {n.sum + add * n.cnt, n.cnt};
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

void print(segtree<Node, Update>& seg, ll n){
    forn(i,0,n) cout << i%10 << " ";; cout << ln;
    forn(i,0,n) cout << seg.query(i,i).sum << " ";
    cout << ln;
}

int main(){
    _;
    ll n, q; cin >> n >> q;

    vll vec(n);
    vll vals;
    vector<tuple<ll,ll,ll>> queries(q);
    multiset<ll> ms;
    segtree<Node, Update> seg(MAX);
    
    forn(i,0,n){
        cin >> vec[i];
        vals.push_back(vec[i]);
    }
    
    forn(i,0,q){
        ll t; cin >> t;
        if(t == 1){
            ll x; cin >> x;
            queries[i] = {1,x, -1};
            vals.push_back(x);
        }else{
            ll a, b; cin >> a >> b;
            queries[i] = {2,a, b};
            vals.push_back(a);
            vals.push_back(b);
        }
    }
    
    sort(vals.begin(), vals.end());
    
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    debugv(vals);
    
    auto compress = [&](ll& x){
        x = (ll)(lower_bound(vals.begin(), vals.end(), x) - vals.begin());
    };
    
    forn(i,0,n) compress(vec[i]);
    
    forn(i,0,q){
        auto [t, a, b] = queries[i];
        
        compress(a);
        if(t == 2) compress(b);
        queries[i] = {t, a, b};
    }
    
    forn(i,0,n){
        ms.insert(vec[i]);
        seg.update(vec[i], vec[i], {1});
    }

    // debugv(vec);
    // forn(qq, 0, q){
    //     auto [t,a,b] = queries[qq];
    //     cout << t << " " << a << " " << b << ln;
    // }
 
    forn(qq, 0, q){
        debug(qq);
        trace(print(seg, MAX));
        auto [t,a,b] = queries[qq];

        if(t == 1){
            ll k = a;
            auto it = ms.lower_bound(k);
            if(it == ms.end()){
                ms.insert(k);
                seg.update(k,k,{1});
                debug(k);
            }   
            else if(k != *it){
                ll old_k = *it;
                ms.erase(it);
                seg.update(old_k,old_k,{-1});
                ms.insert(k);
                seg.update(k,k,{1});
                debug(k);
                debug(old_k);
            }
        }else{
            debug(a);
            debug(b);
            cout << seg.query(a, b).sum << ln;
        }
        trace(cout << "-----------------\n\n\n";)
    }

    return 0;
}   