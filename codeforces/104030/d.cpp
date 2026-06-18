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

int main() {
    _;
    ll r; cin >> r;
    ll x = r+1;
    ll y = 0;
    ll bx = r+1;
    ll by = 0;
    ll b = x*x+y*y;

    while(y <= r){
        y++;
        while((x-1)*(x-1)+y*y > r*r) x--;
        if(x*x + y*y < b){
            b = x*x+y*y;
            bx = x;
            by = y;
        }
    }
    cout << bx << " " << by << ln;
    return 0;
}
