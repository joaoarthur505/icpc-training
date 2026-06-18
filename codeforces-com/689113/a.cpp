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
const ll MAX = 100'005;

int main() {
    _;
    ll n, c; cin >> n >> c;
    vll vec(n);
    vll aux(MAX);
    forn(i,0,n){
        cin >> vec[i];
    }
    forn(i,0,c){
        ll m, a; 
        cin >> m >> a;
        m--;
        aux[m] += a;
    }
    ll acc = 0;
    for(ll i = MAX - 1; i >= 0; i--){
        acc += aux[i];
        if(i < n) vec[i] += acc;
    }

    stack<pll> q;
    q.push({INF, -1});
    q.push({vec[0], 0ll});
    debugv(vec);
    forn(i,1,n){
        cout << sz(q) - 1<< ln;
        while(q.top().first <= vec[i]) q.pop();
        // cout << i - q.top().second + sz(q) - 1<< ln;
        q.push({vec[i], i});
    }

    return 0;
} 
