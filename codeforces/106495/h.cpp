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

template<typename T> vector<ll> manacher(const T& s) {
	int l = 0, r = -1, n = s.size();
	vector<int> d1(n), d2(n);
	for (int i = 0; i < n; i++) {
		int k = i > r ? 1 : min(d1[l+r-i], r-i);
		while (i+k < n && i-k >= 0 && s[i+k] == s[i-k]) k++;
		d1[i] = k--;
		if (i+k > r) l = i-k, r = i+k;
	}
	l = 0, r = -1;
	for (int i = 0; i < n; i++) {
		int k = i > r ? 0 : min(d2[l+r-i+1], r-i+1); k++;
		while (i+k <= n && i-k >= 0 && s[i+k-1] == s[i-k]) k++;
		d2[i] = --k;
		if (i+k-1 > r) l = i-k, r = i+k-1;
	}
	vector<ll> ret(2*n-1);
	for (int i = 0; i < n; i++) ret[2*i] = 2*d1[i]-1;
	for (int i = 0; i < n-1; i++) ret[2*i+1] = 2*d2[i+1];
	return ret;
}

void solve(){
    string a, b; cin >> a >> b;
    ll n = sz(a);

    string b_rev = b;
    reverse(b_rev.begin(), b_rev.end());

    ll best_ini = -1, best_end = n;
    while(best_ini < n-1 && a[best_ini+1] == b_rev[best_ini+1]) best_ini++;    
    while(best_end > 0 && a[best_end-1] == b_rev[best_end-1]) best_end--;
    
    ll border = min(best_ini, n -best_end);

    // debug(best_ini);
    // debug(best_end);
    debug(border);

    vll ma = manacher<string>(a), mb = manacher<string>(a);

    // debugv(ma);
    // debugv(mb);

    ll sum = 0;
    forn(i, 0, 2*n-1){
        ll pali_ini, pali_end, middle_ini, middle_end;

        if(i%2 == 0){
            ll pali = min(ma[i], mb[i]);
            ll r = (pali-1)/2;

            pali_ini = i/2-r - 1;
            pali_end = i/2+r + 1;
            middle_ini = i/2-1;
            middle_end = i/2+1;
        } else {
            ll pali = min(ma[i], mb[i]);
            ll r = (pali)/2;

            pali_ini = (i-1)/2 - (r-1) -1;
            pali_end = (i+1)/2 + (r-1) +1;
            middle_ini = (i-1)/2;
            middle_end = (i+1)/2;
        }
        pali_ini = max(0ll, pali_ini);
        pali_end = min(n-1, pali_end);

        debug(i);
        debug(middle_ini);
        debug(middle_end);
        debug(pali_ini);
        debug(pali_end);


        // fudeu, tem que consertar abaixo;

        sum += max(min(border, middle_ini) - pali_ini + 1, 0ll);
        sum += max(pali_end - max((n-1 - border), middle_end) + 1, 0ll);

        debug(sum); 
    }

    if(border == n-1) sum+= 2;
    sum -= border+1;

    cout << sum << ln;
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();
    return 0;
}
