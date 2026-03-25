#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n; cin >> n;
    map<ll,ll> freq;
    vector<p64> ord;
    forn(i,0,n){
        ll a; cin >> a;
        ord.push_back({a+i+1, a+1});
    }
    sort(ord.rbegin(), ord.rend());

    set<ll> s;
    ll last = INF;
    forn(i, 0, n){
        cout << last << ln;

        if(last > ord[i].first){
            last = ord[i].first;
            s.insert(last);
            continue;
        }
        if(last > ord[i].second){
            last--;
            s.insert(last);
        }
    }

    for(auto it = s.rbegin(); it != s.rend(); it++){
        cout << *it << " ";
    }
    cout << ln;
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}