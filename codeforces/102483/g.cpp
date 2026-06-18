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

struct pt{
    ll x,y;
    pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
    pt operator + (const pt p) const { return pt(x + p.x, y+ p.y);}
    pt operator * (const ll c) const { return pt(x*c, y*c);}
};

map<char, pt> dir = {{'L', pt(-1, 0)}, {'R', pt(1, 0)}, {'U', pt(0, 1)}, {'D', pt(0, -1)}};
map<char, char> anti = {{'L', 'R'}, {'R', 'L'}, {'U', 'D'}, {'D', 'U'}}; 

string process(string s){
    if(sz(s) == 1) return s;

    ll n = sz(s);
    string s_fix;
    ll i = 0;
    while(i < n){
        if(i < n-2 && s[i] == s[i+2] && s[i] == anti[s[i+1]]){
            // debug(i);
            if(i == 0) return "";
            i += 2;
        }
        else{
            s_fix.push_back(s[i]);
            i++;
        }
    }

    n = sz(s_fix);
    forn(j, 0, n-1) if(s_fix[j] == s_fix[j+1]) return "";
    
    return s_fix;
}

int main() {
    _; string s; cin >> s;
    reverse(s.begin(), s.end());
    vector<pt> obstacles;
    pt curr;
    
    s = process(s);
    if(s == ""){
        cout << "impossible" << ln;
        return 0;
    } 
    ll n = sz(s);
    
    debug(s);

    ll pot = 1<<(n+2);
    forn(i, 0, n){
        pot /= 2;
        // debug(s[i]);
        // debug(curr.x);
        // debug(curr.y);
        obstacles.push_back(curr + dir[s[i]]);
        curr = curr + dir[s[i]]*(-pot);
    }

    cout << curr.x << " " << curr.y << ln;
    cout << sz(obstacles) << ln;
    forn(i, 0, sz(obstacles)){
        cout << obstacles[i].x << " " << obstacles[i].y << ln;
    }

    return 0;
}
