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
const ll N = 10;
const ll M = 15;
const ll W = 10;

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}

int main(){
    _; cout << 1 << ln;

    ll n = uniform(2, N);
    ll M_true = min(M, n*(n-1)/2);
    ll m = uniform(1, M_true);
    cout << n << " " << m << ln;

    forn(i, 0, n){
        cout << uniform(1, W) << " \n"[i == n-1];
    }

    set<pair<ll,ll>> s;

    forn(i, 0, m){
        pair<ll, ll> p;
        do{
            p = {uniform(1, n), uniform(1, n)};
        }while(p.first == p.second || s.count(p));

        s.insert(p);
        cout << p.first << " " <<  p.second << ln;
    }

    return 0;
}