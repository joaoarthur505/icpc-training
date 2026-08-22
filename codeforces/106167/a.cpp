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
    _; ll n; cin >> n;
    if(n == 1){
        cout << 1 << ln;
        return 0;
    }
    if(n == 3){
        cout << 1 << ln;
        return 0;
    }

    n--;
    ll pow = 1, cnt = 0, especial = -1;;

    while(n > 0){
        if(n%2 != 0){
            cnt++;
            if(especial == -1) especial = pow;
        }
        pow*=2;
        n/=2;
    }

    debug(cnt);

    if(cnt == 2){
        cout << especial+1 << ln;
        return 0;
    }

    if(cnt == 1){
        cout << especial/2 + 1 << ln;
        return 0;
    }

    cout << "impossible" << ln;
    return 0;
}
