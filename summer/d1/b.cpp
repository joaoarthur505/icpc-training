#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MAXROMAN = 4000;
const ll MOD = 998244353;

vector<string> roman;
string alfa = "CDILMVX";
vector<vector<ll>> transition(MAXROMAN, v64(sz(alfa))); // transition[i][j] me diz para qual estado eu vou ao adicionar alfa[j] no final de roman[i]

template<ll p> struct mod_int {
    ll expo(ll b, ll e) {
        ll ret = 1;
        while (e) {
            if (e % 2) ret = ret * b % p;
            e /= 2, b = b * b % p;
        }
        return ret;
    }
    ll inv(ll b) { return expo(b, p-2); }

    using m = mod_int;
    ll v;
    mod_int() : v(0) {}
    mod_int(ll v_) {
        if (v_ >= p or v_ <= -p) v_ %= p;
        if (v_ < 0) v_ += p;
        v = v_;
    }
    m& operator +=(const m& a) {
        v += a.v;
        if (v >= p) v -= p;
        return *this;
    }
    m& operator -=(const m& a) {
        v -= a.v;
        if (v < 0) v += p;
        return *this;
    }
    m& operator *=(const m& a) {
        v = v * a.v % p;
        return *this;
    }
    m& operator /=(const m& a) {
        v = v * inv(a.v) % p;
        return *this;
    }
    m operator -() const { return m(-v); }
    m& operator ^=(ll e) {
        if (e < 0) {
            v = inv(v);
            e = -e;
        }
        v = expo(v, e);
        // possible optimization:
        // careful with 0^0
        // v = expo(v, e%(p-1)); 
        return *this;
    }
    bool operator ==(const m& a) { return v == a.v; }
    bool operator !=(const m& a) { return v != a.v; }

    friend istream& operator >>(istream& in, m& a) {
        ll val; in >> val;
        a = m(val);
        return in;
    }
    friend ostream& operator <<(ostream& out, m a) {
        return out << a.v;
    }
    friend m operator +(m a, m b) { return a += b; }
    friend m operator -(m a, m b) { return a -= b; }
    friend m operator *(m a, m b) { return a *= b; }
    friend m operator /(m a, m b) { return a /= b; }
    friend m operator ^(m a, ll e) { return a ^= e; }
};
typedef mod_int<MOD> mint;

void prepare(){
    vector<string> th ={"", "M", "MM", "MMM"};
    vector<string> hu ={"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    vector<string> te ={"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    vector<string> un ={"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    forn(uni, 0, 10)
    forn(ten, 0, 10)
    forn(hun, 0, 10)
    forn(tho, 0, 4){
        string written = th[tho] + hu[hun] + te[ten] + un[uni];
        roman.push_back(written);
    }

    sort(roman.begin(), roman.end());

    forn(i, 0, MAXROMAN){
        forn(j, 0, sz(alfa)){
            string new_num = roman[i] + alfa[j];
            ll len = sz(new_num);

            forn(k, 0, len){
                string search = new_num.substr(k, len - k);
                auto it = lower_bound(roman.begin(), roman.end(), search);
                if(*it == search){
                    transition[i][j] = it - roman.begin();
                    break;
                }
            }
        }
    }
}

mint solve(ll k, ll n){
    vector<vector<mint>> dp(n+1, vector<mint>(MAXROMAN, 0));
    dp[0][0] = 1;
    forn(i, 0, n){
        forn(e, 0, MAXROMAN){
            forn(j, 0, sz(alfa)){
                string nxt = roman[transition[e][j]];
                if(sz(nxt) == k) continue;
                dp[i+1][transition[e][j]] += dp[i][e];
            }
        }
    }

    mint ans = 0;
    forn(e, 0, MAXROMAN) ans += dp[n][e];

    debug(k);
    debug(ans);
    return ans;
}

int main(){ 
    _; prepare();
    ll n; cin >> n;

    mint sum = 0;

    forn(k, 1, 16){
        sum += solve(k, n);
    }

    debug(sum);
    mint total_words = ((mint)7)^n;
    debug(total_words);
    mint resp = 15 - sum/(total_words);

    cout << resp << ln;

    return 0;
}