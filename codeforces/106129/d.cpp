#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define forn(i,s,e) for(ll i=s;i<e;i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace (u)
#define _
#else#define trace (u)
#define _ ios::sync_with_stdio
#endif

// #define debug(u) (trace)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    ll n; cin >> n;
    ll ymax = -INF, ymin = INF, xmax = -INF, xmin = INF;

    vector<pll> v(n);
    forn(i, 0, n){
        cin >> v[i].first >> v[i].second;
    }

    forn(i, 0, n){
        if(v[i].first == v[(i+1)%n].first){
            xmax = max(xmax, v[i].first);
            xmin = min(xmin, v[i].first);
        }
        if(v[i].second == v[(i+1)%n].second){
            ymax = max(ymax, v[i].second);
            ymin = min(ymin, v[i].second);
        }
    }

    cout << 4 << ln;
    cout << xmax << " " << ymax << ln;
    cout << xmin << " " << ymax << ln;
    cout << xmin << " " << ymin << ln;
    cout << xmax << " " << ymin << ln;
}