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

    void solve(){
        ll a, b, c, k; cin >> a >> b >> c >> k;
        bool deu_ruim = false;
        
        if(c < max(a, b) || c > max(a, b)+1) deu_ruim = true;
        if(k >= (power[a] - power[a-1])*(power[b] - power[b-1]))deu_ruim = true;

        ll resp_a, resp_b;
        if(c == max(a,b)){
            ll num_a;

            for(num_a = power[a-1]; num_a < power[a]; num_a++){
                ll pos_b = power[c] - num_a - power[b-1];
                if(pos_b <= 0){
                    deu_ruim = true;
                    break;
                }
                if(k > pos_b) k -= pos_b;
                else break;
            }

            resp_a = num_a;
            resp_b = k;
        }

        if(c == max(a,b)+1){
            ll num_a;

            for(num_a = power[a-1]; num_a < power[a]; num_a++){
                ll pos_b = power[b] -power[c-1] + num_a;
                if(pos_b <= 0){
                    deu_ruim = true;
                    break;
                }
                if(k > pos_b) k -= pos_b;
                else break;
            }

            resp_a = num_a;
            resp_b = k + power[c-1] - num_a - 1;
        }
        
        ll resp_c = resp_a + resp_b;
        if(resp_a < power[a-1] || resp_a >= power[a]) deu_ruim = true;
        if(resp_b < power[b-1] || resp_b >= power[b]) deu_ruim = true;
        if(resp_c < power[c-1] || resp_c >= power[c]) deu_ruim = true;

        if(deu_ruim){
            cout << -1 << ln;
            return;
        }

        cout << resp_a << " + " << resp_b << " = " << resp_c << ln;
    }



    int main() {
        _; ll t; cin >> t;
        forn(i, 0, t) solve();
        return 0;
    }
