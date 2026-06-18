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

void process(string s);

bool is_print(string s){
    return s.substr(0, 6) == "print(";
}

bool is_if(string s){
    return s.substr(0, 3) == "if ";
}

bool is_while(string s){
    return s.substr(0, 6) == "while ";
}

void apresente(string s){
    cout << "APRESENTE " << s.substr(6, sz(s) - 7) << ln;
}

void se(string s){
    cout << "SE " << s.substr(3, sz(s) - 4) << " ENTAO ";
    string s2;
    getline(cin, s2);
    // cout << s2;
    process(s2.substr(4, sz(s2) - 4)); 
}

void enquanto(string s){
    cout << "ENQUANTO " << s.substr(6, sz(s) - 7) << " ";
    string s2;
    getline(cin, s2);
    // cout << s2;
    process(s2.substr(4, sz(s2) - 4)); 
}

void leia(string s){
    ll cnt = 0;
    while(s[cnt] != ' ') cnt++;
    cout << "LEIA " << s.substr(0, cnt) << ln;
}

void process(string s){
    if(is_print(s)) apresente(s);
    else if(is_if(s)) se(s);
    else if(is_while(s)) enquanto(s);
    else leia(s);
}

int main() {
    string linha;
    getline(cin, linha);
    process(linha);
    return 0;
}
