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
    _; ll n; cin >> n;
    vector<v64> dist(n, v64(n, INF));

    vector<p64> step = {p64(1,2), p64(-1,2), p64(1,-2), p64(-1,-2), p64(2, 1), p64(-2, 1), p64(2, -1), p64(-2, -1)}; 

    dist[0][0] = 0;
    queue<p64> bfs;
    bfs.emplace(0,0);
    while(!bfs.empty()){
        p64 curr = bfs.front();
        bfs.pop();

        forn(i, 0, 8){
            p64 next = {curr.first + step[i].first, curr.second + step[i].second};
            if(next.first < 0 || next.first > n-1 || next.second < 0 || next.second > n-1) continue;
            if(dist[next.first][next.second] != INF) continue;

            dist[next.first][next.second] = dist[curr.first][curr.second] + 1;
            bfs.push(next);
        }
    }

    forn(i, 0, n)
    forn(j, 0, n){
        cout << dist[i][j] << " \n"[j == n-1];
    }
    return 0;
}
