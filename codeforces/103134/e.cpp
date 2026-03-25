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

struct Palavra
{
    string p;
    set<string> dep;
    bool aprendido;
    //bool operator<(Palavra o) {
    //    return this->p.size() < o.p.size();
    //}
};

bool aprende(Palavra pal, set<string> dict)
{
    for (string p: pal.dep) {
        if (dict.find(p) == dict.end()) {
            return false;
        }
    }
    pal.aprendido = true;
    return true;
}

int main(){
    
    ll nDict;
    cin >> nDict;

    set<string> dict;
    forn(i, 0, nDict) {
        string x;
        cin >> x;
        dict.insert(x);
    }

    ll nFila;
    cin >> nFila;
    vector<Palavra> fila;
    vector<bool> aprendido;

    forn(i, 0, nFila) {
        string p;
        ll nDep;
        cin >> p;
        cin >> nDep;
        
        set<string> dep;
        forn(j, 0, nDep) {
            string x;
            cin >> x;
            dep.insert(x);
        }

        Palavra pal;
        pal.p = p;
        pal.dep = dep;
        fila.push_back(pal);
        aprendido.push_back(false);
    }
    
    bool aprendeu = true;
    while (aprendeu)
    {
        aprendeu = false;

        forn(i, 0, nFila) {
            Palavra pal = fila[i];
            if (aprendido[i]) {
                continue;
            } else {

                if (aprende(pal, dict)) {
                    aprendeu = true;
                    aprendido[i] = true;
                    dict.insert(pal.p);
                }
            }
        }
    }

    cout << dict.size() << ln;
    

    return 0;
}