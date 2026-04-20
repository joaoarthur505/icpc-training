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
const ll SIDE = 8;
const ll SIZE = SIDE*SIDE;

vector<p64> moves = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};

v64 adj(ll curr){
    ll x = curr%8;
    ll y = curr/8;
    v64 v;

    for(auto p : moves){
        ll currx = x + p.first;
        ll curry = y + p.second;

        if(currx < 0 || currx >= 8) continue;
        if(curry < 0 || curry >= 8) continue;

        v.push_back(8*curry+currx);
    }
    return v;
}

bool dfs(ll curr, ll step, vector<v64> &path, vector<v64> &g, vector<v64> &prio){
    if(path[curr%8][curr/8] != -1) return false;
    path[curr%8][curr/8] = ++step;

    if(step == 64) return true;

    vector<p64> order;
    for(auto v : g[curr]){
        prio[v%8][v/8]--;
        order.push_back({prio[v%8][v/8], v});
    }

    sort(order.begin(), order.end());
    for(auto [val, next] : order) if(dfs(next, step, path, g, prio)) return true;

    for(auto v : g[curr])prio[v%8][v/8]++;

    path[curr%8][curr/8] = -1;
    step--;
    return false;
}

int main() {
    _; ll x, y; cin >> x >> y;
    x--;
    y--;

    vector<v64> g(64);
    forn(i, 0, SIZE) g[i] = adj(i);

    vector<v64> path(SIDE, v64(SIDE, -1));
    vector<v64> prio(SIDE, v64(SIDE));
    forn(i, 0, SIDE)
    forn(j, 0, SIDE)
        prio[i][j] = sz(g[8*j+i]);

    dfs(SIDE*x + y, 0, path, g, prio);

    forn(i, 0, SIDE)
    forn(j, 0, SIDE)
        cout << setw(2) << path[i][j] << " \n"[j == SIDE-1];

    return 0;
}
