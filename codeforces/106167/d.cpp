#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
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

// FFT/NTT Convolution
//
// Implements iterative FFT over complex numbers and NTT over supported primes; provides convolution utility.
//
// complexity: O(N log N), O(N)

// Para FFT
void get_roots(bool f, int n, vector<complex<double>>& roots) {
    const static double PI = acosl(-1);
    for (int i = 0; i < n/2; i++) {
        double alpha = i*((2*PI)/n);
        if (f) alpha = -alpha;
        roots[i] = {cos(alpha), sin(alpha)};
    }
}

template<typename T> void fft(vector<T>& a, bool f, int N, vector<int>& rev) {
    for (int i = 0; i < N; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
    int l, r, m;
    vector<T> roots(N);
    for (int n = 2; n <= N; n *= 2) {
        get_roots(f, n, roots);
        for (int pos = 0; pos < N; pos += n) {
            l = pos + 0, r = pos + n/2, m = 0;
            while (m < n/2) {
                auto t = roots[m] * a[r];
                a[r] = a[l] - t;
                a[l] = a[l] + t;
                l++, r++, m++;
            }
        }
    }
    if (f) {
        auto invN = T(1) / T(N);
        for (int i = 0; i < N; i++) a[i] = a[i] * invN;
    }
}

template<typename T> vector<T> convolution(vector<T>& a, vector<T>& b) {
    vector<T> l(a.begin(), a.end()), r(b.begin(), b.end());
    int N = sz(l)+sz(r)-1;
    int n = 1, log_n = 0;
    while (n <= N) n *= 2, log_n++;
    vector<int> rev(n);
    for (int i = 0; i < n; i++) {
        rev[i] = 0;
        for (int j = 0; j < log_n; j++) if (i>>j&1)
            rev[i] |= 1 << (log_n-1-j);
    }

    assert(N <= n);
    l.resize(n);
    r.resize(n);
    fft(l, false, n, rev);
    fft(r, false, n, rev);
    for (int i = 0; i < n; i++) l[i] *= r[i];
    fft(l, true, n, rev);
    l.resize(N);
    return l;
}

int main() {
    _;
    ll n; cin >> n;
    string ss; cin >> ss;
    string rr; cin >> rr;
    vll r(2*n); 
    vll s(n); 
    forn(i,0,n) r[i+n] = r[i] = rr[i] - 'a';
    forn(i,0,n) s[i] = ss[i] - 'a';

    vector<vector<cpx>> a(26, vector<cpx>(n));
    vector<vector<cpx>> b(26, vector<cpx>(2*n));
    
    forn(l,0,26){
        forn(i,0,n) a[l][n-1-i] = cpx((ll)(s[i] == l));
        forn(i,0,n) b[l][i+n] = b[l][i] = cpx((ll)(r[i] == l));
    }

    ll best = 0;
    forn(cifra,0,26){
        vll resp(2*n);        
        forn(l,0,26){
            auto conv = convolution(a[(l+cifra)%26],b[l]);
            forn(i,0,2*n) resp[i] += (ll)(conv[i].real()+0.5);
            best = max(best, *max_element(resp.begin(), resp.end()));
        }
        debugv(resp);
    } 

    cout << n - best << ln;
    return 0;
}
