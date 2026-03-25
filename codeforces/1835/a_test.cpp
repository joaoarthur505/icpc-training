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

    v64 power = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

    p64 solve(ll a, ll b, ll c, ll k){
        bool deu_ruim = false;
        
        ll resp_a, resp_b;
        ll num_a;

        for(num_a = power[a-1]; num_a < power[a]; num_a++){
            ll pos_b = min(power[c] - num_a, power[b]) - max(power[c-1] - num_a , power[b-1]);
            if(pos_b <= 0) continue;
            if(k > pos_b) k -= pos_b;
            else break;
        }

        resp_a = num_a;
        resp_b = k + max(power[c-1] - num_a , power[b-1]) - 1; 

        // debug(resp_a);
        // debug(resp_b);
        
        ll resp_c = resp_a + resp_b;
        if(resp_a < power[a-1] || resp_a >= power[a]) deu_ruim = true;
        if(resp_b < power[b-1] || resp_b >= power[b]) deu_ruim = true;
        if(resp_c < power[c-1] || resp_c >= power[c]) deu_ruim = true;

        if(deu_ruim){
            return p64(-1, -1);
        }

        return {resp_a, resp_b};
    }



    int main() {
        _;
        forn(a, 1, 7)
        forn(b, 1, 7)
        forn(c, 1, 7){
            ll k = 1;
            forn(num_a, power[a-1], power[a])
            forn(num_b, power[b-1], power[b]){
                if(num_a+num_b < power[c-1] || num_a+num_b >= power[c])continue;
                debug(k);
                p64 resp = solve(a, b, c, k);
                if(resp != p64(num_a, num_b)){
                    cout << a << " " << b << " " << c << " " << k << ln;
                    cout << num_a << " + " << num_b << " = " << num_a + num_b << ln;
                    cout << "minha resp:" << ln;
                    cout << resp.first << " + " << resp.second << " = " << resp.first + resp.second << ln;
                    
                    ll x;
                    cin >> x;
                    x += x;
                }
                k++;
            }
        }
        return 0;
    }
