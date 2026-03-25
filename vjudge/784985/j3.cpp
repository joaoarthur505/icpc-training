#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define per(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); i--)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x.size())

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pii>;
using vl = vector<ll>;
using vb = vector<bool>;

using ld = long double;
struct Line {
    ld a, b, c;
};

bool half(Line m) { return m.a < 0 || m.a == 0 && m.b < 0; }

bool operator<(Line m, Line n) {
    return make_pair(half(m), m.b * n.a) < make_pair(half(n), m.a * n.b);
}

const ld INF = 1e18;

tuple<ld, ld, ld> LineIntersection(Line m, Line n) {
    ld d = m.a * n.b - m.b * n.a;
    ld x = m.c * n.b - m.b * n.c;
    ld y = m.a * n.c - m.c * n.a;
    return {x, y, d};
}

struct HalfplaneSet : multiset<Line> {
    HalfplaneSet() {
        insert({+1, 0, INF}), insert({0, +1, INF});
        insert({-1, 0, 0}), insert({0, -1, 0});
    }

    auto adv(auto it, int z) {
        return (z == -1 ? --(it == begin() ? end() : it)
                        : ++it == end() ? begin() : it);
    }

    bool chk(auto it) {
        Line l = *it, pl = *adv(it, -1), nl = *adv(it, +1);
        auto [x, y, d] = LineIntersection(pl, nl);
        ld sat = l.a * x + l.b * y - l.c * d;
        if (d < 0 && sat < 0) return clear(), 0;
        if ((d > 0 && sat <= 0) || (d == 0 && sat < 0)) return erase(it), 1;
        return 0;
    }

    void Cut(Line l) {
        if (empty()) return;
        auto it = insert(l);
        if (chk(it)) return;
        for (int z : {-1, +1})
            while (size() && chk(adv(it, z)));
    }

    ld Maximize(ld a, ld b) {
        if (empty()) return -1 / 0.;
        auto it = lower_bound({a, b});
        if (it == end()) it = begin();
        auto [x, y, d] = LineIntersection(*adv(it, -1), *it);
        return (1.0 * a * x + 1.0 * b * y) / d;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, p, q;
    cin >> n >> p >> q;

    HalfplaneSet hp;
    rep(i, 0, n) {
        int a, b;
        cin >> a >> b;
        hp.Cut({(ld)a, (ld)b, 1});
    }

    cout << fixed << setprecision(10) << hp.Maximize(p, q) << '\n';
}