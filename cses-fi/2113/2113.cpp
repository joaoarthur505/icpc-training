#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cd;
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
    _; ll n, m; cin >> n >> m;
    vector<cd> a(n), b(m);
    forn(i, 0, n){
        ll _a; cin >> _a;
        a[i] = cd{_a,0};
    }
    forn(i, 0, m){
        ll _b; cin >> _b;
        b[m-1 - i] = cd{_b, 0};
    }

    auto c = convolution<complex<double>>(a,b);

    for(auto x : c) cout << (ll)(x.real()+0.1) << " ";
    cout << ln;

    return 0;
}
