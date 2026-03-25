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

int main(){
    _;
    string s1 , s2 ,s3;
    cin >> s1;
    cin >> s2;
    s3 = "";
    multiset<char> m1 , m2 , m3;
    for (char c : s1) {m1.insert(c);}
    for (char c : s2) {m2.insert(c);}
    
    for (char c : m1) {
        if (m2.find(c)!=m2.end()) {
            m3.insert(c);
            m2.erase(m2.find(c));
        }
            m1.erase(m1.find(c));
    }
    for (char c:s1) {
        if (m3.find(c)!=m3.end()){
            s3.push_back(c);
            m3.erase(m3.find(c));
        }
        if (m3.size()==0){
            break;
        }

    }
    cout << s3.length() << ln;



    return 0;
}