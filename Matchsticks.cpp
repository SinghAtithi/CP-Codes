/*
    कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
    मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

    Karmanye vadhikaraste Ma Phaleshu Kadachana,
    Ma Karmaphalaheturbhurma Te Sangostvakarmani,

    The meaning of the verse is :—
    You have the right to work only but never to its fruits.
    Let not the fruits of action be your motive, nor let your attachment be to
   inaction
*/

#include <math.h>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define int int64_t
#define vi vector<int>
#define vii vector<pair<int, int>>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define pb push_back
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define vin(x, v) \
    for (auto& x : v) cin >> x;
#define vout(x, v) \
    for (auto x : v) cout << x << " ";
#define MEM(a, b) memset(a, (b), sizeof(a))
#define loop(i, j, k) for (int i = j; i < k; i += 1)
#define rloop(i, j, k) for (int i = j; i >= k; i -= 1)
#define rep(i, j) loop(i, 0, j)
#define rrep(i, j) rloop(i, j, 0)
#define MP make_pair
#define endl "\n"
#define INF (int)1e18
#define EPS 1e-18
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define MODD 998244353
// cout <<setprecision(15)
#define NEED_FOR_SPEED_MOST_WANTED    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

/*-----------------------------------D-E-B-U-G-----------------------------------------------*/
#ifndef ONLINE_JUDGE
#define deb(x)         \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define deb(x)
#endif

void _print(int32_t t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T> void _print(vector<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T> void _print(set<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T> void _print(multiset<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
/*-----------------------------------D-E-B-U-G-----------------------------------------------*/
struct node {
    int mini;
    int maxi;
};

int N;
vi arr;
vector<node> segTree;

node merge(node a, node b) {
    return {min(a.mini, b.mini), max(a.maxi, b.maxi)};
}

void build(int v, int start, int end) {
    if (start == end) {
        segTree[v] = {arr[start], arr[start]};
        return;
    }
    int mid = (start + end) / 2;
    build(2 * v, start, mid);
    build(2 * v + 1, mid + 1, end);
    segTree[v] = merge(segTree[2 * v], segTree[2 * v + 1]);
}

node query(int v, int l, int r, int start, int end) {
    if (l > end || r < start || l > r) {
        return {INT_MAX, INT_MIN};
    }
    if (l <= start && r >= end) {
        return segTree[v];
    }
    int mid = (start + end) / 2;
    node left = query(2 * v, l, r, start, mid);
    node right = query(2 * v + 1, l, r, mid + 1, end);
    return merge(left, right);
}

node query(int l, int r) { return query(1, l, r, 0, N - 1); }

void init() {
    cin >> N;
    arr.resize(N);
    vin(x, arr);
    segTree.resize(4 * N);
    cout << fixed;
    cout << setprecision(1);
}

double ans(int l, int r) {
    node a = query(l, r);
    node b = query(r + 1, N - 1);
    node c = query(0, l - 1);
    double ans = a.mini;
    ans += (double(a.maxi - a.mini)) / 2;
    ans = max(ans, double(a.mini + b.maxi));
    ans = max(ans, double(a.mini + c.maxi));
    return ans;
}

void solve() {

    /*
        Good question to start with segTree
        You can use node or make two seg trees
        make sure to avoid edge case such as i did!
        in case my (l>r) and some part of [l,r] is in range [0,n-1] it will give WA
    */

    init();
    int q;
    cin >> q;
    build(1, 0, N - 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << ans(l, r) << "\n";
    }
}

signed main() {
    NEED_FOR_SPEED_MOST_WANTED;
    //#ifndef ONLINE_JUDGE
    // FOR GETTING INPUT FROM input.txt
    // freopen("input.txt", "r", stdin);
    // FOR GETTING INPUT FROM input.txt
    // freopen("output.txt", "w", stdout);
    //	#endif
    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
        cout << endl;
    }
}