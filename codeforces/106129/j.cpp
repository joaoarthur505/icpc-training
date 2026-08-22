    #include<bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef pair<ll,ll> pll;
    typedef vector<ll> vll;

    #define forn(i,s,e) for(ll i=s;i<e;i++)
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
    #define debugv(v) trace(cout << #v ": "; for(auto xx : v) cout << xx << " "; cout << ln)
    #define debugm(v) trace(cout << #v ": "; for(auto xx : v) cout << xx.first << ":" << xx.second << " "; cout << ln)

    const ll INF = 0x3f3f3f3f3f3f3f3fll;

    void enc(ll n, string s){
        ll pt = 0;
        while(pt < n && s[pt] == s[0]) pt++;
        
        if(pt == n){
            cout << s << ln;
            return;
        }

        forn(i,0,pt) s[i] = '2';
        cout << s << ln;
    }

    void dec(ll n, string s){
        string edg0(n, '0');
        string edg1(n, '1');

        if(s == edg0){
            cout << s << ln;
            return;
        }
        if(s == edg1){
            cout << s << ln;
            return;
        }

        s = s + s;
        ll pt = 0;
        ll pf = 0;
        while(s[pt] == '2') pt++;
        while(s[pt] != '2') pt++;
        pf = pt;

        while(s[pf] == '2') pf++;
        string resp(n, '#');    
        
        char c = '0';
        if(s[pf] == '0') c = '1';

        forn(i,pt,pt+n){
            if(s[i] == '2') resp[i-pt] = c;
            else resp[i-pt] = s[i];
        }
        cout << resp << ln;
    }

    int main(){
        _;  
        string t; cin >> t;
        ll n; cin >> n;
        string s; cin >> s;
        
        if(t[0] == 'E') enc(n, s);
        else dec(n, s);

        return 0;
    }