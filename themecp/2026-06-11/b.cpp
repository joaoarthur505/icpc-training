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

pll separate(ll n, ll s){
    if((n-s)%2!=0) return {-1, -1};
    if(n > s) return {(n-s)/2, 0};
    else return {0, (s-n)/2};
}

void solve(){
    ll num; cin >> num;
    string move; cin >> move;

    ll n=0, s=0, e=0, w=0;
    forn(i, 0, num){
        if(move[i] == 'N') n++;
        if(move[i] == 'S') s++;
        if(move[i] == 'E') e++;
        if(move[i] == 'W') w++;
    }

    auto [nh, sh] = separate(n, s);
    auto [eh, wh] = separate(e, w);

    if(n == s && n >=1){
        nh++;
        sh++;
    } else if (e == w && e>= 1){
        eh++;
        wh++;
    }

    if(nh < 0 || eh < 0 || nh+sh+eh+wh == num){
        cout << "NO" << ln;
        return;
    }

    string ans(num, 'R');
    forn(i, 0, num){
        if(move[i] == 'N' && nh > 0){
            ans[i] = 'H';
            nh--;
        }
        if(move[i] == 'S' && sh > 0){
            ans[i] = 'H';
            sh--;
        }
        if(move[i] == 'E' && eh > 0){
            ans[i] = 'H';
            eh--;
        }
        if(move[i] == 'W' && wh > 0){
            ans[i] = 'H';
            wh--;
        }
    }

    cout << ans << ln;
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();
    return 0;
}
