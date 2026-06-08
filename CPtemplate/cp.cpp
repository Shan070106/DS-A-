#include <bits/stdc++.h>
using namespace std;

// ---------- Type aliases ----------
typedef string str;
typedef long double ld;
typedef long long int lli;
typedef unsigned long long int ull;

// ---------- Constants ----------
const lli MOD = 1e9 + 7;
const lli INF = 1e18;
const double EPS = 1e-9;

// ---------- Fast I/O ----------
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

// ---------- Macros ----------
#define all(x) (x).begin(), (x).end()
#define sum(x) accumulate(all(x), 0LL)
#define rall(x) (x).rbegin(), (x).rend()
#define permute(x) next_permutation(all(x))

//---------- Added STL Macros -----------------
#define cnti1(x) __builtin_popcount(x)
#define cntll1(x) __builtin_popcountll(x)

//---------- STL Shortened -----------------
#define ft front
#define bk back
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define rb pop_back
#define rf pop_front
#define eb emplace_back

//---------- Inputs & Outputs -----------------
#define endl '\n'
#define no cout << "NO\n";
#define yes cout << "YES\n";
#define inputs(v, n) for (int i = 0; i < n; ++i) cin >> v[i];
#define READ_LINE(type, var, action) { \
    string _l; getline(cin, _l); \
    stringstream _ss(_l); type var; \
    while(_ss >> var) { action; } \
}
// Usage: READ_LINE(int, x, dist[i][x] = 1); 


//-------------- Data Structure type shortened ----------------
template <size_t N> using bit = std::bitset<N>;
template <typename T> using stk = std::stack<T>;
template <typename T> using que = std::queue<T>;
template <typename T> using deq = std::deque<T>;
template <typename T> using vec = std::vector<T>;
template <typename T> using uset = std::unordered_set<T>;
template <typename T> using mxhp = std::priority_queue<T>;

// For multiple types (Maps)
template <typename K, typename V> using umap = std::unordered_map<K, V>;

// For the Min-Heap (the long one)
template <typename T> using mnhp = std::priority_queue<T, std::vector<T>, std::greater<T>>;

// ---------- Debug ----------
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << x << endl
#else
#define dbg(x)
#endif

// ---------- Common Loops ----------
#define rep(i, a, b) for (lli i = (a); i < (b); ++i)
#define repr(i, a, b) for (lli i = (b) - 1; i >= (a); --i)
#define fl(i ,a ,b ,c) for (lli i = (a); i <= (b); i += (c))
#define maxe(v) *max_element(all(v))
#define mine(v) *min_element(all(v))


// ---------- Helper Functions ----------
lli gcd(lli a, lli b) { return b ? gcd(b, a % b) : a; }
lli lcm(lli a, lli b) { return (a / gcd(a, b)) * b; }
lli mod_add(lli a, lli b, lli m = MOD) { a %= m; b %= m; return (a + b) % m; }
lli mod_sub(lli a, lli b, lli m = MOD) { a %= m; b %= m; return (a - b + m) % m; }
lli mod_mul(lli a, lli b, lli m = MOD) { a %= m; b %= m; return (a * b) % m; }
lli mod_pow(lli a, lli b, lli m = MOD) {
    lli res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = mod_mul(res, a, m);
        a = mod_mul(a, a, m);
        b >>= 1;
    }
    return res;
}

vec<lli> factors(lli n){
    vec<lli> res;
    for (lli i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res.pb(i);
            n /= i;
        }
    }
    // sort(all(res));
    if (n > 1) res.pb(n);
    return res;
}

// ---------- Main Function ----------
int main() {
    fastio;

    int T = 1;
    cin >> T;
    while (T--) {

    }

    return 0;
}
