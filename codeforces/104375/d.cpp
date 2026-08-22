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


struct Bit {
    ll n; 
    vll bit;
    Bit(ll _n = 0) : n(_n), bit(n+1) {};

    void update(ll i, ll x){
        for(i++; i <= n; i += i & -i) bit[i] += x;
    }

    ll pref(ll i){
        ll ret = 0;
        for(i++; i; i -= i&-i) ret += bit[i];
        return ret;
    }
    ll query(ll l, ll r){
        return pref(r) - pref(l-1);
    }
};

// void print(segtree<Node, Update>& seg, ll n){
//     forn(i,0,n) cout << i%10 << " ";; cout << ln;
//     forn(i,0,n) cout << seg.query(i,i).sum << " ";
//     cout << ln;
// }

int main(){
    _;
    ll n, q; cin >> n >> q;

    vll vec(n);
    vll vals;
    vector<tuple<ll,ll,ll>> queries(q);
    multiset<ll> ms;

    Bit bit(MAX);

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
        bit.update(vec[i], {1});
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
                bit.update(k,1);
            }   
            else if(k != *it){
                ll old_k = *it;
                ms.erase(it);
                bit.update(old_k,-1);
                ms.insert(k);
                bit.update(k,1);
                debug(k);
                debug(old_k);
            }
        }else{
            cout << bit.query(a, b) << ln;
        }
        trace(cout << "-----------------\n\n\n";)
    }

    return 0;
}   