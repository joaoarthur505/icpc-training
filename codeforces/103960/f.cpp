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

bool order (string s1 , string s2) {
    ll k = min(s1.size(),s2.size());
    forn(i,0,k) {
        if (s1[i]<s2[i])
            return true;
        else if (s1[i]>s2[i])
            return false;
    }
    if (s1.size()<s2.size())
        return true;
    else 
        return false;
}

int main() {     
    _;
    ll n , c ; 
    cin >> n >> c ; 
    vector<string> v (n);

    forn(i,0,n)
        cin >> v[i];
    string vc = "abcdefghijklmnopqrstuvwxyz";
    //cout << vc.size() << ln;

    unordered_map<string, ll > m  ;  
    
    forn(i,0,n) {
        forn(j,0,vc.size()) {
            string s2 = v[i];
		forn(k,0,v[i].size())
			if (s2[k]=='*') {
				s2[k]=vc[j];
				m[s2]++;
			}		
        }
    }
	string max_num_s ; 
	ll max_num  = 0 ;
	for (auto s2 : m) {
		ll k = s2.second;
		if (k>max_num) {
			max_num_s= s2.first;
			max_num = k;
		}
		else if (max_num==k && order(s2.first,max_num_s)) {
			max_num_s  = s2.first;
			max_num = k;
		}
	}
	cout << max_num_s << " " << max_num << ln;
    return 0;
}