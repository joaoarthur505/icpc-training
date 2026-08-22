#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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
const ll MAX = 70'000'005;

ull modmul(ull a, ull b, ull M){
    ll ret = a*b - M * ull(1.L / M*a*b);
    ull ans = ret + M * (ret < 0) - M * (ret >= (ll)M); 
    return ans;
}

ull modpow(ull b, ull e, ull mod){
    ull ans = 1;
    for(; e; b = modmul(b,b,mod), e /=2)
    if(e & 1) ans = modmul(ans, b, mod);
    
    return ans;
}

bool isPrime(ull n){
    if(n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}, 
        s = __builtin_ctzll(n-1), d = n >> s;
    for(ull a : A){
        ull p = modpow(a%n, d, n), i = s;
        while(p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if(p != n-1 && i != s) return 0;
    }
    return 1;
}

int main() {
    _;

    vector<int> vec(MAX);
    vector<int> acc(MAX);

    vec[1] = 1;
    vec[2] = 1;
    vec[4] = 1;
    vec[6] = 1;
    vec[10] = 1;
    vec[14] = 1;
    vec[16] = 1;

    for(ll i = 18; i < MAX; i += 2){
        if(i % 5 == 2 || i % 5 == 3) continue;
        if(i % 13 == 5 || i % 13 == 8) continue;
        if(i % 17 == 4 || i % 17 == 13) continue;
        ll x= i*i+1;
        if(isPrime(x)) vec[i] = 1;
    }

    forn(i,1,MAX) acc[i] = vec[i] + acc[i-1];

    ll q; cin >> q;
    while(q--){
        ll n; cin >> n;
        cout << acc[n] << ln;
    }
    return 0;
}
