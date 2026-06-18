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

vector<string> v = {
    "pigs", "sand", "mail", "date", "head",
    "clam", "peak", "sand", "joya", "well",
    "toad", "card", "will", "tape", "legs",
    "tree", "road", "maid", "slab", "rock",
    "hand", "vase", "safe", "clay", "toes"
};

ll solve(string s){
    ll a = s[0] - 'a', b = s[1] - 'a', c = s[2] - 'a', d = s[3] - 'a';
    a++;
    b++;
    c++;
    d++;

    debug(s);
    debug(a);
    debug(b);
    debug(c);
    debug(d);

    ll best = INF;
    if(((a - b)*c)%d == 0 && (a >= b)){
        best = min(best, ((a - b)*c)/d); 
        debug(((a - b)*c)/d);
    }
    if(((a - b)*d)%c == 0  && (a >= b)){
        best = min(best, ((a - b)*d)/c); 
        debug(((a - b)/c)*d);
    }
    if(((a*b)-c)%d == 0 && (a*b >= c)) best = min(best, ((a*b)-c)/d); 
    if((a*b)%c == 0 && (((a*b)/c)>=d)) best = min(best, ((a*b)/c)-d); 
    if(a%b == 0 && (a/b >= c)) best = min(best, ((a/b)-c)*d); 
    if(a%b == 0 && ((a/b)*c)>=d) best = min(best, ((a/b)*c)-d); 

    return best;
}

int main() {
    _;
    ll n = sz(v);
    vll resp(n);

    forn(i, 0, n) resp[i] = solve(v[i]);

    forn(i, 0, 5){
        forn(j, 0, 5){
            cout << resp[5*i+j] << " ";
        }
        cout << ln;
    }

    forn(i, 0, 25) cout << (char)(resp[i]+'a') << " ";
    cout << ln;
    return 0;
}
