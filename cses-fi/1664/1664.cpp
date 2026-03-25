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
const ll MAXN = 1000004;
// const ll MAXN = 15;
const ll LOG = 20;

bool cmp(p64 p1, p64 p2){
    if(p1.second != p2.second) return p1.second < p2.second;
    return p1.first > p2.first;
}

int main() {
    _; ll n, q; cin >> n >> q;
    vector<v64> nxt_end_movie(LOG , v64(MAXN, 0));
    vector<p64> movies(n);
    forn(i, 0, n){
        ll a, b; cin >> a >> b;
        movies[i] = {a,b};
    }
    movies.push_back({MAXN-1, MAXN-1});

    sort(movies.begin(), movies.end(), cmp);

    ll idx = 0;
    forn(i, 0, MAXN){
        while(movies[idx].first < i) idx++;

        nxt_end_movie[0][i] = movies[idx].second;
        trace( cout << nxt_end_movie[0][i] << " \n"[i == MAXN-1];);
    }

    forn(lvl, 1, LOG)
    forn(i, 0, MAXN){
        nxt_end_movie[lvl][i] = nxt_end_movie[lvl-1][nxt_end_movie[lvl-1][i]];
        trace( cout << nxt_end_movie[lvl][i] << " \n"[i == MAXN-1];);
    }

    forn(i, 0, q){
        ll a, b; cin >> a >> b;

        ll qnt = 0;
        ll curr = a;
        for(ll step = LOG -1; step>= 0; step--){
            debug(curr);
            debug(nxt_end_movie[step][curr]);
            if(nxt_end_movie[step][curr] <= b){
                qnt += 1<<step;
                curr = nxt_end_movie[step][curr];
            }
        }

        cout << qnt << ln;
    }

    return 0;
}
