#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
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
const ll NUMITS = 1000;

ull modmul(ull a, ull b, ull M){ 
    ll ret = a*b - M * ull(1.L / M*a*b);    
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
};

ull modpow(ull b, ull e, ull mod){
    ull ans = 1;
    for(; e; b = modmul(b, b, mod), e /= 2)
        if(e & 1) ans = modmul(ans, b, mod);
    return ans;
}

bool isPrime(ull n){
    if(n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}, s = __builtin_ctzll(n-1), d = n >> s;
    for (ull a : A) {
        ull p = modpow(a%n, d, n), i = s;
        while(p != 1 && p != n-1 && a % n && i--)
            p = modmul(p, p, n);
        if(p != n-1 && i != s) return 0;
    } 
    return 1;
}

void solve(){
    ll a; cin >> a;
    ll prime = -1;
    forn(i, 1, NUMITS){
        if(isPrime(a+i)){
            prime = a+i;
            break;
        }
    }

    cout << prime << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
