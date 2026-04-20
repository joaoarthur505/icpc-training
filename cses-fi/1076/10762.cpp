#include <bits/stdc++.h>
using namespace std;

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

int main() {
    _; ll n, k; cin >> n >> k;
    v64 v(n), v_aux(k);
    forn(i, 0, n){
        cin >> v[i];
        if(i<k)v_aux[i] = v[i];
    }

    multiset<ll> upper, lower;
    ll median = 0;

    ll sz_upper = k/2;
    ll sz_lower = k/2 - (k%2 == 0);

    sort(v_aux.begin(), v_aux.end());

    forn(i, 0, sz_lower) lower.insert(v_aux[i]);
    median = v_aux[sz_lower];
    forn(i, 0, sz_upper) upper.insert(v_aux[i+sz_lower+1]);

    forn(i, k, n){
        cout << median << " ";

        if(v[i - k] == median){
            median = *lower.rbegin();
            lower.erase(lower.lower_bound(median));
        }
        if(v[i - k] < median) lower.erase(v[i-k]);
        if(v[i - k] > median) upper.erase(v[i-k]);

        if(v[i] <= median) lower.insert(v[i]);
        if(v[i] > median) upper.insert(v[i]);

        if(sz(upper) > sz_upper){
            lower.insert(median);
            median = *upper.begin(); 
            upper.erase(upper.begin());
        }
        if(sz(lower) > sz_lower){
            upper.insert(median);
            median = *lower.rbegin();
            lower.erase(lower.lower_bound(median));
        }

        trace(
            cout << ln;
            cout << "======" << ln;
            for(auto x: lower) cout << x << " ";
            cout << ln;
            cout << median << ln;
            for(auto x : upper) cout << x << " ";
            cout << ln;
            cout << "======" << ln;
            cout << ln;
        );
    }
    cout << median << ln;

    return 0;
}
