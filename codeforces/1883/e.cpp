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
const ll MAX_VOW = 2;
const ll MAX_CON = 2;

string vowel = "aeiouy";
string consonant = "bcdfghjklmnpqrstvwxz";
vector<string> options(10);
ll n;

void brute(string force, ll step, ll num_vow, ll num_con){
    if(step == n){
        cout << force << ln;
        cout << ln;
        return;
    }

    forn(i, 0, sz(options[step])){
        char c = options[step][i];
        if(vowel.find(c)){
            if(num_vow == MAX_VOW) continue;
            brute(force + c, step+1, num_vow+1, 0);
        }
        else{
            if(num_con == MAX_CON) continue;
            brute(force + c, step+1, 0, num_con+1);
        }
    }
}

int main() {
    _; cin >> n;
    forn(i, 0, n) cin >> options[i];

    brute("", 0, 0, 0);

    return 0;
}
