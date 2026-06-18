// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
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

const ll MOD = 1000000007;
const ll MAX = 10006;

vector<mint> fact(MAX);

mint binom(ll a, ll b){
    if(b > a) return 0;

    mint prod_cima = 1, prod_baixo = 1;

    forn(i, 0, b){
        prod_baixo *= (i+1);
        prod_cima *= (a-b+1 + i); 
    }

    return prod_cima/prod_baixo;
}

int main() {
    _;
    ll a, b, n; cin >> n >> a >> b;
    mint pot = 2;
    pot ^= n;
    cout << pot - binom(n, a) - binom(n, b) - 1;
    return 0;
}
