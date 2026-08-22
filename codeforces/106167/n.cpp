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

struct edg {
    ll v, t;
    vll colors;
};

struct gpp {
    ll open = 0;
    ll mx = 0;
};

struct gp {
    ll open = 0;
    set<ll> colors;
    map<ll, gpp> info_by_color;
};


int main() {
    _;
    ll n, m, k; cin >> n >> m >> k;
    vector<vector<edg>> g(n);
    vector<gp> gps(n);

    forn (i, 0, m) {
        ll u, v, t; cin >> u >> v >> t;
        u--; v--;
        ll l; cin >> l;
        vll colors(l);
        forn(j, 0, l) {
            cin >> colors[j];
            gps[u].colors.insert(colors[j]);
            gps[u].info_by_color[colors[j]].open++;
        }

        g[v].emplace_back(u, t, move(colors));
    }
    forn(u, 0, n) {
        gps[u].open = sz(gps[u].colors);
    }


    ll s = n-1;
    vll d(n, INF);
    d[s] = 0;

    priority_queue<pll> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ll u = pq.top().second;
        ll d_u = -pq.top().first;
        pq.pop();

        if (d_u != d[u]) continue;

        for (auto edge : g[u]) {
            for (auto c : edge.colors) {
                auto &info = gps[edge.v].info_by_color[c];

                info.mx = max(info.mx, d[u] + edge.t);
                info.open--;
                if (info.open == 0) {
                    if (info.mx < d[edge.v]) {
                        d[edge.v] = info.mx;
                        pq.push({-info.mx, edge.v});
                    }
                }
            }
        }
    }

    if (d[0] == INF)
        cout << "impossible\n";
    else
        cout << d[0] << '\n';
    
    return 0;
}
