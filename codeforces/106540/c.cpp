#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

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
const ll MOD = 1'000'000'007;
const ll MAX = 1'000'005;

template<ll p> struct mod_int{
    ll expo(ll b, ll e) {
        ll ret = 1;
        while(e) {
            if(e%2) ret = ret * b % p;
            e /= 2, b = b*b % p; 
        }
        return ret;
    }

    ll inv(ll b) { return expo(b, p-2); }

    using m = mod_int;
    ll v;
    mod_int() : v(0) {}
    mod_int(ll v_) {
        if (v_ >= p || v_ >= p) v_ %= p;
        if (v_ < 0) v_ += p;
        v = v_;
    }
    m& operator *= (const m& a){
        v = v * a.v % p;
        return *this;
    }
    m& operator /= (const m& a) {
        v = v * inv(a.v) % p;
        return *this;
    }

    friend ostream& operator << (ostream& out, m a) {
        return out << a.v;
    }
};
typedef mod_int<MOD> mint;

int main() {
    _; 
    vll vec(MAX);
    vll acc(MAX);

    forn(i,0,MAX) vec[i] = (i-1)/2;
    forn(i,1,MAX) acc[i] = acc[i-1] + vec[i];
    
    ll t; cin >> t;

    trace(
        forn(i,0,20) cout << setw(2) << vec[i] << " ";; cout << ln;
        forn(i,0,20) cout << setw(2) << acc[i] << " ";; cout << ln;
    )

    mint resp = 1;
    while(t--){
        ll n;
        cin >> n;
        mint num = acc[n];
        debug(num);
        mint dem = (n*(n-1)*(n-2))/6;
        debug(dem);
        num /= dem;
        resp *= num;
        cout << resp << ln;
    }
    return 0;
}
 